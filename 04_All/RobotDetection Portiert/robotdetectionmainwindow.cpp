/****************************************************************************
 * This is the RobotDetection main programm. It is part of the camera
 * calibration and robot detection system created by  "Gewerk 5"  during the
 * cooperative project of automation technologies in 2013/2014 at the Hamburg
 * University of Applied Sciences.
 *
 * Filename: robotdetectionmainwindow.cpp
 * Author:   Markus Baden, Benjamin Wilberger
 * Created:  2013-12-24
 * Changed:  2014-04-17
 * Changed:  2016-04-12 : Extend by ARUCO and Clock-Synchronisation
 ***************************************************************************/

#include "robotdetectionmainwindow.h"
#include "ui_robotdetectionmainwindow.h"
#include <iostream>
#include <fstream>
#include <QDebug>
#include <QShortcut>

/*
 * Constructor & Destructor Section
 */

RobotDetectionMainWindow::RobotDetectionMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RobotDetectionMainWindow)
{

    ui->setupUi(this);

    //F5 Shortcut for Start/Stop Camera
    QShortcut *shortcutF5 = new QShortcut(QKeySequence(Qt::Key_F5), this);
    connect(shortcutF5, SIGNAL(activated()), ui->pushButtonStartCam, SLOT(click()));

    QShortcut *shortcutF6 = new QShortcut(QKeySequence(Qt::Key_Period), this);
    connect(shortcutF6, SIGNAL(activated()), ui->pushButtonStopCam, SLOT(click()));

    QShortcut *shortcutF9 = new QShortcut(QKeySequence(Qt::Key_PageDown), this);
    connect(shortcutF9, SIGNAL(activated()), ui->pushButtonTakeSnapshot, SLOT(click()));

    QShortcut *shortcutBackSpace = new QShortcut(QKeySequence(Qt::Key_Backspace), this);
    connect(shortcutBackSpace, SIGNAL(activated()), ui->pushButtonResetThr, SLOT(click()));

    if(programSettings.load())
    {
        ui->tabMain->setCurrentIndex(3);
        ui->tabMain_Navigation->setEnabled(false);
        ui->tabMain_Aruco->setEnabled(false);
        ui->tabMain_Calibration->setEnabled(false);
        ui->pushButtonSaveSettings->setEnabled(false);
    }

    ui->spinBoxSwap1->setEnabled(false);
    ui->spinBoxSwap2->setEnabled(false);
    ui->pushButtonSwap->setEnabled(false);

    udpStruct = programSettings.udpStruct;
    timerMilSecs = programSettings.timerMilSecs;
    ui->slider_cornerRefinementMaxIterations->setValue(programSettings.cornerRefinementMaxIterations);
    ui->slider_cornerRefinementMinAccuracy->setValue(programSettings.cornerRefinementMinAccuracy);
    ui->slider_errorCorrectionRate->setValue(programSettings.errorCorrectionRate);
    ui->slider_adaptiveThreshWinSizeMin->setValue(programSettings.adaptiveThreshWinSizeMin);
    ui->slider_adaptiveThreshWinSizeStep->setValue(programSettings.adaptiveThreshWinSizeStep);
    ui->slider_adaptiveThreshConstant->setValue(programSettings.adaptiveThreshConstant);
    ui->slider_minMarkerPerimeterRate->setValue(programSettings.minMarkerPerimeterRate);
    ui->slider_maxMarkerPerimeterRate->setValue(programSettings.maxMarkerPerimeterRate);
    ui->slider_polygonalApproxAccuracyRate->setValue(programSettings.polygonalApproxAccuracyRate);
    ui->slider_perspectiveRemovePixelPerCell->setValue(programSettings.perspectiveRemovePixelPerCell);
    ui->slider_threshold->setValue(programSettings.cameraImageThreshold);
    ui->slider_MinSizeofRects->setValue(programSettings.MinSizeofRects);

    ui->lineEditSettingsFileName->setText(QString::fromStdString(programSettings.filename));
    ui->lineEditArucoDictionaryFileName->setText(QString::fromStdString(programSettings.arucoDictFileName));
    ui->lineEditArucoMakerSizeInPixel->setText(QString::number(programSettings.arucoMarkerSizePixel));
    ui->lineEditCameraFieldHeight->setText(QString::number(programSettings.cameraFieldSizeMilimeter.height));
    ui->lineEditCameraFieldWidth->setText(QString::number(programSettings.cameraFieldSizeMilimeter.width));
    ui->lineEditCameraImageHeight->setText(QString::number(programSettings.cameraImageSize.height));
    ui->lineEditCameraImageWidth->setText(QString::number(programSettings.cameraImageSize.width));
    ui->lineEditMaxNumberOfRobots->setText(QString::number(programSettings.robotMaxNumber));
    ui->lineEditNumberOfCams->setText(QString::number(programSettings.camFieldSize.area()));
    ui->lineEditReceiveIpSyncService->setText(QString::fromStdString(programSettings.udpStruct.reciveIp_SyncService));
    ui->lineEditReceivePortSyncService->setText(QString::number(programSettings.udpStruct.recivePort_SyncService));
    ui->lineEditRobotRadius->setText(QString::number(programSettings.robotRadius));
    ui->lineEditRobotStdThresh->setText(QString::number(programSettings.robotStdThresh));
    ui->lineEditRobotStdThreshMax->setText(QString::number(programSettings.robotStdThreshMax));
    ui->lineEditSendToIp->setText(QString::fromStdString(programSettings.udpStruct.sendToIp));
    ui->lineEditSendToIpSyncService->setText(QString::fromStdString(programSettings.udpStruct.sendToIp_SyncService));
    ui->lineEditSendToPort->setText(QString::number(programSettings.udpStruct.sendToPort));
    ui->lineEditSendToPortSyncService->setText(QString::number(programSettings.udpStruct.sendToPort_SyncService));
    ui->spinBoxFieldHeight->setValue(programSettings.camFieldSize.height);
    ui->spinBoxFieldWidth->setValue(programSettings.camFieldSize.width);

    ui->lineEditCalibrationBoardWidth->setText(QString::number(programSettings.boardSize.width));
    ui->lineEditCalibrationBoardHeight->setText(QString::number(programSettings.boardSize.height));
    ui->lineEditCalibrationSquareSize->setText(QString::number(programSettings.squareSize));
    ui->comboBoxCalibrationPattern->setCurrentIndex(programSettings.calibrationPattern-1);
    ui->checkBoxCalibrationPatternWhiteOnBlack->setChecked(programSettings.calibPatternWhiteOnBlack);

    ui->spinBoxCameraNr->setMaximum(programSettings.camFieldSize.area()-1);

    //load aruco dict
    this->defaultArucoDict = ArucoDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    this->defaultArucoDict.load(QString::fromStdString(programSettings.arucoDictFileName));
    this->initArucoTab();

    mainloopIsActive = false;
    calibrateOffset_ON_OFF = false;

    timerFPS = new QTimer(this);
    connect(timerFPS, &QTimer::timeout, this, &RobotDetectionMainWindow::incrementFPSCounter);
    fpsCount = 0;

    // read camera calibration data and perspective transform matrices from xml
    readXmlCalibrationFile();

    ui->labelVersion->setText("Version: " + QString(__DATE__) + " " + QString(__TIME__));

    setMaximumSize(size());

    // Calibration Tab configuration
    isCameraRunning = false;
    isCalibrate = false;

    ui->pushButtonStopCam->setEnabled(false);
    ui->horizontalSliderMaxValue->setEnabled(false);
    ui->horizontalSliderThreshold->setEnabled(false);
    ui->pushButtonTakeSnapshot->setEnabled(false);
    ui->pushButtonGetExtrinsics->setEnabled(false);
    ui->pushButtonResetThr->setEnabled(false);
    ui->pushButtonSaveContrast->setEnabled(false);
    ui->pushButtonSaveToXML->setEnabled(false);
}

