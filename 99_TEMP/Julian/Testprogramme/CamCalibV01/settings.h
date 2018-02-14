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


    Size boardSize;                 // The size of the board -> Number of items by width and height
    Pattern calibrationPattern;     // One of the Chessboard, circles, or asymmetric circle pattern
    float squareSize;               // The size of a square in your defined unit (point, millimeter,etc).
    int nrFrames;                   // The number of frames to use from the input for calibration
    float aspectRatio;              // The aspect ratio
    bool calibZeroTangentDist;      // Assume zero tangential distortion
    bool calibFixPrincipalPoint;    // Fix the principal point at the center
    string outputFileName;          // The name of the file where to write
    bool showUndistorsed;           // Show undistorted images after calibration
    int delay;                      // In case of a video input


    int cameraID;
    bool goodInput;
    int calibFlag;                  // Flag(s) for calibration

    /*if(calibFixPrincipalPoint) flag |= CV_CALIB_FIX_PRINCIPAL_POINT;
    if(calibZeroTangentDist)   flag |= CV_CALIB_ZERO_TANGENT_DIST;
    if(aspectRatio)            flag |= CV_CALIB_FIX_ASPECT_RATIO;*/

};

#endif // SETTINGS_H
