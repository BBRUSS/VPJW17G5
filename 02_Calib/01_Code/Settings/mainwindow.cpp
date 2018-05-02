#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_int_test->setText("clean");
}

void MainWindow::on_pushButtonSave_clicked()
{
    Settings s;
    Size cams;
    cams.height = 2;
    cams.width = 2;
    s.setCamFieldSize(cams);
    for (int i = 0; i<s.camFieldSize.area(); i++){
     s.cams.at(i)->cameraID = i;
    }
    s.save();
//    FileStorage fs(s.filename, FileStorage::WRITE);
//    fs << "MySettings"<< s;
//    fs.release();
}

void MainWindow::on_pushButtonLoade_clicked()
{
    Settings s;
    s.load();
//    FileStorage fs(s.filename, FileStorage::READ);

//    if (!fs.isOpened()){
//        fs.release();
//    }

//    fs["MySettings"] >> s;
//    fs.release();

    qDebug() << "boardSize.width" << s.boardSize.width;
    qDebug() << "boardSize.height" << s.boardSize.height;
    qDebug() << "camFieldSize.width" << s.camFieldSize.width;
    qDebug() << "camFieldSize.height" << s.camFieldSize.height;
    qDebug() << "calibrationPattern" << s.calibrationPattern;
    qDebug() << "squareSize" << s.squareSize;
    qDebug() << "nrFrames" << s.nrFrames;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonMainSettings_clicked()
{
    hide();
    mainsettings = new MainSettings(this);
    mainsettings->show();
}
