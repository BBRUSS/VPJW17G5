#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //F5 Shortcut for Start/Stop Camera
    QShortcut *shortcutF5 = new QShortcut(QKeySequence(Qt::Key_F5), this);
    connect(shortcutF5, SIGNAL(activated()), ui->startCameraButton, SLOT(click()));

    //F9 Shortcut for Take Snapshot Button
    QShortcut *shortcutF9 = new QShortcut(QKeySequence(Qt::Key_F9), this);
    connect(shortcutF9, SIGNAL(activated()), ui->takeSnapshotButton, SLOT(click()));

    ui->cameraSlider->setRange(1,6);
    ui->cameraSlider->setSingleStep(1);

    ui->contrastSlider->setRange(0,100);
    ui->contrastSlider->setSingleStep(1);

    ui->brightnessSlider->setRange(0,250);
    ui->brightnessSlider->setSingleStep(1);

    ui->exposureSlider->setRange(-10,10);
    ui->exposureSlider->setSingleStep(1);

    ui->brightnessSlider->setEnabled(false);
    ui->brightnessValue_label->setEnabled(false);
    ui->selectBrightness_label->setEnabled(false);
    ui->contrastSlider->setEnabled(false);
    ui->contrastValue_label->setEnabled(false);
    ui->selectContrast_label->setEnabled(false);
    ui->exposureSlider->setEnabled(false);
    ui->exposureValue_label->setEnabled(false);
    ui->selectExposure_label->setEnabled(false);

    isCameraRunning = false;
    isCalibrate = false;
    boardSize.width = 5;
    boardSize.height = 4;
    numSeq = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startCameraButton_clicked()
{
    ui->cameraSlider->setEnabled(false);
    ui->selectCam_label->setEnabled(false);
    ui->camValue_label->setEnabled(false);

    ui->resetButton->setEnabled(false);

    ui->distHeight_spinBox->setEnabled(false);
    ui->height_label->setEnabled(false);
    ui->distWidth_spinBox->setEnabled(false);
    ui->with_label->setEnabled(false);


    if(numSeq > 0){
        ui->saveButton->setEnabled(true);
    }


    if(cameraCalib.getSelectedCamID() < 0 || cameraCalib.getSelectedCamID() > 5){
        QMessageBox::information(this, tr("Information"), tr("No camera selected. Default camera set."));
        cameraCalib.setSelectedCamID(0);
    }

    /*
     * the webcam is not yet started
     * Pfad wird durchlaufen, wenn der "Start Camera" button das erste Mal gedrückt wird.
    */
    if(!isCameraRunning)
    {
        // open camera stream
        capture.open(cameraCalib.getSelectedCamID()); // default: 0 - only one single camera connected

        ui->brightnessSlider->setValue(capture.get(CV_CAP_PROP_BRIGHTNESS));
        ui->contrastSlider->setValue(capture.get(CV_CAP_PROP_CONTRAST));
        ui->exposureSlider->setValue(capture.get(CV_CAP_PROP_EXPOSURE));

        char camIDasChar[32];
        sprintf(camIDasChar, "%d", cameraCalib.getSelectedCamID());
        char message[64] = "Camera with the following ID is not connected: ID ";

        if(!capture.isOpened())
        {
            QMessageBox::information(this, tr("Information"), tr(strcat(message, camIDasChar)));

            ui->cameraSlider->setEnabled(true);
            ui->selectCam_label->setEnabled(true);
            ui->camValue_label->setEnabled(true);

            ui->resetButton->setEnabled(true);

            ui->distHeight_spinBox->setEnabled(true);
            ui->height_label->setEnabled(true);
            ui->distWidth_spinBox->setEnabled(true);
            ui->with_label->setEnabled(true);

            return;
        }


        capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
        capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

        //Jetzt läuft Kamera und Flag wird true
        isCameraRunning = true;

        // start timer for acquiring the video
        cameraTimer.start(33); // 33 ms = 30 fps

        //SIGNAL AND SLOT CONNECTION
        //at the timeout() event, execute the cameraTimerTimeout() method
        //sender (source of signal): of type QTimer; signal (value of signal): timeout()
        //receiver: this Window - slot:a function of the receiver that processes the incoming signal
        connect(&cameraTimer, SIGNAL(timeout()), this, SLOT(cameraTimerTimeout()));

        // update the user interface...
        ui->startCameraButton->setText("Stop Camera (F5)");
        ui->after_img->setText("Take as much images as you need for calibration.\nYou can save the xml configuration in a file for every iteration step.");

        ui->takeSnapshotButton->setEnabled(true);
        ui->brightnessSlider->setEnabled(true);
        ui->brightnessValue_label->setEnabled(true);
        ui->selectBrightness_label->setEnabled(true);
        ui->contrastSlider->setEnabled(true);
        ui->contrastValue_label->setEnabled(true);
        ui->selectContrast_label->setEnabled(true);
        ui->exposureSlider->setEnabled(true);
        ui->exposureValue_label->setEnabled(true);
        ui->selectExposure_label->setEnabled(true);

    }
    /*
     * ELSE Zweig wird durchlaufen, wenn die Kamera grad läuft. Dann nämlich trägt der linke Button die Aufschrift "Stop Camera".
     * Alle Parameter werden auf Stop gesetzt, viedo files geschlossen etc.
    */
    else
    {
        if(!capture.isOpened())
        {
            return;
        }

        // stop timer
        cameraTimer.stop();
        // release camera stream - Closes video file or capturing device.
        capture.release();

        isCameraRunning = false;

        // Ausgangssituiation der GUI wird wiederhergestellt.
        ui->startCameraButton->setText("Start Camera (F5)");
        ui->before_img->clear();
        ui->after_img->clear();
        ui->takeSnapshotButton->setEnabled(false);
        ui->saveButton->setEnabled(false);
        ui->success_label->setText("");

        ui->cameraSlider->setEnabled(true);
        ui->selectCam_label->setEnabled(true);
        ui->camValue_label->setEnabled(true);

        ui->brightnessSlider->setEnabled(false);
        ui->brightnessValue_label->setEnabled(false);
        ui->selectBrightness_label->setEnabled(false);
        ui->contrastSlider->setEnabled(false);
        ui->contrastValue_label->setEnabled(false);
        ui->selectContrast_label->setEnabled(false);
        ui->exposureSlider->setEnabled(false);
        ui->exposureValue_label->setEnabled(false);
        ui->selectExposure_label->setEnabled(false);

        ui->resetButton->setEnabled(true);

        ui->distHeight_spinBox->setEnabled(true);
        ui->height_label->setEnabled(true);
        ui->distWidth_spinBox->setEnabled(true);
        ui->with_label->setEnabled(true);

        cameraCalib.setSelectedCamID(cameraCalib.getSelectedCamID());

    }
}