RobotDetectionMainWindow::~RobotDetectionMainWindow()
{
    emit stopWorker();
    workerThread.quit();
    workerThread.wait();

    frames.stop();

    for(int i=0; i<captures.size(); i++)
    {
        if (captures.at(i)->isOpened())
        {
            captures.at(i)->release();
        }
    }

    programSettings.cornerRefinementMaxIterations = ui->slider_cornerRefinementMaxIterations->value();
    programSettings.cornerRefinementMinAccuracy = ui->slider_cornerRefinementMinAccuracy->value();
    programSettings.errorCorrectionRate = ui->slider_errorCorrectionRate->value();
    programSettings.adaptiveThreshWinSizeMin = ui->slider_adaptiveThreshWinSizeMin->value();
    programSettings.adaptiveThreshWinSizeStep = ui->slider_adaptiveThreshWinSizeStep->value();
    programSettings.adaptiveThreshConstant = ui->slider_adaptiveThreshConstant->value();
    programSettings.minMarkerPerimeterRate = ui->slider_minMarkerPerimeterRate->value();
    programSettings.maxMarkerPerimeterRate = ui->slider_maxMarkerPerimeterRate->value();
    programSettings.polygonalApproxAccuracyRate = ui->slider_polygonalApproxAccuracyRate->value();
    programSettings.perspectiveRemovePixelPerCell = ui->slider_perspectiveRemovePixelPerCell->value();
    programSettings.cameraImageThreshold = ui->slider_threshold->value();
    programSettings.MinSizeofRects = ui->slider_MinSizeofRects->value();
    programSettings.save();

    defaultArucoDict.save(QString::fromStdString(programSettings.arucoDictFileName));

    delete ui;
}

/*
 * Signals & Slots Section
 *
 * Slots
 */

void RobotDetectionMainWindow::incrementFPSCounter()
{
    QString str = "GUI Frames per second: ";
    str.append(QString::number(fpsCount));
    ui->labelFPS->setText(str);
    str = "UDP Frames per second: ";
    str.append(QString::number(udpCount));
    ui->labelUDPFPS->setText(str);
    fpsCount = 0;
    udpCount = 0;
}

void RobotDetectionMainWindow::incrementUDPCounter() {
    udpCount++;
}

void RobotDetectionMainWindow::updateGuiImage(const QList<cv::Mat> cameraImage, const QList<cv::Point3f> robotLocations, const QList<int> robotLocationsStd1d, const QList<QList<RobotPosition>> robotIDLocation, const QList<RobotPosition> detectedRobots){
    disconnect(imgWorker, &ImageProcessingWorker::updateGui, this, &RobotDetectionMainWindow::updateGuiImage);

    fpsCount++;

    writeRobotLocationsToTable(robotLocations);
    // Display either camera images or white background

    cv::Mat guiImage(programSettings.guiImageBase, CV_8UC3);
    if (ui->checkBoxLiveView->isChecked() && !cameraImage.empty())   // show real frames
    {
        guiImage.setTo(COLOR_BLACK);
        for (int i = 0; i < cameraImage.size(); i++)
        {
            if (!cameraImage[i].empty()) {
                // Undistort Image
                cv::Mat undistortedImage;
                cv::Mat warpedImage;
                cv::undistort(cameraImage[i], undistortedImage, cameraMatrix.at(i), distCoeffs.at(i));
                // Apply perspective Transformation
                cv::warpPerspective(undistortedImage, warpedImage, guiTransfMatrix.at(i), programSettings.guiImageBase, cv::INTER_NEAREST, cv::BORDER_CONSTANT, 0);
                cv::addWeighted(guiImage, 1, warpedImage, 1, 0, guiImage, -1);
            }
        }
    }
    else     // show white background with grid
    {
        guiImage.setTo(COLOR_WHITE);
        for (unsigned int i = 0; i < 40; i++)
        {
            if (i % 5 == 0)
            {
                cv::line(guiImage, cv::Point(i * 200 / programSettings.getGuiScale(), 0), cv::Point(i * 200 / programSettings.getGuiScale(), guiImage.rows), COLOR_DARK_GREY,  1, 8, 0);
            }
            else
            {
                cv::line(guiImage, cv::Point(i * 200 / programSettings.getGuiScale(), 0), cv::Point(i * 200 / programSettings.getGuiScale(), guiImage.rows), COLOR_LIGHT_GREY, 1, 8, 0);
            }
        }
        for (unsigned int i = 0; i < 20; i++)
        {
            if (i % 5 == 0)
            {
                cv::line(guiImage, cv::Point(0, i * 200 / programSettings.getGuiScale()), cv::Point(guiImage.cols, i * 200 / programSettings.getGuiScale()), COLOR_DARK_GREY,  1, 8, 0);
            }
            else
            {
                cv::line(guiImage, cv::Point(0, i * 200 / programSettings.getGuiScale()), cv::Point(guiImage.cols, i * 200 / programSettings.getGuiScale()), COLOR_LIGHT_GREY, 1, 8, 0);
            }
        }
    }
    // invert y-axis
    cv::flip(guiImage, guiImage, 0);

    //Draw Line and Circle for Robots in GUI
    for(int i = 0; i < robotLocations.size();i++)
    {

        //If a Robot are detected
        if(robotLocations[i].x != 0)
        {

            cv::Point2f centerPoint = cv::Point2f(robotLocations[i].x, programSettings.cameraFieldSizeMilimeter.height - robotLocations[i].y);
            double centerRadius = programSettings.robotRadius;
            double angledegree = 2*3.14159265359-(robotLocations[i].z*3.14159265359/180);
            cv::Point2f directionPoint = cv::Point2f(scaleToGui(centerPoint).x + scaleToGui(centerRadius)*cos(angledegree ), scaleToGui(centerPoint).y + scaleToGui(centerRadius)*sin(angledegree));

            //Draw circles and lines for center and orientation circles

            if (robotLocationsStd1d[i] >= programSettings.robotStdThresh) {

                cv::circle(guiImage, scaleToGui(centerPoint), scaleToGui(centerRadius+robotLocationsStd1d[i]), COLOR_RED, 2, CV_AA);
            } else {
                float stdPercent = robotLocationsStd1d[i]/programSettings.robotStdThresh;
                cv::circle(guiImage, scaleToGui(centerPoint), scaleToGui(centerRadius+robotLocationsStd1d[i]), cv::Scalar(0, 255*(1-stdPercent), 255*stdPercent), 2, CV_AA);
            }

            cv::circle(guiImage, scaleToGui(centerPoint), scaleToGui(centerRadius), COLOR_GREEN, 2, CV_AA);
            cv::line(guiImage, scaleToGui(centerPoint), directionPoint, COLOR_BLUE, 2, CV_AA);

        }
    }

    // show error message in image if camera is missing
    for (int j = 0; j < programSettings.camFieldSize.width; j++)
    {
        for (int i = 0; i < programSettings.camFieldSize.height; i++) {
            int ID = i*programSettings.camFieldSize.width+j;

            if( ! videoCapture[ID].isOpened())
            {
                std::string numStr = QString("Camera not connected. ID: " + QString::number(ID)).toStdString();
                int baseline = 0;
                Size textSize = cv::getTextSize(numStr, CV_FONT_HERSHEY_PLAIN, 1, 1, &baseline);
                int x = (programSettings.guiImageBase.width/programSettings.camFieldSize.width)*((float)j+0.5)-textSize.width/2.0;
                int y = (programSettings.guiImageBase.height/programSettings.camFieldSize.height)*((float)i+0.5)-textSize.height/2.0;
                cv::putText(guiImage, numStr, cv::Point2f(x, y), CV_FONT_HERSHEY_PLAIN, 1, COLOR_DARK_GREY, 1, 8, false);
            }
        }
    }

    // Write robot IDs into guiImage
    writeRobotIDsToGui(guiImage, robotLocations);

    //convert colors and show image in GUI
    cv::cvtColor(guiImage, guiImage, CV_BGR2RGB);
    QPixmap pixmap;

    //pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, QImage::Format_RGB888));
    pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, guiImage.step, QImage::Format_RGB888));
    //pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, QImage::Format_RGB888));
    ui->labelImage->setPixmap(pixmap);

    sendSettingsUpdate();
    if (workerThread.isRunning()) {
        connect(imgWorker, &ImageProcessingWorker::updateGui, this, &RobotDetectionMainWindow::updateGuiImage);;
    }
}

void RobotDetectionMainWindow::updateRobotOffsets(QList<RobotOffset> foundOffsets) {
    if (foundOffsets.size() < defaultArucoDict.getMarkerCount()/2) {
        ui->statusBar->showMessage("Not all robots found in camera images. Trying again ...", 2000);
    } else {
        for (int i = 0; foundOffsets.size(); i++) {
            int ID = foundOffsets.at(i).id;
            programSettings.robotOffset.at(ID) = foundOffsets.at(i).offsetMarkerEven;
        }
        robotOffsets.clear();
        for(int i = 0; i < programSettings.robotMaxNumber; i++)
        {
            RobotOffset temp = {i, programSettings.robotOffset[i], -programSettings.robotOffset[i]};
            robotOffsets.append(temp);
        }
        calibrateOffset_ON_OFF = false;
        ui->statusBar->showMessage("Robot offsets have been updated ...", 2000);
    }
}

