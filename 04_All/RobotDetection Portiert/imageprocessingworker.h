#ifndef IMAGEPROCESSINGWORKER_H
#define IMAGEPROCESSINGWORKER_H

#include <QObject>
#include "myudp.h"
#include <QThreadPool>
#include "imgtask.h"
#include <QMessageBox>
#include <QMetaType>
//#include "arucoserializer.h"
#include "settings.h"

class ImageProcessingWorker : public QObject
{
    Q_OBJECT
public:
    //explicit ImageProcessingWorker();
    explicit ImageProcessingWorker(Settings::UDPSettings udpStruct, QList<cv::VideoCapture> &videoCapture, QList<cv::Mat> cameraMatrix, QList<cv::Mat> distCoeffs, QList<cv::Mat> perspTransfMatrix);
    ~ImageProcessingWorker();

    friend cv::Point3f operator*(const cv::Point3f& a, const cv::Point3f& b);
    void setArucoDict(cv::Ptr<cv::aruco::Dictionary> arucoDict);
    void setArucoParameters(cv::Ptr<cv::aruco::DetectorParameters> arucoParameters);
    void setCameraMatrix(const QList<cv::Mat> cameraMatrix);
    void setDebugMode(bool debugMode);
    void setDistCoeffs(const QList<cv::Mat> distCoeffs);
    void setMeasureData(bool measure);
    void setPerpTransfMatrix(const QList<cv::Mat> perspTransfMatrix);
    void setRobotCount(int robotCount);
    void setRobotOffsets(const QList<RobotOffset> robotOffsets);
    void setRobotStdThreshMax(float robotStdThreshMax);
    void setRobotMaxNumber(int robotMaxNumber);
    void setTaskRectMinSize(int minSize);
    void setTaskThreshold(int threshold);
    void setUdpSettings(const Settings::UDPSettings udpStruct);
    void setVideoCapture(const QList<cv::VideoCapture> &videoCapture);

private:

    bool calibrateOffset_ON_OFF = false;
    bool debugMode = false;
    bool mainLoopActive = false;
    bool measureData = false;
    QList<cv::Mat> cameraImages;
    cv::Ptr<cv::aruco::DetectorParameters> arucoParameters;
    cv::Ptr<cv::aruco::Dictionary> arucoDict;
    int recivePort_SyncService;
    int robotCount = 0;
    int sendToPort;
    int sendToPort_SyncService;
    int taskRectMinSize = 0;
    int taskThreshold = 0;
    MyUDP *udpClient;
    QList<cv::Mat> cameraMatrix;
    QList<cv::Mat> distCoeffs;
    QList<cv::Mat> liveViewImage;
    QList<cv::Mat> perspTransfMatrix;
    QList<cv::Point3f> robotLocations;
    QList<cv::Point3f> robotLocationStd;
    QList<cv::VideoCapture> videoCapture;
    QList<ImgTask*> tasks;
    QList<int> robotLocationStd1d;
    QList<QList<RobotPosition>> robotIDLocation;
    QList<RobotOffset> robotOffsets;
    QMutex workerMutex;
    QString reciveIp_SyncService;
    QString sendToIp;
    QString sendToIp_SyncService;
    QThreadPool threadPool;
    QTime timeStamp;
    float robotStdThreshMax;
    int robotMaxNumber;

signals:
    void finishedUDPData(QList<cv::Point3f> robotLocations, QTime timeStamp);
    void requestSettingsUpdate();
    void requestUDPIncrement();
    void updateGui(const QList<cv::Mat> cameraImage, const QList<cv::Point3f> robotLocations, const QList<int> robotLocationsStd1d, const QList<QList<RobotPosition>> robotIDLocation, const QList<RobotPosition> detectedRobots);
    void finishedRobotOffsets(QList<RobotOffset> foundOffsets);

public slots:
    void startProcessing();
    void stopProcessing();
    void processSettingsUpdate(int taskThreshold,
                               int taskRectMinSize,
                               int robotCount,
                               bool debugMode,
                               bool measureData,
                               cv::Ptr<cv::aruco::DetectorParameters> arucoParameters,
                               cv::Ptr<cv::aruco::Dictionary> arucoDict,
                               QList<RobotOffset> robotOffsets,
                               bool calibrateOffset_ON_OFF);

};

#endif // IMAGEPROCESSINGWORKER_H