void MainWindow::cameraTimerTimeout()
{
    if(isCameraRunning && capture.isOpened())
    {
        // store the frame to show in a Qt window
        QImage frameToShow, frameUndistorted;

        // get the current frame from the video stream
        // Mat image wird beschrieben mit Hilfe des überladenen Operators >>
        //Aus VideoCapture wird hier also ein 2D Mat
        capture >> image;

        // show the circle_grid_board pattern
        //Man hat jetzt also ein Bild auf dem man versucht ein Circle GRID Muster zu erkennen und hervorzuheben
        //Dieses Bild wird dann in einer anderen Variable gespeichert(imageSaved), wenn ein Kreismuster erkannt wurde.
        //siehe Kommentar an der Funktion
        findAndDrawPoints();

        // prepare the image for the Qt format...
        // ... change color channel ordering (from BGR in our Mat to RGB in QImage)
        cvtColor(image, image, CV_BGR2RGB);


        //1. Bild für GUI kopieren - image variable muss unangetastet bleiben
        image.copyTo(imageForGui);


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
                        circle(imageForGui,cvPoint(currentArea[j].x,currentArea[j].y), 5,CV_RGB(100,0,0),3,8,0);
                    }
                }

            }

        }


        //3. Bild resizen und altes imageForGui mit neuem ersetzen
        //Resizes an image in order to adapt to the GUI size
        cv::resize(imageForGui, imageForGui, Size(ui->before_img->width(), ui->before_img->height()));

        //QImage
        frameToShow = QImage((const unsigned char*)(imageForGui.data), imageForGui.cols, imageForGui.rows, imageForGui.step, QImage::Format_RGB888);


        ui->before_img->setScaledContents(true);
        // display on label (left label)
        ui->before_img->setPixmap(QPixmap::fromImage(frameToShow));

        // show undistorted (after calibration) frames
        if (isCalibrate) {
            // Wird nur nach der Kalibrierung aufgerufen und schreibt ins rechte Label.
            // remap of undistorted frame and conversion in the Qt format

            //VERSION 2 - NEU
            Mat undistorted = cameraCalib.remap(image);
            cv::resize(undistorted, undistortedForGui, Size(ui->after_img->width(), ui->after_img->height()));
            frameUndistorted = QImage((uchar*)undistortedForGui.data, undistortedForGui.cols, undistortedForGui.rows, undistortedForGui.step, QImage::Format_RGB888);
            ui->after_img->setScaledContents(true);
            ui->after_img->setPixmap(QPixmap::fromImage(frameUndistorted));



        }
    }
}

