#ifndef SETTINGS_H
#define SETTINGS_H

#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>
#include <QDebug>

using namespace cv;
using namespace std;

class Settings{

    // Data in Settings

public:

    enum Pattern { NOT_EXISTING, CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };

    struct cam
    {
        int calibFixAspectratio;        // Assume fix aspect ratio (usual for lens cameras)
        int calibZeroTangentDist;       // Assume zero tangential distortion
        int calibFixPrincipalPoint;     // Fix the principal point at the center
        bool showUndistorsed;           // Show undistorted images after calibration (Do we really need that in Settings?)
        int cameraID;                   // Camera windows id
        int calibFlag;                  // Flag(s) for calibration
        Mat cameraMatrix;               // intrinsic parameters
        Mat distCoeffs;                 // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
        Mat rvecs;                      // rotation vectors estimated for each pattern view
        Mat tvecs;                      // translation vectors estimated for each pattern view
        int blackWhiteThreshold;        // Threshold gained by slider in "Contrast Window"
        int maxValue;                   // Max value gained by slider in "Contrast Window"
    };

    const string filename = "settings.xml"; // The name of the file where to write

    // Global Settings
    Size boardSize;                     // The size of the board -> Number of items by width and height
    Size camFieldSize;                  // The size of camara field
    Pattern calibrationPattern;         // One of the Chessboard, circles, or asymmetric circle pattern
    float squareSize;                   // The size of a square in your defined unit (point, millimeter,etc).
    int nrFrames;                       // The number of frames to use from the input for calibration

    // Camera Settings
    vector<cam*> cams;


    // Methods in Settings

public:

    // Default constructor (no argument)
    Settings();

    // Write serialization for this class
    void write(FileStorage& fs) const;

    // Read serialization for this class
    void read(const FileNode& node);

    // save with write serialization for this class
    void save();

    // laode with read serialization for this class
    int load();

    //
    void setCamFieldSize(Size camFieldSize);
};

//These write and read functions must be defined for the serialization in FileStorage to work

static void write(FileStorage& fs, const std::string&, const Settings& x){

    x.write(fs);
}

static void read(const FileNode& node, Settings& x, const Settings& default_value = Settings()){

    x.read(node);
}

#endif // SETTINGS_H
