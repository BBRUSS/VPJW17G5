/** CAMERA Class
  * used for calibrating camera
  *
  * Sources:
  * https://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html#calibratecamera
  * https://docs.opencv.org/3.0-beta/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html
  * https://www.youtube.com/watch?v=GYIQiV9Aw74&t=305s
  * http://aishack.in/tutorials/calibrating-undistorting-opencv-oh-yeah/
  *
  * https://stackoverflow.com/questions/44382267/how-to-find-the-focal-length-from-camera-matrix
  * http://ksimek.github.io/2013/08/13/intrinsic/
  *
  * focal length px --> mm: Fx = fx * W/w = fx * pxWidth | W: sensor width in mm; w: image width in px;
  *
  * ####### Passwort Softwareinstallateur PC VPJ Raum: eckehaard #######
  */

#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include "ui_mainwindow.h"
#include "settings.h"
//#include "robotdetectionmainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


class Camera : public QMainWindow
{
    Q_OBJECT
public:
    Camera();
    Camera(int nr, int id, Settings *s);


    // According to George Lecaces Youtube video "OpenCV Basics"
    void createKnownBoardPositions(vector<Point3f>& corners, Size size, float squareSize, Settings::Pattern pattern, float xOrigin, float yOrigin);
    bool getCalibPatternCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showFoundCorners=false);
    void cameraCalibration(vector<Mat> calibrationImages, Size boardSize);
    void cameraCalibration(vector<vector<Point2f>> chessboardImageSpacePoints, vector<vector<Point3f>> worldSpaceCornerPoints, Size boardSize);
    double cameraCalibration(Size &imageSize);
    int doCalibrationExtrinsics(Mat &image);    // Function to get extrinsics
    void saveCameraCalibrationParameters();     // Save parameters to XML file
    Mat getUndistorted(Mat distorted, Mat cameraMatrix, Mat distCoeffs);
    Mat getUndistorted(Mat distorted);
    Mat remap(const Mat &distorted);
    int getID();
    void setContrast(int blackWhiteThreshold, int maxValue);
    double computeReprojectionErrors(vector<vector<Point3f>> &objectPoints,
                                     vector<vector<Point2f> > &imagePoints,
                                     vector<Mat> &rvecs, vector<Mat> &tvecs,
                                     Mat &cameraMatrix, Mat &distCoeffs);
    int addCirclePoints(const std::vector<Mat>& imageList); // Source: Maaß
    void addPoints(const vector<Point2f>& pointBuf, const vector<Point3f>& circlePoints3d); // Source: Maaß

public:
    int id;                     // Windows ID of the camera
    int nr;                     // Number of camera in the camera field
    Settings *s;                // Reference to Settings-class

    Mat cameraMatrix;           // intrinsic parameters
    Mat distCoeffs;             // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
    Mat rvec;                   // rotation vectors estimated for extrinsics (TODO: in Settings einarbeiten)
    Mat tvec;                   // translation vectors estimated for extrinsics (TODO: in Settings einarbeiten)
    vector<Mat> rvecs;          // rotation vectors estimated for each pattern view (TODO: aus Settings entfernen)
    vector<Mat> tvecs;          // translation vectors estimated for each pattern view (TODO: aus Settings entfernen)

    int blackWhiteThreshold;    // Threshold gained by slider in "Contrast Window"
    int maxValue;               // Max value gained by slider in "Contrast Window"

    vector< vector<Point3f> > objectPoints; // real world 3D coordinates
    vector< vector<Point2f> > imagePoints;  // 2D coordinates (pixel values)

    bool mustInitUndistort;     // Flag to avoid unnessesary Mapping operations
    Mat map1, map2;             // Mapping functions for undistorting

};

#endif // CAMERA_H
