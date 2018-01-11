#ifndef WORLD_H
#define WORLD_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>

class MainWindow;

class world : public QMainWindow
{
    Q_OBJECT

public:
    explicit world(Ui::MainWindow *dasUi);

signals:

public slots:
    void pushWorld();

private:
    Ui::MainWindow *UiVonMain;
};

#endif // WORLD_H
