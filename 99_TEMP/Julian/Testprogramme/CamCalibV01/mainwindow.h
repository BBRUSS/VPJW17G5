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

    vector<Camera*> cams;
    Settings *s;

private slots:
    void on_pushButtonSetContrast_clicked();
    void changedValue();
    void on_pushButtonSave_clicked();
    void on_pushButtonLoad_clicked();

    void on_checkBoxWhiteOnBlack_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    CameraContrast *contrastWindow;

};

#endif // MAINWINDOW_H
