#ifndef CAMERACONTRAST_H
#define CAMERACONTRAST_H

#include <QDialog>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <QTimer>
//#include "mainwindow.h"
#include "camera.h"

using namespace std;
using namespace cv;



namespace Ui {
class CameraContrast;
}

class CameraContrast : public QDialog
{
    Q_OBJECT

public:
    explicit CameraContrast(QWidget *parent = 0);
    ~CameraContrast();

private slots:
    void frameReady();
    void on_pushButtonStartCam_clicked();
    void on_pushButtonStopCam_clicked();
    void on_pushButtonSaveContrast_clicked();
    void on_pushButtonGetIntrinsics_clicked();
    void on_pushButtonGetExtrinsics_clicked();

    void on_pushButtonResetThr_clicked();

    void on_pushButtonCloseCalibWindow_clicked();

public:
    void setCams(vector<Camera*> cams)
    {
        this->cams = cams;
    }
private:
    Ui::CameraContrast *ui;
    vector<Camera*> cams;
    int id;
    Mat image,  imageOrig;
    VideoCapture capture;
    QTimer cameraTimer;
};

#endif // CAMERACONTRAST_H