// Aruco Section Start
void RobotDetectionMainWindow::on_pushButton_addAruco_clicked()
{
    if (defaultArucoDict.getMarkerCount() < programSettings.robotMaxNumber*2)
    {
        defaultArucoDict.add(2);
        initArucoTab();
    } else {
        this->ui->statusBar->showMessage("Maximum number of robots is reached. (" + QString::number(programSettings.robotMaxNumber) + ")");
    }
    //sendSettingsUpdate();
}

void RobotDetectionMainWindow::on_pushButton_deleteAruco_clicked()
{
    if (defaultArucoDict.getMarkerCount() > 2)
    {
        defaultArucoDict.remove(2);
        initArucoTab();
    }
}

void RobotDetectionMainWindow::on_tableWidget_Aruco_cellChanged(int row, int column)
{
    if (row%2) { // odd number
        this->ui->tableWidget_Aruco->item(row-1, column)->setText(this->ui->tableWidget_Aruco->item(row, column)->text());
    } else {
        this->ui->tableWidget_Aruco->item(row+1, column)->setText(this->ui->tableWidget_Aruco->item(row, column)->text());
    }
    updateIDNameHeightMap();
}

void RobotDetectionMainWindow::on_tableWidget_Aruco_cellClicked(int row, int column)
{
    updateArucoTab(row);
}

void RobotDetectionMainWindow::on_tabMain_tabBarClicked(int index)
{
    if (index == 2) {
        this->initArucoTab();
    }
}

void RobotDetectionMainWindow::on_pushButton_SaveToImage_clicked()
{
    QString fileName = QFileDialog::getExistingDirectory(this, "Open Directory",
                                                         QDir::currentPath(),
                                                         QFileDialog::ShowDirsOnly
                                                         | QFileDialog::DontResolveSymlinks);
    if (!fileName.isEmpty()) {
        QString name;
        QModelIndexList selectedIndexes = this->ui->tableWidget_Aruco->selectionModel()->selectedRows();
        for (int i = 0; i < selectedIndexes.size(); i++)
        {
            int row = selectedIndexes.at(i).row();
            int ID = this->ui->tableWidget_Aruco->item(row, 0)->text().toInt();
            name = defaultArucoDict.getNameById(row);
            QString namePrefix = QString::number(QDateTime::currentMSecsSinceEpoch()) + "_Name_"+ name + "_ID_";
            bool ret = defaultArucoDict.drawSingle(fileName + "/", namePrefix, ID);
            if (ret) {
                this->ui->statusBar->showMessage("File saved to " + fileName, 3000);
            } else {
                this->ui->statusBar->showMessage("Could not write to file:" + fileName, 3000);
            }
        }
    }
}
// Aruco Section End

void RobotDetectionMainWindow::on_pushButtonStartStop_clicked()
{

    if(mainloopIsActive)
    {
        this->ui->tabMain_Calibration->setEnabled(true);
        this->ui->tabMain_Settings->setEnabled(true);

        emit stopWorker();
        timerFPS->stop();
        for (int i = 0; i < programSettings.cams.size(); i++)
        {
            videoCapture[i].release();
        }
        workerThread.quit();
        ui->statusBar->showMessage("Releasing cameras...", 2000);
        ui->pushButtonStartStop->setText("Start Detection");
        mainloopIsActive = false;
    }
    else
    {
        //Set Offset for Robots
        robotOffsets.clear();
        for(int i = 0; i < programSettings.robotMaxNumber; i++)
        {
            RobotOffset temp = {i, -programSettings.robotOffset[i], programSettings.robotOffset[i]};
            robotOffsets.append(temp);
        }
        videoCapture.clear();

        this->ui->tabMain_Calibration->setEnabled(false);
        this->ui->tabMain_Settings->setEnabled(false);

        for (int i = 0; i < programSettings.cams.size(); i++)
        {
            cv::VideoCapture capt;
            videoCapture.append(capt);
            videoCapture[i].open(programSettings.cams.at(i)->cameraID); //TÓDO: 0 -> i
            videoCapture[i].set(CV_CAP_PROP_FRAME_WIDTH, programSettings.cameraImageSize.width);
            videoCapture[i].set(CV_CAP_PROP_FRAME_HEIGHT, programSettings.cameraImageSize.height);
            videoCapture[i].set(CV_CAP_PROP_BRIGHTNESS, brightnessValue[i]);
            videoCapture[i].set(CV_CAP_PROP_CONTRAST, contrastValue[i]);
            videoCapture[i].set(CV_CAP_PROP_EXPOSURE, exposureValue[i]);
        }
        ui->statusBar->showMessage("Connecting to cameras...", 3000);
        // give cameras some time to get connected,
        // otherwise program might crash (depends on camera driver)
        Sleep(3000);
        //timer.start(timerMilSecs);#

        QList<cv::Mat> tempCameraMatrix;
        QList<cv::Mat> tempDistCoeffs;
        QList<cv::Mat> tempGuiTransfMatrix;
        QList<cv::Mat> tempPerspTransfMatrix;

        for (int i = 0; i<programSettings.camFieldSize.area(); i++) {

            // build cameraMatrix
            tempCameraMatrix.insert(i, programSettings.cams.at(i)->cameraMatrix);
            tempDistCoeffs.insert(i, programSettings.cams.at(i)->distCoeffs);


            cout << programSettings.cams.at(i)->rvecs;

            cv::Mat R;
            cv::Rodrigues(programSettings.cams.at(i)->rvecs, R);
            cv::Mat P;
            cv::Mat Res;
            cv::hconcat(R, programSettings.cams.at(i)->tvecs, Res);
            P = programSettings.cams.at(i)->cameraMatrix*Res;

            cout << P;

            // perspTransfMatrix.insert(i, R);


            // calculate GUI Transformation Matrix by scaling down perspTransfMatrix
            cv:: Mat scaleMatrix = cv::Mat::zeros(3, 3, CV_64F);
            scaleMatrix.at<double>(0, 0) = 1.0 / programSettings.getGuiScale();
            scaleMatrix.at<double>(1, 1) = 1.0 / programSettings.getGuiScale();
            scaleMatrix.at<double>(2, 2) = 1.0;
            guiTransfMatrix.append(scaleMatrix * perspTransfMatrix.at(i));
        }
        imgWorker = new ImageProcessingWorker(programSettings.udpStruct, videoCapture, cameraMatrix, distCoeffs, perspTransfMatrix);
        imgWorker->setTaskThreshold(ui->slider_threshold->value());
        imgWorker->setTaskRectMinSize(ui->slider_MinSizeofRects->value());
        imgWorker->setRobotCount(defaultArucoDict.getMarkerCount()/2);
        imgWorker->setDebugMode(this->ui->checkBoxLiveView->isChecked());
        imgWorker->setMeasureData(this->ui->checkBox_Measurement->isChecked());
        imgWorker->setArucoParameters(readArucoParameters());
        imgWorker->setArucoDict(defaultArucoDict.get());
        imgWorker->setRobotOffsets(robotOffsets);
        imgWorker->setRobotMaxNumber(programSettings.robotMaxNumber);
        imgWorker->setRobotStdThreshMax(programSettings.robotStdThreshMax);
        imgWorker->moveToThread(&workerThread);

        connect(&workerThread, &QThread::finished, imgWorker, &QObject::deleteLater);
        connect(&workerThread, &QThread::started, imgWorker, &ImageProcessingWorker::startProcessing);
        connect(this, &RobotDetectionMainWindow::stopWorker, imgWorker, &ImageProcessingWorker::stopProcessing);

        connect(imgWorker, &ImageProcessingWorker::updateGui, this, &RobotDetectionMainWindow::updateGuiImage);
        connect(this, &RobotDetectionMainWindow::workerUpdateSettings, imgWorker, &ImageProcessingWorker::processSettingsUpdate);
        connect(imgWorker, &ImageProcessingWorker::requestUDPIncrement, this, &RobotDetectionMainWindow::incrementUDPCounter);
        connect(imgWorker, &ImageProcessingWorker::finishedRobotOffsets, this, &RobotDetectionMainWindow::updateRobotOffsets);

        workerThread.start(QThread::HighestPriority);

        timerFPS->start(1000);
        ui->pushButtonStartStop->setText("Stop Detection");
        mainloopIsActive = true;
    }
}

