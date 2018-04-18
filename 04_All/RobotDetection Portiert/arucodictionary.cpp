#include "arucodictionary.h"
#include <QDebug>

ArucoDictionary::ArucoDictionary() {

}
ArucoDictionary::ArucoDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME baseDict) {
    this->baseDict = baseDict;
    cv::Ptr<cv::aruco::Dictionary> tempDict = cv::aruco::getPredefinedDictionary(this->baseDict);
    this->markerBits = tempDict->markerSize;
    generateDict();
}
ArucoDictionary::ArucoDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME baseDict, int markerCount) {
    this->baseDict = baseDict;
    this->markerCount = markerCount;
    cv::Ptr<cv::aruco::Dictionary> tempDict = cv::aruco::getPredefinedDictionary(this->baseDict);
    this->markerBits = tempDict->markerSize;
    generateDict();
}
ArucoDictionary::ArucoDictionary(int markerBits){
    this->markerBits = markerBits;
}
ArucoDictionary::ArucoDictionary(int markerBits, int markerCount){
    this->markerBits = markerBits;
    this->markerCount = markerCount;
    generateDict();
}

void ArucoDictionary::setMarkerCount(int markerCount) {
    this->markerCount = markerCount;
    generateDict();
}

void ArucoDictionary::setNameById(int ID, QString Name) {
    arucoIdNameMap.insert(ID, Name);
}

void ArucoDictionary::setHeightById(int ID, float Height){
    arucoIdHeightMap.insert(ID, Height);
}

QString ArucoDictionary::getNameById(int ID) {
    if (arucoIdNameMap.contains(ID)) {
        return arucoIdNameMap.value(ID);
    } else {
        return QString("");
    }
}

float ArucoDictionary::getHeightById(int ID) {
    if (arucoIdHeightMap.contains(ID)) {
        return arucoIdHeightMap.value(ID);
    } else {
        return defaultHeight;
    }
}

int ArucoDictionary::getMarkerCount() {
    return this->markerCount;
}
int ArucoDictionary::getMarkerBits() {
    return this->markerBits;
}
void ArucoDictionary::add(int count) {
    if (count > 0) {
        markerCount = markerCount + count;
    } else if (count < 0) {
        markerCount = markerCount + count;
        if (markerCount < 0) {
            markerCount = 0;
        }
    }
    generateDict();
}

void ArucoDictionary::remove(int count) {
    add(-1*count);
}

cv::Ptr<cv::aruco::Dictionary> ArucoDictionary::get() {
    return dictionary;
}

void ArucoDictionary::generateDict() {
    cv::Ptr<cv::aruco::Dictionary> tempDict = cv::aruco::getPredefinedDictionary(this->baseDict);
    dictionary = tempDict;
    //dictionary = cv::aruco::generateCustomDictionary(markerCount, markerBits, tempDict);
}

bool ArucoDictionary::save(QString Path) {
    QFile mapFile(Path);
    if (!mapFile.open(QIODevice::WriteOnly))
    {
        false;
    }

    QDataStream out(&mapFile);
    out.setVersion(QDataStream::Qt_5_9);
    out << arucoIdNameMap;
    out << arucoIdHeightMap;
    out << baseDict;
    out << markerBits;
    out << markerCount;
    return true;
}

bool ArucoDictionary::load(QString Path) {
    QFile mapFile(Path);
    QDataStream in(&mapFile);
    in.setVersion(QDataStream::Qt_5_9);

    if (!mapFile.open(QIODevice::ReadOnly))
    {
        return false;
    }
    in >> arucoIdNameMap >> arucoIdHeightMap >> baseDict >> markerBits >> markerCount;
    generateDict();
    return true;
}

bool ArucoDictionary::draw(QString Path, QString NamePrefix, int Size) {
    try {
        cv::Mat Marker;
        cv::aruco::Dictionary* DictObject;
        DictObject = dictionary.get();
        for (int i = 0; i<DictObject->bytesList.rows; i++)
        {
            cv::aruco::drawMarker(dictionary, i, Size, Marker);
            cv::imwrite((Path+NamePrefix+QString("%1.png")).arg(i).toUtf8().constData(), Marker);
        }
    } catch (...) {
        return false;
    }
    return true;
}

bool ArucoDictionary::drawSingle(QString Path, QString NamePrefix, int ID, int Size) {
    try {
        cv::Mat Marker;
        cv::aruco::drawMarker(dictionary, ID, Size, Marker);
        cv::imwrite((Path+NamePrefix+QString("%1.png")).arg(ID).toUtf8().constData(), Marker);
    } catch (...) {
        return false;
    }
    return true;
}

cv::Ptr<cv::aruco::Dictionary> ArucoDictionary::loadDict(QString Path) {
    cv::aruco::Dictionary Dictionary;
    try {
        cv::FileStorage Storage(Path.toUtf8().constData(), cv::FileStorage::READ);
        int MSize, MCBits;
        cv::Mat BytesList;
        Storage["MarkerSize"] >> MSize;
        Storage["MaxCorrectionBits"] >> MCBits;
        Storage["ByteList"] >> BytesList;
        Storage.release();
        Dictionary = cv::aruco::Dictionary(BytesList, MSize, MCBits);
    } catch (...) {
        cv::Ptr<cv::aruco::Dictionary> Empty;
        return Empty;
    }
    return cv::makePtr<cv::aruco::Dictionary>(Dictionary);
}

bool ArucoDictionary::saveDict(cv::aruco::Dictionary Dict, QString Path) {
    try {
        cv::FileStorage Storage(Path.toUtf8().constData(), cv::FileStorage::WRITE);
        Storage << "MarkerSize" << Dict.markerSize;
        Storage << "MaxCorrectionBits" << Dict.maxCorrectionBits;
        Storage << "ByteList" << Dict.bytesList;
        Storage.release();
    } catch (...) {
        return false;
    }
    return true;
}