void MainWindow::findAndDrawPoints()
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
    cvtColor(image, greyImage, cv::COLOR_RGB2GRAY);

    bool found = findCirclesGrid(cv::Scalar::all(255) - greyImage, boardSize, pointBuf);

    // store the image to be used for the calibration process
    // imageSaved hält ein Bild für den Kalibrierungsprozess vor
    if(found)
    {
        image.copyTo(imageSaved);
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
    drawChessboardCorners(image, boardSize, pointBuf, found);

    if (found) {
    Point2f pointFirst = pointBuf[0];

    cv::circle(image, pointFirst, 5, cv::Scalar(255,0,0));
    }

}

void MainWindow::on_takeSnapshotButton_clicked()
{
    // If it is the first snapshot, activate save button up from now
    if(numSeq == 0){
        ui->saveButton->setEnabled(true);
    }


    if(imageSaved.data){

        bool circlesGridFound;
        vector<Point2f> currentSnapshotArea;

        circlesGridFound = findCirclesGrid(cv::Scalar::all(255) - greyImage, boardSize, currentSnapshotArea);

        if(!circlesGridFound){
            int snapCount = numSeq + 1;
            char snapCountAsChar[32];
            sprintf(snapCountAsChar, "%d", snapCount);
            char message[64] = "Snapshot No. ";

            QMessageBox::information(this, tr(strcat(message, snapCountAsChar)), tr("Invalid Snapshot.\nLast valid image is used for calibration."));
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
    if (isCameraRunning && imageSaved.data)
    {
        // store the image, if valid
        imageList.push_back(imageSaved);
        //cout << "In numSeq " << numSeq << " enthaelt imageList " << imageList.size() << " gute Bilder" << endl;
        numSeq++;
        startCalibration();
    }
}

// start the calibration process
void MainWindow::startCalibration()
//Die macht jetzt jedesmal was, wenn der Take Snapshot Button betätigt wurde
{

        // open circle_grid_board images and extract corner points
        successes = cameraCalib.addCirclePoints(imageList,boardSize);

        cout << "Anzahl der successes: " << successes << endl;

        // calibrate the camera frames
        Size calibSize = Size(ui->after_img->size().width(), ui->after_img->size().height());
        cameraCalib.calibrate(calibSize);

        isCalibrate = true;
        ui->success_label->setText("Successful images used: " + QString::number(successes));

}


int MainWindow::getSelectedCamID(){
    return cameraCalib.getSelectedCamID();
}

void MainWindow::on_resetButton_clicked()
{
    //MainWindow
    image.release();
    imageSaved.release();
    imageForGui.release();
    greyImage.release();
    isCalibrate = false;
    numSeq = 0;
    successes = 0;
    imageList.clear();
    ui->cameraSlider->setValue(1);
    ui->brightnessSlider->setValue(capture.get(CV_CAP_PROP_BRIGHTNESS));
    ui->contrastSlider->setValue(capture.get(CV_CAP_PROP_CONTRAST));
    ui->exposureSlider->setValue(capture.get(CV_CAP_PROP_EXPOSURE));
    ui->distHeight_spinBox->setValue(55);
    ui->distWidth_spinBox->setValue(55);
    ui->saveButton->setEnabled(false);
    allSnapshotAreas.clear();
    allFounds.clear();

    //CameraCalibrator
    cameraCalib.resetVals();

    QMessageBox::information(this, tr("Information"), tr("Program has been reset."));
}

void MainWindow::on_cameraSlider_valueChanged(int value)
{
    cameraCalib.setSelectedCamID(value-1);
    ui->camValue_label->setText("Selected cam: " + QString::number(value));

}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    ui->brightnessValue_label->setText("Value: " + QString::number(value));
    capture.set(CV_CAP_PROP_BRIGHTNESS, value);
}

void MainWindow::on_contrastSlider_valueChanged(int value)
{
    ui->contrastValue_label->setText("Value: " + QString::number(value));
    capture.set(CV_CAP_PROP_CONTRAST, value);
}

void MainWindow::on_exposureSlider_valueChanged(int value)
{
    ui->exposureValue_label->setText("Value: " + QString::number(value));
    capture.set(CV_CAP_PROP_EXPOSURE, value);
}

void MainWindow::on_saveButton_clicked()
{
    double contrast = capture.get(CV_CAP_PROP_CONTRAST);
    double exposure = capture.get(CV_CAP_PROP_EXPOSURE);
    double brightness = capture.get(CV_CAP_PROP_BRIGHTNESS);

    if(numSeq != 0){
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                   "..\\config\\output_parameters.xml",
                                   tr("XML-Files (*.xml)"));

        if(fileName != ""){
            cameraCalib.writeXML(fileName, exposure, contrast, brightness);
            QMessageBox::information(this, tr("Information"), tr("XML has been saved to\n") + fileName);
        }else{
            QMessageBox::information(this, tr("Information"), tr("Save operation cancelled."));
        }

    }else{
        QMessageBox::information(this, tr("Information"), tr("Cannot write XML. No valid snapshot was taken."));
    }

}

