#include "camcalibration.h"
#include "mainwindow.h"

CamCalibration::CamCalibration(QWidget *parent) : QWidget(parent)
{

}

int CamCalibration::doCalibration()
{
    help();
    cout << "doCalibration() called" << endl;
    return 0;
}


void CamCalibration::help()
{
    QString outString;
    outString = "This is a camera calibration sample. \n Usage: camera_calibration [configuration_file -- default ./default.xml] \n Near the sample file you'll find the configuration file, which has detailed help of \n how to edit it.  It may be any OpenCV supported file format XML/YAML.";
    cout << outString.toStdString() << endl;
    //this->ui->textEdit_Subline->setText(outString.toStdString());
    //this->ui->sublineTextEdit(outString);
}


void CamCalibration::setUI(Ui::MainWindow* Ui)
{
    this->ui = Ui;
}
