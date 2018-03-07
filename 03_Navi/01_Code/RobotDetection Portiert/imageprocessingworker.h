#ifndef IMAGEPROCESSINGWORKER_H
#define IMAGEPROCESSINGWORKER_H

#include <QObject>
#include "myudp.h"
#include <QThreadPool>
#include "imgtask.h"
#include <QMessageBox>
#include <QMetaType>


class ImageProcessingWorker : public QObject
{
    Q_OBJECT
public:
    //explicit ImageProcessingWorker();
    explicit ImageProcessingWorker(UDPSettings udpStruct, cv::Ptr<cv::aruco::DetectorParameters> arucoParameters, QList<cv::VideoCapture> videoCapture, QList<cv::Mat> cameraMatrix, QList<cv::Mat> distCoeffs, QList<cv::Mat> perspTransfMatrix, QList<RobotOffset> robotOffsets);
    ~ImageProcessingWorker();
    void setMeasureData(bool measure);
    void setTaskThreshold(int threshold);
    void setTaskRectMinSize(int minSize);

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
    cv::Mat cameraImages[NR_OF_CAMS];
    QList<cv::Point3f> robotLocations;
    QList<cv::Point3f> robotLocationStd;
    bool calibrateOffset_ON_OFF = false;
    bool debugMode = true;
    bool measureData = false;
    int taskThreshold = 0;
    int taskRectMinSize = 0;
    QList<cv::Mat> warpedImage;
    QList<cv::Mat> cameraMatrix;
    QList<cv::Mat> distCoeffs;
    QList<cv::Mat> perspTransfMatrix;
    QList<RobotOffset> robotOffsets;
    QList<QList<RobotPosition>> robotIDLocation;

signals:
    void updateGui(QList<cv::Mat> warpedImage, QList<cv::Point3f> robotLocations, QList<RobotPosition> detectedRobots);
    void finishedUDPData(QList<cv::Point3f> robotLocations, QTime timeStamp);

public slots:
    void processImages();


};

#endif // IMAGEPROCESSINGWORKER_H
