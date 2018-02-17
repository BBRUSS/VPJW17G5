#include "cameracontrast.h"
#include "ui_cameracontrast.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

CameraContrast::CameraContrast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CameraContrast)
{
    this->cams = cams;
    ui->setupUi(this);
    ui->pushButtonStopCam->setEnabled(false);
}

CameraContrast::~CameraContrast()
{
    delete ui;
}


void CameraContrast::on_pushButtonStartCam_clicked()
{
    cameraTimer.start(33); // 33 ms = 30 fps

    //SIGNAL AND SLOT CONNECTION
    //at the timeout() event, execute the cameraTimerTimeout() method
    //sender (source of signal): of type QTimer; signal (value of signal): timeout()
    //receiver: this Window - slot:a function of the receiver that processes the incoming signal
    id = ui->spinBoxCameraID->value();
    capture.open(id);

    if (capture.isOpened())
    {
        connect(&cameraTimer, SIGNAL(timeout()), this, SLOT(frameReady()));
        ui->pushButtonStartCam->setEnabled(false);
        ui->spinBoxCameraID->setEnabled(false);
        ui->pushButtonStopCam->setEnabled(true);
        ui->pushButtonGetExtrinsics->setEnabled(true);
        ui->pushButtonGetIntrinsics->setEnabled(true);
        ui->pushButtonSaveContrast->setEnabled(true);
        ui->pushButtonResetThr->setEnabled(true);
        ui->lineEditStatus->clear();


    }
    else
    {
        ui->lineEditStatus->setText("Not found!");
    }
}

void CameraContrast::on_pushButtonStopCam_clicked()
{
    if(capture.isOpened())
    {

        // release camera stream - Closes video file or capturing device.
        capture.release();
        ui->labelImageOrig->clear();
        ui->labelImageContrast->clear();
    }

    // stop timer
    cameraTimer.stop();

    ui->pushButtonStopCam->setEnabled(false);
    ui->pushButtonGetExtrinsics->setEnabled(false);
    ui->pushButtonGetIntrinsics->setEnabled(false);
    ui->pushButtonSaveContrast->setEnabled(false);
    ui->pushButtonResetThr->setEnabled(false);
    ui->pushButtonStartCam->setEnabled(true);
    ui->spinBoxCameraID->setEnabled(true);
}


void CameraContrast::frameReady()
{
    if(capture.isOpened())
    {
        // store the frame to show in a Qt window
        QImage originalFrame, thresholdFrame;

        // get the current frame from the video stream
        // Mat image wird beschrieben mit Hilfe des überladenen Operators >>
        // Aus VideoCapture wird hier also ein 2D Mat
        capture.read(image);
        image.copyTo(imageOrig);

        // prepare the image for the Qt format...
        // ... change color channel ordering (from BGR in our Mat to RGB in QImage)
        cvtColor(imageOrig, imageOrig, CV_BGR2RGB);

        Mat threshold;

        cv::threshold(imageOrig, threshold, ui->horizontalSliderThreshold->value(), ui->horizontalSliderMaxValue->value(), THRESH_BINARY);

        //imshow("Test", threshold);

        // 3. Bild resizen und altes imageForGui mit neuem ersetzen
        // Resizes an image in order to adapt to the GUI size

        cv::resize(imageOrig, imageOrig, Size(ui->labelImageOrig->width(), ui->labelImageOrig->height()));
        cv::resize(threshold, threshold, Size(ui->labelImageContrast->width(), ui->labelImageContrast->height()));

        // QImage
        originalFrame  = QImage((const unsigned char*)(imageOrig.data), imageOrig.cols, imageOrig.rows, imageOrig.step, QImage::Format_RGB888);
        thresholdFrame = QImage((const unsigned char*)(threshold.data), threshold.cols, threshold.rows, threshold.step, QImage::Format_RGB888);

        ui->labelImageOrig->setScaledContents(true);
        ui->labelImageContrast->setScaledContents(true);
        // display on labels
        ui->labelImageOrig->setPixmap(QPixmap::fromImage(originalFrame));
        ui->labelImageContrast->setPixmap(QPixmap::fromImage(thresholdFrame));

    }
}


void CameraContrast::on_pushButtonSaveContrast_clicked()
{
    qInfo() <<"save id "<< id;
    cams.at(id)->setContrast(ui->horizontalSliderThreshold->value(), ui->horizontalSliderMaxValue->value());
}


void CameraContrast::on_pushButtonGetIntrinsics_clicked()
{
   capture.release();
   int success = cams.at(id)->doCalibrationIntrinsics();
   capture.open(id);
   qInfo() << "intrinsic success:" << success;
}


void CameraContrast::on_pushButtonGetExtrinsics_clicked()
{
    capture.release();
    cams.at(id)->doCalibrationExtrinsics();
    capture.open(id);
}


void CameraContrast::on_pushButtonResetThr_clicked()
{
    ui->horizontalSliderMaxValue->setValue(128);
    ui->horizontalSliderThreshold->setValue(128);
    cams.at(id)->setContrast(-1, -1);
}

void CameraContrast::on_pushButtonCloseCalibWindow_clicked()
{
    this->close();
}
