/** CAMERA Class
  * used for calibrating camera
  *
  * Sources:
  * https://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html#calibratecamera
  * https://docs.opencv.org/3.0-beta/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html
  * https://www.youtube.com/watch?v=GYIQiV9Aw74&t=305s
  * http://aishack.in/tutorials/calibrating-undistorting-opencv-oh-yeah/
  *
  */

#ifndef CAMERA_H
#define CAMERA_H

#include <QMainWindow>
#include <QObject>
//#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"

#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>

using namespace cv;
using namespace std;

class Camera : public QMainWindow
{
    Q_OBJECT
public:
    Camera();
    Camera(int id, Ui::MainWindow *ui, Settings *s);


    // According to George Lecaces Youtube video "OpenCV Basics"
    void createKnownBoardPositions(vector<Point3f>& corners);
    bool getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showFoundCorners=false);
    void cameraCalibration(vector<Mat> calibrationImages, Size boardSize);
    int doCalibration();
    void saveCameraCalibrationParameters();
    Mat showUndistorted(Mat distorted);
    // Mat getBlackWhiteOptimatedPicture()
    // TODO: Reprojection-Error calculation



private:
    int id;
    Ui::MainWindow *ui;
    Settings *s;

    Mat cameraMatrix;           // intrinsic parameters
    Mat distCoeffs;             // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
    vector<Mat> rvecs;          // rotation vectors estimated for each pattern view
    vector<Mat> tvecs;          // translation vectors estimated for each pattern view

    // TODO: Weitere Variablen für Kontrasteinstellung etc.
};

#endif // CAMERA_H