void RobotDetectionMainWindow::on_pushButtonCalibrateOffset_clicked()
{
    if (calibrateOffset_ON_OFF) {
        calibrateOffset_ON_OFF = false;
        this->ui->pushButtonCalibrateOffset->setText("Start Robot Offset Calibration");
    } else {
        calibrateOffset_ON_OFF = true;
        this->ui->pushButtonCalibrateOffset->setText("Stop Robot Offset Calibration");
    }
}

/*
 * Helper Functions Section
 */

//Point Section Start
double RobotDetectionMainWindow::distanceBetweenPoints(cv::Point2f a, cv::Point2f b)
{
    return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

cv::Point2f RobotDetectionMainWindow::scaleToGui(cv::Point2f srcDot)
{
    return cv::Point2f( (srcDot.x / programSettings.getGuiScale()) , (srcDot.y / programSettings.getGuiScale()) );
}

cv::Point3f RobotDetectionMainWindow::scaleToGui(cv::Point3f srcDot)
{
    return cv::Point3f( (srcDot.x / programSettings.getGuiScale()) , (srcDot.y / programSettings.getGuiScale()) , (srcDot.z / programSettings.getGuiScale()));
}

double RobotDetectionMainWindow::scaleToGui(double value)
{
    return (value / programSettings.getGuiScale());
}
//Point Section End
//Aruco Section Start
void RobotDetectionMainWindow::initArucoTab()
{
    int MarkerCount = this->defaultArucoDict.getMarkerCount();
    this->ui->tableWidget_Aruco->setRowCount(0);
    this->ui->tableWidget_Aruco->blockSignals(true);

    for (int row = 0; row < MarkerCount; row++) {

        this->ui->tableWidget_Aruco->insertRow( this->ui->tableWidget_Aruco->rowCount());
        QTableWidgetItem *itemID = new QTableWidgetItem(QString::number(row));

        this->ui->tableWidget_Aruco->setItem   ( this->ui->tableWidget_Aruco->rowCount()-1,
                                                 0,
                                                 itemID);

        itemID->setFlags(itemID->flags() ^ Qt::ItemIsEditable);

        QTableWidgetItem *itemName;
        itemName = new QTableWidgetItem(defaultArucoDict.getNameById(row));
        this->ui->tableWidget_Aruco->setItem   ( this->ui->tableWidget_Aruco->rowCount()-1,
                                                 2,
                                                 itemName);

        QTableWidgetItem *itemHeight;
        itemHeight = new QTableWidgetItem(QString::number(defaultArucoDict.getHeightById(row)));
        this->ui->tableWidget_Aruco->setItem   ( this->ui->tableWidget_Aruco->rowCount()-1,
                                                 1,
                                                 itemHeight);
    }

    updateArucoTab(0);

    this->ui->tableWidget_Aruco->blockSignals(false);
}

cv::Ptr<cv::aruco::DetectorParameters> RobotDetectionMainWindow::readArucoParameters(){
    //Read Settings
    cv::Ptr<cv::aruco::DetectorParameters> arucoParameters = cv::aruco::DetectorParameters::create();

    QList<double> temp;

    arucoParameters->perspectiveRemovePixelPerCell = ui->slider_perspectiveRemovePixelPerCell->value();
    arucoParameters->cornerRefinementMaxIterations = ui->slider_cornerRefinementMaxIterations->value();
    arucoParameters->adaptiveThreshWinSizeMin = ui->slider_adaptiveThreshWinSizeMin->value();
    arucoParameters->adaptiveThreshWinSizeStep = ui->slider_adaptiveThreshWinSizeStep->value();
    arucoParameters->adaptiveThreshConstant = ui->slider_adaptiveThreshConstant->value();

    temp.append(ui->slider_minMarkerPerimeterRate->value());
    temp.append(ui->slider_maxMarkerPerimeterRate->value());
    temp.append(ui->slider_polygonalApproxAccuracyRate->value());
    temp.append(ui->slider_errorCorrectionRate->value());
    temp.append(ui->slider_cornerRefinementMinAccuracy->value());

    arucoParameters->minMarkerPerimeterRate = temp[0]/100;
    arucoParameters->maxMarkerPerimeterRate = temp[1]/100;
    arucoParameters->polygonalApproxAccuracyRate = temp[2]/100;
    arucoParameters->errorCorrectionRate = temp[3]/100;
    arucoParameters->cornerRefinementMinAccuracy = temp[4]/100;

    return arucoParameters;
}

void RobotDetectionMainWindow::updateArucoTab(int SelectedRow)
{
    int MarkerCount = this->defaultArucoDict.getMarkerCount();
    if (SelectedRow < MarkerCount) {
        cv::Mat Marker;
        cv::aruco::drawMarker(this->defaultArucoDict.get(), SelectedRow, this->ui->label_arucomarker->height(), Marker);
        cv::cvtColor(Marker, Marker, cv::COLOR_GRAY2RGB);
        QPixmap pixmap;
        pixmap = QPixmap::fromImage(QImage((unsigned char*) Marker.data, Marker.cols, Marker.rows, Marker.step, QImage::Format_RGB888));
        this->ui->label_arucomarker->setPixmap(pixmap);
    }
}

void RobotDetectionMainWindow::updateIDNameHeightMap() {
    int tableRows = this->ui->tableWidget_Aruco->rowCount();
    for (int i = 0; i < tableRows; i++) {
        defaultArucoDict.setNameById(this->ui->tableWidget_Aruco->item(i, 0)->text().toInt(), this->ui->tableWidget_Aruco->item(i, 2)->text());
        defaultArucoDict.setHeightById(this->ui->tableWidget_Aruco->item(i, 0)->text().toInt(), this->ui->tableWidget_Aruco->item(i, 1)->text().toFloat());
    }
}
// Aruco Section End
// Settings Section Start
QMap<QString, QXmlStreamAttributes> RobotDetectionMainWindow::parseCamera(QXmlStreamReader& xmlReader)
{
    QMap<QString, QXmlStreamAttributes> camera;
    if(xmlReader.tokenType() != QXmlStreamReader::StartElement && xmlReader.name() == "Camera")
    {
        return camera;
    }
    // read the attributes for Camera
    QXmlStreamAttributes attributes = xmlReader.attributes();
    // check if Camera has id attribute and add attributes to the map
    if(attributes.hasAttribute("id"))
    {
        camera.insert("Camera", xmlReader.attributes());
    }
    // Next element...
    xmlReader.readNext();

    // read until endElement by the name "Camera" occurs
    while(!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name() == "Camera"))
    {
        if(xmlReader.tokenType() == QXmlStreamReader::StartElement)
        {
            // elements by the name "Matrix", "LensDistortion" or "Settings" are added
            camera.insert(xmlReader.name().toString(), xmlReader.attributes());
        }
        xmlReader.readNext();
    }
    return camera;
}

