#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBoxFieldHeight->setMinimum(1);
    ui->spinBoxFieldHeight->setValue(2);
    ui->spinBoxFieldWidth->setMinimum(1);
    ui->spinBoxFieldWidth->setValue(3);
    ui->spinBoxChange1->setEnabled(false);
    ui->spinBoxChange2->setEnabled(false);
    ui->pushButtonChange->setEnabled(false);
    ui->pushButtonSaveSettings->setEnabled(false);
}

MainWindow::~MainWindow()
{
    for(int i=0; i<s.cams.size(); i++)
    {
        captures.at(i)->release();
    }
    delete ui;
}

void MainWindow::on_pushButtonResizeCamField_clicked()
{
    s.setCamFieldSize(Size(ui->spinBoxFieldWidth->text().toInt(), ui->spinBoxFieldHeight->text().toInt()));

    ui->spinBoxFieldHeight->setEnabled(false);
    ui->spinBoxFieldWidth->setEnabled(false);
    ui->pushButtonResizeCamField->setEnabled(false);
    ui->spinBoxChange1->setEnabled(true);
    ui->spinBoxChange1->setMinimum(0);
    ui->spinBoxChange1->setMaximum(s.camFieldSize.area()-1);
    ui->spinBoxChange2->setEnabled(true);
    ui->spinBoxChange2->setMinimum(0);
    ui->spinBoxChange2->setMaximum(s.camFieldSize.area()-1);
    ui->pushButtonChange->setEnabled(true);
    ui->pushButtonSaveSettings->setEnabled(true);

    this->initializeCams();
}

void MainWindow::initializeCams()
{
    for(int i=0; i<s.cams.size(); i++)
    {
        captures.push_back(new VideoCapture);
        captures.at(i)->open(s.cams.at(i)->cameraID);
    }

    guiImage = Mat(640*s.camFieldSize.width,480*s.camFieldSize.height, CV_8UC3);
    guiImage.setTo(Scalar(0,0,0));

    for(int i=0; i<s.cams.size(); i++)
    {
        if(captures.at(i)->isOpened())
        {
            captures.at(i)->read(camImage);
            cv::resize(guiImage,guiImage,cvSize(camImage.cols*s.camFieldSize.width,camImage.rows*s.camFieldSize.height));
            break;
        }
    }

    frames.start(33);
    connect(&frames, SIGNAL(timeout()), this, SLOT(updateFrame()));
}

void MainWindow::updateFrame()
{
    for(int i=0; i<s.cams.size(); i++)
    {
        if (captures.at(i)->isOpened())
        {
            captures.at(i)->read(camImage);
            cvtColor(camImage,camImage,COLOR_RGB2BGR);
        }
        else
        {
            cv::resize(camImage,camImage,cvSize(guiImage.cols/s.camFieldSize.width,guiImage.rows/s.camFieldSize.height));
            camImage.setTo(Scalar(0,0,0));
            string str = "Camera not connected. ID: " + to_string(s.cams.at(i)->cameraID);
            putText(camImage, str, cvPoint(60,60), FONT_HERSHEY_PLAIN, 1.5, Scalar(255,255,255), 1, CV_AA, 0);
        }

        putText(camImage, to_string(i), cvPoint(camImage.cols/2,camImage.rows/2), FONT_HERSHEY_PLAIN, 3, Scalar(255,0,0), 1, CV_AA, 0);
        int mulRows = i/s.camFieldSize.width;
        int mulCols= i%s.camFieldSize.width;
        camImage.copyTo(guiImage(Rect(mulCols * camImage.cols,mulRows * camImage.rows,camImage.cols, camImage.rows)));
    }

    QPixmap pixmap;
    pixmap = QPixmap::fromImage(QImage((unsigned char*) guiImage.data, guiImage.cols, guiImage.rows, QImage::Format_RGB888));
    ui->label->setPixmap(pixmap);
}

void MainWindow::on_pushButtonChange_clicked()
{
    VideoCapture* temp = captures.at(ui->spinBoxChange1->text().toInt());
    captures.at(ui->spinBoxChange1->text().toInt()) = captures.at(ui->spinBoxChange2->text().toInt());
    captures.at(ui->spinBoxChange2->text().toInt()) = temp;

    Settings::cam* temp2 = s.cams.at(ui->spinBoxChange1->text().toInt());
    s.cams.at(ui->spinBoxChange1->text().toInt()) = s.cams.at(ui->spinBoxChange2->text().toInt());
    s.cams.at(ui->spinBoxChange2->text().toInt()) = temp2;
}

void MainWindow::on_pushButtonSaveSettings_clicked()
{
    ui->spinBoxFieldHeight->setEnabled(true);
    ui->spinBoxFieldWidth->setEnabled(true);
    ui->pushButtonResizeCamField->setEnabled(true);
    ui->spinBoxChange1->setEnabled(false);
    ui->spinBoxChange2->setEnabled(false);
    ui->pushButtonChange->setEnabled(false);
    ui->pushButtonSaveSettings->setEnabled(false);

    s.save();
    frames.stop();
}
