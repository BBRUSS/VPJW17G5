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
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelImageContrast;
    QLabel *labelImageOrig;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_3;
    QSpinBox *spinBoxCameraID;
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
        CameraContrast->resize(931, 526);
        horizontalLayoutWidget = new QWidget(CameraContrast);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 470, 254, 23));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonStartCam = new QPushButton(horizontalLayoutWidget);
        pushButtonStartCam->setObjectName(QStringLiteral("pushButtonStartCam"));

        horizontalLayout->addWidget(pushButtonStartCam);

        pushButtonStopCam = new QPushButton(horizontalLayoutWidget);
        pushButtonStopCam->setObjectName(QStringLiteral("pushButtonStopCam"));
        pushButtonStopCam->setEnabled(false);

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
        horizontalSliderThreshold->setMaximum(255);
        horizontalSliderThreshold->setValue(128);
        horizontalSliderThreshold->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderThreshold);

        horizontalSliderMaxValue = new QSlider(horizontalLayoutWidget_2);
        horizontalSliderMaxValue->setObjectName(QStringLiteral("horizontalSliderMaxValue"));
        horizontalSliderMaxValue->setMaximum(255);
        horizontalSliderMaxValue->setValue(128);
        horizontalSliderMaxValue->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSliderMaxValue);

        horizontalLayoutWidget_3 = new QWidget(CameraContrast);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(280, 440, 641, 24));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMouseTracking(false);
        lineEdit->setAutoFillBackground(true);
        lineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMouseTracking(false);
        lineEdit_2->setAutoFillBackground(true);
        lineEdit_2->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEdit_2);

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
        lineEdit_3 = new QLineEdit(horizontalLayoutWidget_5);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMouseTracking(false);
        lineEdit_3->setReadOnly(true);

        horizontalLayout_5->addWidget(lineEdit_3);

        spinBoxCameraID = new QSpinBox(horizontalLayoutWidget_5);
        spinBoxCameraID->setObjectName(QStringLiteral("spinBoxCameraID"));
        spinBoxCameraID->setValue(1);

        horizontalLayout_5->addWidget(spinBoxCameraID);

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
        pushButtonStartCam->setText(QApplication::translate("CameraContrast", "Start Camera", nullptr));
        pushButtonStopCam->setText(QApplication::translate("CameraContrast", "Stop Camera", nullptr));
        pushButtonSaveContrast->setText(QApplication::translate("CameraContrast", "Save", nullptr));
        lineEdit->setText(QApplication::translate("CameraContrast", "Black/White Threshold", nullptr));
        lineEdit_2->setText(QApplication::translate("CameraContrast", "Max-Value", nullptr));
        labelImageContrast->setText(QString());
        labelImageOrig->setText(QString());
        lineEdit_3->setText(QApplication::translate("CameraContrast", "Camera ID:", nullptr));
        pushButtonGetIntrinsics->setText(QApplication::translate("CameraContrast", "get Intrinsics", nullptr));
        pushButtonGetExtrinsics->setText(QApplication::translate("CameraContrast", "get Extrinsics", nullptr));
        pushButtonResetThr->setText(QApplication::translate("CameraContrast", "Reset", nullptr));
        pushButtonCloseCalibWindow->setText(QApplication::translate("CameraContrast", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraContrast: public Ui_CameraContrast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERACONTRAST_H