void RobotDetectionMainWindow::readXmlCalibrationFile()
{
    QString fileName = "CalibrationData.xml";
    QFile* file = new QFile(fileName);

    // If file can't be found, choose other file.
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,
                             "File Error",
                             "Couldn't find CalibrationData.xml. Please choose calibration file.",
                             QMessageBox::Ok);
        fileName = QFileDialog::getOpenFileName(this, "Load Calibration File", "", "Calibration Files (*.xml)");
        file = new QFile(fileName);

        // If file still can't be opened, show an error message.
        if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::critical(this,
                                  "File Error",
                                  "Couldn't open XML File",
                                  QMessageBox::Ok);
            return;
        }
    }

    QXmlStreamReader xmlReader(file);
    QList< QMap<QString, QXmlStreamAttributes> > cameraList;

    // parse until end of file or until error.
    while(!xmlReader.atEnd() && !xmlReader.hasError())
    {
        /* Read next element.*/
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        /* If token is just StartDocument, we'll go to next.*/
        if(token == QXmlStreamReader::StartDocument)
        {
            continue;
        }
        if(token == QXmlStreamReader::StartElement)
        {
            // CameraCalibrationData has no data for itself
            if(xmlReader.name() == "CameraCalibrationData")
            {
                continue;
            }
            // Camera does have the data, so it is parsed
            if(xmlReader.name() == "Camera")
            {
                cameraList.append(this->parseCamera(xmlReader));
            }
        }
    }
    // Error handling
    if(xmlReader.hasError())
    {
        QMessageBox::critical(this, "Parse Error", xmlReader.errorString(), QMessageBox::Ok);
    }
    xmlReader.clear();

    for(int i = 0; i < cameraList.size(); i++)
    {
        QXmlStreamAttributes attribCamera, attribMatrix, attribLensDist, attribTrafoMatrix, attribSettings;
        attribCamera = cameraList.at(i)["Camera"];
        attribMatrix = cameraList.at(i)["Matrix"];
        attribLensDist = cameraList.at(i)["LensDistortion"];
        attribTrafoMatrix = cameraList.at(i)["TransformationMatrix"];
        attribSettings = cameraList.at(i)["Settings"];

        // build cameraMatrix
        cameraMatrix.insert(i, cv::Mat::eye(3, 3, CV_64F));
        cameraMatrix[i].at<double>(0, 0) = attribMatrix.value("fx").toDouble();
        cameraMatrix[i].at<double>(0, 2) = attribMatrix.value("cx").toDouble();
        cameraMatrix[i].at<double>(1, 1) = attribMatrix.value("fy").toDouble();
        cameraMatrix[i].at<double>(1, 2) = attribMatrix.value("cy").toDouble();

        // build distCoeffs
        distCoeffs.insert(i, cv::Mat::zeros(8, 1, CV_64F));
        distCoeffs[i].at<double>(0) = attribLensDist.value("k1").toDouble();
        distCoeffs[i].at<double>(1) = attribLensDist.value("k2").toDouble();
        distCoeffs[i].at<double>(2) = attribLensDist.value("p1").toDouble();
        distCoeffs[i].at<double>(3) = attribLensDist.value("p2").toDouble();
        distCoeffs[i].at<double>(4) = attribLensDist.value("k3").toDouble();

        // build perspective transformation matrix
        perspTransfMatrix.insert(i, cv::Mat::eye(3, 3, CV_64F));
        perspTransfMatrix[i].at<double>(0, 0) = attribTrafoMatrix.value("t1").toDouble();
        perspTransfMatrix[i].at<double>(0, 1) = attribTrafoMatrix.value("t2").toDouble();
        perspTransfMatrix[i].at<double>(0, 2) = attribTrafoMatrix.value("t3").toDouble();
        perspTransfMatrix[i].at<double>(1, 0) = attribTrafoMatrix.value("t4").toDouble();
        perspTransfMatrix[i].at<double>(1, 1) = attribTrafoMatrix.value("t5").toDouble();
        perspTransfMatrix[i].at<double>(1, 2) = attribTrafoMatrix.value("t6").toDouble();
        perspTransfMatrix[i].at<double>(2, 0) = attribTrafoMatrix.value("t7").toDouble();
        perspTransfMatrix[i].at<double>(2, 1) = attribTrafoMatrix.value("t8").toDouble();
        perspTransfMatrix[i].at<double>(2, 2) = attribTrafoMatrix.value("t9").toDouble();


        // calculate GUI Transformation Matrix by scaling down perspTransfMatrix
        cv:: Mat scaleMatrix = cv::Mat::zeros(3, 3, CV_64F);
        scaleMatrix.at<double>(0, 0) = 1.0 / programSettings.getGuiScale();
        scaleMatrix.at<double>(1, 1) = 1.0 / programSettings.getGuiScale();
        scaleMatrix.at<double>(2, 2) = 1.0;
        guiTransfMatrix.append(scaleMatrix * perspTransfMatrix.at(i));

        // build settings
        exposureValue.insert(i, attribSettings.value("exp").toInt());
        contrastValue.insert(i, attribSettings.value("cnt").toInt());
        brightnessValue.insert(i, attribSettings.value("brg").toInt());
    }

    file->close();
    ui->statusBar->showMessage("XML-File was read successfully...", 2000);
}

void RobotDetectionMainWindow::sendSettingsUpdate(){

    emit workerUpdateSettings(ui->slider_threshold->value(),
                              ui->slider_MinSizeofRects->value(),
                              defaultArucoDict.getMarkerCount()/2,
                              this->ui->checkBoxLiveView->isChecked(),
                              this->ui->checkBox_Measurement->isChecked(),
                              readArucoParameters(),
                              defaultArucoDict.get(),
                              robotOffsets,
                              calibrateOffset_ON_OFF);
}
// Section Settings End
// Section Gui Start
void RobotDetectionMainWindow::writeRobotLocationsToTable(QList<cv::Point3f> robotLocations)
{
    int robotCount = robotLocations.size();
    this->ui->tableWidget->setRowCount(0);

    // init tableWidget during first run

    for(int row = 0; row < robotCount; row++){

        this->ui->tableWidget->insertRow(row);

        for(int col = 0; col < 3; col++)
        {
            if (ui->tableWidget->item(row, col) == 0)
            {
                QTableWidgetItem *itab = new QTableWidgetItem;
                itab->setText("init");
                ui->tableWidget->setItem(row, col, itab);
            }

        }

    }
    // write RobotLocations to tableWidget
    for(int row = 0; row < robotCount; row++)
    {
        ui->tableWidget->item(row, 0)->setText(QString::number(robotLocations.at(row).x, 'f', 1));
        ui->tableWidget->item(row, 1)->setText(QString::number(robotLocations.at(row).y, 'f', 1));
        ui->tableWidget->item(row, 2)->setText(QString::number(robotLocations.at(row).z, 'f', 1));
    }
}

void RobotDetectionMainWindow::writeRobotIDsToGui(cv::Mat guiImage, QList<cv::Point3f> robotLocations)
{

    cv::Point2f offsetId = cv::Point2f(programSettings.robotRadius, -programSettings.robotRadius);
    cv::Point2f offsetName = cv::Point2f(programSettings.robotRadius, + programSettings.robotRadius);

    for (int i = 0; i < robotLocations.size(); i++)
    {
        cv::Point2f center = cv::Point2f(robotLocations.at(i).x, programSettings.cameraFieldSizeMilimeter.height - robotLocations.at(i).y);
        if (center.y != programSettings.cameraFieldSizeMilimeter.height)
        {
            cv::putText( guiImage, QString::number(i + 1).toStdString(), scaleToGui(center) + scaleToGui(offsetId),
                         CV_FONT_HERSHEY_PLAIN, 2, COLOR_RED, 2, CV_AA, false);
            cv::putText(guiImage, defaultArucoDict.getNameById(i*2).toUtf8().constData(),scaleToGui(center) + scaleToGui(offsetName),
                        CV_FONT_HERSHEY_PLAIN, 1, COLOR_RED, 2, CV_AA, false);
        }
    }
}
// Section Gui End

void RobotDetectionMainWindow::on_pushButtonResizeCamField_clicked()
{
    ui->tabMain_Navigation->setEnabled(false);
    ui->tabMain_Aruco->setEnabled(false);
    ui->tabMain_Calibration->setEnabled(false);
    ui->tabMain_Settings->setEnabled(true);
    ui->pushButtonSaveSettings->setEnabled(true);
    ui->pushButtonSettingsCancel->setEnabled(true);

    programSettings.setCamFieldSize(Size(ui->spinBoxFieldWidth->text().toInt(), ui->spinBoxFieldHeight->text().toInt()));

    ui->spinBoxFieldHeight->setEnabled(false);
    ui->spinBoxFieldWidth->setEnabled(false);
    ui->pushButtonResizeCamField->setEnabled(false);
    ui->spinBoxSwap1->setEnabled(true);
    ui->spinBoxSwap1->setMinimum(0);
    ui->spinBoxSwap1->setMaximum(programSettings.camFieldSize.area()-1);
    ui->spinBoxSwap2->setEnabled(true);
    ui->spinBoxSwap2->setMinimum(0);
    ui->spinBoxSwap2->setMaximum(programSettings.camFieldSize.area()-1);
    ui->pushButtonSwap->setEnabled(true);
    ui->pushButtonSaveSettings->setEnabled(true);
    ui->spinBoxCameraNr->setMaximum(programSettings.camFieldSize.area()-1);

    this->initializeCams();
}


void RobotDetectionMainWindow::on_pushButtonSettingsCancel_clicked()
{
    this->ui->tabMain_Navigation->setEnabled(true);
    this->ui->tabMain_Aruco->setEnabled(true);
    this->ui->tabMain_Calibration->setEnabled(true);
    this->ui->tabMain_Settings->setEnabled(true);
    ui->pushButtonSettingsCancel->setEnabled(false);

    frames.stop();

    for(int i=0; i<programSettings.cams.size(); i++)
    {
        if (captures.at(i)->isOpened())
        {
            captures.at(i)->release();
        }
    }


    ui->spinBoxFieldHeight->setEnabled(true);
    ui->spinBoxFieldWidth->setEnabled(true);
    ui->pushButtonResizeCamField->setEnabled(true);
    ui->spinBoxSwap1->setEnabled(false);
    ui->spinBoxSwap2->setEnabled(false);
    ui->pushButtonSwap->setEnabled(false);
    ui->pushButtonSaveSettings->setEnabled(false);
}


