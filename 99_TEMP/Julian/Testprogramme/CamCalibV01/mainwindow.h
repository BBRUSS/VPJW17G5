#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camera.h"
#include "settings.h"
#include "cameracontrast.h"
#define MAX_CAMS 6

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int camID;
    //Camera *cam1;
    vector<Camera*> cams;
    Settings *s;

private slots:
//    void on_pushButtonCalibIntrinsics_clicked();
//    void on_pushButtonCalibExtrinsics_clicked();
    void on_pushButtonSetContrast_clicked();
    void changedValue();

private:
    Ui::MainWindow *ui;
    CameraContrast *contrastWindow;

};

#endif // MAINWINDOW_H
