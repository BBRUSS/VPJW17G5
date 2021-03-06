/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *textEditCalibPattern;
    QTextEdit *textEdit;
    QSlider *horizontalSliderCalibPattern;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonSetContrast;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QCheckBox *checkBoxWhiteOnBlack;
    QLabel *labelSize;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(418, 313);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEditCalibPattern = new QTextEdit(centralWidget);
        textEditCalibPattern->setObjectName(QStringLiteral("textEditCalibPattern"));
        textEditCalibPattern->setGeometry(QRect(217, 50, 151, 31));
        textEditCalibPattern->setAutoFillBackground(true);
        textEditCalibPattern->setFrameShape(QFrame::NoFrame);
        textEditCalibPattern->setReadOnly(true);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(217, 10, 201, 31));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setReadOnly(true);
        horizontalSliderCalibPattern = new QSlider(centralWidget);
        horizontalSliderCalibPattern->setObjectName(QStringLiteral("horizontalSliderCalibPattern"));
        horizontalSliderCalibPattern->setGeometry(QRect(370, 50, 41, 31));
        horizontalSliderCalibPattern->setMaximum(2);
        horizontalSliderCalibPattern->setValue(2);
        horizontalSliderCalibPattern->setSliderPosition(2);
        horizontalSliderCalibPattern->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 220, 160, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonSetContrast = new QPushButton(verticalLayoutWidget);
        pushButtonSetContrast->setObjectName(QStringLiteral("pushButtonSetContrast"));

        verticalLayout->addWidget(pushButtonSetContrast);

        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(220, 220, 80, 21));
        pushButtonLoad = new QPushButton(centralWidget);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));
        pushButtonLoad->setGeometry(QRect(310, 220, 80, 21));
        checkBoxWhiteOnBlack = new QCheckBox(centralWidget);
        checkBoxWhiteOnBlack->setObjectName(QStringLiteral("checkBoxWhiteOnBlack"));
        checkBoxWhiteOnBlack->setGeometry(QRect(220, 90, 91, 19));
        labelSize = new QLabel(centralWidget);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setGeometry(QRect(220, 120, 191, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 418, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Camera Navigation", nullptr));
        textEditCalibPattern->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Calibration pattern</p></body></html>", nullptr));
        pushButtonSetContrast->setText(QApplication::translate("MainWindow", "Calibrate", nullptr));
        pushButtonSave->setText(QApplication::translate("MainWindow", "Save Settings", nullptr));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "Load Settings", nullptr));
        checkBoxWhiteOnBlack->setText(QApplication::translate("MainWindow", "White on Black", nullptr));
        labelSize->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
