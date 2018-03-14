#ifndef SETTINGS_H
#define SETTINGS_H

#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>
#include <QString>
#include <QObject>

using namespace cv;
using namespace std;

class Settings
{

    // Methods in Settings

public:

    // Default constructor (no argument)
    Settings();

    // Constructor with test
    Settings(int test);

    // Copykonstruktor
    //    Settings(const Settings& orig);

    // Assignment operator
    Settings& operator=(const Settings & orig);

    //Write serialization for this class
    void write(FileStorage& fs) const;

    //Read serialization for this class
    void read(const FileNode& node);

    //save with write serialization for this class
    //    void save(QWidge);

    //laode with read serialization for this class
    //    void loade(const FileNode& node);



    //public slots:
    //    void save();

    // Data in Settings
public:
    const string filename = "settings.xml";
    int test;

    enum Pattern { NOT_EXISTING, CHESSBOARD, CIRCLES_GRID, ASYMMETRIC_CIRCLES_GRID };

    // Global Settings
    Size boardSize;                 // The size of the board -> Number of items by width and height
    Size camFieldSize;              // The size of camara field
    Pattern calibrationPattern;     // One of the Chessboard, circles, or asymmetric circle pattern
    float squareSize;               // The size of a square in your defined unit (point, millimeter,etc).
    int nrFrames;                   // The number of frames to use from the input for calibration
    string outputFileName;          // The name of the file where to write

    // Camera-depending settings (later in struct)
    struct cams
    {
        bool calibFixAspectratio;       // Assume fix aspect ratio (usual for lens cameras)
        bool calibZeroTangentDist;      // Assume zero tangential distortion
        bool calibFixPrincipalPoint;    // Fix the principal point at the center
        bool showUndistorsed;           // Show undistorted images after calibration (Do we really need that in Settings?)
        int cameraID;
        int calibFlag;                  // Flag(s) for calibration
    };


};

//These write and read functions must be defined for the serialization in FileStorage to work

static void write(FileStorage& fs, const std::string&, const Settings& x)
{
    x.write(fs);
}

static void read(const FileNode& node, Settings& x, const Settings& default_value = Settings())
{
    if(node.empty())
        // what will be done if node is empty. here x is equal to a default instance
        x = default_value;
    else
        x.read(node);
}

#endif // SETTINGS_H
