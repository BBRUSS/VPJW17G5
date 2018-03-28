#include "imageprocessingworker.h"
#include <QDebug>

ImageProcessingWorker::ImageProcessingWorker(Settings::UDPSettings udpStruct, cv::Ptr<cv::aruco::DetectorParameters> arucoParameters, cv::Ptr<cv::aruco::Dictionary> arucoDict, QList<cv::VideoCapture> &videoCapture, QList<cv::Mat> cameraMatrix, QList<cv::Mat> distCoeffs, QList<cv::Mat> perspTransfMatrix, QList<RobotOffset> robotOffsets)
{
    qRegisterMetaType<QList<cv::Mat>>("QList<cv::Mat>");
    qRegisterMetaType<QList<cv::Point3f>>("QList<cv::Point3f>");
    qRegisterMetaType<QList<RobotPosition>>("QList<RobotPosition>");
    qRegisterMetaType<QList<QList<RobotPosition>>>("QList<QList<RobotPosition>>");
    qRegisterMetaType<QList<int>>("QList<int>");

    udpClient = new MyUDP(nullptr);
    // create UDP-Client and open socket
    udpClient->setSendConfig (QString::fromStdString(udpStruct.sendToIp), udpStruct.sendToPort);
    udpClient->setReciveConfig_SyncService(QString::fromStdString(udpStruct.reciveIp_SyncService),udpStruct.recivePort_SyncService);
    udpClient->setSendConfig_SyncService(QString::fromStdString(udpStruct.sendToIp_SyncService),udpStruct.sendToPort_SyncService);

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
    this->arucoDict = arucoDict;
    this->videoCapture = videoCapture;
    this->cameraMatrix = cameraMatrix;
    this->distCoeffs = distCoeffs;
    this->perspTransfMatrix = perspTransfMatrix;
    this->robotOffsets = robotOffsets;
}

ImageProcessingWorker::~ImageProcessingWorker() {
}

void ImageProcessingWorker::setArucoDict(cv::Ptr<cv::aruco::Dictionary> arucoDict){
    this->arucoDict = arucoDict;
}

void ImageProcessingWorker::setArucoParameters(cv::Ptr<cv::aruco::DetectorParameters> arucoParameters) {
    this->arucoParameters = arucoParameters;
}

void ImageProcessingWorker::setCameraMatrix(const QList<cv::Mat> cameraMatrix){
    this->cameraMatrix = cameraMatrix;
}

void ImageProcessingWorker::setDebugMode(bool debugMode) {
    this->debugMode = debugMode;
}

void ImageProcessingWorker::setDistCoeffs(const QList<cv::Mat> distCoeffs){
    this->distCoeffs = distCoeffs;
}

void ImageProcessingWorker::setMeasureData(bool measure) {
    measureData = measure;
}

void ImageProcessingWorker::setPerpTransfMatrix(const QList<cv::Mat> perspTransfMatrix) {
    this->perspTransfMatrix = perspTransfMatrix;
}

void ImageProcessingWorker::setRobotCount(int robotCount) {
    this->robotCount = robotCount;
}

void ImageProcessingWorker::setRobotOffsets(const QList<RobotOffset> robotOffsets) {
    this->robotOffsets = robotOffsets;
}

void ImageProcessingWorker::setTaskRectMinSize(int minSize) {
    this->taskRectMinSize = minSize;
}

void ImageProcessingWorker::setTaskThreshold(int threshold) {
    this->taskThreshold = threshold;
}

void ImageProcessingWorker::setUdpSettings(const Settings::UDPSettings udpStruct) {
    // create UDP-Client and open socket
    udpClient->setSendConfig (QString::fromStdString(udpStruct.sendToIp), udpStruct.sendToPort);
    udpClient->setReciveConfig_SyncService(QString::fromStdString(udpStruct.reciveIp_SyncService),udpStruct.recivePort_SyncService);
    udpClient->setSendConfig_SyncService(QString::fromStdString(udpStruct.sendToIp_SyncService),udpStruct.sendToPort_SyncService);
}

void ImageProcessingWorker::setVideoCapture(const QList<cv::VideoCapture> &videoCapture) {
    this->videoCapture = videoCapture;
}

