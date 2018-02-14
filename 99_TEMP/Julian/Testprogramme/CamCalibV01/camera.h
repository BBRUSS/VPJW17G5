/** CAMERA Class
  * used for calibrating camera
  *
  * https://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html#calibratecamera
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
    Mat getInputPic();
    Mat getUndistortedPic();
    bool calibrate();
    void showChessboardPattern(Size imageSize, Mat view);

    // According to George Lecaces Youtube video "OpenCV Basics"
    void createKnownBoardPositions(vector<Point3f>& corners);
    void getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showFoundCorners=false);
    void cameraCalibration(vector<Mat> calibrationImages, Size boardSize/*, Mat& cameraMatrix, Mat& distCoeffs*/);
    int doCalibration();
    void saveCameraCalibrationParameters();



private:
    bool runCalibration();
    void calcBoardCornerPositions(vector<Point3f>& corners);
    Mat nextImage();

    int id;
    Ui::MainWindow *ui;
    Settings *s;

    Mat cameraMatrix;       // intrinsic parameters
    Mat distCoeffs;         // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
    //bool found;             // found calibration pattern?
    VideoCapture inputCapture;
    //vector<vector<Point3f> > objectPoints;   // hold position of calibration pattern objects
    vector<vector<Point2f> > imagePoints;       // projection if calibration pattern points
    Size imageSize;                             // view image size (used to initialize the intrinsic camera matrix
    vector<Mat> rvecs;                          // rotation vectors estimated for each pattern view
    vector<Mat> tvecs;                          // translation vectors estimated for each pattern view

    // According to George Lecaces Youtube video "OpenCV Basics"
    //vector<Point3f> corners;        // store information of corner position in calibration pattern (world space)
    //vector<Vec2f> foundPoints;      // store cornerpoints found in video image (image space)
};

#endif // CAMERA_H
