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
    QLabel *labelGer;
    QLabel *labelWorld;
    QPushButton *pushButtonGer;
    QPushButton *pushButtonWorld;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelGer = new QLabel(centralWidget);
        labelGer->setObjectName(QStringLiteral("labelGer"));
        labelGer->setGeometry(QRect(50, 40, 101, 16));
        labelWorld = new QLabel(centralWidget);
        labelWorld->setObjectName(QStringLiteral("labelWorld"));
        labelWorld->setGeometry(QRect(210, 40, 131, 16));
        pushButtonGer = new QPushButton(centralWidget);
        pushButtonGer->setObjectName(QStringLiteral("pushButtonGer"));
        pushButtonGer->setGeometry(QRect(50, 140, 75, 23));
        pushButtonWorld = new QPushButton(centralWidget);
        pushButtonWorld->setObjectName(QStringLiteral("pushButtonWorld"));
        pushButtonWorld->setGeometry(QRect(220, 140, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
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
        labelGer->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        labelWorld->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButtonGer->setText(QApplication::translate("MainWindow", "PushButtonGer", Q_NULLPTR));
        pushButtonWorld->setText(QApplication::translate("MainWindow", "PushButtonWorld", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
