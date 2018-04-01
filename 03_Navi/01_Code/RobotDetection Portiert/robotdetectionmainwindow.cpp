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

/*
 * Constructor & Destructor Section
 */

RobotDetectionMainWindow::RobotDetectionMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RobotDetectionMainWindow)
{

    ui->setupUi(this);
    // read settings from ini file
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.beginGroup("RobotDetectionSettings");

    //programSettings.load();
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

    //load aruco dict
    this->defaultArucoDict = ArucoDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    this->defaultArucoDict.load(ARUCO_DICT_NAME);
    this->initArucoTab();

    //Set Offset for Robots
    robotOffsets.clear();
    for(int i = 0; i < MAX_NR_OF_ROBOTS; i++)
    {
        RobotOffset temp = {i, programSettings.robotOffset[i], -programSettings.robotOffset[i]};
        robotOffsets.append(temp);
    }

    for (int i = 0; i < NR_OF_CAMS; i++)
    {
        cv::VideoCapture capt;
        videoCapture.append(capt);
    }

    mainloopIsActive = false;
    calibrateOffset_ON_OFF = false;

    timerFPS = new QTimer(this);
    connect(timerFPS, &QTimer::timeout, this, &RobotDetectionMainWindow::incrementFPSCounter);
    fpsCount = 0;

    // read camera calibration data and perspective transform matrices from xml
    readXmlCalibrationFile();

    ui->labelVersion->setText("Version: " + QString(__DATE__) + " " + QString(__TIME__));

    setMaximumSize(size());
}

