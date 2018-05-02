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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBoxFieldHeight;
    QLineEdit *lineEditConstX;
    QSpinBox *spinBoxFieldWidth;
    QPushButton *pushButtonResizeCamField;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonSaveSettings;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBoxChange1;
    QPushButton *pushButtonChange;
    QSpinBox *spinBoxChange2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 805);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 100, 1280, 640));
        label->setFrameShape(QFrame::Box);
        label->setScaledContents(true);
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(520, 0, 260, 101));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBoxFieldHeight = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxFieldHeight->setObjectName(QStringLiteral("spinBoxFieldHeight"));

        horizontalLayout_2->addWidget(spinBoxFieldHeight);

        lineEditConstX = new QLineEdit(horizontalLayoutWidget_2);
        lineEditConstX->setObjectName(QStringLiteral("lineEditConstX"));
        lineEditConstX->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditConstX->sizePolicy().hasHeightForWidth());
        lineEditConstX->setSizePolicy(sizePolicy);
        lineEditConstX->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditConstX);

        spinBoxFieldWidth = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxFieldWidth->setObjectName(QStringLiteral("spinBoxFieldWidth"));

        horizontalLayout_2->addWidget(spinBoxFieldWidth);

        pushButtonResizeCamField = new QPushButton(horizontalLayoutWidget_2);
        pushButtonResizeCamField->setObjectName(QStringLiteral("pushButtonResizeCamField"));

        horizontalLayout_2->addWidget(pushButtonResizeCamField);

        horizontalLayoutWidget_4 = new QWidget(centralWidget);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(1140, 0, 111, 101));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButtonSaveSettings = new QPushButton(horizontalLayoutWidget_4);
        pushButtonSaveSettings->setObjectName(QStringLiteral("pushButtonSaveSettings"));

        horizontalLayout_4->addWidget(pushButtonSaveSettings);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 0, 221, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spinBoxChange1 = new QSpinBox(horizontalLayoutWidget);
        spinBoxChange1->setObjectName(QStringLiteral("spinBoxChange1"));

        horizontalLayout->addWidget(spinBoxChange1);

        pushButtonChange = new QPushButton(horizontalLayoutWidget);
        pushButtonChange->setObjectName(QStringLiteral("pushButtonChange"));

        horizontalLayout->addWidget(pushButtonChange);

        spinBoxChange2 = new QSpinBox(horizontalLayoutWidget);
        spinBoxChange2->setObjectName(QStringLiteral("spinBoxChange2"));

        horizontalLayout->addWidget(spinBoxChange2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 26));
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
        label->setText(QString());
        lineEditConstX->setText(QApplication::translate("MainWindow", "      X", Q_NULLPTR));
        pushButtonResizeCamField->setText(QApplication::translate("MainWindow", "resize Cam", Q_NULLPTR));
        pushButtonSaveSettings->setText(QApplication::translate("MainWindow", "save settings", Q_NULLPTR));
        pushButtonChange->setText(QApplication::translate("MainWindow", "Change", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
