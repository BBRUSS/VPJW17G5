#include "cameracontrast.h"
#include "ui_cameracontrast.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
/* TODO's
   - User interface Existenz von XML prüfen -> erstellen wenn nicht vorhanden, füttern mit Werten
   -
*/

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


/** Starts timer and connects "frameReady()"-Method as TOV-ISR.
 *  Starts camera capture and enables/disables corresponding pushbuttons
 * @brief CameraContrast::on_pushButtonStartCam_clicked
 */
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
        ui->horizontalSliderMaxValue->setEnabled(true);
        ui->horizontalSliderThreshold->setEnabled(true);
        ui->lineEditStatus->clear();
        on_pushButtonResetThr_clicked();    // reset b/w threshold and max values
    }
    else
    {
        ui->lineEditStatus->setText("Not found!");
    }
}


/** Stops camera capture and enables/disables corresponding pushbuttons
 * @brief CameraContrast::on_pushButtonStopCam_clicked
 */
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
    ui->horizontalSliderMaxValue->setEnabled(false);
    ui->horizontalSliderThreshold->setEnabled(false);
    ui->pushButtonStartCam->setEnabled(true);
    ui->spinBoxCameraID->setEnabled(true);
}


/** Writes sample image to calibration window GUI after timeout (30fps),
 *  convert image according to horizontal sliders values for black/white threshold
 *  and max value respectively.
 * @brief CameraContrast::frameReady
 */
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


/** Save the horizontal slider values for black/white threshold and max value
 *  to active camera object, in order to use these values while calibration process
 * @brief CameraContrast::on_pushButtonSaveContrast_clicked
 */
void CameraContrast::on_pushButtonSaveContrast_clicked()
{
    qInfo() <<"save id "<< id;
    cams.at(id)->setContrast(ui->horizontalSliderThreshold->value(), ui->horizontalSliderMaxValue->value());
}


/** Start the calibration process to get intrinsic parameters.
 *  Therefor, the capture from parent window needs to be released, else the "frameReady()" method
 *  will have size-errors and the application will crash.
 * @brief CameraContrast::on_pushButtonGetIntrinsics_clicked
 */
void CameraContrast::on_pushButtonGetIntrinsics_clicked()
{
   capture.release();
   int success = cams.at(id)->doCalibrationIntrinsics();
   capture.open(id);
   qInfo() << "intrinsic success:" << success;
}


/** Start the calibration process to get extrinsic parameters.
 *  Therefor, the capture from parent window needs to be released, else the "frameReady()" method
 *  will have size-errors and the application will crash.
 * @brief CameraContrast::on_pushButtonGetExtrinsics_clicked
 */
void CameraContrast::on_pushButtonGetExtrinsics_clicked()
{
    capture.release();
    cams.at(id)->doCalibrationExtrinsics();
    capture.open(id);
}


/** Reset the horizontal slider values for black/white threshold and max value
 *  and the corresponding values in active camera object.
 * @brief CameraContrast::on_pushButtonResetThr_clicked
 */
void CameraContrast::on_pushButtonResetThr_clicked()
{
    ui->horizontalSliderMaxValue->setValue(128);
    ui->horizontalSliderThreshold->setValue(128);
    cams.at(id)->setContrast(-1, -1);
}


/** close the calibration window.
 *  If a calibration has been already started, the calibration process
 *  will not be interrupted.
 * @brief CameraContrast::on_pushButtonCloseCalibWindow_clicked
 */
void CameraContrast::on_pushButtonCloseCalibWindow_clicked()
{
    capture.release();
    this->close();
}
