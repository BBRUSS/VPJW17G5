#include "mainwindow.h"
#include "main.h"
#include <QApplication>

#include <sstream>
#include <iostream>
#include <fstream>

#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>




void cameraCalibration(vector<Mat> calibrationImages, Size boardSize, float squareEdgeLength, Mat& cameraMatrix, Mat& distanceCoefficients)
{
    vector<vector<Point2f>> checkerboardImageSpacePoints;
    getChessboardCorners(calibrationImages, checkerboardImageSpacePoints, false);

    vector<vector<Point3f>> worldSpaceCornerPoints(1);
    createKnownBoardPosition(boardSize, squareEdgeLength, worldSpaceCornerPoints[0]);
    worldSpaceCornerPoints.resize(checkerboardImageSpacePoints.size(), worldSpaceCornerPoints[0]);

    vector<Mat> rVectors, tVectors;
    distanceCoefficients = Mat::zeros(8, 1, CV_64F);

    calibrateCamera(worldSpaceCornerPoints, checkerboardImageSpacePoints, boardSize, cameraMatrix, distanceCoefficients, rVectors, tVectors);


}

void createKnownBoardPosition(cv::Size boardSize, float squareEdgeLength, vector<Point3f>& corners)
{
    for(int i = 0; i < boardSize.height; i++)
    {
        for(int j = 0; j < boardSize.width; j++)
        {
            corners.push_back(Point3f(j*squareEdgeLength, i*squareEdgeLength, 0.0f));
        }
    }
}


void getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showResult = false)
{
    for(vector<Mat>::iterator iter = images.begin(); iter  != images.end(); iter++)
    {
        vector<Point2f> pointBuf;
        bool found = findChessboardCorners(*iter, cv::Size(9,6), pointBuf, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        if(found)
        {
            allFoundCorners.push_back(pointBuf);
        }

        if(showResult)
        {
            drawChessboardCorners(*iter, Size(9,6), pointBuf, found);
            imshow("Looking for Corners", *iter);
            waitKey(0);
        }
    }
}

bool saveCameraCalibration(string name, Mat cameraMatrix, Mat distanceCoefficients)
{
    ofstream outStream(name);
    if(outStream)
    {
        uint16_t rows = cameraMatrix.rows;
        uint16_t columns = cameraMatrix.cols;

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                double value = cameraMatrix.at<double>(r, c);
                outStream << value << endl;
            }
        }

        rows = distanceCoefficients.rows;
        columns = distanceCoefficients.cols;

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < columns; c++)
            {
                double value = distanceCoefficients.at<double>(r, c);
                outStream << value << endl;
            }
        }
        outStream.close();
        return true;
    }
    return false;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Mat frame;
    Mat drawToFrame;
    Mat cameraMatrix = Mat::eye(3,3, CV_64F);
    Mat distanceCoefficients;

    vector<Mat> savedImages;

    VideoCapture vid(1);
    if(!vid.isOpened())
    {
        printf("No Camera found!\n");
        return 0;
    }

    int framesPerSecond = 20;
    namedWindow("Webcam", CV_WINDOW_AUTOSIZE);
    while(true)
    {
        if(!vid.read(frame))
            break;
        vector<Vec2f> foundPoints;
        bool found = false;

        found = findChessboardCorners(frame, chessboardDimensions, foundPoints, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        frame.copyTo(drawToFrame);
        drawChessboardCorners(drawToFrame, chessboardDimensions, foundPoints, found);
        if(found)
            imshow("Webcam", drawToFrame);
        else
            imshow("Webcam", frame);
        char character = waitKey(1000 / framesPerSecond);   // char = waitkey(delay_ms)

        switch(character)
        {
        case ' ':
            printf("saving image");
            //Ui.saveImagesFromGUI(found, frame, savedImages) ;
            break;
        case 13:    // (Enter)
            printf("start calibration");
            //Ui.startCalibrationFromGUI(savedImages, chessboardDimensions, calibrationSquareDimension, cameraMatrix, distanceCoefficients);
            break;
        case 27:    // (Esc)
            printf("exit");
            return 0;
            break;
        }

    }

    return a.exec();
}


