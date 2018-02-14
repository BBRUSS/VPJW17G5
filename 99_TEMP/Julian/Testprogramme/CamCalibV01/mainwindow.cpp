#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "camera.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Settings *s = new Settings();
    s->boardSize.height = 9;    // number of corners in height
    s->boardSize.width = 6;     // number of corners in width
    s->squareSize = 0.02f;      // size of squares in m
    s->calibrationPattern = Settings::CHESSBOARD;
    s->nrFrames = 10;
    s->calibFixPrincipalPoint = 1;
    s->calibZeroTangentDist = 0;

    cam1 = new Camera(1, ui, s);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCalib_clicked()
{
    qDebug() << "clicked";
    cam1->doCalibration();
}
