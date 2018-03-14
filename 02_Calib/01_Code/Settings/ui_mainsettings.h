/********************************************************************************
** Form generated from reading UI file 'mainsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSETTINGS_H
#define UI_MAINSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MainSettings
{
public:
    QPushButton *pushButtonLoade;
    QLineEdit *lineEdit_int_test;

    void setupUi(QDialog *MainSettings)
    {
        if (MainSettings->objectName().isEmpty())
            MainSettings->setObjectName(QStringLiteral("MainSettings"));
        MainSettings->resize(400, 300);
        pushButtonLoade = new QPushButton(MainSettings);
        pushButtonLoade->setObjectName(QStringLiteral("pushButtonLoade"));
        pushButtonLoade->setGeometry(QRect(270, 200, 93, 28));
        lineEdit_int_test = new QLineEdit(MainSettings);
        lineEdit_int_test->setObjectName(QStringLiteral("lineEdit_int_test"));
        lineEdit_int_test->setEnabled(true);
        lineEdit_int_test->setGeometry(QRect(150, 200, 100, 25));
        lineEdit_int_test->setCursor(QCursor(Qt::IBeamCursor));

        retranslateUi(MainSettings);

        QMetaObject::connectSlotsByName(MainSettings);
    } // setupUi

    void retranslateUi(QDialog *MainSettings)
    {
        MainSettings->setWindowTitle(QApplication::translate("MainSettings", "Dialog", Q_NULLPTR));
        pushButtonLoade->setText(QApplication::translate("MainSettings", "loade", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainSettings: public Ui_MainSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSETTINGS_H
