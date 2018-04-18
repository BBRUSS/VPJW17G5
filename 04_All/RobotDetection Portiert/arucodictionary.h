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
    void setHeightById(int ID, float Height);
    QString getNameById(int ID);
    float getHeightById(int ID);

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

    int defaultHeight = 300.0;
    cv::Ptr<cv::aruco::Dictionary> dictionary;

    QMap<int, QString> arucoIdNameMap;
    QMap<int, float> arucoIdHeightMap;
    int baseDict;
    int markerBits = 5;
    int markerCount = 2;

};

#endif // ARUCODICTIONARY_H


