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
    // Ein Pointer auf das Ui wird übergeben.
    explicit world( Ui::MainWindow *dasUi);

signals:

public slots:
    void pushWorld();

private:
    // Ein Ui-Pointer in derm nacher der Pointer gespeichert wird.
    Ui::MainWindow *UiVonMain;

};
#endif // WORLD_H
