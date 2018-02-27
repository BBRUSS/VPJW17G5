#include "imageprocessingworker.h"

ImageProcessingWorker::ImageProcessingWorker(UDPSettings udpStruct, cv::Ptr<cv::aruco::DetectorParameters> arucoParameters, QList<cv::VideoCapture> videoCapture, QList<cv::Mat> cameraMatrix, QList<cv::Mat> distCoeffs, QList<cv::Mat> perspTransfMatrix, QList<RobotOffset> robotOffsets)
{
    qRegisterMetaType<QList<cv::Mat>>("QList<cv::Mat>");
    qRegisterMetaType<QList<cv::Point3f>>("QList<cv::Point3f>");
    qRegisterMetaType<QList<RobotPosition>>("QList<RobotPosition>");

    udpClient = new MyUDP(nullptr);
    // create UDP-Client and open socket
    udpClient->setSendConfig (udpStruct.sendToIp,udpStruct.sendToPort);

    udpClient->setReciveConfig_SyncService(udpStruct.reciveIp_SyncService,udpStruct.recivePort_SyncService);
    udpClient->setSendConfig_SyncService(udpStruct.sendToIp_SyncService,udpStruct.sendToPort_SyncService);

    connect(this, &ImageProcessingWorker::finishedUDPData, udpClient, &MyUDP::sendUdpData);

    threadPool.setMaxThreadCount(NR_OF_CAMS);
    for (int i = 0; i < NR_OF_CAMS; i++)
    {
        ImgTask* temp = new ImgTask();

        temp->setAutoDelete(false);
        temp->setCameraMatrix(cameraMatrix.at(i));
        temp->setDistCoeffs(distCoeffs.at(i));
        temp->setPerspTransfMatrix(perspTransfMatrix.at(i));
        temp->setRobotOffsets(robotOffsets);
        tasks.append(temp);
    }
    this->arucoParameters = arucoParameters;
    this->videoCapture = videoCapture;
    this->cameraMatrix = cameraMatrix;
    this->distCoeffs = distCoeffs;
    this->perspTransfMatrix = perspTransfMatrix;
    this->robotOffsets = robotOffsets;
}

ImageProcessingWorker::~ImageProcessingWorker() {
}

void ImageProcessingWorker::setMeasureData(bool measure) {
    measureData = measure;
}

void ImageProcessingWorker::setTaskThreshold(int threshold) {
    this->taskThreshold = threshold;
}

void ImageProcessingWorker::setTaskRectMinSize(int minSize) {
    this->taskRectMinSize = minSize;
}