void ImageProcessingWorker::startProcessing() {
    if(!workerMutex.tryLock())
    {
        return;
    }

    mainLoopActive = true;

    QElapsedTimer timer;

    while (mainLoopActive){
        int localRobotCount = robotCount;
        // GRAB TIMESTAMP
        timeStamp = QTime::currentTime(); // read system time

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
            tasks[i]->setArucoDict(arucoDict);
            tasks[i]->setThreshold(taskThreshold);
            tasks[i]->setMinSizeofRects(taskRectMinSize);
            tasks[i]->setRobotCount(localRobotCount);
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

            if(foundOffsets.size() != localRobotCount)
            {
                QString alarmtxt = "Calibration failed! Please place all Robots in Field! Found Robots are: ";
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
        for (int i = 0; i < localRobotCount; i++)
        {
            robotIDLocation.append(QList<RobotPosition>());
            robotLocations.append(cv::Point3f(0, 0, 0));
            robotLocationStd.append(cv::Point3f(0, 0, 0));
            robotLocationStd1d.append(0);
        }


        QVector<int> falseDetection = QVector<int>(detectedRobots.size());
        for(int a = 0;a<localRobotCount;a++)
        {
            for(int i = 0; i < detectedRobots.size();i++)
            {
                if(detectedRobots[i].id == a)
                {
                    robotIDLocation[a].append(detectedRobots[i]);
                    robotIDLocation[a].last().id = i;

                    for(int b = 0; b < detectedRobots.size(); b++)
                    {
                        if (i == b) {
                            continue;
                        }
                        if (detectedRobots[i].id != detectedRobots[b].id) {
                            if(abs(detectedRobots[i].coordinates.x - detectedRobots[b].coordinates.x) < 250
                                    && (abs(detectedRobots[i].coordinates.y - detectedRobots[b].coordinates.y) < 250))
                            {
                                falseDetection[i] = 1;
                            }
                        } else {
                            robotIDLocation[a].append(detectedRobots[b]);
                            robotIDLocation[a].last().id = b;
                        }

                    }

                }
            }
        }

        for (int a = 0;a<localRobotCount;a++) {
            cv::Point3f tempMeanVal = cv::Point3f(0, 0, 0);
            cv::Point3f tempVariance3f = cv::Point3f(0, 0, 0);
            cv::Point3f tempStdVal = cv::Point3f(0, 0, 0);

            int tempStdVal1d = 0;

            if (!robotIDLocation[a].empty()) {

                for(int i = 0; i < robotIDLocation[a].size(); i++) {
                    tempMeanVal += robotIDLocation[a].at(i).coordinates;
                }
                tempMeanVal = tempMeanVal / robotIDLocation[a].size();

                if (robotIDLocation[a].size() > 1) {
                    for(int i = 0; i < robotIDLocation[a].size(); i++) {
                        tempVariance3f += (robotIDLocation[a].at(i).coordinates-tempMeanVal)*(robotIDLocation[a].at(i).coordinates-tempMeanVal);
                    }
                    tempVariance3f = tempVariance3f / (robotIDLocation[a].size()-1);
                    tempStdVal.x = sqrt(tempVariance3f.x);
                    tempStdVal.y = sqrt(tempVariance3f.y);
                    tempStdVal.z = sqrt(tempVariance3f.z);

                    tempStdVal1d = sqrt(tempVariance3f.x + tempVariance3f.y);

                    if (tempStdVal1d > ROBOT_STD_THRESH_MAX)  {
                        tempMeanVal = cv::Point3f(0, 0, 0);
                    }
                }

            }
            robotLocations[a] = tempMeanVal;
            robotLocationStd[a] = tempStdVal;
            robotLocationStd1d[a] = tempStdVal1d;
        }


        //If Measurement is checked, save all Robot Positions, in a txt. File
        if(measureData)
        {
            std::ofstream f;
            f.open("Measurement.txt",std::ios::app);

            for(int a = 0;a<robotLocations.size();a++)
            {
                f << robotLocations[a].x << "\t" << robotLocations[a].y << "\t" << robotLocations[a].z << "\t";
                f << robotLocationStd[a].x << "\t" << robotLocationStd[a].y << "\t" << robotLocationStd[a].z << "\t";
            }

            f << "\n";
            f.close();
        }
        // sendUDPdata...
        emit finishedUDPData(robotLocations, timeStamp);
        //udpClient->sendUdpData(robotLocations, timeStamp);
        emit requestUDPIncrement();

        if (debugMode) {
            for (int i = 0; i < NR_OF_CAMS; i++)
            {
                liveViewImage.append(tasks[i]->getLiveViewImage());
            }
        }

        emit requestSettingsUpdate();
        emit updateGui(liveViewImage, robotLocations, robotLocationStd1d, robotIDLocation, detectedRobots);

        robotIDLocation.clear();
        liveViewImage.clear();
        detectedRobots.clear();
        robotLocations.clear();

        qApp->processEvents();
    }
}

void ImageProcessingWorker::stopProcessing() {
    mainLoopActive = false;
    workerMutex.unlock();
}

cv::Point3f operator*(const cv::Point3f& a, const cv::Point3f& b) {
    double x1 = a.x;
    double x2 = b.x;
    double y1 = a.y;
    double y2 = b.y;
    double z1 = a.z;
    double z2 = b.z;

    return cv::Point3f(x1*x2, y1*y2, z1*z2);
}
