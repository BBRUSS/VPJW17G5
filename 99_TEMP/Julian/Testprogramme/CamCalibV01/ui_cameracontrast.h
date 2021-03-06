/********************************************************************************
** Form generated from reading UI file 'cameracontrast.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERACONTRAST_H
#define UI_CAMERACONTRAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraContrast
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonStartCam;
    QPushButton *pushButtonStopCam;
    QPushButton *pushButtonSaveContrast;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSliderThreshold;
    QSlider *horizontalSliderMaxValue;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelBWThreshold;
    QLabel *labelMaxValue;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelImageContrast;
    QLabel *labelImageOrig;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelCamID;
    QSpinBox *spinBoxCameraNr;
    QLineEdit *lineEditStatus;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonGetIntrinsics;
    QPushButton *pushButtonGetExtrinsics;
    QPushButton *pushButtonResetThr;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonCloseCalibWindow;

    void setupUi(QDialog *CameraContrast)
    {
        if (CameraContrast->objectName().isEmpty())
            CameraContrast->setObjectName(QStringLiteral("CameraContrast"));
        CameraContrast->resize(929, 532);
        horizontalLayoutWidget = new QWidget(CameraContrast);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 470, 254, 23));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonStartCam = new QPushButton(horizontalLayoutWidget);
        pushButtonStartCam->setObjectName(QStringLiteral("pushButtonStartCam"));
        pushButtonStartCam->setMouseTracking(true);
        pushButtonStartCam->setToolTipDuration(-1);

        horizontalLayout->addWidget(pushButtonStartCam);

        pushButtonStopCam = new QPushButton(horizontalLayoutWidget);
        pushButtonStopCam->setObjectName(QStringLiteral("pushButtonStopCam"));
        pushButtonStopCam->setEnabled(false);
        pushButtonStopCam->setToolTipDuration(-1);

        horizontalLayout->addWidget(pushButtonStopCam);

        pushButtonSaveContrast = new QPushButton(horizontalLayoutWidget);
        pushButtonSaveContrast->setObjectName(QStringLiteral("pushButtonSaveContrast"));
        pushButtonSaveContrast->setEnabled(false);

        horizontalLayout->addWidget(pushButtonSaveContrast);

        horizontalLayoutWidget_2 = new QWidget(CameraContrast);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(280, 470, 641, 21));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSliderThreshold = new QSlider(horizontalLayoutWidget_2);
        horizontalSliderThreshold->setObjectName(QStringLiteral("horizontalSliderThreshold"));
        horizontalSliderThreshold->setEnabled(false);
        horizontalSliderThreshold->setToolTipDuration(-1);
        horizontalSliderThreshold->setMaximum(255);
        horizontalSliderThreshold->setValue(128);
        horizontalSliderThreshold->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderThreshold);

        horizontalSliderMaxValue = new QSlider(horizontalLayoutWidget_2);
        horizontalSliderMaxValue->setObjectName(QStringLiteral("horizontalSliderMaxValue"));
        horizontalSliderMaxValue->setEnabled(false);
        horizontalSliderMaxValue->setMaximum(255);
        horizontalSliderMaxValue->setValue(255);
        horizontalSliderMaxValue->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderMaxValue);

        horizontalLayoutWidget_3 = new QWidget(CameraContrast);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(280, 440, 641, 24));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelBWThreshold = new QLabel(horizontalLayoutWidget_3);
        labelBWThreshold->setObjectName(QStringLiteral("labelBWThreshold"));

        horizontalLayout_3->addWidget(labelBWThreshold);

        labelMaxValue = new QLabel(horizontalLayoutWidget_3);
        labelMaxValue->setObjectName(QStringLiteral("labelMaxValue"));

        horizontalLayout_3->addWidget(labelMaxValue);

        horizontalLayoutWidget_4 = new QWidget(CameraContrast);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 29, 911, 381));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelImageContrast = new QLabel(horizontalLayoutWidget_4);
        labelImageContrast->setObjectName(QStringLiteral("labelImageContrast"));
        labelImageContrast->setFrameShape(QFrame::StyledPanel);
        labelImageContrast->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(labelImageContrast);

        labelImageOrig = new QLabel(horizontalLayoutWidget_4);
        labelImageOrig->setObjectName(QStringLiteral("labelImageOrig"));
        labelImageOrig->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_4->addWidget(labelImageOrig);

        horizontalLayoutWidget_5 = new QWidget(CameraContrast);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 440, 251, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        labelCamID = new QLabel(horizontalLayoutWidget_5);
        labelCamID->setObjectName(QStringLiteral("labelCamID"));

        horizontalLayout_5->addWidget(labelCamID);

        spinBoxCameraNr = new QSpinBox(horizontalLayoutWidget_5);
        spinBoxCameraNr->setObjectName(QStringLiteral("spinBoxCameraNr"));
        spinBoxCameraNr->setValue(1);

        horizontalLayout_5->addWidget(spinBoxCameraNr);

        lineEditStatus = new QLineEdit(horizontalLayoutWidget_5);
        lineEditStatus->setObjectName(QStringLiteral("lineEditStatus"));
        lineEditStatus->setMouseTracking(false);
        lineEditStatus->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEditStatus);

        horizontalLayoutWidget_6 = new QWidget(CameraContrast);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 490, 911, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButtonGetIntrinsics = new QPushButton(horizontalLayoutWidget_6);
        pushButtonGetIntrinsics->setObjectName(QStringLiteral("pushButtonGetIntrinsics"));
        pushButtonGetIntrinsics->setEnabled(false);

        horizontalLayout_6->addWidget(pushButtonGetIntrinsics);

        pushButtonGetExtrinsics = new QPushButton(horizontalLayoutWidget_6);
        pushButtonGetExtrinsics->setObjectName(QStringLiteral("pushButtonGetExtrinsics"));
        pushButtonGetExtrinsics->setEnabled(false);

        horizontalLayout_6->addWidget(pushButtonGetExtrinsics);

        pushButtonResetThr = new QPushButton(horizontalLayoutWidget_6);
        pushButtonResetThr->setObjectName(QStringLiteral("pushButtonResetThr"));
        pushButtonResetThr->setEnabled(false);

        horizontalLayout_6->addWidget(pushButtonResetThr);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButtonCloseCalibWindow = new QPushButton(horizontalLayoutWidget_6);
        pushButtonCloseCalibWindow->setObjectName(QStringLiteral("pushButtonCloseCalibWindow"));

        horizontalLayout_6->addWidget(pushButtonCloseCalibWindow);


        retranslateUi(CameraContrast);

        QMetaObject::connectSlotsByName(CameraContrast);
    } // setupUi

    void retranslateUi(QDialog *CameraContrast)
    {
        CameraContrast->setWindowTitle(QApplication::translate("CameraContrast", "Calibration", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonStartCam->setToolTip(QApplication::translate("CameraContrast", "Connect to camera with chosen ID", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonStartCam->setText(QApplication::translate("CameraContrast", "Start Camera", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonStopCam->setToolTip(QApplication::translate("CameraContrast", "Disconnect from camera", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonStopCam->setText(QApplication::translate("CameraContrast", "Stop Camera", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonSaveContrast->setToolTip(QApplication::translate("CameraContrast", "Save threshold and max value to camera, in order to use them in calibration processes", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonSaveContrast->setText(QApplication::translate("CameraContrast", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        horizontalSliderThreshold->setToolTip(QApplication::translate("CameraContrast", "Slide this value to change the black / white treshold", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        horizontalSliderMaxValue->setToolTip(QApplication::translate("CameraContrast", "Slide this value to change the maximum value", nullptr));
#endif // QT_NO_TOOLTIP
        labelBWThreshold->setText(QApplication::translate("CameraContrast", "Black/White Threshold", nullptr));
        labelMaxValue->setText(QApplication::translate("CameraContrast", "Max-Value", nullptr));
        labelImageContrast->setText(QString());
        labelImageOrig->setText(QString());
        labelCamID->setText(QApplication::translate("CameraContrast", " Camera Nr: ", nullptr));
#ifndef QT_NO_TOOLTIP
        spinBoxCameraNr->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pushButtonGetIntrinsics->setToolTip(QApplication::translate("CameraContrast", "Start calibration process for chosen camera to get intrinsic parameters", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonGetIntrinsics->setText(QApplication::translate("CameraContrast", "get Intrinsics", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonGetExtrinsics->setToolTip(QApplication::translate("CameraContrast", "Start calibration process for chosen camera to get extrinsic parameters", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonGetExtrinsics->setText(QApplication::translate("CameraContrast", "get Extrinsics", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonResetThr->setToolTip(QApplication::translate("CameraContrast", "Reset threshold and max-value", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonResetThr->setText(QApplication::translate("CameraContrast", "Reset", nullptr));
        pushButtonCloseCalibWindow->setText(QApplication::translate("CameraContrast", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraContrast: public Ui_CameraContrast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACONTRAST_H