RobotDetectionMainWindow::~RobotDetectionMainWindow()
{
    emit stopWorker();
    workerThread.quit();
    workerThread.wait();

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

    defaultArucoDict.save(ARUCO_DICT_NAME);

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
    cv::Mat guiImage(GUI_HEIGTH, GUI_WIDTH, CV_8UC3);
    if (ui->checkBoxLiveView->isChecked() && !cameraImage.empty())   // show real frames
    {
        guiImage.setTo(COLOR_BLACK);
        for (int i = 0; i < NR_OF_CAMS; i++)
        {
            // Undistort Image
            cv::Mat undistortedImage;
            cv::Mat warpedImage;
            cv::undistort(cameraImage[i], undistortedImage, cameraMatrix.at(i), distCoeffs.at(i));
            //cv::line(undistortedImage,cv::Point(0,0),cv::Point(0, undistortedImage.rows),cv::Scalar(0,0,200,100),10);
            // Apply perspective Transformation
            cv::warpPerspective(undistortedImage, warpedImage, guiTransfMatrix.at(i), cv::Size(GUI_WIDTH, GUI_HEIGTH), cv::INTER_NEAREST, cv::BORDER_CONSTANT, 0);
            cv::addWeighted(guiImage, 1, warpedImage, 1, 0, guiImage, -1);
        }
    }
    else     // show white background with grid
    {
        guiImage.setTo(COLOR_WHITE);
        for (unsigned int i = 0; i < 40; i++)
        {
            if (i % 5 == 0)
            {
                cv::line(guiImage, cv::Point(i * 200 / GUI_SCALING, 0), cv::Point(i * 200 / GUI_SCALING, guiImage.rows), COLOR_DARK_GREY,  1, 8, 0);
            }
            else
            {
                cv::line(guiImage, cv::Point(i * 200 / GUI_SCALING, 0), cv::Point(i * 200 / GUI_SCALING, guiImage.rows), COLOR_LIGHT_GREY, 1, 8, 0);
            }
        }
        for (unsigned int i = 0; i < 20; i++)
        {
            if (i % 5 == 0)
            {
                cv::line(guiImage, cv::Point(0, i * 200 / GUI_SCALING), cv::Point(guiImage.cols, i * 200 / GUI_SCALING), COLOR_DARK_GREY,  1, 8, 0);
            }
            else
            {
                cv::line(guiImage, cv::Point(0, i * 200 / GUI_SCALING), cv::Point(guiImage.cols, i * 200 / GUI_SCALING), COLOR_LIGHT_GREY, 1, 8, 0);
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

            cv::Point2f centerPoint = cv::Point2f(robotLocations[i].x, FIELD_HEIGTH - robotLocations[i].y);
            double centerRadius = ROBOT_RADIUS;
            double angledegree = 2*3.14159265359-(robotLocations[i].z*3.14159265359/180);
            cv::Point2f directionPoint = cv::Point2f(scaleToGui(centerPoint).x + scaleToGui(ROBOT_RADIUS)*cos(angledegree ), scaleToGui(centerPoint).y + scaleToGui(ROBOT_RADIUS)*sin(angledegree));

            //Draw circles and lines for center and orientation circles

            if (robotLocationsStd1d[i] > ROBOT_STD_THRESH) {
                cv::circle(guiImage, scaleToGui(centerPoint), scaleToGui(centerRadius+robotLocationsStd1d[i]), COLOR_RED, 2, CV_AA);
            } else {
                cv::circle(guiImage, scaleToGui(centerPoint), scaleToGui(centerRadius+robotLocationsStd1d[i]), COLOR_YELLOW, 2, CV_AA);
            }

            cv::circle(guiImage, scaleToGui(centerPoint), scaleToGui(centerRadius), COLOR_GREEN, 2, CV_AA);
            cv::line(guiImage, scaleToGui(centerPoint), directionPoint, COLOR_BLUE, 2, CV_AA);

        }
    }

    // show error message in image if camera is missing
    for (int i = 0; i < NR_OF_CAMS; i++ )
    {
        if( ! videoCapture[i].isOpened())
        {
            QString str = "Camera not connected. ID: ";
            str.append(QString::number(i));
            std::string str2 = str.toStdString();
            double x = 0, y = 0;
            if ( i % 2 == 0)
            {
                y = GUI_HEIGTH / 4 - 20;
            }
            else
            {
                y = GUI_HEIGTH * 3 / 4 + 20;
            }
            if ( (i == 0) || (i == 5) )
            {
                x = 60;
            }
            else if ( (i == 1) || (i == 2) )
            {
                x = 60 + GUI_WIDTH / 3;
            }
            else if ( (i == 3) || (i == 4) )
            {
                x = 60 + 2 * GUI_WIDTH / 3;
            }
            cv::putText(guiImage, str2, cv::Point2f(x, y), CV_FONT_HERSHEY_PLAIN, 1, COLOR_DARK_GREY, 1, 8, false);
        }
    }

    // Write robot IDs into guiImage
    writeRobotIDsToGui(guiImage, robotLocations);

    //convert colors and show image in GUI
    cv::cvtColor(guiImage, guiImage, CV_BGR2RGB);
    QPixmap pixmap;
    pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, QImage::Format_RGB888));
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
        for(int i = 0; i < MAX_NR_OF_ROBOTS; i++)
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
    if (defaultArucoDict.getMarkerCount() < MAX_NR_OF_ROBOTS*2)
    {
        defaultArucoDict.add(2);
        initArucoTab();
    } else {
        this->ui->statusBar->showMessage("Maximum number of robots is reached. (" + QString::number(MAX_NR_OF_ROBOTS) + ")");
    }
    //sendSettingsUpdate();
}

void RobotDetectionMainWindow::on_pushButton_deleteAruco_clicked()
{
    defaultArucoDict.remove(2);
    initArucoTab();
}

