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
#include "..\..\..\02_Calib\01_Code\Settings\settings.h"

namespace Ui {
class RobotDetectionMainWindow;
}

class RobotDetectionMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RobotDetectionMainWindow(QWidget *parent = 0);
    ~RobotDetectionMainWindow();

private:
    //cv::VideoCapture videoCapture[NR_OF_CAMS];
    //QTimer * timer;
    ArucoDictionary defaultArucoDict;
    bool calibrateOffset_ON_OFF;
    bool mainloopIsActive;
    cv::Mat originalImages[NR_OF_CAMS];
    ImageProcessingWorker* imgWorker;
    int fpsCount = 0;
    int timerMilSecs;
    int udpCount = 0;
    QList<cv::Mat> cameraMatrix;
    QList<cv::Mat> distCoeffs;
    QList<cv::Mat> guiTransfMatrix;
    QList<cv::Mat> perspTransfMatrix;
    QList<cv::VideoCapture> videoCapture;
    QList<int> brightnessValue;
    QList<int> contrastValue;
    QList<int> exposureValue;
    QList<RobotOffset> robotOffsets;
    QMutex guiUpdateMutex;
    QMutex settingsUpdateMutex;
    QThread workerThread;
    QTime timeStamp;
    QTimer * timerFPS;
    Settings programSettings;
    Settings::UDPSettings udpStruct;
    Ui::RobotDetectionMainWindow *ui;

protected:
    //point
    double distanceBetweenPoints(cv::Point2f a, cv::Point2f b);
    cv::Point2f scaleToGui(cv::Point2f srcDot);
    cv::Point3f scaleToGui(cv::Point3f srcDot);
    double scaleToGui(double value);

    //aruco
    void initArucoTab();
    cv::Ptr<cv::aruco::DetectorParameters> readArucoParameters();
    void updateArucoTab(int SelectedRow);
    void updateIDNameMap();

    //settings
    QMap<QString, QXmlStreamAttributes> parseCamera(QXmlStreamReader& xmlReader);
    void readXmlCalibrationFile();
    void sendSettingsUpdate();

    //gui
    void writeRobotIDsToGui(cv::Mat guiImage, QList<cv::Point3f> robotLocations);
    void writeRobotLocationsToTable(QList<cv::Point3f> robotLocations);

private slots:
    void incrementFPSCounter();
    void incrementUDPCounter();
    void updateRobotOffsets(QList<RobotOffset> foundOffsets);
    void on_pushButton_addAruco_clicked();
    void on_pushButton_deleteAruco_clicked();
    void on_pushButton_SaveToImage_clicked();
    void on_pushButtonCalibrateOffset_clicked();
    void on_pushButtonStartStop_clicked();
    void on_tableWidget_Aruco_cellChanged(int row, int column);
    void on_tableWidget_Aruco_cellClicked(int row, int column);
    void on_tabMain_tabBarClicked(int index);

public slots:
    void updateGuiImage(const QList<cv::Mat> cameraImage, const QList<cv::Point3f> robotLocations, const QList<int> robotLocationsStd1d, const QList<QList<RobotPosition>> robotIDLocation, const QList<RobotPosition> detectedRobots);

signals:
    void stopWorker();
    void workerUpdateSettings(int taskThreshold,
                              int taskRectMinSize,
                              int robotCount,
                              bool debugMode,
                              bool measureData,
                              cv::Ptr<cv::aruco::DetectorParameters> arucoParameters,
                              cv::Ptr<cv::aruco::Dictionary> arucoDict,
                              QList<RobotOffset> robotOffsets,
                              bool calibrateOffset_ON_OFF);
};

#endif // ROBOTDETECTIONMAINWINDOW_H
