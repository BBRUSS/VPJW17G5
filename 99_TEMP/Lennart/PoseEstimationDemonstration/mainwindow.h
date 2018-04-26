#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <QTimer>
#include <iostream>     // std::cout
#include <QtAlgorithms>    // std::copy
#include <vector>       // std::vector

#include "settings.h"
#include "camera.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

struct cameraRelation {
    double xT = 0;
    double yT = 0;
    double cosP = 0;
    double sinP = 0;
};

private:
    Ui::MainWindow *ui;
    Settings ps;
    cv::Mat guiImage;
    int toolMarkerId = 11;
    double markerSizeMM = 202;
    bool originSet = false;
    int originCameraIDTmp;
    int originCameraID;

    cv::Mat rvecTmp;
    cv::Mat tvecTmp;
    cv::Mat RTmp;

    cv::Mat rvec;
    cv::Mat tvec;
    cv::Mat R;

    std::vector<cv::VideoCapture*> vc;
    std::vector<cv::Mat> cameraImages;
    std::vector<bool> cameraIsFixed;
    bool saveData = false;
    bool allCamerasFixed = false;
    double scalingFactor = 0;
    std::vector<std::vector<cv::Point2f>> fixedCameraPoints;
    std::vector<std::vector<cv::Point2f>> fixedCameraPointsLESB;
    std::vector<cameraRelation> fixedCameraRelation;
    std::vector<cv::Mat> fixedCameraRelationMat;
    QTimer cameraTimer;
    std::vector<std::vector<cv::Point2f>> tempMarkerCorners;      //Vector contains the Cornerposition of detected Marker in Order by Vector Marker Corners
    std::vector<std::vector<cv::Point2f>> finalMarkerCorners;      //Vector contains the Cornerposition of detected Marker in Order by Vector Marker Corners
    std::vector<cv::Point2f> lastValidMarkerOrigin;
    std::vector<int> tempMarkerIds;     //Contains the Position of rejectedCandidates
    std::vector<int> cameraMarkerIds;     //Contains the Position of rejectedCandidates
    cv::Ptr<cv::aruco::Dictionary> dict;
    void printCV2dMat(cv::Mat Mat, QString Name);

private slots:
    void processImage();
    void on_pushButtonSetOrigin_clicked();
    void on_pushButtonAddPoint_clicked();
};

#endif // MAINWINDOW_H
