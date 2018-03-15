#ifndef SETTINGS_H
#define SETTINGS_H

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

class Settings
{
public:
    Settings();
    enum Pattern { NOT_EXISTING, CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };

    // Global Settings
    Size boardSize;                 // The size of the board -> Number of items by width and height
    Pattern calibrationPattern;     // One of the Chessboard, circles, or asymmetric circle pattern
    float squareSize;               // The size of a square in your defined unit (point, millimeter,etc).
    int nrFrames;                   // The number of frames to use from the input for calibration
    string outputFileName;          // The name of the file where to write

    // Camera-depending settings (later in struct)
    bool calibFixAspectratio;       // Assume fix aspect ratio (usual for lens cameras)
    bool calibZeroTangentDist;      // Assume zero tangential distortion
    bool calibFixPrincipalPoint;    // Fix the principal point at the center
    bool showUndistorsed;           // Show undistorted images after calibration (Do we really need that in Settings?)
    int cameraID;
    int calibFlag;                  // Flag(s) for calibration
    Mat cameraMatrix;               // intrinsic parameters
    Mat distCoeffs;                 // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
    Mat rvecs;                      // rotation vectors estimated for each pattern view
    Mat tvecs;                      // translation vectors estimated for each pattern view

    int blackWhiteThreshold;        // Threshold gained by slider in "Contrast Window"
    int maxValue;                   // Max value gained by slider in "Contrast Window"


    /*if(calibFixPrincipalPoint)    flag |= CV_CALIB_FIX_PRINCIPAL_POINT;
    if(calibZeroTangentDist)        flag |= CV_CALIB_ZERO_TANGENT_DIST;
    if(calibFixAspectratio)         flag |= CV_CALIB_FIX_ASPECT_RATIO;*/

};

#endif // SETTINGS_H
