#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_int_test->setText("clean");
}

void MainWindow::on_pushButtonSave_clicked()
{
    Settings s(13);

    FileStorage fs(s.filename, FileStorage::WRITE);

//    fs << "test" << ui->lineEdit_int_test->text().toInt();
    fs << "MySettings" << s;

    fs.release();
}

void MainWindow::on_pushButtonLoade_clicked()
{
    Settings s;
    FileStorage fs(s.filename, FileStorage::READ);

    fs["MySettings"] >> s;

//    ui->lineEdit_int_test->setText(QString::number((int) fs["test"]));
    ui->lineEdit_int_test->setText(QString::number(s.test));

    fs.release();
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
