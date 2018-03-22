#include "settings.h"

Settings::Settings(){                                   // Default constructor (no argument)
}

void Settings::write(FileStorage& fs) const{            //Write serialization for this class

    string patternToUse;

    switch (calibrationPattern){
    case Settings::CHESSBOARD:
        patternToUse = "CHESSBOARD";
        break;
    case Settings::CIRCLES_GRID:
        patternToUse = "CIRCLES_GRID";
        break;
    case Settings::ASYMMETRIC_CIRCLES_GRID:
        patternToUse = "ASYMMETRIC_CIRCLES_GRID";
        break;
    default:
        patternToUse = "NOT_EXISTING";
        break;
    };

    fs << "{";

    //    Global Settings
    fs << "boardSize" << boardSize;
    fs << "camFieldSize" << camFieldSize;
    fs << "patternToUse" << patternToUse;
    fs << "squareSize" << squareSize;
    fs << "nrFrames" << nrFrames;

    //    Camera Settings
    for (int i = 0; i<camFieldSize.area(); i++){
        string cam_ID = "cam_" ;
        cam_ID += to_string(cams.at(i)->cameraID);

        fs << cam_ID << "{";

        fs << "calibFixAspectratio" << cams.at(i)->calibFixAspectratio;
        fs << "calibZeroTangentDist" << cams.at(i)->calibZeroTangentDist;
        fs << "calibFixPrincipalPoint" << cams.at(i)->calibFixPrincipalPoint;
        fs << "showUndistorsed" << cams.at(i)->showUndistorsed;
        fs << "cameraID" << cams.at(i)->cameraID;
        fs << "calibFlag" << cams.at(i)->calibFlag;
        fs << "cameraMatrix" << cams.at(i)->cameraMatrix;
        fs << "distCoeffs" << cams.at(i)->distCoeffs;
        fs << "rvecs" << cams.at(i)->rvecs;
        fs << "tvecs" << cams.at(i)->tvecs;
        fs << "blackWhiteThreshold" << cams.at(i)->blackWhiteThreshold;
        fs << "maxValue" << cams.at(i)->maxValue;

        fs << "}";
    }

    //    Navigation Settings
    fs << "UDPSettings" << "{";
    fs << "sendToIP" << udpStruct.sendToIp;
    fs << "sendToPort" << udpStruct.sendToPort;
    fs << "sendToIp_SyncService" << udpStruct.sendToIp_SyncService;
    fs << "sendToPort_SyncService" << udpStruct.sendToPort_SyncService;
    fs << "reciveIp_SyncService" << udpStruct.reciveIp_SyncService;
    fs << "recivePort_SyncService" << udpStruct.recivePort_SyncService;
    fs << "}";

    fs << "timerMilSecs" << timerMilSecs;
    fs << "cornerRefinementMaxIterations" << cornerRefinementMaxIterations;
    fs << "cornerRefinementMinAccuracy" << cornerRefinementMinAccuracy;
    fs << "errorCorrectionRate" << errorCorrectionRate;
    fs << "adaptiveThreshWinSizeMin" << adaptiveThreshWinSizeMin;
    fs << "adaptiveThreshWinSizeStep" << adaptiveThreshWinSizeStep;
    fs << "adaptiveThreshConstant" << adaptiveThreshConstant;
    fs << "minMarkerPerimeterRate" << minMarkerPerimeterRate;
    fs << "slider_maxMarkerPerimeterRate" << slider_maxMarkerPerimeterRate;
    fs << "slider_polygonalApproxAccuracyRate" << slider_polygonalApproxAccuracyRate;
    fs << "slider_perspectiveRemovePixelPerCell" << slider_perspectiveRemovePixelPerCell;
    fs << "threshold" << threshold;
    fs << "MinSizeofRects" << MinSizeofRects;

    fs << "}";
}

void Settings::read(const FileNode& node){              //Read serialization for this class

    string patternToUse;

    //    Global Settings
    node["boardSize"] >> boardSize;
    node["camFieldSize"] >> camFieldSize;
    this->setCamFieldSize(this->camFieldSize);
    node["patternToUse"] >> patternToUse;
    node["squareSize"] >> squareSize;
    node["nrFrames"] >> nrFrames;

    //    Camera Settings
    for (int i = 0; i<camFieldSize.area(); i++){
        string actCam = "cam_" ;
        actCam += to_string(i);

        FileNode nodeActCam;
        nodeActCam = node[actCam];

        nodeActCam["calibFixAspectratio"] >> cams.at(i)->calibFixAspectratio;
        nodeActCam["calibZeroTangentDist"] >> cams.at(i)->calibZeroTangentDist;
        nodeActCam["calibFixPrincipalPoint"] >> cams.at(i)->calibFixPrincipalPoint;
        nodeActCam["showUndistorsed"] >> cams.at(i)->showUndistorsed;
        nodeActCam["cameraID"] >> cams.at(i)->cameraID;
        nodeActCam["calibFlag"] >> cams.at(i)->calibFlag;
        nodeActCam["cameraMatrix"] >> cams.at(i)->cameraMatrix;
        nodeActCam["distCoeffs"] >> cams.at(i)->distCoeffs;
        nodeActCam["rvecs"] >> cams.at(i)->rvecs;
        nodeActCam["tvecs"] >> cams.at(i)->tvecs;
        nodeActCam["blackWhiteThreshold"] >> cams.at(i)->blackWhiteThreshold;
        nodeActCam["maxValue"] >> cams.at(i)->maxValue;
        qDebug() << "l" << i+1;
    }

    calibrationPattern = Settings::NOT_EXISTING;
    if (!patternToUse.compare("CHESSBOARD")) calibrationPattern = Settings::CHESSBOARD;
    else if (!patternToUse.compare("CIRCLES_GRID")) calibrationPattern = Settings::CIRCLES_GRID;
    else if (!patternToUse.compare("ASYMMETRIC_CIRCLES_GRID")) calibrationPattern = Settings::ASYMMETRIC_CIRCLES_GRID;

    //    Navigation Settings
    FileNode nodeUDP;
    nodeUDP = node["UDPSettings"];

    nodeUDP["sendToIP"] >> udpStruct.sendToIp;
    nodeUDP["sendToPort"] >> udpStruct.sendToPort;
    nodeUDP["sendToIp_SyncService"] >> udpStruct.sendToIp_SyncService;
    nodeUDP["sendToPort_SyncService"] >> udpStruct.sendToPort_SyncService;
    nodeUDP["reciveIp_SyncService"] >> udpStruct.reciveIp_SyncService;
    nodeUDP["recivePort_SyncService"] >> udpStruct.recivePort_SyncService;

    node["timerMilSecs"] >> timerMilSecs;
    node["cornerRefinementMaxIterations"] >> cornerRefinementMaxIterations;
    node["cornerRefinementMinAccuracy"] >> cornerRefinementMinAccuracy;
    node["errorCorrectionRate"] >> errorCorrectionRate;
    node["adaptiveThreshWinSizeMin"] >> adaptiveThreshWinSizeMin;
    node["adaptiveThreshWinSizeStep"] >> adaptiveThreshWinSizeStep;
    node["adaptiveThreshConstant"] >> adaptiveThreshConstant;
    node["minMarkerPerimeterRate"] >> minMarkerPerimeterRate;
    node["slider_maxMarkerPerimeterRate"] >> slider_maxMarkerPerimeterRate;
    node["slider_polygonalApproxAccuracyRate"] >> slider_polygonalApproxAccuracyRate;
    node["slider_perspectiveRemovePixelPerCell"] >> slider_perspectiveRemovePixelPerCell;
    node["threshold"] >> threshold;
    node["MinSizeofRects"] >> MinSizeofRects;
}

void Settings::save(){                                  //save with write serialization for this class

    FileStorage fs(this->filename, FileStorage::WRITE);
    fs << "Settings"<< *this;
    fs.release();
}

int Settings::load(){                                   //laode with read serialization for this class

    FileStorage fs(this->filename, FileStorage::READ);

    if (!fs.isOpened()){
        fs.release();
        return 1;
    }

    fs["Settings"] >> *this;
    fs.release();
    return 0;
}

void Settings::setCamFieldSize(Size camFieldSize){

    this->camFieldSize = camFieldSize;
    cams.clear();

    for(int i=0; i<this->camFieldSize.area(); i++){
        cams.push_back(new cam);
    }
}
