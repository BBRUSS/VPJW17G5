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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *stopCameraButton;
    QPushButton *startCameraButton;
    QLabel *labelImage;
    QSpinBox *spinBoxCaptureID;
    QLineEdit *lineEdit_2;
    QSlider *horizontalSliderThreshold;
    QSlider *horizontalSliderMaxvalue;
    QLineEdit *lineEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(895, 605);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stopCameraButton = new QPushButton(centralWidget);
        stopCameraButton->setObjectName(QStringLiteral("stopCameraButton"));

        gridLayout->addWidget(stopCameraButton, 2, 1, 1, 1);

        startCameraButton = new QPushButton(centralWidget);
        startCameraButton->setObjectName(QStringLiteral("startCameraButton"));

        gridLayout->addWidget(startCameraButton, 2, 0, 1, 1);

        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelImage->sizePolicy().hasHeightForWidth());
        labelImage->setSizePolicy(sizePolicy);
        labelImage->setMinimumSize(QSize(20, 20));
        labelImage->setAutoFillBackground(false);
        labelImage->setFrameShape(QFrame::Box);

        gridLayout->addWidget(labelImage, 0, 0, 1, 5);

        spinBoxCaptureID = new QSpinBox(centralWidget);
        spinBoxCaptureID->setObjectName(QStringLiteral("spinBoxCaptureID"));
        spinBoxCaptureID->setMinimum(-1);

        gridLayout->addWidget(spinBoxCaptureID, 2, 2, 1, 1);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 4, 1, 1);

        horizontalSliderThreshold = new QSlider(centralWidget);
        horizontalSliderThreshold->setObjectName(QStringLiteral("horizontalSliderThreshold"));
        horizontalSliderThreshold->setMaximum(255);
        horizontalSliderThreshold->setValue(128);
        horizontalSliderThreshold->setOrientation(Qt::Horizontal);
        horizontalSliderThreshold->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(horizontalSliderThreshold, 2, 3, 1, 1);

        horizontalSliderMaxvalue = new QSlider(centralWidget);
        horizontalSliderMaxvalue->setObjectName(QStringLiteral("horizontalSliderMaxvalue"));
        horizontalSliderMaxvalue->setMaximum(255);
        horizontalSliderMaxvalue->setValue(128);
        horizontalSliderMaxvalue->setOrientation(Qt::Horizontal);
        horizontalSliderMaxvalue->setTickPosition(QSlider::TicksBelow);

        gridLayout->addWidget(horizontalSliderMaxvalue, 2, 4, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Camera Calibration", Q_NULLPTR));
        stopCameraButton->setText(QApplication::translate("MainWindow", "Stop Camera", Q_NULLPTR));
        startCameraButton->setText(QApplication::translate("MainWindow", "Start Camera (F5)", Q_NULLPTR));
        labelImage->setText(QString());
        lineEdit_2->setText(QApplication::translate("MainWindow", "Max-Value", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "Black/White Treshold", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
