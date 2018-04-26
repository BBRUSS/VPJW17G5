#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ps.load();
    qDebug() << ps.cams.size();


    //guiImage.resize(ps.camFieldSize.width*ps.cameraImageSize.width, ps.camFieldSize.height*ps.cameraImageSize.height);

    for (int i = 0; i < ps.camFieldSize.area(); i++) {
        vc.push_back(new cv::VideoCapture);
        vc.at(i)->open(i);
    }

    dict = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL);

    connect(&cameraTimer, &QTimer::timeout, this, &MainWindow::processImage);
    cameraTimer.start(100);
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < vc.size(); i++) {
        vc.at(i)->release();
    }

    delete ui;
}

void MainWindow::processImage() {
    //todo;
    cameraImages.clear();
    finalMarkerCorners.clear();
    cameraMarkerIds.clear();

    for (int i = 0; i < ps.camFieldSize.area(); i++) {
        cv::Mat image;
        if (vc.at(ps.cams.at(i)->cameraID)->isOpened()) {
            vc.at(ps.cams.at(i)->cameraID)->read(image);
            cv::Mat undistImage;
            cv::undistort(image, undistImage, ps.cams.at(i)->cameraMatrix, ps.cams.at(i)->distCoeffs);
            cameraImages.push_back(undistImage);
            cv::aruco::detectMarkers(undistImage, dict, tempMarkerCorners, tempMarkerIds);
            for (int j = 0; j < tempMarkerIds.size(); j++) {
                if (tempMarkerIds.at(j) == toolMarkerId) {
                    finalMarkerCorners.push_back(tempMarkerCorners.at(j));
                    cameraMarkerIds.push_back(i);
                    break;
                }
            }
        }
    }

    if (cameraMarkerIds.size() == 1 && !originSet) {

        lastValidMarkerOrigin = finalMarkerCorners.at(0);
        std::vector<cv::Point3f> objectPoints;

        objectPoints.push_back(cv::Point3f(0 * markerSizeMM, 0 * markerSizeMM, 0.0f));
        objectPoints.push_back(cv::Point3f(markerSizeMM, 0 * markerSizeMM, 0.0f));
        objectPoints.push_back(cv::Point3f(markerSizeMM, markerSizeMM, 0.0f));
        objectPoints.push_back(cv::Point3f(0 * markerSizeMM, markerSizeMM, 0.0f));


        qDebug()<< objectPoints[0].x;
        qDebug()<< objectPoints[0].y;
        qDebug()<< objectPoints[1].x;
        qDebug()<< objectPoints[1].y;
        qDebug()<< objectPoints[2].x;
        qDebug()<< objectPoints[2].y;
        qDebug()<< objectPoints[3].x;
        qDebug()<< objectPoints[3].y;

        qDebug()<< lastValidMarkerOrigin[0].x;
        qDebug()<< lastValidMarkerOrigin[0].y;
        qDebug()<< lastValidMarkerOrigin[1].x;
        qDebug()<< lastValidMarkerOrigin[1].y;
        qDebug()<< lastValidMarkerOrigin[2].x;
        qDebug()<< lastValidMarkerOrigin[2].y;
        qDebug()<< lastValidMarkerOrigin[3].x;
        qDebug()<< lastValidMarkerOrigin[3].y;

        bool success = cv::solvePnP (objectPoints, lastValidMarkerOrigin, ps.cams.at(cameraMarkerIds.at(0))->cameraMatrix, cv::Mat(), rvecTmp, tvecTmp);

        if (success) {
            cv::Rodrigues(rvecTmp, RTmp);
            originCameraIDTmp = cameraMarkerIds.at(0);

            std::vector<cv::Point3d> framePoints;
            framePoints.push_back(cv::Point3d(  0,   0,   0));
            framePoints.push_back(cv::Point3d(markerSizeMM*2,   0,   0));
            framePoints.push_back(cv::Point3d(  0, markerSizeMM*2,   0));
            framePoints.push_back(cv::Point3d(  0,   0, markerSizeMM*2));

            std::vector<cv::Point2d> frameDataPoints;

            cv::projectPoints(framePoints, rvecTmp, tvecTmp, ps.cams.at(cameraMarkerIds.at(0))->cameraMatrix, cv::Mat(), frameDataPoints);

            cv::line(cameraImages.at(cameraMarkerIds.at(0)), frameDataPoints[0], frameDataPoints[1], cv::Scalar(255,0,0),3);
            cv::line(cameraImages.at(cameraMarkerIds.at(0)), frameDataPoints[0], frameDataPoints[2], cv::Scalar(0,255,0),3);
            cv::line(cameraImages.at(cameraMarkerIds.at(0)), frameDataPoints[0], frameDataPoints[3], cv::Scalar(0,0,255),3);

            ui->pushButtonSetOrigin->setEnabled(true);
        }
    }

    if (originSet) {
        std::vector<cv::Point3d> framePoints;
        framePoints.push_back(cv::Point3d(  0,   0,   0));
        framePoints.push_back(cv::Point3d(markerSizeMM*2,   0,   0));
        framePoints.push_back(cv::Point3d(  0, markerSizeMM*2,   0));
        framePoints.push_back(cv::Point3d(  0,   0, markerSizeMM*2));

        std::vector<cv::Point2d> frameDataPoints;

        cv::projectPoints(framePoints, rvec, tvec, ps.cams.at(originCameraID)->cameraMatrix, cv::Mat(), frameDataPoints);

        cv::line(cameraImages.at(originCameraID), frameDataPoints[0], frameDataPoints[1], cv::Scalar(255,0,0),3);
        cv::line(cameraImages.at(originCameraID), frameDataPoints[0], frameDataPoints[2], cv::Scalar(0,255,0),3);
        cv::line(cameraImages.at(originCameraID), frameDataPoints[0], frameDataPoints[3], cv::Scalar(0,0,255),3);
    }

    cv::cvtColor(cameraImages.at(0), guiImage, cv::COLOR_BGR2RGB);

    QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, guiImage.step, QImage::Format_RGB888));
    //pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, QImage::Format_RGB888));
    ui->labelImage->setPixmap(pixmap);
}

void MainWindow::on_pushButtonSetOrigin_clicked()
{
    tvec = tvecTmp;
    rvec = rvecTmp;
    R = RTmp;
    originCameraID = originCameraIDTmp;
    originSet = true;
}
