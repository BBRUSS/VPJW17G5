#include "mainwindow.h"
#include "camera_calibration.h"
#include <QApplication>
#include <stdint.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>

#include "opencv2/opencv.hpp"
#include <opencv2/core/utility.hpp>
#include "opencv2/calib3d.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/videoio.hpp>


using namespace cv;
using namespace std;

void lection1();
void lection2();
void lection3();
int lection4();
void lection5();
//void lection6();


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    calibCamera();


    return a.exec();
}

/** TUTORIAL George Lecakes' OpenCV Basics (Youtube) **/

/*************************************************************************************************/
/* Lection 1: Loading and Showing a picture from working directory                               */
/*************************************************************************************************/
void lection1()
{
    Mat pic = imread("logo.png", CV_LOAD_IMAGE_COLOR);
    Mat picGrey = imread("logo.png", CV_LOAD_IMAGE_GRAYSCALE);

    imshow("pic", pic);
    imshow("grey", picGrey);

    waitKey();
}

/*************************************************************************************************/
/* Lection 2: Accessing pixels in a picture                                                      */
/*************************************************************************************************/
void lection2()
{
    Mat original = imread("logo.png", CV_LOAD_IMAGE_GRAYSCALE);
    Mat modified = imread("logo.png", CV_LOAD_IMAGE_GRAYSCALE);

    // walk through every pixel and half the intensity
    for(int r = 0; r < modified.rows; r++)
    {
        for(int c = 0; c < modified.cols; c++)
        {
            modified.at<uint8_t>(r, c) = modified.at<uint8_t>(r, c) * 0.5f;
        }
    }

    imshow("Original", original);   // is bright
    imshow("Modified", modified);   // is darker because of half intensity
    waitKey();

    /* ---- now do the same with coloured picture ---- */
    original = imread("logo.png", CV_LOAD_IMAGE_COLOR);
    modified = imread("logo.png", CV_LOAD_IMAGE_COLOR);

    // walk through every pixel and kill the blue colour part
    for(int r = 0; r < modified.rows; r++)
    {
        for(int c = 0; c < modified.cols; c++)
        {
            // In OpenCV, it's BGR
            //modified.at<Vec3b>(r, c)[0] = modified.at<Vec3b>(r, c)[0] * 0;  // Blue
            //modified.at<Vec3b>(r, c)[1] = modified.at<Vec3b>(r, c)[1] * 0;  // Green
            modified.at<Vec3b>(r, c)[2] = modified.at<Vec3b>(r, c)[2] * 0;  // Red
        }
    }

    imshow("Original", original);   // is bright
    imshow("Modified", modified);   // is darker because of half intensity
    waitKey();
}


/*************************************************************************************************/
/* Lection 3: Split and Merge an image                                                           */
/*************************************************************************************************/
void lection3()
{
    Mat original = imread("logo.png", CV_LOAD_IMAGE_COLOR);
    Mat splitChannels[3];

    split(original, splitChannels); // Split image into the 3 colour matrices

    imshow("Original", original);
    imshow("B", splitChannels[0]);
    imshow("G", splitChannels[1]);
    imshow("R", splitChannels[2]);
    waitKey();

    splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1); // replace channel 2 by zero matrix
    imshow("R_man", splitChannels[2]);
    Mat output;
    merge(splitChannels, 3, output); // Merge the colours again, with manipulated Red-part
    imshow("Merged", output);
}


/*************************************************************************************************/
/* Lection 4: Capture Video from Webcam                                                          */
/*************************************************************************************************/
int lection4()
{
    Mat frame;
    int fps = 20;

    VideoCapture vid(1);
    if(!vid.isOpened())
    {
        return -1;
    }

    while(vid.read(frame))
    {
        imshow("Webcam", frame);
        if(waitKey(1000/fps) >= 0)
            break;
    }
    return 1;
}


/*************************************************************************************************/
/* Lection 5: Camera Calibration                                                                 */
/*************************************************************************************************/
void lection5()
{
    const float calibSquareDimension = 0.0195f; // meters
    const float arucoSquareDimension = 0.1015f;
    const Size chessboardDimensions = Size(6, 9);

    // create board positions


}

void createKnownBoardPosition(Size boardSize, float squareEdgeLength, vector<Point3f>& corners)
{
    for(int i = 0; i < boardSize.height; i++)
    {
        for(int j = 0; j < boardSize.width; j++)
        {
            corners.push_back(Point3f(j*squareEdgeLength, i*squareEdgeLength, 0.0f));
        }
    }
}

void getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showResults)
{
    for(vector<Mat>::iterator iter = images.begin(); iter != images.end(); iter++)
    {
        vector<Point2f> pointBuf;
        bool found = findChessboardCorners(*iter, Size(9,6), pointBuf, CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_NORMALIZE_IMAGE);
        if(found)
        {
            allFoundCorners.push_back(pointBuf);
        }

        if (showResults)
        {
            drawChessboardCorners(*iter, Size(9,6), pointBuf, found);
            imshow("Looking for Corners", *iter);
            waitKey(0);
        }


    }
}

