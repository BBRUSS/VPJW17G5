#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void saveImagesFromGUI(bool found, Mat& frame, vector<Mat>& savedImages);
    void startCalibrationFromGUI(vector<Mat> savedImages, Size chessboardDimensions, float calibrationSquareDimension, Mat& cameraMatrix, Mat& distanceCoefficients);


};

#endif // MAINWINDOW_H