void MainWindow::on_distWidth_spinBox_valueChanged(int value)
{
    //cout << "Breite gesetzt auf " << value << "mm" << endl;
    //float meters = (float)value/1000;
    //cout << "daraus werden " << meters << "m" << endl;
    cameraCalib.setDistanceWidth(value);
}

void MainWindow::on_distHeight_spinBox_valueChanged(int value)
{
    //cout << "Hoehe gesetzt auf " << value << "mm" << endl;
    //float meters = (float)value/1000;
    //cout << "daraus werden " << meters << "m" << endl;
    cameraCalib.setDistanceHeight(value);
}

void MainWindow::resizeEvent(QResizeEvent* event)
{

    if(event->oldSize().width() != event->size().width()
            && event->oldSize().height() != event->size().height()){


        ui->before_img->setFixedSize(((event->size().width()/2.1)-2), ((event->size().width()/2.7)-2));
        ui->after_img->setFixedSize(((event->size().width()/2.1)-2), ((event->size().width()/2.7)-2));

        ui->before_label->setFixedWidth(((event->size().width()/2.1)-2));
        ui->after_label->setFixedWidth(((event->size().width()/2.1)-2));

        this->layout()->setSizeConstraint(QLayout::SetNoConstraint);

        updateGeometry();
    }

}
