#ifndef CAMERA_H
#define CAMERA_H
#include "mainwindow.h"
#include "settings.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;
using namespace std;

enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };


class Camera : public QMainWindow
{
    Q_OBJECT
public:
    Camera(int id, Ui::MainWindow *ui);
   /*static*/ double computeReprojectionErrors( const vector<vector<Point3f> >& objectPoints,
                                             const vector<vector<Point2f> >& imagePoints,
                                             const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                                             const Mat& cameraMatrix , const Mat& distCoeffs,
                                             vector<float>& perViewErrors);

    /*static*/ void calcBoardCornerPositions(Size boardSize, float squareSize, vector<Point3f>& corners,
                                         Settings::Pattern patternType /*= Settings::CHESSBOARD*/);

    /*static*/ bool runCalibration( Settings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
                                vector<vector<Point2f> > imagePoints, vector<Mat>& rvecs, vector<Mat>& tvecs,
                                vector<float>& reprojErrs,  double& totalAvgErr);

    /*static*/ void saveCameraParams( Settings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
                                  const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                                  const vector<float>& reprojErrs, const vector<vector<Point2f> >& imagePoints,
                                  double totalAvgErr );

    bool runCalibrationAndSave(Settings& s, Size imageSize, Mat&  cameraMatrix, Mat& distCoeffs,vector<vector<Point2f> > imagePoints );

public slots:
    int calibrate();

private:
    int id;
    Ui::MainWindow *ui;
};

#endif // CAMERA_H
