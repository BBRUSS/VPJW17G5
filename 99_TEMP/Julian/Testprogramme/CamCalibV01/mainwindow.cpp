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
    ui->horizontalSliderCalibPattern->setSingleStep(1);
    ui->horizontalSliderCalibPattern->setRange(0,1);
    ui->textEditCalibPattern->setText("Chessboard");
    connect(ui->horizontalSliderCalibPattern, SIGNAL(valueChanged(int)),this, SLOT(changedValue()));
    s = new Settings();

    s->calibrationPattern = Settings::CHESSBOARD;
    s->nrFrames = 10;
    s->calibFlag |= CV_CALIB_FIX_ASPECT_RATIO | CV_CALIB_FIX_FOCAL_LENGTH | CV_CALIB_FIX_PRINCIPAL_POINT;

    cam1 = new Camera(1, ui, s);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCalibIntrinsics_clicked()
{
    qDebug() << "Starting intrinsic calibration...";
    cam1->doCalibrationIntrinsics();  // intrinsic parameters
    // Wenn Kalibrierung neu: flag = CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5
    // Wenn Kalibierung vorhanden: flag = CV_CALIB_USE_INTRINSIC_GUESS|CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5
}


void MainWindow::on_pushButtonCalibExtrinsics_clicked()
{
    // how to get extrinsics:
    // Pro Camera (4?) 6* Bilder mit dem "Punkt-Ständer" in jeweils einer Ecke aufnehmen, Bilder Schwarz-weiß mit Kontrast so einstellen,
    // dass alles schwarz ist und nur der Punkt (Kreis) weiß ist.
    // Die 4 Einzelbilder mittels bitwise-OR zu einem Bild zusammenfügen, dann mit der zuvor gewonnenen Kameramatrix (Kopie erstellen) und Flag
    // <CV_CALIB_USE_INTRINSIC_GUESS> 1x calibrateCamera() aufrufen. Somit erhält man rvec und tvec als Rotationsmatrix und Translationsvektor.
    // eventuell kann man mit diesem Schritt mittels getNewCameramatrix() (oder so ähnlich heißt die) eine verbesserte Kalibierung der intrinsischen
    // Parameter erhalten.
    // Somit entstehen zwei nötige Kalibierungen: 1x mit dem Schachbrettmuster für die Intrinsics und danach mit dem "Punkt-Ständer" für die Extrinsics.
    // +----------+
    // |*        *|
    // |          |
    // |*        *|    => Extrinsic calibration pattern: symmetric circle grid 2 x 3
    // |          |
    // |*        *|
    // +----------+
    //
    // * 6 Bilder sind besser als 4, da für getChessboadCorners() / getCircleGrid() empfohlen wird, eine gerade und eine ungerade Dimension zu haben.

    qDebug() << "Starting extrinsic calibration...";
    cam1->doCalibrationExtrinsics();
}

void MainWindow::changedValue()
{
    if(ui->horizontalSliderCalibPattern->value()==0)
    {
        s->calibrationPattern = Settings::CHESSBOARD;
        ui->textEditCalibPattern->setText("Chessboard");
        s->boardSize.height = 9;    // number of corners in height
        s->boardSize.width = 6;     // number of corners in width
        s->squareSize = 23.1f;      // size of squares in mm
    }
    else if(ui->horizontalSliderCalibPattern->value()==1)
    {
        s->calibrationPattern = Settings::ASYMMETRIC_CIRCLES_GRID;
        ui->textEditCalibPattern->setText("Asym. Circlegrid");
        s->boardSize.height = 11;    // number of corners in height
        s->boardSize.width = 4;      // number of corners in width
        s->squareSize = 15.0f;       // size of squares in mm
    }
}
