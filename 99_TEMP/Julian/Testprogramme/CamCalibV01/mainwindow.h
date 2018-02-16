#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camera.h"
#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Camera *cam1;
    Settings *s;

private slots:
    void on_pushButtonCalibIntrinsics_clicked();
    void on_pushButtonCalibExtrinsics_clicked();
    void changedValue();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
