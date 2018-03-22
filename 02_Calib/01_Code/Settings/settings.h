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

    struct cam{

        bool calibFixAspectratio = 0;       // Assume fix aspect ratio (usual for lens cameras)
        bool calibZeroTangentDist = 0;      // Assume zero tangential distortion
        bool calibFixPrincipalPoint = 0;    // Fix the principal point at the center
        bool showUndistorsed = 0;           // Show undistorted images after calibration (Do we really need that in Settings?)
        int cameraID = -1;
        int calibFlag = 0;                  // Flag(s) for calibration
        Mat cameraMatrix;               // intrinsic parameters
        Mat distCoeffs;                 // (k1, k2, p1, p2 [,k3[, k4, k5, k6]]), not depending on resolution or view
        Mat rvecs;                      // rotation vectors estimated for each pattern view
        Mat tvecs;                      // translation vectors estimated for each pattern view
        int blackWhiteThreshold = -1;        // Threshold gained by slider in "Contrast Window"
        int maxValue = -1;                   // Max value gained by slider in "Contrast Window"
    };

    struct UDPSettings {

        string sendToIp = "192.168.0.255";
        int sendToPort = 25000;
        string sendToIp_SyncService = "192.168.0.255";
        int sendToPort_SyncService = 25110;
        string reciveIp_SyncService = "192.168.0.20";
        int recivePort_SyncService = 25111;
    };

    const string filename = "settings.xml"; // The name of the file where to write

    // Global Settings
    Size boardSize;                 // The size of the board -> Number of items by width and height
    Size camFieldSize;              // The size of camara field
    Pattern calibrationPattern;     // One of the Chessboard, circles, or asymmetric circle pattern
    float squareSize = 0.0;               // The size of a square in your defined unit (point, millimeter,etc).
    int nrFrames = 10;                   // The number of frames to use from the input for calibration

    // Camera Settings
    vector<cam*> cams;

    // Navidation Settings
    UDPSettings udpStruct;
    int timerMilSecs = 20;
    int cornerRefinementMaxIterations = 1;
    double cornerRefinementMinAccuracy = 10;
    double errorCorrectionRate = 511;
    int adaptiveThreshWinSizeMin = 10;
    int adaptiveThreshWinSizeStep = 99;
    int adaptiveThreshConstant = 10;
    double minMarkerPerimeterRate = 91;
    double slider_maxMarkerPerimeterRate = 300;
    double slider_polygonalApproxAccuracyRate = 11;
    int slider_perspectiveRemovePixelPerCell = 1;
    int threshold = 160;
    int MinSizeofRects = 8000;

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
