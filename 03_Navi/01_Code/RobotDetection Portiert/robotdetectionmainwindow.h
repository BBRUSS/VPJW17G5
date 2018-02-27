#ifndef ROBOTDETECTIONMAINWINDOW_H
#define ROBOTDETECTIONMAINWINDOW_H


#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QTime>
#include <opencv2/opencv.hpp>
#include <QMessageBox>
#include <QThread>
#include <QMutex>

#include "imageprocessingworker.h"
#include "myudp.h"
#include "constants.h"

namespace Ui {
class RobotDetectionMainWindow;
}

class RobotDetectionMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RobotDetectionMainWindow(QWidget *parent = 0);
    ~RobotDetectionMainWindow();

public slots:
    void updateGuiImage(const QList<cv::Mat> warpedImage, const QList<cv::Point3f> robotLocations, const QList<RobotPosition> detectedRobots);

private:
    UDPSettings udpStruct;
    Ui::RobotDetectionMainWindow *ui;
    int timerMilSecs;
    QTimer * timer;
    QTimer * timerFPS;
    QList<cv::Mat> cameraMatrix;
    QList<cv::Mat> distCoeffs;
    QList<cv::Mat> perspTransfMatrix;
    QList<RobotOffset> robotOffsets;
    QThread workerThread;
    QList<int> exposureValue;
    QList<int> contrastValue;
    QList<int> brightnessValue;
    ImageProcessingWorker* imgWorker;
    QList<cv::VideoCapture> videoCapture;
    //cv::VideoCapture videoCapture[NR_OF_CAMS];
    QMutex guiUpdateMutex;
    cv::Mat originalImages[NR_OF_CAMS];
    bool mainloopIsActive;
    bool calibrateOffset_ON_OFF;
    int fpsCount = 0;
    int udpCount = 0;
    QTime timeStamp;

protected:
    void writeRobotLocationsToTable(QList<cv::Point3f> robotLocations);
    void writeRobotIDsToGui(cv::Mat guiImage, QList<cv::Point3f> robotLocations);
    void readXmlCalibrationFile();
    cv::Ptr<cv::aruco::DetectorParameters> readArucoParameters();

    double scaleToGui(double value);
    double distanceBetweenPoints(cv::Point2f a, cv::Point2f b);

    cv::Point2f scaleToGui(cv::Point2f srcDot);
    cv::Point3f scaleToGui(cv::Point3f srcDot);

    QMap<QString, QXmlStreamAttributes> parseCamera(QXmlStreamReader& xmlReader);

private slots:
    void on_pushButtonCalibrateOffset_clicked();
    void on_pushButtonStartStop_clicked();
    void fpsCounter();

};

#endif // ROBOTDETECTIONMAINWINDOW_H