void RobotDetectionMainWindow::initializeCams()
{
    for(int i=0; i<programSettings.cams.size(); i++)
    {
        captures.push_back(new VideoCapture);
        captures.at(i)->open(programSettings.cams.at(i)->cameraID);
    }

    guiImage = Mat(programSettings.cameraImageSize.width*programSettings.camFieldSize.width,programSettings.cameraImageSize.height*programSettings.camFieldSize.height, CV_8UC3);
    guiImage.setTo(Scalar(0,0,0));

    for(int i=0; i<programSettings.cams.size(); i++)
    {
        if(captures.at(i)->isOpened())
        {
            captures.at(i)->read(camImage);
            cv::resize(guiImage,guiImage,cvSize(camImage.cols*programSettings.camFieldSize.width,camImage.rows*programSettings.camFieldSize.height));
            break;
        }
    }

    frames.start(33);
    connect(&frames, &QTimer::timeout, this, &RobotDetectionMainWindow::updateFrame);
}

void RobotDetectionMainWindow::updateFrame() {
    for(int i=0; i<programSettings.cams.size(); i++)
    {
        if (captures.at(i)->isOpened())
        {
            captures.at(i)->read(camImage);
            cvtColor(camImage,camImage,COLOR_RGB2BGR);
        }
        else
        {
            cv::resize(camImage,camImage,cvSize(guiImage.cols/programSettings.camFieldSize.width,guiImage.rows/programSettings.camFieldSize.height));
            camImage.setTo(Scalar(0,0,0));
            string str = "Camera not connected. ID: " + to_string(programSettings.cams.at(i)->cameraID);
            putText(camImage, str, cvPoint(60,60), FONT_HERSHEY_PLAIN, 1.5, Scalar(255,255,255), 1, CV_AA, 0);
        }

        putText(camImage, to_string(i), cvPoint(camImage.cols/2,camImage.rows/2), FONT_HERSHEY_PLAIN, 3, Scalar(255,0,0), 1, CV_AA, 0);
        int mulRows = i/programSettings.camFieldSize.width;
        int mulCols= i%programSettings.camFieldSize.width;
        camImage.copyTo(guiImage(Rect(mulCols * camImage.cols,mulRows * camImage.rows,camImage.cols, camImage.rows)));
    }

    QPixmap pixmap;
    pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, QImage::Format_RGB888));
    ui->labelCamFieldSettings->setPixmap(pixmap);
}

void RobotDetectionMainWindow::on_pushButtonSwap_clicked() {
    VideoCapture* temp = captures.at(ui->spinBoxSwap1->text().toInt());
    captures.at(ui->spinBoxSwap1->text().toInt()) = captures.at(ui->spinBoxSwap2->text().toInt());
    captures.at(ui->spinBoxSwap2->text().toInt()) = temp;

    Settings::cam* temp2 = programSettings.cams.at(ui->spinBoxSwap1->text().toInt());
    programSettings.cams.at(ui->spinBoxSwap1->text().toInt()) = programSettings.cams.at(ui->spinBoxSwap2->text().toInt());
    programSettings.cams.at(ui->spinBoxSwap2->text().toInt()) = temp2;
}


void RobotDetectionMainWindow::on_pushButtonSaveSettings_clicked() {
    ui->spinBoxFieldHeight->setEnabled(true);
    ui->spinBoxFieldWidth->setEnabled(true);
    ui->pushButtonResizeCamField->setEnabled(true);
    ui->spinBoxSwap1->setEnabled(false);
    ui->spinBoxSwap2->setEnabled(false);
    ui->pushButtonSwap->setEnabled(false);
    ui->pushButtonSettingsCancel->setEnabled(false);

    programSettings.arucoDictFileName = ui->lineEditArucoDictionaryFileName->text().toStdString();
    programSettings.arucoMarkerSizePixel = ui->lineEditArucoMakerSizeInPixel->text().toInt();
    programSettings.cameraFieldSizeMilimeter.height = ui->lineEditCameraFieldHeight->text().toInt();
    programSettings.cameraFieldSizeMilimeter.width = ui->lineEditCameraFieldWidth->text().toInt();
    programSettings.cameraImageSize.height = ui->lineEditCameraImageHeight->text().toInt();
    programSettings.cameraImageSize.width = ui->lineEditCameraImageWidth->text().toInt();
    programSettings.udpStruct.reciveIp_SyncService = ui->lineEditReceiveIpSyncService->text().toStdString();
    programSettings.udpStruct.recivePort_SyncService = ui->lineEditReceivePortSyncService->text().toInt();
    programSettings.udpStruct.sendToIp = ui->lineEditSendToIp->text().toStdString();
    programSettings.udpStruct.sendToIp_SyncService = ui->lineEditSendToIpSyncService->text().toStdString();
    programSettings.udpStruct.sendToPort = ui->lineEditSendToPort->text().toInt();
    programSettings.udpStruct.sendToPort_SyncService = ui->lineEditSendToPortSyncService->text().toInt();

    programSettings.robotRadius = ui->lineEditRobotRadius->text().toFloat();
    programSettings.robotMaxNumber = ui->lineEditMaxNumberOfRobots->text().toInt();
    programSettings.robotStdThresh = ui->lineEditRobotStdThresh->text().toFloat();
    programSettings.robotStdThreshMax = ui->lineEditRobotStdThreshMax->text().toFloat();

    programSettings.boardSize.width = ui->lineEditCalibrationBoardWidth->text().toInt();
    programSettings.boardSize.height = ui->lineEditCalibrationBoardHeight->text().toInt();
    programSettings.squareSize = ui->lineEditCalibrationSquareSize->text().toInt();
    programSettings.calibrationPattern = Settings::Pattern(ui->comboBoxCalibrationPattern->currentIndex()+1);
    programSettings.calibPatternWhiteOnBlack = ui->checkBoxCalibrationPatternWhiteOnBlack->isChecked();

    programSettings.save();
    frames.stop();


    for(int i=0; i<captures.size(); i++)
    {
        if (captures.at(i)->isOpened())
        {
            captures.at(i)->release();
        }
    }

    this->ui->tabMain_Navigation->setEnabled(true);
    this->ui->tabMain_Aruco->setEnabled(true);
    this->ui->tabMain_Calibration->setEnabled(true);

}


/** Starts timer and connects "frameReady()"-Method as TOV-ISR.
 *  Starts camera capture and enables/disables corresponding pushbuttons
 * @brief RobotDetectionMainWindow::on_pushButtonStartCam_clicked
 */
void RobotDetectionMainWindow::on_pushButtonStartCam_clicked()
{

    ui->tabMain_Navigation->setEnabled(false);
    ui->tabMain_Aruco->setEnabled(false);
    ui->tabMain_Settings->setEnabled(false);

    cameraTimer.start(33); // 33 ms = 30 fps

    //SIGNAL AND SLOT CONNECTION
    //at the timeout() event, execute the cameraTimerTimeout() method
    //sender (source of signal): of type QTimer; signal (value of signal): timeout()
    //receiver: this Window - slot:a function of the receiver that processes the incoming signal

    cams.clear();
    // Create camera objects for calibration purpose
    for(int nr=0; nr < programSettings.camFieldSize.area(); nr++)
    {
        cams.push_back(new Camera(nr, programSettings.cams.at(nr)->cameraID, &programSettings));
    }

    nr = ui->spinBoxCameraNr->value();
    id = programSettings.cams.at(nr)->cameraID;  // s->cams.at(nr)->cameraID
    qInfo() << "Opening Cam Nr <" << nr << "> with id <" << id << ">";

    capture.open(id);

    if (capture.isOpened())
    {
        connect(&cameraTimer, SIGNAL(timeout()), this, SLOT(frameReady()));
        ui->pushButtonStartCam->setEnabled(false);
        ui->spinBoxCameraNr->setEnabled(false);
        ui->pushButtonStopCam->setEnabled(true);
        ui->pushButtonGetExtrinsics->setEnabled(true);
        ui->pushButtonTakeSnapshot->setEnabled(true);
        ui->pushButtonSaveContrast->setEnabled(true);
        ui->pushButtonResetThr->setEnabled(true);
        ui->horizontalSliderMaxValue->setEnabled(true);
        ui->horizontalSliderThreshold->setEnabled(true);
        isCameraRunning = true;
    }
    else
    {
        ui->statusBar->showMessage("Not found!", 3000);
        isCameraRunning = false;
    }
}

