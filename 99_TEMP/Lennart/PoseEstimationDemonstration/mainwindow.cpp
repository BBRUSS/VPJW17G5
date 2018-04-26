#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::copy
#include <vector>       // std::vector

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ps.load();
    qDebug() << ps.cams.size();


    //guiImage.resize(ps.camFieldSize.width*ps.cameraImageSize.width, ps.camFieldSize.height*ps.cameraImageSize.height);

    cv::Point2f tempPoint(0.0f, 0.0f);
std:vector<cv::Point2f> tempVector;
    //tempVector.push_back(tempPoint);
    //tempVector.push_back(tempPoint);


    for (int i = 0; i < ps.camFieldSize.area(); i++) {
        vc.push_back(new cv::VideoCapture);
        vc.at(i)->open(i);
        cameraIsFixed.push_back(false);
        fixedCameraPoints.push_back(tempVector);
        fixedCameraPointsLESB.push_back(tempVector);
        cameraRelation temp;
        fixedCameraRelation.push_back(temp);
        //cv::Point2f pointTmp(0.0, 0.0);
        fixedCameraRelationMat.push_back(cv::Mat::eye(cv::Size(3, 3), cv::DataType<double>::type));
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
            // cv::imshow((QString::number(i)).toStdString(), image);
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

        qDebug() << 3;
        lastValidMarkerOrigin = finalMarkerCorners.at(0);
        std::vector<cv::Point3f> objectPoints;
        qDebug() << 4;
        objectPoints.push_back(cv::Point3f(0 * markerSizeMM, 0 * markerSizeMM, 0.0f));
        objectPoints.push_back(cv::Point3f(markerSizeMM, 0 * markerSizeMM, 0.0f));
        objectPoints.push_back(cv::Point3f(markerSizeMM, markerSizeMM, 0.0f));
        objectPoints.push_back(cv::Point3f(0 * markerSizeMM, markerSizeMM, 0.0f));

        qDebug() << 5;

        bool success = cv::solvePnP (objectPoints, lastValidMarkerOrigin, ps.cams.at(cameraMarkerIds.at(0))->cameraMatrix, cv::Mat(), rvecTmp, tvecTmp);
        qDebug() << 6;
        if (success) {
            cv::Rodrigues(rvecTmp, RTmp);
            printCV2dMat(rvecTmp, "rvecTmp");
            originCameraIDTmp = cameraMarkerIds.at(0);

            std::vector<cv::Point3d> framePoints;
            framePoints.push_back(cv::Point3d(  0,   0,   0));
            framePoints.push_back(cv::Point3d(markerSizeMM*2,   0,   0));
            framePoints.push_back(cv::Point3d(  0, markerSizeMM*2,   0));
            framePoints.push_back(cv::Point3d(  0,   0, markerSizeMM*2));

            std::vector<cv::Point2d> frameDataPoints;

            cv::projectPoints(framePoints, rvecTmp, tvecTmp, ps.cams.at(cameraMarkerIds.at(0))->cameraMatrix, cv::Mat(), frameDataPoints);

            cv::cvtColor(cameraImages.at(originCameraIDTmp), guiImage, cv::COLOR_BGR2RGB);

            cv::line(guiImage, frameDataPoints[0], frameDataPoints[1], cv::Scalar(255,0,0),3);
            cv::line(guiImage, frameDataPoints[0], frameDataPoints[2], cv::Scalar(0,255,0),3);
            cv::line(guiImage, frameDataPoints[0], frameDataPoints[3], cv::Scalar(0,0,255),3);

            cv::aruco::drawDetectedMarkers(guiImage, finalMarkerCorners);

            QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, guiImage.step, QImage::Format_RGB888));
            //pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, QImage::Format_RGB888));
            ui->labelImage->setPixmap(pixmap);

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

        cv::cvtColor(cameraImages.at(originCameraID), guiImage, cv::COLOR_BGR2RGB);

        cv::line(guiImage, frameDataPoints[0], frameDataPoints[1], cv::Scalar(255,0,0),3);
        cv::line(guiImage, frameDataPoints[0], frameDataPoints[2], cv::Scalar(0,255,0),3);
        cv::line(guiImage, frameDataPoints[0], frameDataPoints[3], cv::Scalar(0,0,255),3);

        cv::aruco::drawDetectedMarkers(guiImage, finalMarkerCorners);

        QPixmap pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, guiImage.step, QImage::Format_RGB888));
        ui->labelImage->setPixmap(pixmap);
    }


    if (cameraMarkerIds.size() == 2 && originSet) {
        int fixedCameraID = -1;
        int loseCameraID = -1;
        for (int i = 0; i < cameraMarkerIds.size(); i++) {
            if (cameraIsFixed.at(i)) {
                if (fixedCameraID != -1) {
                    fixedCameraID = -1;
                    break;
                }
                fixedCameraID = cameraMarkerIds.at(i);
            } else {
                loseCameraID = cameraMarkerIds.at(i);
            }
        }

        if (fixedCameraID == -1) {
            ui->pushButtonAddPoint->setEnabled(false);
        } else {

            ui->pushButtonAddPoint->setEnabled(true);

            cv::Mat A(4, 4, cv::DataType<double>::type);
            cv::Mat b(4, 1, cv::DataType<double>::type);

            qDebug() << fixedCameraPoints.at(loseCameraID).size();

            if (fixedCameraPoints.at(loseCameraID).size() == 0) {
                double  valuesAtmp[16] = {1.0, 0.0, finalMarkerCorners.at(loseCameraID).at(0).x, -finalMarkerCorners.at(loseCameraID).at(0).y,
                                          0.0, 1.0, finalMarkerCorners.at(loseCameraID).at(0).y, finalMarkerCorners.at(loseCameraID).at(0).x,
                                          1.0, 0.0, finalMarkerCorners.at(loseCameraID).at(0).x, -finalMarkerCorners.at(loseCameraID).at(0).y,
                                          0.0, 1.0, finalMarkerCorners.at(loseCameraID).at(0).y, finalMarkerCorners.at(loseCameraID).at(0).x};

                double  valuesBtmp[4] = {finalMarkerCorners.at(fixedCameraID).at(0).x,
                                         finalMarkerCorners.at(fixedCameraID).at(0).y,
                                         finalMarkerCorners.at(fixedCameraID).at(0).x,
                                         finalMarkerCorners.at(fixedCameraID).at(0).y};

                int idx = 0;


                if (saveData) {
                    fixedCameraPoints.at(loseCameraID) = (finalMarkerCorners.at(loseCameraID));
                    fixedCameraPointsLESB.at(fixedCameraID) = (finalMarkerCorners.at(fixedCameraID));
                    saveData = false;
                }

                //A = cv::Mat(4, 4, cv::DataType<double>::type, valuesAtmp);
                //b = cv::Mat(4, 1, cv::DataType<double>::type, valuesBtmp);
            } else {
                double  valuesAtmp[16] = {1.0, 0.0, fixedCameraPoints.at(loseCameraID).at(0).x, -fixedCameraPoints.at(loseCameraID).at(0).y,
                                          0.0, 1.0, fixedCameraPoints.at(loseCameraID).at(0).y, fixedCameraPoints.at(loseCameraID).at(0).x,
                                          1.0, 0.0, finalMarkerCorners.at(loseCameraID).at(0).x, -finalMarkerCorners.at(loseCameraID).at(0).y,
                                          0.0, 1.0, finalMarkerCorners.at(loseCameraID).at(0).y, finalMarkerCorners.at(loseCameraID).at(0).x};

                double  valuesBtmp[4] = {fixedCameraPointsLESB.at(fixedCameraID).at(0).x,
                                         fixedCameraPointsLESB.at(fixedCameraID).at(0).y,
                                         finalMarkerCorners.at(fixedCameraID).at(0).x,
                                         finalMarkerCorners.at(fixedCameraID).at(0).y};

                int idx = 0;

                A = cv::Mat(4, 4, cv::DataType<double>::type, valuesAtmp);
                b = cv::Mat(4, 1, cv::DataType<double>::type, valuesBtmp);

                printCV2dMat(A, "A");
                printCV2dMat(b, "b");

                cv::Mat x = A.inv()*b;

                printCV2dMat(x, "x");
                qDebug() << "0: " << x.at<double>(0,0) << " 1: " << x.at<double>(0,1) << " 2: "<< x.at<double>(0,2) << " 3: " << x.at<double>(0,3);

                if (saveData) {

                    fixedCameraRelation.at(loseCameraID).xT = x.at<double>(0);
                    fixedCameraRelation.at(loseCameraID).yT = x.at<double>(1);
                    fixedCameraRelation.at(loseCameraID).cosP = x.at<double>(2);
                    fixedCameraRelation.at(loseCameraID).sinP = x.at<double>(3);

                    cv::Mat relation(3, 3, cv::DataType<double>::type);

                    relation.at<double>(0,0) = fixedCameraRelation.at(loseCameraID).cosP;
                    relation.at<double>(0,1) = -fixedCameraRelation.at(loseCameraID).sinP;
                    relation.at<double>(0,2) = fixedCameraRelation.at(loseCameraID).xT;
                    relation.at<double>(1,0) = fixedCameraRelation.at(loseCameraID).sinP;
                    relation.at<double>(1,1) = fixedCameraRelation.at(loseCameraID).cosP;
                    relation.at<double>(1,2) = fixedCameraRelation.at(loseCameraID).yT;
                    relation.at<double>(2,0) = 0.0;
                    relation.at<double>(2,1) = 0.0;
                    relation.at<double>(2,2) = 1.0;

                    fixedCameraRelationMat.at(loseCameraID) = relation;

                    cameraIsFixed.at(loseCameraID) = true;

                    ui->pushButtonAddPoint->setEnabled(false);

                    for (int i = 0; i < cameraIsFixed.size(); i++) {
                        if (!cameraIsFixed.at(i)) {
                            break;
                        }
                        allCamerasFixed = true;
                    }
                    saveData = false;
                }
                //finalMarkerCorners;
            }
        }
    }
    if (!cameraMarkerIds.empty() && allCamerasFixed) {
        for (int i = 0; i < finalMarkerCorners.size(); i++) {

            //finalMarkerCorners.at(i).at(0)

            cv::Mat uvPoint = cv::Mat::ones(3,1, cv::DataType<double>::type); //u,v,1
            uvPoint.at<double>(0,0) = finalMarkerCorners.at(i).at(0).x; //got this point using mouse callback
            uvPoint.at<double>(1,0) = finalMarkerCorners.at(i).at(0).y;

            cv::Mat finalPixelPostion = fixedCameraRelationMat.at(cameraMarkerIds.at(i))*uvPoint;

            printCV2dMat(fixedCameraRelationMat.at(cameraMarkerIds.at(i)), "fixedCameraRelationMat.at(cameraMarkerIds.at(i))");

            printCV2dMat(uvPoint, "uvPoint");
            printCV2dMat(finalPixelPostion, "finalPixelPostion");

            printCV2dMat(cv::Mat(finalMarkerCorners.at(i).at(0)), "Abc");
            cv::Mat P = R.inv() * (scalingFactor * ps.cams.at(cameraMarkerIds.at(i))->cameraMatrix.inv() * finalPixelPostion - tvec);
            printCV2dMat(P, "P");

            ui->label_PX->setText(QString::number(round(P.at<double>(0,0)*1000.0)/1000.0));
            ui->label_PY->setText(QString::number(round(P.at<double>(1,0)*1000.0)/1000.0));
            ui->label_PZ->setText(QString::number(round(P.at<double>(2,0)*1000.0)/1000.0));
        }
    }
}

