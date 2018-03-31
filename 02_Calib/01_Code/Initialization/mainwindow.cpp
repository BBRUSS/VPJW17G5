#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Mat background(640, 1280, CV_8UC3);
    background.setTo(Scalar(0, 0, 0));

    vector<Mat> images;

    Mat roiInclude(640/4, 1280/4, CV_8UC3);
    RNG rng;
    for (int i=0; i<4; i++){
        roiInclude.setTo(Scalar(255, 255, 255));
        string str = to_string(i) + ": " + to_string(rng.uniform(0, 255));
        putText(roiInclude, str, cvPoint(60,60), FONT_HERSHEY_PLAIN, 2.5, Scalar(0,0,0), 1, CV_AA, 0);
        roiInclude.copyTo(background(Rect(i * roiInclude.cols,i * roiInclude.rows,roiInclude.cols, roiInclude.rows)));
    }

    QPixmap pixmap;
    pixmap = QPixmap::fromImage(QImage((unsigned char*) background.data, background.cols, background.rows, QImage::Format_RGB888));
    ui->label->setPixmap(pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}
