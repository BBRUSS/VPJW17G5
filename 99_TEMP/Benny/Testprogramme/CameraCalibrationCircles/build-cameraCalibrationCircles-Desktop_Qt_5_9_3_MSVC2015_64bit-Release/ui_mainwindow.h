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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Help;
    QPushButton *pushButton_ShowLogo;
    QPushButton *pushButton_CloseLogo;
    QTextEdit *textEdit_Subline;
    QPushButton *pushButton_StartCalib;
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
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 190, 381, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_Help = new QPushButton(horizontalLayoutWidget);
        pushButton_Help->setObjectName(QStringLiteral("pushButton_Help"));

        horizontalLayout->addWidget(pushButton_Help);

        pushButton_ShowLogo = new QPushButton(horizontalLayoutWidget);
        pushButton_ShowLogo->setObjectName(QStringLiteral("pushButton_ShowLogo"));

        horizontalLayout->addWidget(pushButton_ShowLogo);

        pushButton_CloseLogo = new QPushButton(horizontalLayoutWidget);
        pushButton_CloseLogo->setObjectName(QStringLiteral("pushButton_CloseLogo"));

        horizontalLayout->addWidget(pushButton_CloseLogo);

        textEdit_Subline = new QTextEdit(centralWidget);
        textEdit_Subline->setObjectName(QStringLiteral("textEdit_Subline"));
        textEdit_Subline->setGeometry(QRect(10, 220, 381, 31));
        pushButton_StartCalib = new QPushButton(centralWidget);
        pushButton_StartCalib->setObjectName(QStringLiteral("pushButton_StartCalib"));
        pushButton_StartCalib->setGeometry(QRect(14, 160, 121, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
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
        pushButton_Help->setText(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        pushButton_ShowLogo->setText(QApplication::translate("MainWindow", "Show Logo", Q_NULLPTR));
        pushButton_CloseLogo->setText(QApplication::translate("MainWindow", "Close Logo", Q_NULLPTR));
        pushButton_StartCalib->setText(QApplication::translate("MainWindow", "Start Calibration", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