void MainWindow::on_pushButtonSetOrigin_clicked()
{
    tvec = tvecTmp;
    rvec = rvecTmp;
    R = RTmp;

    double sTmp;

    printCV2dMat(R,"R");
    printCV2dMat(R.inv(),"3d");
    printCV2dMat(ps.cams.at(originCameraIDTmp)->cameraMatrix.inv(), "invCamera");

    printCV2dMat(R.inv() * (ps.cams.at(originCameraIDTmp)->cameraMatrix).inv(), "mul2");
    //printCV2dMat((ps.cams.at(originCameraIDTmp)->cameraMatrix).inv() * cv::Mat(point3D), "mul");
    /*
    qDebug() << point3dMat.at(0);
    qDebug() << point3dMat.at(1);
    qDebug() << point3dMat.at(2);
*/

    cv::Mat uvPoint = cv::Mat::ones(3,1,cv::DataType<double>::type); //u,v,1
    uvPoint.at<double>(0,0) = lastValidMarkerOrigin.at(0).x; //got this point using mouse callback
    uvPoint.at<double>(1,0) = lastValidMarkerOrigin.at(0).y;

    cv::Mat tempMat = R.inv() * (ps.cams.at(originCameraIDTmp)->cameraMatrix).inv()*uvPoint;
    printCV2dMat(tempMat, "tempMat");
    cv::Mat tempMat2 = R.inv() * tvec;
    printCV2dMat(tempMat2, "tempMat2");
    qDebug() << 22;

    sTmp = 0 + tempMat2.at<double>(2,0); //285 represents the height Zconst
    qDebug() << 3;
    sTmp /= tempMat.at<double>(2,0);
    qDebug() << 3;

    qDebug() << sTmp;
    scalingFactor = sTmp;
    qDebug() << 4;
    cameraIsFixed.at(originCameraIDTmp) = true;
    originCameraID = originCameraIDTmp;
    originSet = true;
    ui->pushButtonSetOrigin->setEnabled(false);
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

void MainWindow::on_pushButtonAddPoint_clicked()
{
    saveData = true;
}
