#include "settings.h"

// Default constructor (no argument)
Settings::Settings():test(42)
{}

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
    //fs << "{" << "ebene1"; // öffnet XML-Bereich
        //fs << "{" << "ebene2";
            fs << "{";
                fs << "test" << this->test;
            fs << "}";
        //fs << "}";
    //fs << "}"; // schließt XML-Bereich
}

void Settings::read(const FileNode& node)                          //Read serialization for this class
{
    this->test = (int)node["test"];
}
