#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set.load();

    connect(&cameraTimer, SIGNAL(timeout()), this, SLOT(on_cameraTimerEvent()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOpenCamera_clicked()
{
    videoCapture.open(0);
    cameraTimer.start(10);
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
    cv::Mat rvec2, tvec2;
    std::vector<cv::Point2f> pc1;
    std::vector<cv::Point3f> pc2;

    pc1.push_back(cv::Point2d(6.5, 6.5));
    pc1.push_back(cv::Point2d(3.5, 55));
    pc2.push_back(cv::Point2d(83.0, 7.5, 1));
    pc2.push_back(cv::Point2d(84.5, 52.0, 1));

    cv::findEssentialMat()

//    cv::solvePnP(pc2, pc1, cv::Mat(), cv::Mat(), rvec2, tvec2);

//    printCV2dMat(rvec2, "RVEC");
//    printCV2dMat(tvec2, "TVEC");
//    return;

    cv::Mat image;
    videoCapture.read(image);

    cv::Size boardSize(set.boardSize);
    std::vector<cv::Point2f> imagePoints;

    cv::Mat undistImage;
    cv::undistort(image, undistImage, set.cams.at(0)->cameraMatrix, set.cams.at(0)->distCoeffs);

    cv::Mat detectionImage;
    if (set.calibPatternWhiteOnBlack) {
        cv::Mat Temp = cv::Scalar::all(255) - undistImage;
        Temp.copyTo(detectionImage);
    } else {
        undistImage.copyTo(detectionImage);
    }

    bool found = false;

    switch (set.calibrationPattern) {
    case Settings::Pattern::CHESSBOARD:
        found = findChessboardCorners(detectionImage, set.boardSize, imagePoints);
        break;
    case Settings::Pattern::CIRCLES_GRID:
        found = findCirclesGrid(detectionImage, set.boardSize, imagePoints, CALIB_CB_SYMMETRIC_GRID);
        break;
    case Settings::Pattern::ASYMMETRIC_CIRCLES_GRID:
        found = findCirclesGrid(detectionImage, set.boardSize, imagePoints, CALIB_CB_ASYMMETRIC_GRID);
        break;
    }

    if (!found)
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
            objectPoints.push_back(cv::Point3f(j * set.squareSize, i * set.squareSize, 0.0f));
        }
    }

    cv::Mat rvec, tvec;

    bool success = cv::solvePnP (objectPoints, imagePoints, set.cams.at(0)->cameraMatrix, cv::Mat(), rvec, tvec);

    std::vector<cv::Point3d> framePoints;
    framePoints.push_back(cv::Point3d(  0,   0,   0));
    framePoints.push_back(cv::Point3d(70,   0,   0));
    framePoints.push_back(cv::Point3d(  0, 140,   0));
    framePoints.push_back(cv::Point3d(  0,   0, 35));

    std::vector<cv::Point2d> frameDataPoints;

    cv::projectPoints(framePoints, rvec, tvec, set.cams.at(0)->cameraMatrix, cv::Mat(), frameDataPoints);

    cv::line(undistImage, frameDataPoints[0], frameDataPoints[1], cv::Scalar(255,0,0),3);
    cv::line(undistImage, frameDataPoints[0], frameDataPoints[2], cv::Scalar(0,255,0),3);
    cv::line(undistImage, frameDataPoints[0], frameDataPoints[3], cv::Scalar(0,0,255),3);

    cv::imshow("Undist", undistImage);

    cv::Mat R;

    cv::Rodrigues(rvec, R);

    std::vector<std::vector<cv::Point2f>> tempmarkerCorners;      //Vector contains the Cornerposition of detected Marker in Order by Vector Marker Corners
    std::vector<int> tempmarkerIds;     //Contains the Position of rejectedCandidates

    cv::Ptr<cv::aruco::Dictionary> dict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);
    cv::aruco::detectMarkers(undistImage, dict, tempmarkerCorners, tempmarkerIds);

    if (tempmarkerCorners.size() > 0) {
        cv::aruco::drawDetectedMarkers(undistImage, tempmarkerCorners, tempmarkerIds);

        cv::imshow("Undist", undistImage);

        cv::Mat uvPoint = cv::Mat::ones(3,1,cv::DataType<double>::type); //u,v,1
        uvPoint.at<double>(0,0) = tempmarkerCorners.at(0).at(0).x; //got this point using mouse callback
        uvPoint.at<double>(1,0) = tempmarkerCorners.at(0).at(0).y;

        cv::Mat tempMat, tempMat2;

        double s;

        tempMat = R.inv() * (set.cams.at(0)->cameraMatrix).inv() * uvPoint;
        tempMat2 = R.inv() * tvec;

        float z = ui->lineEdit_Z->text().toDouble();

        s = z + tempMat2.at<double>(2,0); //285 represents the height Zconst
        s /= tempMat.at<double>(2,0);

        qDebug() << s;

        cv::Mat P = R.inv() * (s * set.cams.at(0)->cameraMatrix.inv() * uvPoint - tvec);

        ui->label_PX->setText(QString::number(round(P.at<double>(0,0)*1000.0)/1000.0));
        ui->label_PY->setText(QString::number(round(P.at<double>(1,0)*1000.0)/1000.0));
        ui->label_PZ->setText(QString::number(round(P.at<double>(2,0)*1000.0)/1000.0));
        //printCV2dMat(P, "P");
    }
}

void MainWindow::printCV2dMat(cv::Mat Mat, QString Name) {
    qDebug() << Name << ":";

    QString Row;

    for (int i = 0; i < Mat.rows; i++) {
        for (int j = 0; j < Mat.cols; j++) {
            Row.append(QString::number(Mat.at<double>(i, j)) + " ");
        }
        qDebug() << Row;
        Row.clear();
    }
}


