/** CAMERA Class
  * used for calibrating camera
  *
  * Sources:
  * https://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html#calibratecamera
  * https://docs.opencv.org/3.0-beta/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html
  * https://www.youtube.com/watch?v=GYIQiV9Aw74&t=305s
  * http://aishack.in/tutorials/calibrating-undistorting-opencv-oh-yeah/
  *
  * ####### Passwort Softwareinstallateur PC VPJ Raum: eckehaard #######
  */

#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
//#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
//#include "cameracontrast.h"

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
    Camera(int nr, int id, Ui::MainWindow *ui, Settings *s);


    // According to George Lecaces Youtube video "OpenCV Basics"
    void createKnownBoardPositions(vector<Point3f>& corners, Size size, float squareSize, Settings::Pattern pattern);
    bool getCalibPatternCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showFoundCorners=false);
    void cameraCalibration(vector<Mat> calibrationImages, Size boardSize);
    void cameraCalibration(vector<vector<Point2f>> chessboardImageSpacePoints, vector<vector<Point3f>> worldSpaceCornerPoints, Size boardSize);
    int doCalibrationIntrinsics();              // Function to get intrinsics
    int doCalibrationExtrinsics();              // Function to get extrinsics
    void saveCameraCalibrationParameters();     // Save parameters to XML file
    Mat showUndistorted(Mat distorted);         // get and show undistorted picture to compare to distorted one
    // TODO: Reprojection-Error calculation
    int getID();
    void setContrast(int blackWhiteThreshold, int maxValue);
    double computeReprojectionErrors(vector<vector<Point3f>> &objectPoints,
                              vector<Point2f> &imagePoints,
                              vector<Mat> &rvecs, vector<Mat> &tvecs,
                              Mat &cameraMatrix, Mat &distCoeffs);


private:
    int id;                     // Windows ID of the camera
    int nr;                     // Number of camera in the camera field
    Ui::MainWindow *ui;
    Settings *s;

    Mat cameraMatrix;           // intrinsic parameters
    Mat distCoeffs;             // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
    vector<Mat> rvecs;          // rotation vectors estimated for each pattern view
    vector<Mat> tvecs;          // translation vectors estimated for each pattern view

    int blackWhiteThreshold;    // Threshold gained by slider in "Contrast Window"
    int maxValue;               // Max value gained by slider in "Contrast Window"

};

#endif // CAMERA_H
