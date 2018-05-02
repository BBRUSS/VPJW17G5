#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>
#include "cameracalibrator.h"
//#include <QPainter>
//#include <QPointF>
#include <QResizeEvent>

using namespace cv;
using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int getSelectedCamID();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_startCameraButton_clicked();
    void on_takeSnapshotButton_clicked();
    void cameraTimerTimeout();

    void findAndDrawPoints();
    void startCalibration();

    //void on_pushButton_clicked();
    //void on_comboBox_activated(int index);

    void on_resetButton_clicked();

    void on_cameraSlider_valueChanged(int value);

    void on_brightnessSlider_valueChanged(int value);

    void on_contrastSlider_valueChanged(int value);

    void on_exposureSlider_valueChanged(int value);

    void on_saveButton_clicked();

    void on_distWidth_spinBox_valueChanged(int value);

    void on_distHeight_spinBox_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    Mat image, imageSaved, imageForGui, greyImage, undistortedForGui;
    VideoCapture capture;
    bool isCameraRunning, isCalibrate;
    QTimer cameraTimer;
    Size boardSize;
    int numSeq, successes;
    //int  numRequiredSnapshot;
    CameraCalibrator cameraCalib;
    vector<Mat> imageList;
    void debugAusgabe();

    vector< vector<Point2f> > allSnapshotAreas;
    vector<bool> allFounds;
    void resizeEvent(QResizeEvent* event);
};

#endif // MAINWINDOW_H
