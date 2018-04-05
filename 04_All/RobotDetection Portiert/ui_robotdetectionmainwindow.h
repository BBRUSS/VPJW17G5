/********************************************************************************
** Form generated from reading UI file 'robotdetectionmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTDETECTIONMAINWINDOW_H
#define UI_ROBOTDETECTIONMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobotDetectionMainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_10;
    QTabWidget *tabMain;
    QWidget *tabMain_Navigation;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_NavigationWindow;
    QLabel *labelImage;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButtonStartStop;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBoxLiveView;
    QCheckBox *checkBox_Measurement;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelUDPFPS;
    QLabel *labelFPS;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonCalibrateOffset;
    QHBoxLayout *horizontalLayout_30;
    QLabel *labelBigNone_5;
    QLabel *value_threshold;
    QSlider *slider_threshold;
    QHBoxLayout *horizontalLayout;
    QLabel *labelBigNone_6;
    QLabel *value_cornerRefinementMinAccuracy;
    QSlider *slider_cornerRefinementMinAccuracy;
    QHBoxLayout *horizontalLayout_31;
    QLabel *labelMaxMiddle_5;
    QLabel *labelMaxMiddleValue_5;
    QSlider *slider_cornerRefinementMaxIterations;
    QHBoxLayout *horizontalLayout_35;
    QLabel *labelMaxMiddle_9;
    QLabel *value_errorCorrectionRate;
    QSlider *slider_errorCorrectionRate;
    QHBoxLayout *horizontalLayout_34;
    QLabel *labelMaxMiddle_8;
    QLabel *value_minMarkerPerimeterRate;
    QSlider *slider_minMarkerPerimeterRate;
    QHBoxLayout *horizontalLayout_40;
    QLabel *labelMaxMiddle_14;
    QLabel *value_maxMarkerPerimeterRate;
    QSlider *slider_maxMarkerPerimeterRate;
    QHBoxLayout *horizontalLayout_36;
    QLabel *labelMaxMiddle_10;
    QLabel *value_polygonalApproxAccuracyRate;
    QSlider *slider_polygonalApproxAccuracyRate;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelMaxMiddle_20;
    QLabel *value_adaptiveThreshWinSizeStepMin;
    QSlider *slider_adaptiveThreshWinSizeMin;
    QHBoxLayout *horizontalLayout_37;
    QLabel *labelMaxMiddle_12;
    QLabel *value_adaptiveThreshWinSizeStep;
    QSlider *slider_adaptiveThreshWinSizeStep;
    QHBoxLayout *horizontalLayout_38;
    QLabel *labelMaxMiddle_13;
    QLabel *value_adaptiveThreshConstant;
    QSlider *slider_adaptiveThreshConstant;
    QHBoxLayout *horizontalLayout_41;
    QLabel *labelMaxMiddle_15;
    QLabel *value_perspectiveRemovePixelPerCell;
    QSlider *slider_perspectiveRemovePixelPerCell;
    QHBoxLayout *horizontalLayout_42;
    QLabel *labelMaxMiddle_16;
    QLabel *value_MinSizeofRects;
    QSlider *slider_MinSizeofRects;
    QLabel *labelVersion;
    QLabel *labelLogo;
    QWidget *tabMain_Calibration;
    QWidget *tabMain_Aruco;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_ArucoMarker;
    QLabel *label_arucomarker;
    QVBoxLayout *verticalLayout_arucoList;
    QTableWidget *tableWidget_Aruco;
    QHBoxLayout *horizontalLayout_arucoButtons;
    QPushButton *pushButton_addAruco;
    QPushButton *pushButton_deleteAruco;
    QPushButton *pushButton_SaveToImage;
    QWidget *tabSettings;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QSpinBox *spinBoxChange1;
    QPushButton *pushButtonChange;
    QSpinBox *spinBoxChange2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *spinBoxFieldHeight;
    QLabel *labelFieldX;
    QSpinBox *spinBoxFieldWidth;
    QPushButton *pushButtonResizeCamField;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButtonSaveSettings;
    QHBoxLayout *horizontalLayout_11;
    QLabel *labelCamFieldSettings;
    QScrollArea *scrollAreaSettings;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RobotDetectionMainWindow)
    {
        if (RobotDetectionMainWindow->objectName().isEmpty())
            RobotDetectionMainWindow->setObjectName(QStringLiteral("RobotDetectionMainWindow"));
        RobotDetectionMainWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RobotDetectionMainWindow->sizePolicy().hasHeightForWidth());
        RobotDetectionMainWindow->setSizePolicy(sizePolicy);
        RobotDetectionMainWindow->setMinimumSize(QSize(640, 480));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/Hawhamburg-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        RobotDetectionMainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(RobotDetectionMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_10 = new QVBoxLayout(centralWidget);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName(QStringLiteral("tabMain"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabMain->sizePolicy().hasHeightForWidth());
        tabMain->setSizePolicy(sizePolicy1);
        tabMain_Navigation = new QWidget();
        tabMain_Navigation->setObjectName(QStringLiteral("tabMain_Navigation"));
        sizePolicy1.setHeightForWidth(tabMain_Navigation->sizePolicy().hasHeightForWidth());
        tabMain_Navigation->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(tabMain_Navigation);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_NavigationWindow = new QHBoxLayout();
        horizontalLayout_NavigationWindow->setSpacing(6);
        horizontalLayout_NavigationWindow->setObjectName(QStringLiteral("horizontalLayout_NavigationWindow"));
        horizontalLayout_NavigationWindow->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelImage = new QLabel(tabMain_Navigation);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(10);
        sizePolicy2.setVerticalStretch(10);
        sizePolicy2.setHeightForWidth(labelImage->sizePolicy().hasHeightForWidth());
        labelImage->setSizePolicy(sizePolicy2);
        labelImage->setMinimumSize(QSize(0, 0));
        labelImage->setMaximumSize(QSize(16777215, 16777215));
        labelImage->setSizeIncrement(QSize(10, 10));
        labelImage->setBaseSize(QSize(2, 2));
        labelImage->setFrameShape(QFrame::StyledPanel);
        labelImage->setFrameShadow(QFrame::Sunken);
        labelImage->setScaledContents(true);

        horizontalLayout_NavigationWindow->addWidget(labelImage);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, -1, -1, -1);
        pushButtonStartStop = new QPushButton(tabMain_Navigation);
        pushButtonStartStop->setObjectName(QStringLiteral("pushButtonStartStop"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(pushButtonStartStop->sizePolicy().hasHeightForWidth());
        pushButtonStartStop->setSizePolicy(sizePolicy3);

        verticalLayout_9->addWidget(pushButtonStartStop);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(2, 6, -1, 6);
        checkBoxLiveView = new QCheckBox(tabMain_Navigation);
        checkBoxLiveView->setObjectName(QStringLiteral("checkBoxLiveView"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(checkBoxLiveView->sizePolicy().hasHeightForWidth());
        checkBoxLiveView->setSizePolicy(sizePolicy4);
        QFont font;
        font.setKerning(true);
        checkBoxLiveView->setFont(font);

        horizontalLayout_5->addWidget(checkBoxLiveView);

        checkBox_Measurement = new QCheckBox(tabMain_Navigation);
        checkBox_Measurement->setObjectName(QStringLiteral("checkBox_Measurement"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(checkBox_Measurement->sizePolicy().hasHeightForWidth());
        checkBox_Measurement->setSizePolicy(sizePolicy5);
        checkBox_Measurement->setBaseSize(QSize(0, 0));

        horizontalLayout_5->addWidget(checkBox_Measurement);


        verticalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(2, 6, -1, 6);
        labelUDPFPS = new QLabel(tabMain_Navigation);
        labelUDPFPS->setObjectName(QStringLiteral("labelUDPFPS"));
        sizePolicy5.setHeightForWidth(labelUDPFPS->sizePolicy().hasHeightForWidth());
        labelUDPFPS->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(labelUDPFPS);

        labelFPS = new QLabel(tabMain_Navigation);
        labelFPS->setObjectName(QStringLiteral("labelFPS"));
        sizePolicy5.setHeightForWidth(labelFPS->sizePolicy().hasHeightForWidth());
        labelFPS->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(labelFPS);


        verticalLayout_9->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer);

        tabWidget = new QTabWidget(tabMain_Navigation);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy6);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font2;
        font2.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font2.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setMinimumSize(QSize(200, 148));
        tableWidget->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setPointSize(14);
        tableWidget->setFont(font3);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(true);
        tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(95);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(43);
        tableWidget->verticalHeader()->setMinimumSectionSize(33);
        tableWidget->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tableWidget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sizePolicy1.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 287, 652));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButtonCalibrateOffset = new QPushButton(scrollAreaWidgetContents);
        pushButtonCalibrateOffset->setObjectName(QStringLiteral("pushButtonCalibrateOffset"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(pushButtonCalibrateOffset->sizePolicy().hasHeightForWidth());
        pushButtonCalibrateOffset->setSizePolicy(sizePolicy7);

        verticalLayout_2->addWidget(pushButtonCalibrateOffset);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        labelBigNone_5 = new QLabel(scrollAreaWidgetContents);
        labelBigNone_5->setObjectName(QStringLiteral("labelBigNone_5"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(labelBigNone_5->sizePolicy().hasHeightForWidth());
        labelBigNone_5->setSizePolicy(sizePolicy8);
        labelBigNone_5->setMinimumSize(QSize(160, 0));

        horizontalLayout_30->addWidget(labelBigNone_5);

        value_threshold = new QLabel(scrollAreaWidgetContents);
        value_threshold->setObjectName(QStringLiteral("value_threshold"));
        QSizePolicy sizePolicy9(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(value_threshold->sizePolicy().hasHeightForWidth());
        value_threshold->setSizePolicy(sizePolicy9);

        horizontalLayout_30->addWidget(value_threshold);


        verticalLayout_2->addLayout(horizontalLayout_30);

        slider_threshold = new QSlider(scrollAreaWidgetContents);
        slider_threshold->setObjectName(QStringLiteral("slider_threshold"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(slider_threshold->sizePolicy().hasHeightForWidth());
        slider_threshold->setSizePolicy(sizePolicy10);
        slider_threshold->setMinimum(5);
        slider_threshold->setMaximum(255);
        slider_threshold->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_threshold);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelBigNone_6 = new QLabel(scrollAreaWidgetContents);
        labelBigNone_6->setObjectName(QStringLiteral("labelBigNone_6"));
        sizePolicy8.setHeightForWidth(labelBigNone_6->sizePolicy().hasHeightForWidth());
        labelBigNone_6->setSizePolicy(sizePolicy8);
        labelBigNone_6->setMinimumSize(QSize(160, 0));

        horizontalLayout->addWidget(labelBigNone_6);

        value_cornerRefinementMinAccuracy = new QLabel(scrollAreaWidgetContents);
        value_cornerRefinementMinAccuracy->setObjectName(QStringLiteral("value_cornerRefinementMinAccuracy"));
        sizePolicy9.setHeightForWidth(value_cornerRefinementMinAccuracy->sizePolicy().hasHeightForWidth());
        value_cornerRefinementMinAccuracy->setSizePolicy(sizePolicy9);

        horizontalLayout->addWidget(value_cornerRefinementMinAccuracy);


        verticalLayout_2->addLayout(horizontalLayout);

        slider_cornerRefinementMinAccuracy = new QSlider(scrollAreaWidgetContents);
        slider_cornerRefinementMinAccuracy->setObjectName(QStringLiteral("slider_cornerRefinementMinAccuracy"));
        sizePolicy10.setHeightForWidth(slider_cornerRefinementMinAccuracy->sizePolicy().hasHeightForWidth());
        slider_cornerRefinementMinAccuracy->setSizePolicy(sizePolicy10);
        slider_cornerRefinementMinAccuracy->setMinimumSize(QSize(0, 0));
        slider_cornerRefinementMinAccuracy->setMinimum(10);
        slider_cornerRefinementMinAccuracy->setMaximum(1000);
        slider_cornerRefinementMinAccuracy->setValue(40);
        slider_cornerRefinementMinAccuracy->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_cornerRefinementMinAccuracy);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        labelMaxMiddle_5 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_5->setObjectName(QStringLiteral("labelMaxMiddle_5"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_5->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_5->setSizePolicy(sizePolicy8);
        labelMaxMiddle_5->setMinimumSize(QSize(160, 0));

        horizontalLayout_31->addWidget(labelMaxMiddle_5);

        labelMaxMiddleValue_5 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddleValue_5->setObjectName(QStringLiteral("labelMaxMiddleValue_5"));

        horizontalLayout_31->addWidget(labelMaxMiddleValue_5);


        verticalLayout_2->addLayout(horizontalLayout_31);

        slider_cornerRefinementMaxIterations = new QSlider(scrollAreaWidgetContents);
        slider_cornerRefinementMaxIterations->setObjectName(QStringLiteral("slider_cornerRefinementMaxIterations"));
        sizePolicy10.setHeightForWidth(slider_cornerRefinementMaxIterations->sizePolicy().hasHeightForWidth());
        slider_cornerRefinementMaxIterations->setSizePolicy(sizePolicy10);
        slider_cornerRefinementMaxIterations->setMinimumSize(QSize(0, 0));
        slider_cornerRefinementMaxIterations->setMinimum(1);
        slider_cornerRefinementMaxIterations->setMaximum(150);
        slider_cornerRefinementMaxIterations->setSingleStep(0);
        slider_cornerRefinementMaxIterations->setValue(40);
        slider_cornerRefinementMaxIterations->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_cornerRefinementMaxIterations);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        labelMaxMiddle_9 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_9->setObjectName(QStringLiteral("labelMaxMiddle_9"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_9->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_9->setSizePolicy(sizePolicy8);
        labelMaxMiddle_9->setMinimumSize(QSize(160, 0));

        horizontalLayout_35->addWidget(labelMaxMiddle_9);

        value_errorCorrectionRate = new QLabel(scrollAreaWidgetContents);
        value_errorCorrectionRate->setObjectName(QStringLiteral("value_errorCorrectionRate"));

        horizontalLayout_35->addWidget(value_errorCorrectionRate);


        verticalLayout_2->addLayout(horizontalLayout_35);

        slider_errorCorrectionRate = new QSlider(scrollAreaWidgetContents);
        slider_errorCorrectionRate->setObjectName(QStringLiteral("slider_errorCorrectionRate"));
        sizePolicy10.setHeightForWidth(slider_errorCorrectionRate->sizePolicy().hasHeightForWidth());
        slider_errorCorrectionRate->setSizePolicy(sizePolicy10);
        slider_errorCorrectionRate->setMinimum(10);
        slider_errorCorrectionRate->setMaximum(1000);
        slider_errorCorrectionRate->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_errorCorrectionRate);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        labelMaxMiddle_8 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_8->setObjectName(QStringLiteral("labelMaxMiddle_8"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_8->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_8->setSizePolicy(sizePolicy8);
        labelMaxMiddle_8->setMinimumSize(QSize(160, 0));

        horizontalLayout_34->addWidget(labelMaxMiddle_8);

        value_minMarkerPerimeterRate = new QLabel(scrollAreaWidgetContents);
        value_minMarkerPerimeterRate->setObjectName(QStringLiteral("value_minMarkerPerimeterRate"));

        horizontalLayout_34->addWidget(value_minMarkerPerimeterRate);


        verticalLayout_2->addLayout(horizontalLayout_34);

        slider_minMarkerPerimeterRate = new QSlider(scrollAreaWidgetContents);
        slider_minMarkerPerimeterRate->setObjectName(QStringLiteral("slider_minMarkerPerimeterRate"));
        sizePolicy10.setHeightForWidth(slider_minMarkerPerimeterRate->sizePolicy().hasHeightForWidth());
        slider_minMarkerPerimeterRate->setSizePolicy(sizePolicy10);
        slider_minMarkerPerimeterRate->setMinimum(1);
        slider_minMarkerPerimeterRate->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_minMarkerPerimeterRate);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        labelMaxMiddle_14 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_14->setObjectName(QStringLiteral("labelMaxMiddle_14"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_14->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_14->setSizePolicy(sizePolicy8);
        labelMaxMiddle_14->setMinimumSize(QSize(160, 0));

        horizontalLayout_40->addWidget(labelMaxMiddle_14);

        value_maxMarkerPerimeterRate = new QLabel(scrollAreaWidgetContents);
        value_maxMarkerPerimeterRate->setObjectName(QStringLiteral("value_maxMarkerPerimeterRate"));

        horizontalLayout_40->addWidget(value_maxMarkerPerimeterRate);


        verticalLayout_2->addLayout(horizontalLayout_40);

        slider_maxMarkerPerimeterRate = new QSlider(scrollAreaWidgetContents);
        slider_maxMarkerPerimeterRate->setObjectName(QStringLiteral("slider_maxMarkerPerimeterRate"));
        sizePolicy10.setHeightForWidth(slider_maxMarkerPerimeterRate->sizePolicy().hasHeightForWidth());
        slider_maxMarkerPerimeterRate->setSizePolicy(sizePolicy10);
        slider_maxMarkerPerimeterRate->setMinimum(100);
        slider_maxMarkerPerimeterRate->setMaximum(999);
        slider_maxMarkerPerimeterRate->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_maxMarkerPerimeterRate);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        labelMaxMiddle_10 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_10->setObjectName(QStringLiteral("labelMaxMiddle_10"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_10->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_10->setSizePolicy(sizePolicy8);
        labelMaxMiddle_10->setMinimumSize(QSize(160, 0));

        horizontalLayout_36->addWidget(labelMaxMiddle_10);

        value_polygonalApproxAccuracyRate = new QLabel(scrollAreaWidgetContents);
        value_polygonalApproxAccuracyRate->setObjectName(QStringLiteral("value_polygonalApproxAccuracyRate"));

        horizontalLayout_36->addWidget(value_polygonalApproxAccuracyRate);


        verticalLayout_2->addLayout(horizontalLayout_36);

        slider_polygonalApproxAccuracyRate = new QSlider(scrollAreaWidgetContents);
        slider_polygonalApproxAccuracyRate->setObjectName(QStringLiteral("slider_polygonalApproxAccuracyRate"));
        sizePolicy10.setHeightForWidth(slider_polygonalApproxAccuracyRate->sizePolicy().hasHeightForWidth());
        slider_polygonalApproxAccuracyRate->setSizePolicy(sizePolicy10);
        slider_polygonalApproxAccuracyRate->setMinimum(1);
        slider_polygonalApproxAccuracyRate->setMaximum(100);
        slider_polygonalApproxAccuracyRate->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_polygonalApproxAccuracyRate);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelMaxMiddle_20 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_20->setObjectName(QStringLiteral("labelMaxMiddle_20"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_20->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_20->setSizePolicy(sizePolicy8);
        labelMaxMiddle_20->setMinimumSize(QSize(160, 0));

        horizontalLayout_8->addWidget(labelMaxMiddle_20);

        value_adaptiveThreshWinSizeStepMin = new QLabel(scrollAreaWidgetContents);
        value_adaptiveThreshWinSizeStepMin->setObjectName(QStringLiteral("value_adaptiveThreshWinSizeStepMin"));

        horizontalLayout_8->addWidget(value_adaptiveThreshWinSizeStepMin);


        verticalLayout_2->addLayout(horizontalLayout_8);

        slider_adaptiveThreshWinSizeMin = new QSlider(scrollAreaWidgetContents);
        slider_adaptiveThreshWinSizeMin->setObjectName(QStringLiteral("slider_adaptiveThreshWinSizeMin"));
        sizePolicy10.setHeightForWidth(slider_adaptiveThreshWinSizeMin->sizePolicy().hasHeightForWidth());
        slider_adaptiveThreshWinSizeMin->setSizePolicy(sizePolicy10);
        slider_adaptiveThreshWinSizeMin->setMinimum(4);
        slider_adaptiveThreshWinSizeMin->setMaximum(10);
        slider_adaptiveThreshWinSizeMin->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_adaptiveThreshWinSizeMin);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        labelMaxMiddle_12 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_12->setObjectName(QStringLiteral("labelMaxMiddle_12"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_12->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_12->setSizePolicy(sizePolicy8);
        labelMaxMiddle_12->setMinimumSize(QSize(160, 0));

        horizontalLayout_37->addWidget(labelMaxMiddle_12);

        value_adaptiveThreshWinSizeStep = new QLabel(scrollAreaWidgetContents);
        value_adaptiveThreshWinSizeStep->setObjectName(QStringLiteral("value_adaptiveThreshWinSizeStep"));

        horizontalLayout_37->addWidget(value_adaptiveThreshWinSizeStep);


        verticalLayout_2->addLayout(horizontalLayout_37);

        slider_adaptiveThreshWinSizeStep = new QSlider(scrollAreaWidgetContents);
        slider_adaptiveThreshWinSizeStep->setObjectName(QStringLiteral("slider_adaptiveThreshWinSizeStep"));
        sizePolicy10.setHeightForWidth(slider_adaptiveThreshWinSizeStep->sizePolicy().hasHeightForWidth());
        slider_adaptiveThreshWinSizeStep->setSizePolicy(sizePolicy10);
        slider_adaptiveThreshWinSizeStep->setMinimum(1);
        slider_adaptiveThreshWinSizeStep->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_adaptiveThreshWinSizeStep);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        labelMaxMiddle_13 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_13->setObjectName(QStringLiteral("labelMaxMiddle_13"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_13->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_13->setSizePolicy(sizePolicy8);
        labelMaxMiddle_13->setMinimumSize(QSize(160, 0));

        horizontalLayout_38->addWidget(labelMaxMiddle_13);

        value_adaptiveThreshConstant = new QLabel(scrollAreaWidgetContents);
        value_adaptiveThreshConstant->setObjectName(QStringLiteral("value_adaptiveThreshConstant"));

        horizontalLayout_38->addWidget(value_adaptiveThreshConstant);


        verticalLayout_2->addLayout(horizontalLayout_38);

        slider_adaptiveThreshConstant = new QSlider(scrollAreaWidgetContents);
        slider_adaptiveThreshConstant->setObjectName(QStringLiteral("slider_adaptiveThreshConstant"));
        sizePolicy10.setHeightForWidth(slider_adaptiveThreshConstant->sizePolicy().hasHeightForWidth());
        slider_adaptiveThreshConstant->setSizePolicy(sizePolicy10);
        slider_adaptiveThreshConstant->setMinimum(1);
        slider_adaptiveThreshConstant->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_adaptiveThreshConstant);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        labelMaxMiddle_15 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_15->setObjectName(QStringLiteral("labelMaxMiddle_15"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_15->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_15->setSizePolicy(sizePolicy8);
        labelMaxMiddle_15->setMinimumSize(QSize(160, 0));

        horizontalLayout_41->addWidget(labelMaxMiddle_15);

        value_perspectiveRemovePixelPerCell = new QLabel(scrollAreaWidgetContents);
        value_perspectiveRemovePixelPerCell->setObjectName(QStringLiteral("value_perspectiveRemovePixelPerCell"));

        horizontalLayout_41->addWidget(value_perspectiveRemovePixelPerCell);


        verticalLayout_2->addLayout(horizontalLayout_41);

        slider_perspectiveRemovePixelPerCell = new QSlider(scrollAreaWidgetContents);
        slider_perspectiveRemovePixelPerCell->setObjectName(QStringLiteral("slider_perspectiveRemovePixelPerCell"));
        sizePolicy10.setHeightForWidth(slider_perspectiveRemovePixelPerCell->sizePolicy().hasHeightForWidth());
        slider_perspectiveRemovePixelPerCell->setSizePolicy(sizePolicy10);
        slider_perspectiveRemovePixelPerCell->setMinimum(1);
        slider_perspectiveRemovePixelPerCell->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_perspectiveRemovePixelPerCell);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        labelMaxMiddle_16 = new QLabel(scrollAreaWidgetContents);
        labelMaxMiddle_16->setObjectName(QStringLiteral("labelMaxMiddle_16"));
        sizePolicy8.setHeightForWidth(labelMaxMiddle_16->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_16->setSizePolicy(sizePolicy8);
        labelMaxMiddle_16->setMinimumSize(QSize(160, 0));

        horizontalLayout_42->addWidget(labelMaxMiddle_16);

        value_MinSizeofRects = new QLabel(scrollAreaWidgetContents);
        value_MinSizeofRects->setObjectName(QStringLiteral("value_MinSizeofRects"));

        horizontalLayout_42->addWidget(value_MinSizeofRects);


        verticalLayout_2->addLayout(horizontalLayout_42);

        slider_MinSizeofRects = new QSlider(scrollAreaWidgetContents);
        slider_MinSizeofRects->setObjectName(QStringLiteral("slider_MinSizeofRects"));
        sizePolicy10.setHeightForWidth(slider_MinSizeofRects->sizePolicy().hasHeightForWidth());
        slider_MinSizeofRects->setSizePolicy(sizePolicy10);
        slider_MinSizeofRects->setMinimum(4001);
        slider_MinSizeofRects->setMaximum(10000);
        slider_MinSizeofRects->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(slider_MinSizeofRects);


        verticalLayout_8->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_7->addWidget(scrollArea);


        verticalLayout_3->addLayout(verticalLayout_7);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_9->addWidget(tabWidget);

        labelVersion = new QLabel(tabMain_Navigation);
        labelVersion->setObjectName(QStringLiteral("labelVersion"));
        sizePolicy5.setHeightForWidth(labelVersion->sizePolicy().hasHeightForWidth());
        labelVersion->setSizePolicy(sizePolicy5);
        labelVersion->setMinimumSize(QSize(10, 0));
        labelVersion->setMaximumSize(QSize(16777215, 16777215));
        labelVersion->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_9->addWidget(labelVersion);

        labelLogo = new QLabel(tabMain_Navigation);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        QSizePolicy sizePolicy11(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(0);
        sizePolicy11.setHeightForWidth(labelLogo->sizePolicy().hasHeightForWidth());
        labelLogo->setSizePolicy(sizePolicy11);
        labelLogo->setMaximumSize(QSize(340, 100));
        labelLogo->setFrameShape(QFrame::StyledPanel);
        labelLogo->setFrameShadow(QFrame::Sunken);
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/HAW_Hamburg.png")));
        labelLogo->setScaledContents(true);
        labelLogo->setWordWrap(false);

        verticalLayout_9->addWidget(labelLogo);


        horizontalLayout_NavigationWindow->addLayout(verticalLayout_9);


        verticalLayout_4->addLayout(horizontalLayout_NavigationWindow);

        tabMain->addTab(tabMain_Navigation, QString());
        tabMain_Calibration = new QWidget();
        tabMain_Calibration->setObjectName(QStringLiteral("tabMain_Calibration"));
        tabMain->addTab(tabMain_Calibration, QString());
        tabMain_Aruco = new QWidget();
        tabMain_Aruco->setObjectName(QStringLiteral("tabMain_Aruco"));
        sizePolicy1.setHeightForWidth(tabMain_Aruco->sizePolicy().hasHeightForWidth());
        tabMain_Aruco->setSizePolicy(sizePolicy1);
        horizontalLayout_4 = new QHBoxLayout(tabMain_Aruco);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_ArucoMarker = new QHBoxLayout();
        horizontalLayout_ArucoMarker->setSpacing(6);
        horizontalLayout_ArucoMarker->setObjectName(QStringLiteral("horizontalLayout_ArucoMarker"));
        horizontalLayout_ArucoMarker->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_arucomarker = new QLabel(tabMain_Aruco);
        label_arucomarker->setObjectName(QStringLiteral("label_arucomarker"));
        QSizePolicy sizePolicy12(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(label_arucomarker->sizePolicy().hasHeightForWidth());
        label_arucomarker->setSizePolicy(sizePolicy12);
        label_arucomarker->setMaximumSize(QSize(16777215, 16777215));
        label_arucomarker->setScaledContents(true);

        horizontalLayout_ArucoMarker->addWidget(label_arucomarker);

        verticalLayout_arucoList = new QVBoxLayout();
        verticalLayout_arucoList->setSpacing(6);
        verticalLayout_arucoList->setObjectName(QStringLiteral("verticalLayout_arucoList"));
        verticalLayout_arucoList->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableWidget_Aruco = new QTableWidget(tabMain_Aruco);
        if (tableWidget_Aruco->columnCount() < 2)
            tableWidget_Aruco->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Aruco->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Aruco->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        tableWidget_Aruco->setObjectName(QStringLiteral("tableWidget_Aruco"));
        QSizePolicy sizePolicy13(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(tableWidget_Aruco->sizePolicy().hasHeightForWidth());
        tableWidget_Aruco->setSizePolicy(sizePolicy13);
        tableWidget_Aruco->setAlternatingRowColors(true);
        tableWidget_Aruco->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableWidget_Aruco->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Aruco->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_Aruco->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget_Aruco->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget_Aruco->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_Aruco->horizontalHeader()->setStretchLastSection(true);
        tableWidget_Aruco->verticalHeader()->setVisible(false);
        tableWidget_Aruco->verticalHeader()->setDefaultSectionSize(30);

        verticalLayout_arucoList->addWidget(tableWidget_Aruco);

        horizontalLayout_arucoButtons = new QHBoxLayout();
        horizontalLayout_arucoButtons->setSpacing(6);
        horizontalLayout_arucoButtons->setObjectName(QStringLiteral("horizontalLayout_arucoButtons"));
        pushButton_addAruco = new QPushButton(tabMain_Aruco);
        pushButton_addAruco->setObjectName(QStringLiteral("pushButton_addAruco"));
        QSizePolicy sizePolicy14(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy14.setHorizontalStretch(1);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(pushButton_addAruco->sizePolicy().hasHeightForWidth());
        pushButton_addAruco->setSizePolicy(sizePolicy14);

        horizontalLayout_arucoButtons->addWidget(pushButton_addAruco);

        pushButton_deleteAruco = new QPushButton(tabMain_Aruco);
        pushButton_deleteAruco->setObjectName(QStringLiteral("pushButton_deleteAruco"));
        sizePolicy14.setHeightForWidth(pushButton_deleteAruco->sizePolicy().hasHeightForWidth());
        pushButton_deleteAruco->setSizePolicy(sizePolicy14);

        horizontalLayout_arucoButtons->addWidget(pushButton_deleteAruco);

        pushButton_SaveToImage = new QPushButton(tabMain_Aruco);
        pushButton_SaveToImage->setObjectName(QStringLiteral("pushButton_SaveToImage"));
        QSizePolicy sizePolicy15(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy15.setHorizontalStretch(2);
        sizePolicy15.setVerticalStretch(0);
        sizePolicy15.setHeightForWidth(pushButton_SaveToImage->sizePolicy().hasHeightForWidth());
        pushButton_SaveToImage->setSizePolicy(sizePolicy15);

        horizontalLayout_arucoButtons->addWidget(pushButton_SaveToImage);


        verticalLayout_arucoList->addLayout(horizontalLayout_arucoButtons);


        horizontalLayout_ArucoMarker->addLayout(verticalLayout_arucoList);


        horizontalLayout_4->addLayout(horizontalLayout_ArucoMarker);

        tabMain->addTab(tabMain_Aruco, QString());
        tabSettings = new QWidget();
        tabSettings->setObjectName(QStringLiteral("tabSettings"));
        verticalLayout_6 = new QVBoxLayout(tabSettings);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        spinBoxChange1 = new QSpinBox(tabSettings);
        spinBoxChange1->setObjectName(QStringLiteral("spinBoxChange1"));
        QSizePolicy sizePolicy16(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy16.setHorizontalStretch(0);
        sizePolicy16.setVerticalStretch(0);
        sizePolicy16.setHeightForWidth(spinBoxChange1->sizePolicy().hasHeightForWidth());
        spinBoxChange1->setSizePolicy(sizePolicy16);

        horizontalLayout_10->addWidget(spinBoxChange1);

        pushButtonChange = new QPushButton(tabSettings);
        pushButtonChange->setObjectName(QStringLiteral("pushButtonChange"));
        sizePolicy16.setHeightForWidth(pushButtonChange->sizePolicy().hasHeightForWidth());
        pushButtonChange->setSizePolicy(sizePolicy16);

        horizontalLayout_10->addWidget(pushButtonChange);

        spinBoxChange2 = new QSpinBox(tabSettings);
        spinBoxChange2->setObjectName(QStringLiteral("spinBoxChange2"));
        sizePolicy16.setHeightForWidth(spinBoxChange2->sizePolicy().hasHeightForWidth());
        spinBoxChange2->setSizePolicy(sizePolicy16);

        horizontalLayout_10->addWidget(spinBoxChange2);


        horizontalLayout_3->addLayout(horizontalLayout_10);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        spinBoxFieldHeight = new QSpinBox(tabSettings);
        spinBoxFieldHeight->setObjectName(QStringLiteral("spinBoxFieldHeight"));
        sizePolicy16.setHeightForWidth(spinBoxFieldHeight->sizePolicy().hasHeightForWidth());
        spinBoxFieldHeight->setSizePolicy(sizePolicy16);

        horizontalLayout_7->addWidget(spinBoxFieldHeight);

        labelFieldX = new QLabel(tabSettings);
        labelFieldX->setObjectName(QStringLiteral("labelFieldX"));
        sizePolicy11.setHeightForWidth(labelFieldX->sizePolicy().hasHeightForWidth());
        labelFieldX->setSizePolicy(sizePolicy11);

        horizontalLayout_7->addWidget(labelFieldX);

        spinBoxFieldWidth = new QSpinBox(tabSettings);
        spinBoxFieldWidth->setObjectName(QStringLiteral("spinBoxFieldWidth"));
        sizePolicy16.setHeightForWidth(spinBoxFieldWidth->sizePolicy().hasHeightForWidth());
        spinBoxFieldWidth->setSizePolicy(sizePolicy16);

        horizontalLayout_7->addWidget(spinBoxFieldWidth);

        pushButtonResizeCamField = new QPushButton(tabSettings);
        pushButtonResizeCamField->setObjectName(QStringLiteral("pushButtonResizeCamField"));
        sizePolicy16.setHeightForWidth(pushButtonResizeCamField->sizePolicy().hasHeightForWidth());
        pushButtonResizeCamField->setSizePolicy(sizePolicy16);

        horizontalLayout_7->addWidget(pushButtonResizeCamField);


        horizontalLayout_3->addLayout(horizontalLayout_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButtonSaveSettings = new QPushButton(tabSettings);
        pushButtonSaveSettings->setObjectName(QStringLiteral("pushButtonSaveSettings"));
        sizePolicy16.setHeightForWidth(pushButtonSaveSettings->sizePolicy().hasHeightForWidth());
        pushButtonSaveSettings->setSizePolicy(sizePolicy16);

        horizontalLayout_9->addWidget(pushButtonSaveSettings);


        horizontalLayout_3->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        labelCamFieldSettings = new QLabel(tabSettings);
        labelCamFieldSettings->setObjectName(QStringLiteral("labelCamFieldSettings"));
        sizePolicy.setHeightForWidth(labelCamFieldSettings->sizePolicy().hasHeightForWidth());
        labelCamFieldSettings->setSizePolicy(sizePolicy);
        labelCamFieldSettings->setScaledContents(true);

        horizontalLayout_11->addWidget(labelCamFieldSettings);

        scrollAreaSettings = new QScrollArea(tabSettings);
        scrollAreaSettings->setObjectName(QStringLiteral("scrollAreaSettings"));
        QSizePolicy sizePolicy17(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy17.setHorizontalStretch(0);
        sizePolicy17.setVerticalStretch(0);
        sizePolicy17.setHeightForWidth(scrollAreaSettings->sizePolicy().hasHeightForWidth());
        scrollAreaSettings->setSizePolicy(sizePolicy17);
        scrollAreaSettings->setMinimumSize(QSize(250, 0));
        scrollAreaSettings->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollAreaSettings->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 250, 586));
        scrollAreaWidgetContents_2->setMinimumSize(QSize(250, 0));
        verticalLayout_12 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));

        verticalLayout_12->addLayout(verticalLayout_11);

        scrollAreaSettings->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_11->addWidget(scrollAreaSettings);


        verticalLayout_5->addLayout(horizontalLayout_11);


        verticalLayout_6->addLayout(verticalLayout_5);

        tabMain->addTab(tabSettings, QString());

        verticalLayout_10->addWidget(tabMain);

        RobotDetectionMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RobotDetectionMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RobotDetectionMainWindow->setStatusBar(statusBar);

        retranslateUi(RobotDetectionMainWindow);
        QObject::connect(slider_threshold, SIGNAL(valueChanged(int)), value_threshold, SLOT(setNum(int)));
        QObject::connect(slider_cornerRefinementMinAccuracy, SIGNAL(valueChanged(int)), value_cornerRefinementMinAccuracy, SLOT(setNum(int)));
        QObject::connect(slider_adaptiveThreshWinSizeMin, SIGNAL(valueChanged(int)), value_adaptiveThreshWinSizeStepMin, SLOT(setNum(int)));
        QObject::connect(slider_MinSizeofRects, SIGNAL(valueChanged(int)), value_MinSizeofRects, SLOT(setNum(int)));
        QObject::connect(slider_adaptiveThreshWinSizeStep, SIGNAL(valueChanged(int)), value_adaptiveThreshWinSizeStep, SLOT(setNum(int)));
        QObject::connect(slider_cornerRefinementMaxIterations, SIGNAL(valueChanged(int)), labelMaxMiddleValue_5, SLOT(setNum(int)));
        QObject::connect(slider_adaptiveThreshConstant, SIGNAL(valueChanged(int)), value_adaptiveThreshConstant, SLOT(setNum(int)));
        QObject::connect(slider_minMarkerPerimeterRate, SIGNAL(valueChanged(int)), value_minMarkerPerimeterRate, SLOT(setNum(int)));
        QObject::connect(slider_errorCorrectionRate, SIGNAL(valueChanged(int)), value_errorCorrectionRate, SLOT(setNum(int)));
        QObject::connect(slider_perspectiveRemovePixelPerCell, SIGNAL(valueChanged(int)), value_perspectiveRemovePixelPerCell, SLOT(setNum(int)));
        QObject::connect(slider_maxMarkerPerimeterRate, SIGNAL(valueChanged(int)), value_maxMarkerPerimeterRate, SLOT(setNum(int)));
        QObject::connect(slider_polygonalApproxAccuracyRate, SIGNAL(valueChanged(int)), value_polygonalApproxAccuracyRate, SLOT(setNum(int)));

        tabMain->setCurrentIndex(3);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(RobotDetectionMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RobotDetectionMainWindow)
    {
        RobotDetectionMainWindow->setWindowTitle(QApplication::translate("RobotDetectionMainWindow", "Robot Detection", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabMain->setToolTip(QApplication::translate("RobotDetectionMainWindow", "<html><head/><body><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelImage->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonStartStop->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonStartStop->setText(QApplication::translate("RobotDetectionMainWindow", "Start Detection", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBoxLiveView->setToolTip(QApplication::translate("RobotDetectionMainWindow", "activates live view mode with lower framerate", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxLiveView->setText(QApplication::translate("RobotDetectionMainWindow", "Live View", Q_NULLPTR));
        checkBox_Measurement->setText(QApplication::translate("RobotDetectionMainWindow", "Measurement", Q_NULLPTR));
        labelUDPFPS->setText(QApplication::translate("RobotDetectionMainWindow", "UDP Frames per second: ", Q_NULLPTR));
        labelFPS->setText(QApplication::translate("RobotDetectionMainWindow", "GUI Frames per second: ", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RobotDetectionMainWindow", "x", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RobotDetectionMainWindow", "y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RobotDetectionMainWindow", "phi", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RobotDetectionMainWindow", "Localization", Q_NULLPTR));
        pushButtonCalibrateOffset->setText(QApplication::translate("RobotDetectionMainWindow", "Start Robot Offset Calibration", Q_NULLPTR));
        labelBigNone_5->setText(QApplication::translate("RobotDetectionMainWindow", "Threshold ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        value_threshold->setToolTip(QApplication::translate("RobotDetectionMainWindow", "millimeters", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        value_threshold->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelBigNone_6->setText(QApplication::translate("RobotDetectionMainWindow", "Corner Refinement min. Acc.0.x", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        value_cornerRefinementMinAccuracy->setToolTip(QApplication::translate("RobotDetectionMainWindow", "millimeters", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        value_cornerRefinementMinAccuracy->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        slider_cornerRefinementMinAccuracy->setToolTip(QApplication::translate("RobotDetectionMainWindow", "maximum radius for largest circles", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelMaxMiddle_5->setText(QApplication::translate("RobotDetectionMainWindow", "CornerRefinment Max. Iteration", Q_NULLPTR));
        labelMaxMiddleValue_5->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        slider_cornerRefinementMaxIterations->setToolTip(QApplication::translate("RobotDetectionMainWindow", "a circle closer to another circle than this value is ignored", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelMaxMiddle_9->setText(QApplication::translate("RobotDetectionMainWindow", "Error Correction Rate 0.x", Q_NULLPTR));
        value_errorCorrectionRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_8->setText(QApplication::translate("RobotDetectionMainWindow", "Min. Marker Perimet. Rate 0.0x", Q_NULLPTR));
        value_minMarkerPerimeterRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_14->setText(QApplication::translate("RobotDetectionMainWindow", "Max. Marker Perimet. Rate 0.0", Q_NULLPTR));
        value_maxMarkerPerimeterRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_10->setText(QApplication::translate("RobotDetectionMainWindow", "polygonal App. Acc. Rate 0.0x", Q_NULLPTR));
        value_polygonalApproxAccuracyRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_20->setText(QApplication::translate("RobotDetectionMainWindow", "Adaptive Thresh Win. Size min.", Q_NULLPTR));
        value_adaptiveThreshWinSizeStepMin->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_12->setText(QApplication::translate("RobotDetectionMainWindow", "Adaptive Thresh Win. Size Step", Q_NULLPTR));
        value_adaptiveThreshWinSizeStep->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_13->setText(QApplication::translate("RobotDetectionMainWindow", "Adaptive Thresh Constant", Q_NULLPTR));
        value_adaptiveThreshConstant->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_15->setText(QApplication::translate("RobotDetectionMainWindow", "Perspective Remove Pixel", Q_NULLPTR));
        value_perspectiveRemovePixelPerCell->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_16->setText(QApplication::translate("RobotDetectionMainWindow", "Max Size of detected  Rect\302\264s", Q_NULLPTR));
        value_MinSizeofRects->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("RobotDetectionMainWindow", "Settings", Q_NULLPTR));
        labelVersion->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelLogo->setToolTip(QApplication::translate("RobotDetectionMainWindow", "Gewerk 5 FTW !!!", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelLogo->setText(QString());
        tabMain->setTabText(tabMain->indexOf(tabMain_Navigation), QApplication::translate("RobotDetectionMainWindow", "Navigation", Q_NULLPTR));
        tabMain->setTabText(tabMain->indexOf(tabMain_Calibration), QApplication::translate("RobotDetectionMainWindow", "Calibration", Q_NULLPTR));
        label_arucomarker->setText(QString());
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Aruco->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("RobotDetectionMainWindow", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Aruco->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("RobotDetectionMainWindow", "Name", Q_NULLPTR));
        pushButton_addAruco->setText(QApplication::translate("RobotDetectionMainWindow", "+", Q_NULLPTR));
        pushButton_deleteAruco->setText(QApplication::translate("RobotDetectionMainWindow", "-", Q_NULLPTR));
        pushButton_SaveToImage->setText(QApplication::translate("RobotDetectionMainWindow", "Save To Image", Q_NULLPTR));
        tabMain->setTabText(tabMain->indexOf(tabMain_Aruco), QApplication::translate("RobotDetectionMainWindow", "Aruco Dictionary", Q_NULLPTR));
        pushButtonChange->setText(QApplication::translate("RobotDetectionMainWindow", "change", Q_NULLPTR));
        labelFieldX->setText(QApplication::translate("RobotDetectionMainWindow", "X", Q_NULLPTR));
        pushButtonResizeCamField->setText(QApplication::translate("RobotDetectionMainWindow", "resize camera field", Q_NULLPTR));
        pushButtonSaveSettings->setText(QApplication::translate("RobotDetectionMainWindow", "save settings", Q_NULLPTR));
        labelCamFieldSettings->setText(QString());
        tabMain->setTabText(tabMain->indexOf(tabSettings), QApplication::translate("RobotDetectionMainWindow", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RobotDetectionMainWindow: public Ui_RobotDetectionMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDETECTIONMAINWINDOW_H
