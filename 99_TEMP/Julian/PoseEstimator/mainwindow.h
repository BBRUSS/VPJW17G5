#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <QTimer>
#include "settings.h"
#include "camera.h"

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
    void on_pushButtonOpenCamera_clicked();
    void on_cameraTimerEvent();

private:
    Ui::MainWindow *ui;

    cv::Mat cameraMatrix;
    cv::Mat distCoeff;

    Settings set;

    QTimer cameraTimer;
    cv::VideoCapture videoCapture;

    bool first = true;

    void printCV2dMat(cv::Mat Mat, QString Name);
    void processImage();
};

#endif // MAINWINDOW_H
