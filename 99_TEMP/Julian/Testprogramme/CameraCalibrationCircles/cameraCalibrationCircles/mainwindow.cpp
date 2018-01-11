#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "testclass.h"
#include "camcalibration.h"

#include "opencv2/calib3d.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/aruco.hpp"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{ 
    CamCalibration *calibWidget = new CamCalibration(this);
    calibWidget->setUI(ui);
    ui->setupUi(this);

    TestClass *testWidget = new TestClass(this);
    connect(ui->pushButton_ShowLogo, SIGNAL(clicked(bool)), testWidget, SLOT(showCVLogo()));
    connect(ui->pushButton_CloseLogo, SIGNAL(clicked(bool)), testWidget, SLOT(closeCVLogo()));
    connect(ui->pushButton_Help, SIGNAL(clicked(bool)), calibWidget, SLOT(help()));
    connect(ui->pushButton_StartCalib, SIGNAL(clicked(bool)), calibWidget, SLOT(doCalibration()));


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::sublineTextEdit(QString text)
{
    ui->textEdit_Subline->setText(text);
}



//void MainWindow::showCVLogo()
//{
//    QString filename = "logo.png";
//    Mat pic = imread("logo.png", CV_LOAD_IMAGE_COLOR);
//    imshow("Testbild", pic);
//}
