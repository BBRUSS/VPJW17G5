#ifndef IMGTASK_H
#define IMGTASK_H
#include <QVector>
#include <QThreadPool>
#include <QRunnable>
#include <QtCore>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include "constants.h"

typedef QList<cv::Point2f> Pointlist;

//Structur for Robot, with x-, y- Coordinates, Angle and RobotID
struct RobotPosition
{
   int id;
   cv::Point3f coordinates;
};

struct RobotMarker
{
    int id;
    Pointlist cornerPoints;
    Pointlist warpedCornerPoints;
};

struct RobotOffset
{
    int id;
    double offsetMarkerEven;
    double offsetMarkerNotEven;
};

class ImgTask : public QRunnable
{

public:
    //explicit ImgTask();
    static const int InvalidRobotId = -1;
    void run();
    void setImage(cv::Mat image);
    void setCameraMatrix(cv::Mat cameraMatrix);
    void setDistCoeffs(cv::Mat distCoeffs);
    void setPerspTransfMatrix(cv::Mat perspTransfMatrix);
    void setDebugMode(bool liveViewMode);
    void setCalibrateOffset(bool  setValue);
    void setArucoParameters(cv::Ptr<cv::aruco::DetectorParameters> arucoParameters);
    void setArucoDict(cv::Ptr<cv::aruco::Dictionary> arucoDict);
    void setThreshold(int threshold);
    void setMinSizeofRects(int minSizeofRects);
    void setRobotCount(int robotCount);
    QList<RobotOffset> getNewRobotOffsets();
    void setRobotOffsets(QList<RobotOffset> offsets);
    void clearNewRobotOffsets();
    QList<RobotPosition> getdetectRobots();
    cv::Mat getLiveViewImage();
    static Pointlist stdVectorToPointlist(std::vector<cv::Point2f> vec);
    static std::vector<cv::Point2f> PointlistToStdVector( Pointlist  vec);


protected:
    cv::Mat image;
    cv::Mat cameraMatrix;
    cv::Mat distCoeffs;
    cv::Mat perspTransfMatrix;
    cv::Mat liveViewImage;
    cv::Ptr<cv::aruco::Dictionary> arucoDict;
    bool liveViewMode; // debug == LiveView mode...
    bool calibrateOffset;
    QList<RobotPosition> detectedRobots;
    QList<RobotOffset> RobotOffsets;
    QList<RobotOffset> NewRobotOffsets;
    double calculateangle(Pointlist marker);
    double calculateanglebetweenmarker(Pointlist marker1, Pointlist marker2);
    double calculatemiddleangle(QList<double> angles, int prio);
    Pointlist calculatemiddlepointandOffset(Pointlist marker1, Pointlist marker2);
    cv::Point2f calculatemiddlepoint(Pointlist marker1, double offset, double angle);
    cv::Ptr<cv::aruco::DetectorParameters> arucoParameters;
    int getRobotId(int markerID);
    int threshold_max;
    int MinSizeofRects;
    int robotCount;
    QThread warpedImageThread;

signals:

public slots:
};

#endif // IMGTASK_H
