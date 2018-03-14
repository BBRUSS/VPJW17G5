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
#include <QDataStream>
#include <QTableWidgetItem>

#include "arucodictionary.h"
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
    ArucoDictionary defaultArucoDict;


protected:
    void writeRobotLocationsToTable(QList<cv::Point3f> robotLocations);
    void writeRobotIDsToGui(cv::Mat guiImage, QList<cv::Point3f> robotLocations);
    void readXmlCalibrationFile();
    cv::Ptr<cv::aruco::DetectorParameters> readArucoParameters();
    void updateArucoTab(int SelectedRow);
    void initArucoTab();

//    void saveIDNameMap(QMap<int, QString> map);
//    QMap<int, QString> loadIDNameMap();


    double scaleToGui(double value);
    double distanceBetweenPoints(cv::Point2f a, cv::Point2f b);

    cv::Point2f scaleToGui(cv::Point2f srcDot);
    cv::Point3f scaleToGui(cv::Point3f srcDot);

    QMap<QString, QXmlStreamAttributes> parseCamera(QXmlStreamReader& xmlReader);

private slots:

    void on_pushButtonCalibrateOffset_clicked();
    void on_pushButtonStartStop_clicked();
    void fpsCounter();

    void updateIDNameMap();
    void on_pushButton_addAruco_clicked();
    void on_tabMain_tabBarClicked(int index);
    void on_tableWidget_Aruco_cellChanged(int row, int column);
    void on_tableWidget_Aruco_cellClicked(int row, int column);
    void on_pushButton_deleteAruco_clicked();
    void on_pushButton_SaveToImage_clicked();
};

#endif // ROBOTDETECTIONMAINWINDOW_H