/** Stops camera capture and enables/disables corresponding pushbuttons
 * @brief RobotDetectionMainWindow::on_pushButtonStopCam_clicked
 */
void RobotDetectionMainWindow::on_pushButtonStopCam_clicked()
{
    if(capture.isOpened())
    {
        // release camera stream - Closes video file or capturing device.
        capture.release();
        ui->labelImageBefore->clear();
        ui->labelImageAfter->clear();
    }

    // stop timer
    cameraTimer.stop();

    ui->pushButtonStopCam->setEnabled(false);
    ui->pushButtonGetExtrinsics->setEnabled(false);
    ui->pushButtonTakeSnapshot->setEnabled(false);
    ui->pushButtonSaveContrast->setEnabled(false);
    ui->pushButtonResetThr->setEnabled(false);
    ui->horizontalSliderMaxValue->setEnabled(false);
    ui->horizontalSliderThreshold->setEnabled(false);
    ui->pushButtonStartCam->setEnabled(true);
    ui->spinBoxCameraNr->setEnabled(true);

    ui->tabMain_Navigation->setEnabled(true);
    ui->tabMain_Aruco->setEnabled(true);
    ui->tabMain_Settings->setEnabled(true);

    if(numSeq > 0){
        ui->pushButtonSaveToXML->setEnabled(true);
    }
    on_pushButtonResetThr_clicked();
}

/** Writes sample image to calibration window GUI after timeout (30fps),
 *  convert image according to horizontal sliders values for black/white threshold
 *  and max value respectively.
 * @brief RobotDetectionMainWindow::frameReady
 */
void RobotDetectionMainWindow::frameReady()
{
    //    // Old version: config camera threshold operation
    //    if(capture.isOpened())
    //    {
    //        // store the frame to show in a Qt window
    //        QImage originalFrame, thresholdFrame;

    //        // get the current frame from the video stream
    //        // Mat image wird beschrieben mit Hilfe des überladenen Operators >>
    //        // Aus VideoCapture wird hier also ein 2D Mat
    //        capture.read(image);
    //        image.copyTo(imageOrig);

    //        // prepare the image for the Qt format...
    //        // ... change color channel ordering (from BGR in our Mat to RGB in QImage)
    //        cvtColor(imageOrig, imageOrig, CV_BGR2RGB);

    //        Mat threshold;
    //        cv::threshold(imageOrig, threshold, ui->horizontalSliderThreshold->value(), ui->horizontalSliderMaxValue->value(), THRESH_BINARY);


    //        // 3. Bild resizen und altes imageForGui mit neuem ersetzen
    //        // Resizes an image in order to adapt to the GUI size

    //        cv::resize(imageOrig, imageOrig, Size(ui->labelImageOrig->width(), ui->labelImageOrig->height()));
    //        cv::resize(threshold, threshold, Size(ui->labelImageContrast->width(), ui->labelImageContrast->height()));

    //        // QImage
    //        originalFrame  = QImage((const unsigned char*)(imageOrig.data), imageOrig.cols, imageOrig.rows, imageOrig.step, QImage::Format_RGB888);
    //        thresholdFrame = QImage((const unsigned char*)(threshold.data), threshold.cols, threshold.rows, threshold.step, QImage::Format_RGB888);

    //        ui->labelImageOrig->setScaledContents(true);
    //        ui->labelImageContrast->setScaledContents(true);
    //        // display on labels
    //        ui->labelImageOrig->setPixmap(QPixmap::fromImage(originalFrame));
    //        ui->labelImageContrast->setPixmap(QPixmap::fromImage(thresholdFrame));

    //    }

    if(isCameraRunning && capture.isOpened())
    {
        // store the frame to show in a Qt window
        QImage frameToShow, frameUndistorted;

        // get the current frame from the video stream
        // Mat image wird beschrieben mit Hilfe des überladenen Operators >>
        //Aus VideoCapture wird hier also ein 2D Mat
        capture >> imageC;
        imageC.copyTo(ImageExtr);

        // show the circle_grid_board pattern
        //Man hat jetzt also ein Bild auf dem man versucht ein Circle GRID Muster zu erkennen und hervorzuheben
        //Dieses Bild wird dann in einer anderen Variable gespeichert(imageSaved), wenn ein Kreismuster erkannt wurde.
        //siehe Kommentar an der Funktion
        findAndDrawPoints();

        // prepare the image for the Qt format...
        // ... change color channel ordering (from BGR in our Mat to RGB in QImage)
        cvtColor(imageC, imageC, CV_BGR2RGB);


        //1. Bild für GUI kopieren - image variable muss unangetastet bleiben
        imageC.copyTo(imageForGuiC);


        // NEW////
        //2. Aufs neue Bild Kreise malen, aber nur wenn Grid gefunden wurde
        if(allSnapshotAreas.size() != 0){

            vector<Point2f> currentArea;

            if(allSnapshotAreas.size() != allFounds.size()){
                QMessageBox::information(this, tr("ERROR"), tr("allSnapshotAreas.size() != allFounds.size()"));
                return;
            }

            //Iterate to get each vector
            //Everytime we get all vectors
            for(int i=0; i<allSnapshotAreas.size(); i++){

                //For the current considered snapshot area check again whether a circles grid was really found
                currentArea = allSnapshotAreas[i];
                if(allFounds[i]){

                    //If the grid was foud paint the Points2D to GUI
                    for(int j=0; j<currentArea.size(); j++){
                        circle(imageForGuiC,cvPoint(currentArea[j].x,currentArea[j].y), 5,CV_RGB(255,0,253),3,8,0);
                    }
                }

            }

        }


        //3. Bild resizen und altes imageForGui mit neuem ersetzen
        //Resizes an image in order to adapt to the GUI size
        //cv::resize(imageForGuiC, imageForGuiC, Size(ui->labelImageBefore->width(), ui->labelImageBefore->height()));

        //QImage
        frameToShow = QImage((const unsigned char*)(imageForGuiC.data), imageForGuiC.cols, imageForGuiC.rows, imageForGuiC.step, QImage::Format_RGB888);


        ui->labelImageBefore->setScaledContents(true);
        // display on label (left label)
        ui->labelImageBefore->setPixmap(QPixmap::fromImage(frameToShow));

        // show undistorted (after calibration) frames
        if (isCalibrate) {
            // Wird nur nach der Kalibrierung aufgerufen und schreibt ins rechte Label.
            // remap of undistorted frame and conversion in the Qt format

            //VERSION 2 - NEU
            Mat undistorted = cams.at(nr)->remap(imageC);
            //cv::resize(undistorted, undistortedForGuiC, Size(ui->labelImageAfter->width(), ui->labelImageAfter->height()));
            undistorted.copyTo(undistortedForGuiC);
            frameUndistorted = QImage((uchar*)undistortedForGuiC.data, undistortedForGuiC.cols, undistortedForGuiC.rows, undistortedForGuiC.step, QImage::Format_RGB888);
            ui->labelImageAfter->setScaledContents(true);
            ui->labelImageAfter->setPixmap(QPixmap::fromImage(frameUndistorted));



        }
    }

}

/** Save the horizontal slider values for black/white threshold and max value
 *  to active camera object, in order to use these values while calibration process
 * @brief RobotDetectionMainWindow::on_pushButtonSaveContrast_clicked
 */
void RobotDetectionMainWindow::on_pushButtonSaveContrast_clicked()
{
    qInfo() <<"save id "<< id;
    cams.at(nr)->setContrast(ui->horizontalSliderThreshold->value(), ui->horizontalSliderMaxValue->value());
}

/** Start the calibration process to get intrinsic parameters.
 *  Therefor, the capture from parent window needs to be released, else the "frameReady()" method
 *  will have size-errors and the application will crash.
 * @brief RobotDetectionMainWindow::on_pushButtonGetIntrinsics_clicked
 */
void RobotDetectionMainWindow::on_pushButtonGetIntrinsics_clicked()
{
    //capture.release();
    //int success = cams.at(nr)->doCalibrationIntrinsics();
    //capture.open(id);
    //qInfo() << "intrinsic success: " << success;

    // New Test version 16.04.2018
    vector<vector<Point2f>> imagePoints;
    vector<vector<Point3f>> objectPoints;
}