void ImageProcessingWorker::processImages() {

    if(!workerMutex.tryLock())
    {
        return;
    }
    // GRAB TIMESTAMP
    timeStamp = QTime::currentTime(); // read system time

    //TODO: Gui-Elemente zu den entsprechenden Optionen entfernen.
//    if(ui->slider_cornerRefinementMaxIterations->value() > 2)
//    {
//        arucoParameters->doCornerRefinement = true;
//    } else {
//        arucoParameters->doCornerRefinement = false;
//    }

    //Signal an Main class
    //ui->t4_label->setText(QString::number(udpClient.msg_4));


    // READ IMAGES FROM CAMERAS
    // grab frames with smallest time difference possible
    // "grab()" + "retrieve()" is faster than the combined function "read()"

    for (int i = 0; i < NR_OF_CAMS; i++)
    {
        if (videoCapture[i].isOpened())
        {
            videoCapture[i].grab();
        }
    }

    // Fetch detected Robots from tasks
    QList<RobotPosition> detectedRobots;

    for (int i = 0; i < NR_OF_CAMS; i++)
    {
        if (videoCapture[i].isOpened())
        {
            videoCapture[i].retrieve(cameraImages[i], 0);   // get frames from camera
        }
        else     // no camera connected, use black image
        {
            cv::Mat blackImage(CAMERA_IMG_HEIGTH, CAMERA_IMG_WIDTH, CV_8UC3);
            blackImage.setTo(COLOR_BLACK);
            cameraImages[i] = blackImage;
        }

        // start seperate tasks
        tasks[i]->setImage(cameraImages[i]);
        tasks[i]->setDebugMode(debugMode);
        tasks[i]->setCalibrateOffset(calibrateOffset_ON_OFF);
        tasks[i]->setArucoParameters(arucoParameters);
        tasks[i]->setthreshold(taskThreshold);
        tasks[i]->setMinSizeofRects(taskRectMinSize);
        threadPool.start( tasks[i]);
    }
    threadPool.waitForDone();

    for (int i = 0; i < NR_OF_CAMS; i++)
    {
        detectedRobots.append(tasks[i]->getdetectRobots());
    }
    //User clicked on Calibration
    if(calibrateOffset_ON_OFF)
    {
        //Fetch Calibration Data from Tasks
        QList<RobotOffset> foundOffsets;

        for (int i = 0; i < NR_OF_CAMS; i++)
        {
            foundOffsets.append(tasks[i]->getNewRobotOffsets());
            tasks[i]->clearNewRobotOffsets();
        }

        if(foundOffsets.size() != MAX_NR_OF_ROBOTS)
        {
            QString alarmtxt = "Calibration failed! Please place all Robots in Field! Founded Robots are: ";
            for(int i = 0; i < foundOffsets.size() ;i++)
            {
                alarmtxt = alarmtxt + QString::number(foundOffsets.at(i).id+1);

                if(i+1 != foundOffsets.size())
                    alarmtxt = alarmtxt + ",";
            }
            QMessageBox msgBox;
            msgBox.setText(alarmtxt);
            msgBox.exec();
        }
        else
        {
            //Save Offsets
            QSettings settings("settings.ini", QSettings::IniFormat);
            settings.beginGroup("RobotDetectionSettings");
            QString optionNameQString;
            for(int i = 0; i < foundOffsets.size() ;i++)
            {
                //Build String
                optionNameQString = "Robot" + QString::number(foundOffsets.at(i).id);
                settings.setValue(optionNameQString + "MEven",QString::number(-foundOffsets.at(i).offsetMarkerEven));
                settings.setValue(optionNameQString + "MNotEven",QString::number(foundOffsets.at(i).offsetMarkerNotEven));
            }
            settings.endGroup();
        }

        calibrateOffset_ON_OFF = false;
        foundOffsets.clear();
    }

    // init locations with zeros
    for (int i = 0; i < MAX_NR_OF_ROBOTS; i++)
    {
        robotLocations.append(cv::Point3f(0, 0, 0));
    }
    //Check all Robots of double detections
    //That mean, two or more Robots, are detected on the same Place (This is not possible!)
    QList<int> doubledetecterobots;
    for(int a = 0;a<MAX_NR_OF_ROBOTS;a++)
    {
        for(int i = 0; i < detectedRobots.size();i++)
        {
            if(detectedRobots[i].id == a)
            {
                for(int b = 0; b < detectedRobots.size(); b++)
                {

                    if(i != b
                            &&  detectedRobots[i].id != detectedRobots[b].id
                            && (detectedRobots[i].coordinates.x >= detectedRobots[b].coordinates.x-250 && detectedRobots[i].coordinates.x <= detectedRobots[b].coordinates.x+250)
                            && (detectedRobots[i].coordinates.y >= detectedRobots[b].coordinates.y-250 && detectedRobots[i].coordinates.y <= detectedRobots[b].coordinates.y+250))
                    {
                        doubledetecterobots.append(a);
                    }

                }
                robotLocations[a] = detectedRobots[i].coordinates;
            }
        }

        for(int i =0;i < doubledetecterobots.size();i++)
        {
            robotLocations[doubledetecterobots.at(i)] = cv::Point3f(0, 0, 0);
        }
    }

    //If Measurement is checked, save all Robot Positions, in a txt. File
    if(measureData)
    {
        std::ofstream f;
        f.open("Measurement.txt",std::ios::app);

        for(int a = 0;a<robotLocations.size();a++)
        {
            f << robotLocations[a].x << "\t" << robotLocations[a].y << "\t" << robotLocations[a].z << "\t";
        }

        f << "\n";
        f.close();
    }
    // sendUDPdata...
    emit finishedUDPData(robotLocations, timeStamp);
    //udpClient->sendUdpData(robotLocations, timeStamp);

    for (int i = 0; i < NR_OF_CAMS; i++)
    {
        warpedImage.append(tasks[i]->getWarpedImage());
    }

    emit updateGui(warpedImage, robotLocations, detectedRobots);

    warpedImage.clear();
    detectedRobots.clear();
    robotLocations.clear();
    workerMutex.unlock();
}
