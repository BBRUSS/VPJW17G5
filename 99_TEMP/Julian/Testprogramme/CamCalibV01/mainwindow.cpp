#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include "camera.h"
#include "cameracontrast.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Toggle switch (Calibration Pattern) only for testing purpose
    ui->horizontalSliderCalibPattern->setSingleStep(1);
    ui->horizontalSliderCalibPattern->setRange(0,1);
    ui->textEditCalibPattern->setText("Chessboard");
    connect(ui->horizontalSliderCalibPattern, SIGNAL(valueChanged(int)),this, SLOT(changedValue()));

    ui->textEditCalibPattern->setText("Asym. Circlegrid");

    // Config Settings
    s = new Settings();
    s->setCamFieldSize(Size(3,2));
    //s->load()== ok ? calibrieren : frage user nach size -> s.cameraField;
    // TODO: Am Ende die Settings aus der XML laden und dementsprechend Kamerafeld etc. erzeugen

    // Config calibration pattern
    s->calibrationPattern = Settings::CHESSBOARD;

    // Calibration Pattern at home (1)
    if(s->calibrationPattern == Settings::CHESSBOARD)
    {
        s->boardSize.height = 9;                // number of corners in height
        s->boardSize.width = 6;                 // number of corners in width
        s->squareSize = 23.1f;                  // size of squares in mm
        s->calibPatternWhiteOnBlack = false;    // Calibration Pattern is white on black and will need to be inverted
    }
    // Calibration Pattern at home (2)
    else if(s->calibrationPattern == Settings::ASYMMETRIC_CIRCLES_GRID)
    {
        s->boardSize.height = 4;                // number of corners in height
        s->boardSize.width = 5;                 // number of corners in width
        s->squareSize = 15.0f;                  // size of squares in mm
        s->calibPatternWhiteOnBlack = false;    // Calibration Pattern is white on black and will need to be inverted
    }
    // Calibration Pattern in VPJ-room
    else if(s->calibrationPattern == Settings::CIRCLES_GRID)
    {
        s->boardSize.height = 4;                // number of corners in height
        s->boardSize.width = 5;                 // number of corners in width
        s->squareSize = 200.0f;                 // size of squares in mm
        s->calibPatternWhiteOnBlack = true;     // Calibration Pattern is white on black and will need to be inverted
    }



    s->nrFrames = 10;

    for(int i = 0; i < s->camFieldSize.area(); i++)
    {
        s->cams.at(i)->calibFlag = CV_CALIB_FIX_ASPECT_RATIO | CV_CALIB_FIX_FOCAL_LENGTH | CV_CALIB_FIX_PRINCIPAL_POINT;
    }

    // Create camera objects

    for(int nr = 0; nr < s->camFieldSize.area(); nr++)
    {
        s->cams.at(nr)->cameraID = nr;  // TESTING PURPOSE
        cams.push_back( new Camera(nr, s->cams.at(nr)->cameraID, ui, s));
        qInfo() << "created new cam object with id <" << cams.at(nr)->getID() << ">" << endl;
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButtonCalibIntrinsics_clicked()
//{
//    qDebug() << "Starting intrinsic calibration for Cam <"<<cams.at(camID)->getID()<<"> ..."<<endl;
//    cams.at(camID)->doCalibrationIntrinsics();  // intrinsic parameters
//    // Wenn Kalibrierung neu: flag = CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5
//    // Wenn Kalibierung vorhanden: flag = CV_CALIB_USE_INTRINSIC_GUESS|CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5
//}


//void MainWindow::on_pushButtonCalibExtrinsics_clicked()
//{
//    // how to get extrinsics:
//    // Pro Camera (4?) 6* Bilder mit dem "Punkt-Ständer" in jeweils einer Ecke aufnehmen, Bilder Schwarz-weiß mit Kontrast so einstellen,
//    // dass alles schwarz ist und nur der Punkt (Kreis) weiß ist.
//    // Die 4 Einzelbilder mittels bitwise-OR zu einem Bild zusammenfügen, dann mit der zuvor gewonnenen Kameramatrix (Kopie erstellen) und Flag
//    // <CV_CALIB_USE_INTRINSIC_GUESS> 1x calibrateCamera() aufrufen. Somit erhält man rvec und tvec als Rotationsmatrix und Translationsvektor.
//    // eventuell kann man mit diesem Schritt mittels getNewCameramatrix() (oder so ähnlich heißt die) eine verbesserte Kalibierung der intrinsischen
//    // Parameter erhalten.
//    // Somit entstehen zwei nötige Kalibierungen: 1x mit dem Schachbrettmuster für die Intrinsics und danach mit dem "Punkt-Ständer" für die Extrinsics.
//    // +----------+
//    // |*        *|
//    // |          |
//    // |*        *|    => Extrinsic calibration pattern: symmetric circle grid 2 x 3
//    // |          |
//    // |*        *|
//    // +----------+
//    //
//    // * 6 Bilder sind besser als 4, da für getChessboadCorners() / getCircleGrid() empfohlen wird, eine gerade und eine ungerade Dimension zu haben.

//    qDebug() << "Starting extrinsic calibration for Cam <"<<cams.at(camID)->getID()<<"> ..."<<endl;
//    cams.at(camID)->doCalibrationExtrinsics();
//}


void MainWindow::on_pushButtonSetContrast_clicked()
{
    //    CameraContrast contrastWindow; // this is the modal approach for new window, which means that the new window is prior and has to be closed
    //    contrastWindow.setModal(true); // before you can work/move/click the other window(s)
    //    contrastWindow.exec();
    // other way to open new window:
    contrastWindow = new CameraContrast(this);
    contrastWindow->setCams(cams);
    contrastWindow->setAttribute(Qt::WA_AlwaysShowToolTips);
    contrastWindow->show();


}


/** Used for toggle switch in test page
 * @brief MainWindow::changedValue
 */
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


void MainWindow::on_pushButtonSave_clicked()
{
    for(int id = 0; id < s->camFieldSize.area(); id++)
    {
        s->cams.at(id)->cameraID = id;
    }
    s->calibrationPattern = Settings::CIRCLES_GRID;
    s->save();
}


void MainWindow::on_pushButtonLoad_clicked()
{
    s->load();
}