/** Start the calibration process to get extrinsic parameters.
 *  Therefor, the capture from parent window needs to be released, else the "frameReady()" method
 *  will have size-errors and the application will crash.
 * @brief RobotDetectionMainWindow::on_pushButtonGetExtrinsics_clicked
 */
void RobotDetectionMainWindow::on_pushButtonGetExtrinsics_clicked()
{
    int success = -1;
    if(imageSavedC.data)
        success = cams.at(nr)->doCalibrationExtrinsics(ImageExtr);
    else
        ui->statusBar->showMessage("No Camera Matrix found, do intrinsic calibration first!", 3000);
    qInfo() << "extrinsic success: " << success;
    if(success)
    {
        ui->pushButtonSaveToXML->setEnabled(true);
    }
}

/** Reset the horizontal slider values for black/white threshold and max value
 *  and the corresponding values in active camera object.
 * @brief RobotDetectionMainWindow::on_pushButtonResetThr_clicked
 */
void RobotDetectionMainWindow::on_pushButtonResetThr_clicked()
{
    /*ui->horizontalSliderMaxValue->setValue(255);
    ui->horizontalSliderThreshold->setValue(128);
    programSettings.cams.at(nr)->blackWhiteThreshold = -1;
    programSettings.cams.at(nr)->maxValue = -1;*/
    //MainWindow
    imageC.release();
    imageSavedC.release();
    imageForGuiC.release();
    greyImageC.release();
    isCalibrate = false;
    numSeq = 0;
    successes = 0;
    imageList.clear();
    ui->pushButtonSaveToXML->setEnabled(false);
    allSnapshotAreas.clear();
    allFounds.clear();

    //CameraCalibrator
    //cameraCalib.resetVals();

    //QMessageBox::information(this, tr("Information"), tr("Program has been reset."));
    ui->statusBar->showMessage("Program has been reset.", 3000);
}

void RobotDetectionMainWindow::setCams(vector<Camera*> cams)
{
    this->cams = cams;
}

void RobotDetectionMainWindow::findAndDrawPoints()
{
    //Output Array für erkannte Kreismittelpunkte
    std::vector<Point2f> pointBuf;

    /*
    image & board size sind globale Variablen, die im Header definiert sind
    Finds the positions of internal corners of the chessboard.
    @param image – Source chessboard view. It must be an 8-bit grayscale or color image.
    @param boardSize: patternSize – Number of inner corners per a chessboard row and column
    ( patternSize = cvSize(points_per_row,points_per_colum) = cvSize(columns,rows) ).
    Mehr wurde hier auch garnicht gemacht. boardSize.width = 8; und boardSize.height = 6;
    sind die 8 bzw. 6 inneren Ecken zwischen den schwarz-weissen Feldern
    Variable found hätte besser "patternFound" heißen können
    @param pointBuf – Output array of detected corners
    The function attempts to determine whether the input image is a view of the chessboard pattern
    and locate the internal chessboard corners. The function returns a non-zero value if all of the corners
    are found and they are placed in a certain order (row by row, left to right in every row).
    Otherwise, if the function fails to find all the corners or reorder them, it returns 0. For example,
    a regular chessboard has 8 x 8 squares and 7 x 7 internal corners, that is, points where the black
    squares touch each other. The detected coordinates are approximate, and to determine their positions
    more accurately, the function calls cornerSubPix(). You also may use the function cornerSubPix()
    with different parameters if returned coordinates are not accurate enough.
    */

    //Für besseren Kontrast wird das Bild zunächst in Graustufen umgerechnet und dann beim Funktionsaufruf invertiert
    cvtColor(imageC, greyImageC, cv::COLOR_RGB2GRAY);

    bool found = false;

    if (programSettings.calibPatternWhiteOnBlack) {
          greyImageC = cv::Scalar::all(255) - greyImageC;
    }

    switch (programSettings.calibrationPattern) {
        case Settings::Pattern::CHESSBOARD:
            found = findChessboardCorners(greyImageC, programSettings.boardSize, pointBuf);
            break;
        case Settings::Pattern::CIRCLES_GRID:
            found = findCirclesGrid(greyImageC, programSettings.boardSize, pointBuf, CALIB_CB_SYMMETRIC_GRID);
            break;
        case Settings::Pattern::ASYMMETRIC_CIRCLES_GRID:
            found = findCirclesGrid(greyImageC, programSettings.boardSize, pointBuf, CALIB_CB_ASYMMETRIC_GRID);
            break;
    }
    // store the image to be used for the calibration process
    // imageSaved hält ein Bild für den Kalibrierungsprozess vor
    if(found)
    {
        imageC.copyTo(imageSavedC);
    }

    /*
    show the found corners on screen, if any
    The function draws individual chessboard corners detected either as red circles if the board was not found,
    or as colored corners connected with lines if the board was found.

    PARAMETERS:
    image – Destination image. It must be an 8-bit color image.
    patternSize – Number of inner corners per a chessboard row and column
                (patternSize = cv::Size(points_per_row,points_per_column)).
    corners – Array of detected corners, the output of findChessboardCorners.
    patternWasFound – Parameter indicating whether the complete board was found or not.
                      The return value of findChessboardCorners() should be passed here.
    */
    drawChessboardCorners(imageC, programSettings.boardSize, pointBuf, found);


}


void RobotDetectionMainWindow::on_pushButtonTakeSnapshot_clicked()
{
    // If it is the first snapshot, activate save button up from now
    if(numSeq == 0){
        ui->pushButtonTakeSnapshot->setEnabled(true);
    }

    if(imageSavedC.data){
        bool circlesGridFound;
        vector<Point2f> currentSnapshotArea;


        switch (programSettings.calibrationPattern) {
            case Settings::Pattern::CHESSBOARD:
                circlesGridFound = findChessboardCorners(greyImageC, programSettings.boardSize, currentSnapshotArea);
                break;
            case Settings::Pattern::CIRCLES_GRID:
                circlesGridFound = findCirclesGrid(greyImageC, programSettings.boardSize, currentSnapshotArea, CALIB_CB_SYMMETRIC_GRID);
                break;
            case Settings::Pattern::ASYMMETRIC_CIRCLES_GRID:
                circlesGridFound = findCirclesGrid(greyImageC, programSettings.boardSize, currentSnapshotArea, CALIB_CB_ASYMMETRIC_GRID);
                break;
        }

        if(!circlesGridFound){
            int snapCount = numSeq + 1;
            char snapCountAsChar[32];
            sprintf(snapCountAsChar, "%d", snapCount);
            char message[64] = "Snapshot No. ";

            //QMessageBox::information(this, tr(strcat(message, snapCountAsChar)), tr("Invalid Snapshot.\nLast valid image is used for calibration."));
            ui->statusBar->showMessage("Invalid Snapshot. Last valid image is used for calibration.", 3000);
        }
        std::cout << "Korrespondierender Wert in allFounds: " << circlesGridFound << endl;
        allSnapshotAreas.push_back(currentSnapshotArea);
        allFounds.push_back(circlesGridFound);

    }

    //Aus image wurde ja bereits imageSaved, wenn Kreismuster erkannt wurden
    //bool found = findChessboardCorners(image, boardSize, pointBuf);
    //Wenn der "Take Snapshot" Button geklickt wurde, dann wird das gespeicherte Bild
    //in den Vektor für die Kalibrierung geschrieben.
    //Kalibrierung läuft jetzt NACH JEDEM Klick auf den Button - also beliebig oft
    if (isCameraRunning && imageSavedC.data)
    {
        // store the image, if valid
        imageList.push_back(imageSavedC);
        cout << "In numSeq " << numSeq << " enthaelt imageList " << imageList.size() << " gute Bilder" << endl;
        numSeq++;
        startCalibration();
    }
}

// start the calibration process
void RobotDetectionMainWindow::startCalibration()
//Die macht jetzt jedesmal was, wenn der Take Snapshot Button betätigt wurde
{

    // open circle_grid_board images and extract corner points
    successes = cams.at(nr)->addCirclePoints(imageList);

    cout << "Anzahl der successes: " << successes << endl;

    // calibrate the camera frames
    Size calibSize = Size(ui->labelImageAfter->size().width(), ui->labelImageAfter->size().height());
    //Size calibSize = Size(640, 480);
    cams.at(nr)->cameraCalibration(calibSize);

    isCalibrate = true;
    ui->statusBar->showMessage("Successful images used: " + QString::number(successes), 3000);

}

void RobotDetectionMainWindow::on_pushButtonSaveToXML_clicked()
{
    cams.at(nr)->saveCameraCalibrationParameters();
}
