/********************************************************************************
** Form generated from reading UI file 'createnewxml.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWXML_H
#define UI_CREATENEWXML_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_createNewXML
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBoxCamFieldWidth;
    QSpinBox *spinBoxCamFieldHeight;
    QLineEdit *lineEdit_3;
    QTextEdit *textEditFileName;
    QLineEdit *lineEdit_4;
    QSpinBox *spinBoxPatternHeight;
    QSpinBox *spinBoxPatternWidth;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QSpinBox *spinBoxPatternSquareSize;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonOK;
    QLineEdit *lineEdit_8;
    QSpinBox *spinBoxCamID;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSliderCalibPattern;
    QSlider *horizontalSliderFixAspectRatio;
    QSlider *horizontalSliderZeroTangDist;
    QSlider *horizontalSliderFixPrincPoint;

    void setupUi(QDialog *createNewXML)
    {
        if (createNewXML->objectName().isEmpty())
            createNewXML->setObjectName(QStringLiteral("createNewXML"));
        createNewXML->resize(407, 508);
        lineEdit = new QLineEdit(createNewXML);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 80, 113, 21));
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(createNewXML);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 110, 113, 21));
        lineEdit_2->setReadOnly(true);
        spinBoxCamFieldWidth = new QSpinBox(createNewXML);
        spinBoxCamFieldWidth->setObjectName(QStringLiteral("spinBoxCamFieldWidth"));
        spinBoxCamFieldWidth->setGeometry(QRect(140, 110, 43, 22));
        spinBoxCamFieldHeight = new QSpinBox(createNewXML);
        spinBoxCamFieldHeight->setObjectName(QStringLiteral("spinBoxCamFieldHeight"));
        spinBoxCamFieldHeight->setGeometry(QRect(140, 80, 43, 22));
        lineEdit_3 = new QLineEdit(createNewXML);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(10, 50, 113, 21));
        lineEdit_3->setReadOnly(true);
        textEditFileName = new QTextEdit(createNewXML);
        textEditFileName->setObjectName(QStringLiteral("textEditFileName"));
        textEditFileName->setGeometry(QRect(140, 50, 104, 20));
        lineEdit_4 = new QLineEdit(createNewXML);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(10, 150, 113, 21));
        lineEdit_4->setReadOnly(true);
        spinBoxPatternHeight = new QSpinBox(createNewXML);
        spinBoxPatternHeight->setObjectName(QStringLiteral("spinBoxPatternHeight"));
        spinBoxPatternHeight->setGeometry(QRect(140, 180, 43, 22));
        spinBoxPatternWidth = new QSpinBox(createNewXML);
        spinBoxPatternWidth->setObjectName(QStringLiteral("spinBoxPatternWidth"));
        spinBoxPatternWidth->setGeometry(QRect(140, 210, 43, 22));
        lineEdit_5 = new QLineEdit(createNewXML);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(10, 180, 113, 21));
        lineEdit_5->setReadOnly(true);
        lineEdit_6 = new QLineEdit(createNewXML);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(10, 210, 113, 21));
        lineEdit_6->setReadOnly(true);
        lineEdit_7 = new QLineEdit(createNewXML);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(10, 240, 113, 21));
        lineEdit_7->setReadOnly(true);
        spinBoxPatternSquareSize = new QSpinBox(createNewXML);
        spinBoxPatternSquareSize->setObjectName(QStringLiteral("spinBoxPatternSquareSize"));
        spinBoxPatternSquareSize->setGeometry(QRect(140, 240, 43, 22));
        pushButtonCancel = new QPushButton(createNewXML);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(110, 470, 80, 21));
        pushButtonOK = new QPushButton(createNewXML);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(210, 470, 80, 21));
        lineEdit_8 = new QLineEdit(createNewXML);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(10, 340, 113, 21));
        lineEdit_8->setReadOnly(true);
        spinBoxCamID = new QSpinBox(createNewXML);
        spinBoxCamID->setObjectName(QStringLiteral("spinBoxCamID"));
        spinBoxCamID->setGeometry(QRect(140, 340, 43, 22));
        lineEdit_9 = new QLineEdit(createNewXML);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(10, 370, 113, 21));
        lineEdit_9->setReadOnly(true);
        lineEdit_10 = new QLineEdit(createNewXML);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(10, 400, 131, 21));
        lineEdit_10->setReadOnly(true);
        lineEdit_11 = new QLineEdit(createNewXML);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(10, 430, 113, 21));
        lineEdit_11->setReadOnly(true);
        label = new QLabel(createNewXML);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 381, 31));
        label->setFrameShape(QFrame::StyledPanel);
        label->setLineWidth(4);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(createNewXML);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 300, 381, 31));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setLineWidth(4);
        label_2->setAlignment(Qt::AlignCenter);
        horizontalSliderCalibPattern = new QSlider(createNewXML);
        horizontalSliderCalibPattern->setObjectName(QStringLiteral("horizontalSliderCalibPattern"));
        horizontalSliderCalibPattern->setGeometry(QRect(140, 150, 81, 16));
        horizontalSliderCalibPattern->setMaximum(3);
        horizontalSliderCalibPattern->setOrientation(Qt::Horizontal);
        horizontalSliderCalibPattern->setInvertedAppearance(false);
        horizontalSliderCalibPattern->setInvertedControls(false);
        horizontalSliderFixAspectRatio = new QSlider(createNewXML);
        horizontalSliderFixAspectRatio->setObjectName(QStringLiteral("horizontalSliderFixAspectRatio"));
        horizontalSliderFixAspectRatio->setGeometry(QRect(140, 370, 41, 16));
        horizontalSliderFixAspectRatio->setMaximum(1);
        horizontalSliderFixAspectRatio->setOrientation(Qt::Horizontal);
        horizontalSliderFixAspectRatio->setInvertedAppearance(false);
        horizontalSliderFixAspectRatio->setInvertedControls(false);
        horizontalSliderZeroTangDist = new QSlider(createNewXML);
        horizontalSliderZeroTangDist->setObjectName(QStringLiteral("horizontalSliderZeroTangDist"));
        horizontalSliderZeroTangDist->setGeometry(QRect(140, 400, 41, 16));
        horizontalSliderZeroTangDist->setMaximum(1);
        horizontalSliderZeroTangDist->setOrientation(Qt::Horizontal);
        horizontalSliderZeroTangDist->setInvertedAppearance(false);
        horizontalSliderZeroTangDist->setInvertedControls(false);
        horizontalSliderFixPrincPoint = new QSlider(createNewXML);
        horizontalSliderFixPrincPoint->setObjectName(QStringLiteral("horizontalSliderFixPrincPoint"));
        horizontalSliderFixPrincPoint->setGeometry(QRect(140, 430, 41, 16));
        horizontalSliderFixPrincPoint->setMaximum(1);
        horizontalSliderFixPrincPoint->setOrientation(Qt::Horizontal);
        horizontalSliderFixPrincPoint->setInvertedAppearance(false);
        horizontalSliderFixPrincPoint->setInvertedControls(false);

        retranslateUi(createNewXML);

        QMetaObject::connectSlotsByName(createNewXML);
    } // setupUi

    void retranslateUi(QDialog *createNewXML)
    {
        createNewXML->setWindowTitle(QApplication::translate("createNewXML", "Dialog", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit->setText(QApplication::translate("createNewXML", "Num Cams Height", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_2->setText(QApplication::translate("createNewXML", "Num Cams Width", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_3->setText(QApplication::translate("createNewXML", "Filename", nullptr));
        textEditFileName->setHtml(QApplication::translate("createNewXML", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">settings.xml</p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_4->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_4->setText(QApplication::translate("createNewXML", "Calibration Pattern", nullptr));
        lineEdit_5->setText(QApplication::translate("createNewXML", "Num Pattern  Height", nullptr));
        lineEdit_6->setText(QApplication::translate("createNewXML", "Num Pattern  Width", nullptr));
        lineEdit_7->setText(QApplication::translate("createNewXML", "Pattern Square Size", nullptr));
        pushButtonCancel->setText(QApplication::translate("createNewXML", "Cancel", nullptr));
        pushButtonOK->setText(QApplication::translate("createNewXML", "OK", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_8->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_8->setText(QApplication::translate("createNewXML", "Camera ID", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_9->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_9->setText(QApplication::translate("createNewXML", "Fix aspect ratio", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_10->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_10->setText(QApplication::translate("createNewXML", "Zero tangential distortion", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_11->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        lineEdit_11->setText(QApplication::translate("createNewXML", "Fix principal point", nullptr));
        label->setText(QApplication::translate("createNewXML", "Global Settings", nullptr));
        label_2->setText(QApplication::translate("createNewXML", "Camera Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createNewXML: public Ui_createNewXML {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWXML_H
