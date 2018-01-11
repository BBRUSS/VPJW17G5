#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_SaveImage, SIGNAL(clicked(bool)), this, SLOT(saveImagesFromGUI(found, frame, savedImages)) );
    connect(ui->pushButton_StartCalib, SIGNAL(clicked(bool)), this, SLOT(startCalibrationFromGUI(savedImages, chessboardDimensions, calibrationSquareDimension, cameraMatrix, distanceCoefficients)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::saveImagesFromGUI(bool found, Mat& frame, vector<Mat>& savedImages)
{
    ui->textEdit->clear();
    if(found)
    {
        Mat temp;
        frame.copyTo(temp);
        savedImages.push_back(temp);
        ui->textEdit->setText("Image saved!\n");
    } else
    {
        ui->textEdit->setText("No corners found!\n");
    }
}


void MainWindow::startCalibrationFromGUI(vector<Mat> savedImages, Size chessboardDimensions, float calibrationSquareDimension, Mat& cameraMatrix, Mat& distanceCoefficients)
{
    ui->textEdit->clear();
    if(savedImages.size() > 15)
    {
        cameraCalibration(savedImages, chessboardDimensions, calibrationSquareDimension, cameraMatrix, distanceCoefficients);
        saveCameraCalibration("CameraCalibTest", cameraMatrix, distanceCoefficients);
        ui->textEdit->setText("Calibration successfull!\n");
    }
    else
    {
        ui->textEdit->setText("Not enough frames saved!\n");
    }
}