void RobotDetectionMainWindow::on_tableWidget_Aruco_cellChanged(int row, int column)
{
    if (row%2) { // odd number
        this->ui->tableWidget_Aruco->item(row-1, column)->setText(this->ui->tableWidget_Aruco->item(row, column)->text());
    } else {
        this->ui->tableWidget_Aruco->item(row+1, column)->setText(this->ui->tableWidget_Aruco->item(row, column)->text());
    }
    updateIDNameMap();
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
        //timer->stop();
        emit stopWorker();
        timerFPS->stop();
        for (int i = 0; i < NR_OF_CAMS; i++)
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
        for (int i = 0; i < NR_OF_CAMS; i++)
        {
            videoCapture[i].open(i); //TÓDO: 0 -> i
            videoCapture[i].set(CV_CAP_PROP_FRAME_WIDTH, CAMERA_IMG_WIDTH);
            videoCapture[i].set(CV_CAP_PROP_FRAME_HEIGHT, CAMERA_IMG_HEIGTH);
            videoCapture[i].set(CV_CAP_PROP_BRIGHTNESS, brightnessValue[i]);
            videoCapture[i].set(CV_CAP_PROP_CONTRAST, contrastValue[i]);
            videoCapture[i].set(CV_CAP_PROP_EXPOSURE, exposureValue[i]);
        }
        ui->statusBar->showMessage("Connecting to cameras...", 3000);
        // give cameras some time to get connected,
        // otherwise program might crash (depends on camera driver)
        Sleep(3000);
        //timer.start(timerMilSecs);#

        imgWorker = new ImageProcessingWorker(udpStruct, videoCapture, cameraMatrix, distCoeffs, perspTransfMatrix);
        imgWorker->setTaskThreshold(ui->slider_threshold->value());
        imgWorker->setTaskRectMinSize(ui->slider_MinSizeofRects->value());
        imgWorker->setRobotCount(defaultArucoDict.getMarkerCount()/2);
        imgWorker->setDebugMode(this->ui->checkBoxLiveView->isChecked());
        imgWorker->setMeasureData(this->ui->checkBox_Measurement->isChecked());
        imgWorker->setArucoParameters(readArucoParameters());
        imgWorker->setArucoDict(defaultArucoDict.get());
        imgWorker->setRobotOffsets(robotOffsets);
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
    return cv::Point2f( (srcDot.x / GUI_SCALING) , (srcDot.y / GUI_SCALING) );
}

cv::Point3f RobotDetectionMainWindow::scaleToGui(cv::Point3f srcDot)
{
    return cv::Point3f( (srcDot.x / GUI_SCALING) , (srcDot.y / GUI_SCALING) , (srcDot.z / GUI_SCALING));
}

double RobotDetectionMainWindow::scaleToGui(double value)
{
    return (value / GUI_SCALING);
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
                                                 1,
                                                 itemName);
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

void RobotDetectionMainWindow::updateIDNameMap() {
    int tableRows = this->ui->tableWidget_Aruco->rowCount();
    for (int i = 0; i < tableRows; i++) {
        defaultArucoDict.setNameById(this->ui->tableWidget_Aruco->item(i, 0)->text().toInt(), this->ui->tableWidget_Aruco->item(i, 1)->text());
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
        scaleMatrix.at<double>(0, 0) = 1.0 / GUI_SCALING;
        scaleMatrix.at<double>(1, 1) = 1.0 / GUI_SCALING;
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

    cv::Point2f offsetId = cv::Point2f(ROBOT_RADIUS, - ROBOT_RADIUS);
    cv::Point2f offsetName = cv::Point2f(ROBOT_RADIUS, + ROBOT_RADIUS);

    for (int i = 0; i < robotLocations.size(); i++)
    {
        cv::Point2f center = cv::Point2f(robotLocations.at(i).x, FIELD_HEIGTH - robotLocations.at(i).y);
        if (center.y != FIELD_HEIGTH)
        {
            cv::putText( guiImage, QString::number(i + 1).toStdString(), scaleToGui(center) + scaleToGui(offsetId),
                         CV_FONT_HERSHEY_PLAIN, 2, COLOR_RED, 2, CV_AA, false);
            cv::putText(guiImage, defaultArucoDict.getNameById(i).toUtf8().constData(),scaleToGui(center) + scaleToGui(offsetName),
                        CV_FONT_HERSHEY_PLAIN, 1, COLOR_RED, 2, CV_AA, false);
        }
    }
}
// Section Gui End
