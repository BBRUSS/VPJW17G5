#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainsettings.h"

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
    MainSettings *mainsettings;

private slots:
    void on_pushButtonSave_clicked();
    void on_pushButtonLoade_clicked();
    void on_pushButtonMainSettings_clicked();
};

#endif // MAINWINDOW_H
