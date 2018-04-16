#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cameraMatrix.create(3,3,cv::DataType<double>::type);
    distCoeff.create(5,1,cv::DataType<double>::type);

    ui->setupUi(this);

    cameraMatrix.at<double>(0,0) = 580.710; // fx
    cameraMatrix.at<double>(0,2) = 364.396; // cx
    cameraMatrix.at<double>(1,1) = 580.381; // fy
    cameraMatrix.at<double>(1,2) = 259.566; // cy
    cameraMatrix.at<double>(2,2) = 1;

    distCoeff.at<double>(0) = -3.1695735505e-1; // k1
    distCoeff.at<double>(1) =  4.2039386737e-2; // k2
    distCoeff.at<double>(2) =  1.6857058959e-3; // p1
    distCoeff.at<double>(3) =  6.7625617939e-3; // p2
    distCoeff.at<double>(4) =  6.6300068419e-2; // k3

    connect(&cameraTimer, SIGNAL(timeout()), this, SLOT(on_cameraTimerEvent()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOpenCamera_clicked()
{
    videoCapture.open(1);
    cameraTimer.start(33);
}

void MainWindow::on_cameraTimerEvent()
{
    if (videoCapture.isOpened())
    {
        processImage();
    }
    else
    {

    }
}

void MainWindow::processImage()
{
    cv::Mat image;
    videoCapture.read(image);

    cv::Size boardSize(5,4);
    std::vector<cv::Point2f> imagePoints;

    cv::Mat undistImage;
    cv::undistort(image, undistImage, cameraMatrix, distCoeff);



    if (!cv::findCirclesGrid(cv::Scalar::all(255) - undistImage, boardSize, imagePoints))
    {
        cv::imshow("Undist", undistImage);
        return;
    }

    cv::drawChessboardCorners(undistImage, boardSize, imagePoints, true);
    cv::Point2f pointFirst = imagePoints[0];
    cv::circle(undistImage, pointFirst, 5, cv::Scalar(255,255,0));

    std::vector<cv::Point3f> objectPoints;

    for (int i=0; i<boardSize.height; i++)
    {
        for (int j=0; j<boardSize.width; j++)
        {
            objectPoints.push_back(cv::Point3f(j * 200.0f, i * 200.0f, 0.0f));
        }
    }

    cv::Mat rvec, tvec;

    bool success = cv::solvePnP (objectPoints, imagePoints, cameraMatrix, distCoeff, rvec, tvec);

    std::vector<cv::Point3d> framePoints;
    framePoints.push_back(cv::Point3d(  0,   0,   0));
    framePoints.push_back(cv::Point3d(400,   0,   0));
    framePoints.push_back(cv::Point3d(  0, 400,   0));
    framePoints.push_back(cv::Point3d(  0,   0, 400));

    std::vector<cv::Point2d> frameDataPoints;

    cv::projectPoints(framePoints, rvec, tvec, cameraMatrix, distCoeff, frameDataPoints);

    cv::line(undistImage, frameDataPoints[0], frameDataPoints[1], cv::Scalar(255,0,0),3);
    cv::line(undistImage, frameDataPoints[0], frameDataPoints[2], cv::Scalar(0,255,0),3);
    cv::line(undistImage, frameDataPoints[0], frameDataPoints[3], cv::Scalar(0,0,255),3);

    cv::Mat R;

    cv::Rodrigues(rvec, R);

    qDebug() << "R =";
    qDebug() << R.at<double>(0,0) << R.at<double>(0,1) << R.at<double>(0,2);
    qDebug() << R.at<double>(1,0) << R.at<double>(1,1) << R.at<double>(1,2);
    qDebug() << R.at<double>(2,0) << R.at<double>(2,1) << R.at<double>(2,2);


    qDebug() << "t =";
    qDebug() << tvec.at<double>(0);
    qDebug() << tvec.at<double>(1);
    qDebug() << tvec.at<double>(2);





    cv::imshow("Undist", undistImage);
}
