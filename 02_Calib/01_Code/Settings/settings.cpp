#include "settings.h"

#include <QDebug>
#include <QObjectList>
#include <QList>

// Default constructor (no argument)
Settings::Settings()//:test(42)
{
    //    1. lade variablen aus Datei
    //    2. Plausibilitätsprüfung
}

Settings::Settings(int test):test(test)
{}

/*// Copykonstruktor
Settings :: Settings(const Settings& orig)
{
    this->test = orig.test;
}*/

// Zuweisungsoperator
Settings& Settings :: operator=(const Settings & orig)
{
    if ( &orig != this ) // test
    {
    }
    return *this;
}

void Settings::write(FileStorage& fs) const                        //Write serialization for this class
{

    fs << "{";
    fs << "boardSize" << boardSize;
    fs << "}";
}

void Settings::read(const FileNode& node)                          //Read serialization for this class
{
    test = (int)node["test"];
    boardSize = (Size)node["boardSize"];
}
