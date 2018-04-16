#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QTimer>

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

    QTimer cameraTimer;
    cv::VideoCapture videoCapture;

    void processImage();
};

#endif // MAINWINDOW_H
