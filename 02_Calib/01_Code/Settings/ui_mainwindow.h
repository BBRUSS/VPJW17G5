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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoade;
    QLineEdit *lineEdit_int_test;
    QPushButton *pushButtonMainSettings;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(610, 418);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonSave = new QPushButton(centralWidget);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));
        pushButtonSave->setGeometry(QRect(110, 250, 100, 25));
        pushButtonLoade = new QPushButton(centralWidget);
        pushButtonLoade->setObjectName(QStringLiteral("pushButtonLoade"));
        pushButtonLoade->setGeometry(QRect(350, 250, 100, 25));
        lineEdit_int_test = new QLineEdit(centralWidget);
        lineEdit_int_test->setObjectName(QStringLiteral("lineEdit_int_test"));
        lineEdit_int_test->setEnabled(true);
        lineEdit_int_test->setGeometry(QRect(230, 250, 100, 25));
        lineEdit_int_test->setCursor(QCursor(Qt::IBeamCursor));
        pushButtonMainSettings = new QPushButton(centralWidget);
        pushButtonMainSettings->setObjectName(QStringLiteral("pushButtonMainSettings"));
        pushButtonMainSettings->setGeometry(QRect(240, 60, 93, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 610, 21));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        pushButtonLoade->setText(QApplication::translate("MainWindow", "loade", Q_NULLPTR));
        pushButtonMainSettings->setText(QApplication::translate("MainWindow", "main settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
