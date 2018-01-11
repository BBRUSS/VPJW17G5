#ifndef MAIN_H
#define MAIN_H

using namespace cv;
using namespace std;

const float calibrationSquareDimension = 0.02305f;  // meters
//const float arucoSquareDimension = 0.1016f;         // meters
const cv::Size chessboardDimensions = cv::Size(9, 6);

void cameraCalibration(vector<Mat> calibrationImages, Size boardSize, float squareEdgeLength, Mat& cameraMatrix, Mat& distanceCoefficients);
void createKnownBoardPosition(cv::Size boardSize, float squareEdgeLength, vector<Point3f>& corners);
void getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showResult);
bool saveCameraCalibration(string name, Mat cameraMatrix, Mat distanceCoefficients);
void saveImagesFromGUI(bool found, Mat& frame, vector<Mat>& savedImages);
void startCalibrationFromGUI(vector<Mat> savedImages, Size chessboardDimensions, float calibrationSquareDimension, Mat& cameraMatrix, Mat& distanceCoefficients);



#endif // MAIN_H
