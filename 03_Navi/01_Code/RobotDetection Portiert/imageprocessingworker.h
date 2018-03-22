#ifndef IMAGEPROCESSINGWORKER_H
#define IMAGEPROCESSINGWORKER_H

#include <QObject>
#include "myudp.h"
#include <QThreadPool>
#include "imgtask.h"
#include <QMessageBox>
#include <QMetaType>
#include "arucoserializer.h"


class ImageProcessingWorker : public QObject
{
    Q_OBJECT
public:
    //explicit ImageProcessingWorker();
    explicit ImageProcessingWorker(UDPSettings udpStruct, cv::Ptr<cv::aruco::DetectorParameters> arucoParameters, cv::Ptr<cv::aruco::Dictionary> arucoDict, QList<cv::VideoCapture> &videoCapture, QList<cv::Mat> cameraMatrix, QList<cv::Mat> distCoeffs, QList<cv::Mat> perspTransfMatrix, QList<RobotOffset> robotOffsets);
    ~ImageProcessingWorker();
    void setMeasureData(bool measure);
    void setTaskThreshold(int threshold);
    void setTaskRectMinSize(int minSize);
    void setRobotCount(int robotCount);

    friend cv::Point3f operator*(const cv::Point3f& a, const cv::Point3f& b);


private:
    MyUDP *udpClient;
    QThreadPool threadPool;
    QList<ImgTask*> tasks;
    //ImgTask *tasks[NR_OF_CAMS];
    QMutex workerMutex;
    QString sendToIp;
    int sendToPort;
    QString sendToIp_SyncService;
    int sendToPort_SyncService;
    QString reciveIp_SyncService;
    int recivePort_SyncService;
    QTime timeStamp;
    QList<cv::VideoCapture> videoCapture;
    cv::Ptr<cv::aruco::DetectorParameters> arucoParameters;
    cv::Ptr<cv::aruco::Dictionary> arucoDict;
    cv::Mat cameraImages[NR_OF_CAMS];
    QList<cv::Point3f> robotLocations;
    QList<cv::Point3f> robotLocationStd;
    QList<int> robotLocationStd1d;
    bool calibrateOffset_ON_OFF = false;
    bool debugMode = true;
    bool measureData = false;
    int taskThreshold = 0;
    int taskRectMinSize = 0;
    int robotCount = 0;
    QList<cv::Mat> warpedImage;
    QList<cv::Mat> cameraMatrix;
    QList<cv::Mat> distCoeffs;
    QList<cv::Mat> perspTransfMatrix;
    QList<RobotOffset> robotOffsets;
    QList<QList<RobotPosition>> robotIDLocation;

signals:
    //void updateGui(const QList<cv::Mat> cameraImage, const QList<cv::Point3f> robotLocations, const QList<cv::Point3f> robotLocationsStd, const QList<QList<RobotPosition>> robotIDLocation, const QList<RobotPosition> detectedRobots);
    void updateGui(const QList<cv::Mat> cameraImage, const QList<cv::Point3f> robotLocations, const QList<int> robotLocationsStd1d, const QList<QList<RobotPosition>> robotIDLocation, const QList<RobotPosition> detectedRobots);
    void finishedUDPData(QList<cv::Point3f> robotLocations, QTime timeStamp);

public slots:
    void processImages();


};

#endif // IMAGEPROCESSINGWORKER_H
