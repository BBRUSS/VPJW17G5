/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *after_img;
    QLabel *brightnessValue_label;
    QLabel *exposureValue_label;
    QLabel *with_label;
    QSpinBox *distHeight_spinBox;
    QLabel *contrastValue_label;
    QLabel *success_label;
    QSpinBox *distWidth_spinBox;
    QLabel *height_label;
    QLabel *camValue_label;
    QLabel *before_img;
    QSpacerItem *horizontalSpacer;
    QLabel *before_label;
    QLabel *after_label;
    QFrame *line;
    QPushButton *startCameraButton;
    QPushButton *takeSnapshotButton;
    QLabel *selectContrast_label;
    QLabel *selectCam_label;
    QPushButton *saveButton;
    QPushButton *resetButton;
    QLabel *selectExposure_label;
    QLabel *selectBrightness_label;
    QSlider *cameraSlider;
    QFrame *line_2;
    QSlider *exposureSlider;
    QSlider *contrastSlider;
    QSlider *brightnessSlider;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 545);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        after_img = new QLabel(centralWidget);
        after_img->setObjectName(QStringLiteral("after_img"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(after_img->sizePolicy().hasHeightForWidth());
        after_img->setSizePolicy(sizePolicy);
        after_img->setMinimumSize(QSize(20, 20));
        after_img->setLayoutDirection(Qt::RightToLeft);
        after_img->setAutoFillBackground(false);
        after_img->setFrameShape(QFrame::Box);

        gridLayout->addWidget(after_img, 0, 4, 1, 2);

        brightnessValue_label = new QLabel(centralWidget);
        brightnessValue_label->setObjectName(QStringLiteral("brightnessValue_label"));

        gridLayout->addWidget(brightnessValue_label, 10, 5, 1, 1);

        exposureValue_label = new QLabel(centralWidget);
        exposureValue_label->setObjectName(QStringLiteral("exposureValue_label"));

        gridLayout->addWidget(exposureValue_label, 10, 4, 1, 1);

        with_label = new QLabel(centralWidget);
        with_label->setObjectName(QStringLiteral("with_label"));

        gridLayout->addWidget(with_label, 12, 4, 1, 1);

        distHeight_spinBox = new QSpinBox(centralWidget);
        distHeight_spinBox->setObjectName(QStringLiteral("distHeight_spinBox"));
        distHeight_spinBox->setMaximum(500);
        distHeight_spinBox->setValue(55);

        gridLayout->addWidget(distHeight_spinBox, 11, 5, 1, 1);

        contrastValue_label = new QLabel(centralWidget);
        contrastValue_label->setObjectName(QStringLiteral("contrastValue_label"));

        gridLayout->addWidget(contrastValue_label, 10, 2, 1, 1);

        success_label = new QLabel(centralWidget);
        success_label->setObjectName(QStringLiteral("success_label"));

        gridLayout->addWidget(success_label, 11, 1, 1, 2);

        distWidth_spinBox = new QSpinBox(centralWidget);
        distWidth_spinBox->setObjectName(QStringLiteral("distWidth_spinBox"));
        distWidth_spinBox->setMaximum(500);
        distWidth_spinBox->setValue(55);

        gridLayout->addWidget(distWidth_spinBox, 11, 4, 1, 1);

        height_label = new QLabel(centralWidget);
        height_label->setObjectName(QStringLiteral("height_label"));

        gridLayout->addWidget(height_label, 12, 5, 1, 1);

        camValue_label = new QLabel(centralWidget);
        camValue_label->setObjectName(QStringLiteral("camValue_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(camValue_label->sizePolicy().hasHeightForWidth());
        camValue_label->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(camValue_label, 10, 1, 1, 1);

        before_img = new QLabel(centralWidget);
        before_img->setObjectName(QStringLiteral("before_img"));
        sizePolicy.setHeightForWidth(before_img->sizePolicy().hasHeightForWidth());
        before_img->setSizePolicy(sizePolicy);
        before_img->setMinimumSize(QSize(20, 20));
        before_img->setAutoFillBackground(false);
        before_img->setFrameShape(QFrame::Box);

        gridLayout->addWidget(before_img, 0, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(20, 292, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        before_label = new QLabel(centralWidget);
        before_label->setObjectName(QStringLiteral("before_label"));
        before_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(before_label, 2, 1, 1, 2);

        after_label = new QLabel(centralWidget);
        after_label->setObjectName(QStringLiteral("after_label"));
        after_label->setLayoutDirection(Qt::RightToLeft);
        after_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(after_label, 2, 4, 1, 2);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 1, 1, 5);

        startCameraButton = new QPushButton(centralWidget);
        startCameraButton->setObjectName(QStringLiteral("startCameraButton"));

        gridLayout->addWidget(startCameraButton, 5, 1, 1, 1);

        takeSnapshotButton = new QPushButton(centralWidget);
        takeSnapshotButton->setObjectName(QStringLiteral("takeSnapshotButton"));
        takeSnapshotButton->setEnabled(false);

        gridLayout->addWidget(takeSnapshotButton, 5, 2, 1, 1);

        selectContrast_label = new QLabel(centralWidget);
        selectContrast_label->setObjectName(QStringLiteral("selectContrast_label"));

        gridLayout->addWidget(selectContrast_label, 8, 2, 1, 1);

        selectCam_label = new QLabel(centralWidget);
        selectCam_label->setObjectName(QStringLiteral("selectCam_label"));

        gridLayout->addWidget(selectCam_label, 8, 1, 1, 1);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setEnabled(false);

        gridLayout->addWidget(saveButton, 5, 4, 1, 1);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        gridLayout->addWidget(resetButton, 5, 5, 1, 1);

        selectExposure_label = new QLabel(centralWidget);
        selectExposure_label->setObjectName(QStringLiteral("selectExposure_label"));

        gridLayout->addWidget(selectExposure_label, 8, 4, 1, 1);

        selectBrightness_label = new QLabel(centralWidget);
        selectBrightness_label->setObjectName(QStringLiteral("selectBrightness_label"));

        gridLayout->addWidget(selectBrightness_label, 8, 5, 1, 1);

        cameraSlider = new QSlider(centralWidget);
        cameraSlider->setObjectName(QStringLiteral("cameraSlider"));
        cameraSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(cameraSlider, 9, 1, 1, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 7, 1, 1, 5);

        exposureSlider = new QSlider(centralWidget);
        exposureSlider->setObjectName(QStringLiteral("exposureSlider"));
        exposureSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(exposureSlider, 9, 4, 1, 1);

        contrastSlider = new QSlider(centralWidget);
        contrastSlider->setObjectName(QStringLiteral("contrastSlider"));
        contrastSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(contrastSlider, 9, 2, 1, 1);

        brightnessSlider = new QSlider(centralWidget);
        brightnessSlider->setObjectName(QStringLiteral("brightnessSlider"));
        brightnessSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(brightnessSlider, 9, 5, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Camera Calibration", Q_NULLPTR));
        after_img->setText(QString());
        brightnessValue_label->setText(QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        exposureValue_label->setText(QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        with_label->setText(QApplication::translate("MainWindow", "Width Distace (mm) ", Q_NULLPTR));
        contrastValue_label->setText(QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        success_label->setText(QString());
        height_label->setText(QApplication::translate("MainWindow", "Height distance (mm)", Q_NULLPTR));
        camValue_label->setText(QApplication::translate("MainWindow", "Selected Cam: 1", Q_NULLPTR));
        before_img->setText(QString());
        before_label->setText(QApplication::translate("MainWindow", "Before calibration", Q_NULLPTR));
        after_label->setText(QApplication::translate("MainWindow", "After calibration", Q_NULLPTR));
        startCameraButton->setText(QApplication::translate("MainWindow", "Start Camera (F5)", Q_NULLPTR));
        takeSnapshotButton->setText(QApplication::translate("MainWindow", "Take snapshot (F9)", Q_NULLPTR));
        selectContrast_label->setText(QApplication::translate("MainWindow", "Contrast", Q_NULLPTR));
        selectCam_label->setText(QApplication::translate("MainWindow", "Camera", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MainWindow", "Save to XML", Q_NULLPTR));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        selectExposure_label->setText(QApplication::translate("MainWindow", "Exposure", Q_NULLPTR));
        selectBrightness_label->setText(QApplication::translate("MainWindow", "Brightness", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
