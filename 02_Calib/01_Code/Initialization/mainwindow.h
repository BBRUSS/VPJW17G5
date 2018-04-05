#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <QTimer>
#include <string>
#include "settings.h"

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
    void initializeCams();

private slots:

    void updateFrame();
    void on_pushButtonChange_clicked();
    void on_pushButtonResizeCamField_clicked();

    void on_pushButtonSaveSettings_clicked();

private:
    Ui::MainWindow *ui;
    Settings s;
    vector<VideoCapture*> captures;
    QTimer frames;
    Mat guiImage;
    Mat camImage;
};

#endif // MAINWINDOW_H
