#ifndef SETTINGS_H
#define SETTINGS_H

#include <opencv2/core/core.hpp>
#include <iostream>
#include <string>
#include <QString>

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
//    void save(FileStorage& fs);

    //laode with read serialization for this class
//    void loade(const FileNode& node);

    // Data in Settings

public:

    const string filename = "test.xml";
    int test;
};

//evtl write and read in setting.h
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
