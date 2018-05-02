#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QMainWindow>
#include <QTime>
#include <QShortcut>
#include <opencv2/opencv.hpp>

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
    void on_pushButton_startStop_clicked();
    void on_pushButton_takeSnap_clicked();

private:
    Ui::MainWindow *ui;
    bool isStart;
};

#endif // MAINWINDOW_H
