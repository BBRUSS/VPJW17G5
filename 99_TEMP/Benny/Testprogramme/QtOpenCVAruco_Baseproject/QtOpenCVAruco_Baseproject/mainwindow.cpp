#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;
using namespace aruco;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Ptr<Dictionary> test = getPredefinedDictionary(1);
    Mat testmat;
    drawMarker(test, 1, 500, testmat);
    imshow("Fenster", testmat);
}

MainWindow::~MainWindow()
{
    delete ui;
}
