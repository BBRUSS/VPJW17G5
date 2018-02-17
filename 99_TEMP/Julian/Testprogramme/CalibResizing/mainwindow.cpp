#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //F5 Shortcut for Start/Stop Camera
    QShortcut *shortcutF5 = new QShortcut(QKeySequence(Qt::Key_F5), this);
    connect(shortcutF5, SIGNAL(activated()), ui->startCameraButton, SLOT(click()));

    ui->stopCameraButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startCameraButton_clicked()
{
    cameraTimer.start(33); // 33 ms = 30 fps

    //SIGNAL AND SLOT CONNECTION
    //at the timeout() event, execute the cameraTimerTimeout() method
    //sender (source of signal): of type QTimer; signal (value of signal): timeout()
    //receiver: this Window - slot:a function of the receiver that processes the incoming signal

    capture.open(ui->spinBoxCaptureID->value());

    if (capture.isOpened())
    {
        connect(&cameraTimer, SIGNAL(timeout()), this, SLOT(frameReady()));
        ui->startCameraButton->setEnabled(false);
        ui->stopCameraButton->setEnabled(true);
    }
    else
    {
        ui->statusBar->showMessage("Unable to open capture", 3000);
    }
}

void MainWindow::frameReady()
{
    if(capture.isOpened())
    {
        // store the frame to show in a Qt window
        QImage frameToShow;

        // get the current frame from the video stream
        // Mat image wird beschrieben mit Hilfe des überladenen Operators >>
        // Aus VideoCapture wird hier also ein 2D Mat
        capture.read(image);
        image.copyTo(imageForGui);

        // prepare the image for the Qt format...
        // ... change color channel ordering (from BGR in our Mat to RGB in QImage)
        cvtColor(imageForGui, imageForGui, CV_BGR2RGB);

        Mat threshold;

        cv::threshold(imageForGui, threshold, ui->horizontalSliderThreshold->value(), ui->horizontalSliderMaxvalue->value(), THRESH_BINARY);

        imshow("Test", threshold);

        // 3. Bild resizen und altes imageForGui mit neuem ersetzen
        // Resizes an image in order to adapt to the GUI size

        cv::resize(imageForGui, imageForGui, Size(ui->labelImage->width(), ui->labelImage->height()));

        // QImage
        frameToShow = QImage((const unsigned char*)(imageForGui.data), imageForGui.cols, imageForGui.rows, imageForGui.step, QImage::Format_RGB888);

        ui->labelImage->setScaledContents(true);
        // display on label (left label)
        ui->labelImage->setPixmap(QPixmap::fromImage(frameToShow));

    }
}



void MainWindow::on_stopCameraButton_clicked()
{
    if(capture.isOpened())
    {

        // release camera stream - Closes video file or capturing device.
        capture.release();
        ui->labelImage->clear();
        destroyWindow("Test");
    }

    // stop timer
    cameraTimer.stop();

    ui->stopCameraButton->setEnabled(false);
    ui->startCameraButton->setEnabled(true);
}


//void MainWindow::cameraCalibration(vector<Mat> calibrationImages, Size boardSize, float squareEdgeLength, Mat& cameraMatrix, Mat& distanceCoefficients)
//{
//    vector<vector<Point2f>> checkerboardImageSpacePoints;
//    getChessboardCorners(calibrationImages, checkerboardImageSpacePoints, false);

//    vector<vector<Point3f>> worldSpaceCornerPoints(1);
//    createKnownBoardPosition(boardSize, squareEdgeLength, worldSpaceCornerPoints[0]);
//    worldSpaceCornerPoints.resize(checkerboardImageSpacePoints.size(), worldSpaceCornerPoints[0]);

//    vector<Mat> rVectors, tVectors;
//    distanceCoefficients = Mat::zeros(8, 1, CV_64F);

//    calibrateCamera(worldSpaceCornerPoints, checkerboardImageSpacePoints, boardSize, cameraMatrix, distanceCoefficients, rVectors, tVectors);


//}


//void MainWindow::getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showResult = false)
//{
//    for(vector<Mat>::iterator iter = images.begin(); iter  != images.end(); iter++)
//    {
//        vector<Point2f> pointBuf;
//        bool found = findChessboardCorners(*iter, cv::Size(9,6), pointBuf, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
//        if(found)
//        {
//            allFoundCorners.push_back(pointBuf);
//        }

//        if(showResult)
//        {
//            drawChessboardCorners(*iter, Size(9,6), pointBuf, found);
//            imshow("Looking for Corners", *iter);
//            waitKey(0);
//        }
//    }
//}


//bool MainWindow::saveCameraCalibration(string name, Mat cameraMatrix, Mat distanceCoefficients)
//{
//    ofstream outStream(name);
//    if(outStream)
//    {
//        uint16_t rows = cameraMatrix.rows;
//        uint16_t columns = cameraMatrix.cols;

//        for(int r = 0; r < rows; r++)
//        {
//            for(int c = 0; c < columns; c++)
//            {
//                double value = cameraMatrix.at<double>(r, c);
//                outStream << value << endl;
//            }
//        }

//        rows = distanceCoefficients.rows;
//        columns = distanceCoefficients.cols;

//        for(int r = 0; r < rows; r++)
//        {
//            for(int c = 0; c < columns; c++)
//            {
//                double value = distanceCoefficients.at<double>(r, c);
//                outStream << value << endl;
//            }
//        }
//        outStream.close();
//        return true;
//    }
//    return false;
//}


//void MainWindow::createKnownBoardPosition(cv::Size boardSize, float squareEdgeLength, vector<Point3f>& corners)
//{
//    for(int i = 0; i < boardSize.height; i++)
//    {
//        for(int j = 0; j < boardSize.width; j++)
//        {
//            corners.push_back(Point3f(j*squareEdgeLength, i*squareEdgeLength, 0.0f));
//        }
//    }
//}
