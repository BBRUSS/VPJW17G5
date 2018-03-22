#ifndef ARUCODICTIONARY_H
#define ARUCODICTIONARY_H

#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <QObject>
#include <QMap>
#include <QFile>
#include <QDataStream>

class ArucoDictionary
{
public:
    ArucoDictionary();
    ArucoDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME baseDict);
    ArucoDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME baseDict, int markerCount);
    ArucoDictionary(int markerBits);
    ArucoDictionary(int markerBits, int markerCount);



    bool save(QString Path);
    bool load(QString Path);

    bool draw(QString Path, QString NamePrefix, int Size = 1000);
    bool drawSingle(QString Path, QString NamePrefix, int ID, int Size = 1000);

    void setNameById(int ID, QString Name);
    QString getNameById(int ID);

    void setMarkerCount(int markerCount);
    int getMarkerCount();
    int getMarkerBits();


    void add(int count = 1);
    void remove(int count = 1);
    cv::Ptr<cv::aruco::Dictionary> get();
private:
    void generateDict();
    bool saveDict(cv::aruco::Dictionary Dict, QString Path);
    cv::Ptr<cv::aruco::Dictionary> loadDict(QString Path);

    QMap<int, QString> arucoIdNameMap;
    int baseDict;
    cv::Ptr<cv::aruco::Dictionary> dictionary;
    int markerBits = 10;
    int markerCount = 0;

};

#endif // ARUCODICTIONARY_H


