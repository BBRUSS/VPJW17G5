#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Bilddatei laden","","Bilder (*.jpg)");


   cv::Mat bildMatrix = cv::imread(fileName.toStdString());
   cv::Mat newMat;
   cv::resize(bildMatrix, newMat, cvSize(800,600));
   cv::imshow("Name",newMat);
}
