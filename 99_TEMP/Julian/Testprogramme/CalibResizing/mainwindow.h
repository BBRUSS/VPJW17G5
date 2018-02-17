#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <QTimer>
#include <QShortcut>
#include <sstream>
#include <iostream>
#include <fstream>


//#include <QFileDialog>
//#include <QMessageBox>
//#include <QPainter>
//#include <QPointF>
//#include <QResizeEvent>
#include "cameracalibrator.h"

using namespace std;
using namespace cv;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void frameReady();
    void on_startCameraButton_clicked();
    void on_stopCameraButton_clicked();
//    void cameraCalibration(vector<Mat> calibrationImages, Size boardSize, float squareEdgeLength, Mat& cameraMatrix, Mat& distanceCoefficients);
//    void createKnownBoardPosition(cv::Size boardSize, float squareEdgeLength, vector<Point3f>& corners);
//    void getChessboardCorners(vector<Mat> images, vector<vector<Point2f>>& allFoundCorners, bool showResult);
//    bool saveCameraCalibration(string name, Mat cameraMatrix, Mat distanceCoefficients);
//    void saveImagesFromGUI(bool found, Mat& frame, vector<Mat>& savedImages);
//    void startCalibrationFromGUI(vector<Mat> savedImages, Size chessboardDimensions, float calibrationSquareDimension, Mat& cameraMatrix, Mat& distanceCoefficients);

private:
    Ui::MainWindow *ui;
    Mat image,  imageForGui;
    VideoCapture capture;
    QTimer cameraTimer;
};

#endif // MAINWINDOW_H
