#ifndef CAMCALIBRATION_H
#define CAMCALIBRATION_H

#include <QWidget>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdio>

#include <opencv2/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "mainwindow.h"

using namespace cv;
using namespace std;
enum { DETECTION = 0, CAPTURING = 1, CALIBRATED = 2 };

class CamCalibration : public QWidget
{
    Q_OBJECT
public:

    explicit CamCalibration(QWidget *parent = nullptr);
    void setUI(Ui::MainWindow* Ui);
    //static inline void read(const FileNode& node, Settings& x, const Settings& default_value = Settings());
    //static inline void write(FileStorage& fs, const String&, const Settings& s );
    static double computeReprojectionErrors( const vector<vector<Point3f> >& objectPoints,
                                             const vector<vector<Point2f> >& imagePoints,
                                             const vector<Mat>& rvecs, const vector<Mat>& tvecs,
                                             const Mat& cameraMatrix , const Mat& distCoeffs,
                                             vector<float>& perViewErrors, bool fisheye);
   // static void calcBoardCornerPositions(Size boardSize, float squareSize, vector<Point3f>& corners,
    //                                     Settings::Pattern patternType /*= Settings::CHESSBOARD*/);
    //static bool runCalibration( Settings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
    //                            vector<vector<Point2f> > imagePoints, vector<Mat>& rvecs, vector<Mat>& tvecs,
    //                            vector<float>& reprojErrs,  double& totalAvgErr);
    //static void saveCameraParams( Settings& s, Size& imageSize, Mat& cameraMatrix, Mat& distCoeffs,
    //                              const vector<Mat>& rvecs, const vector<Mat>& tvecs,
    //                              const vector<float>& reprojErrs, const vector<vector<Point2f> >& imagePoints,
    //                              double totalAvgErr );
    //bool runCalibrationAndSave(Settings& s, Size imageSize, Mat& cameraMatrix, Mat& distCoeffs,
    //                           vector<vector<Point2f> > imagePoints);


private:
    Ui::MainWindow* ui;

signals:

public slots:
    void help();
    int doCalibration();
};

#endif // CAMCALIBRATION_H
