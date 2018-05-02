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
#include <QtWidgets/QLabel>
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
    QLabel *label_distImg;
    QLabel *label_unDistImg;
    QPushButton *pushButton_startStop;
    QPushButton *pushButton_takeSnap;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_distImg = new QLabel(centralWidget);
        label_distImg->setObjectName(QStringLiteral("label_distImg"));
        label_distImg->setGeometry(QRect(100, 50, 250, 250));
        label_unDistImg = new QLabel(centralWidget);
        label_unDistImg->setObjectName(QStringLiteral("label_unDistImg"));
        label_unDistImg->setGeometry(QRect(450, 50, 250, 250));
        pushButton_startStop = new QPushButton(centralWidget);
        pushButton_startStop->setObjectName(QStringLiteral("pushButton_startStop"));
        pushButton_startStop->setGeometry(QRect(175, 400, 100, 30));
        pushButton_takeSnap = new QPushButton(centralWidget);
        pushButton_takeSnap->setObjectName(QStringLiteral("pushButton_takeSnap"));
        pushButton_takeSnap->setGeometry(QRect(525, 400, 100, 30));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
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
        label_distImg->setText(QString());
        label_unDistImg->setText(QString());
        pushButton_startStop->setText(QApplication::translate("MainWindow", "start", Q_NULLPTR));
        pushButton_takeSnap->setText(QApplication::translate("MainWindow", "take snap", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
