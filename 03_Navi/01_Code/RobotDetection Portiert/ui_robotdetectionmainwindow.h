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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabMain;
    QWidget *tabMain_Navigation;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelImage;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonStartStop;
    QCheckBox *checkBox_Measurement;
    QSpacerItem *verticalSpacer_3;
    QLabel *t4_label;
    QCheckBox *checkBoxLiveView;
    QLabel *labelFPS;
    QLabel *labelLogo;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QLabel *labelVersion;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_11;
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
    QHBoxLayout *horizontalLayout_34;
    QLabel *labelMaxMiddle_8;
    QLabel *value_minMarkerPerimeterRate;
    QSlider *slider_minMarkerPerimeterRate;
    QHBoxLayout *horizontalLayout_35;
    QLabel *labelMaxMiddle_9;
    QLabel *value_errorCorrectionRate;
    QSlider *slider_errorCorrectionRate;
    QHBoxLayout *horizontalLayout_36;
    QLabel *labelMaxMiddle_10;
    QLabel *value_polygonalApproxAccuracyRate;
    QSlider *slider_polygonalApproxAccuracyRate;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelMaxMiddle_20;
    QLabel *value_adaptiveThreshWinSizeStepMin;
    QHBoxLayout *horizontalLayout_38;
    QLabel *labelMaxMiddle_13;
    QLabel *value_adaptiveThreshConstant;
    QSlider *slider_adaptiveThreshWinSizeMin;
    QSlider *slider_adaptiveThreshConstant;
    QSlider *slider_maxMarkerPerimeterRate;
    QHBoxLayout *horizontalLayout_41;
    QLabel *labelMaxMiddle_15;
    QLabel *value_perspectiveRemovePixelPerCell;
    QHBoxLayout *horizontalLayout_42;
    QLabel *labelMaxMiddle_16;
    QLabel *value_MinSizeofRects;
    QSlider *slider_MinSizeofRects;
    QHBoxLayout *horizontalLayout_37;
    QLabel *labelMaxMiddle_12;
    QLabel *value_adaptiveThreshWinSizeStep;
    QSlider *slider_adaptiveThreshWinSizeStep;
    QHBoxLayout *horizontalLayout_40;
    QLabel *labelMaxMiddle_14;
    QLabel *value_maxMarkerPerimeterRate;
    QSlider *slider_perspectiveRemovePixelPerCell;
    QWidget *tabMain_Calibration;
    QWidget *tabMain_Aruco;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_ArucoMarker;
    QLabel *label_arucomarker;
    QVBoxLayout *verticalLayout_arucoList;
    QTableWidget *tableWidget_Aruco;
    QHBoxLayout *horizontalLayout_arucoButtons;
    QPushButton *pushButton_addAruco;
    QPushButton *pushButton_deleteAruco;
    QPushButton *pushButton_SaveToImage;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RobotDetectionMainWindow)
    {
        if (RobotDetectionMainWindow->objectName().isEmpty())
            RobotDetectionMainWindow->setObjectName(QStringLiteral("RobotDetectionMainWindow"));
        RobotDetectionMainWindow->resize(1280, 640);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RobotDetectionMainWindow->sizePolicy().hasHeightForWidth());
        RobotDetectionMainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/Hawhamburg-logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        RobotDetectionMainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(RobotDetectionMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabMain = new QTabWidget(centralWidget);
        tabMain->setObjectName(QStringLiteral("tabMain"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabMain->sizePolicy().hasHeightForWidth());
        tabMain->setSizePolicy(sizePolicy1);
        tabMain_Navigation = new QWidget();
        tabMain_Navigation->setObjectName(QStringLiteral("tabMain_Navigation"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabMain_Navigation->sizePolicy().hasHeightForWidth());
        tabMain_Navigation->setSizePolicy(sizePolicy2);
        horizontalLayoutWidget_3 = new QWidget(tabMain_Navigation);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 0, 1251, 571));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelImage = new QLabel(horizontalLayoutWidget_3);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(10);
        sizePolicy3.setHeightForWidth(labelImage->sizePolicy().hasHeightForWidth());
        labelImage->setSizePolicy(sizePolicy3);
        labelImage->setMinimumSize(QSize(0, 0));
        labelImage->setMaximumSize(QSize(1280, 640));
        labelImage->setSizeIncrement(QSize(20, 20));
        labelImage->setBaseSize(QSize(2, 2));
        labelImage->setFrameShape(QFrame::StyledPanel);
        labelImage->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(labelImage);

        tabWidget = new QTabWidget(horizontalLayoutWidget_3);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy4);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_3 = new QGridLayout(tab_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButtonStartStop = new QPushButton(tab_3);
        pushButtonStartStop->setObjectName(QStringLiteral("pushButtonStartStop"));

        gridLayout_3->addWidget(pushButtonStartStop, 0, 0, 1, 1);

        checkBox_Measurement = new QCheckBox(tab_3);
        checkBox_Measurement->setObjectName(QStringLiteral("checkBox_Measurement"));

        gridLayout_3->addWidget(checkBox_Measurement, 3, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 4, 0, 1, 1);

        t4_label = new QLabel(tab_3);
        t4_label->setObjectName(QStringLiteral("t4_label"));

        gridLayout_3->addWidget(t4_label, 0, 1, 1, 1);

        checkBoxLiveView = new QCheckBox(tab_3);
        checkBoxLiveView->setObjectName(QStringLiteral("checkBoxLiveView"));

        gridLayout_3->addWidget(checkBoxLiveView, 2, 0, 1, 1);

        labelFPS = new QLabel(tab_3);
        labelFPS->setObjectName(QStringLiteral("labelFPS"));

        gridLayout_3->addWidget(labelFPS, 1, 0, 1, 1);

        labelLogo = new QLabel(tab_3);
        labelLogo->setObjectName(QStringLiteral("labelLogo"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(labelLogo->sizePolicy().hasHeightForWidth());
        labelLogo->setSizePolicy(sizePolicy5);
        labelLogo->setMaximumSize(QSize(340, 100));
        labelLogo->setFrameShape(QFrame::StyledPanel);
        labelLogo->setFrameShadow(QFrame::Sunken);
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/HAW_Hamburg.png")));
        labelLogo->setScaledContents(true);
        labelLogo->setWordWrap(false);

        gridLayout_3->addWidget(labelLogo, 5, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        sizePolicy5.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy5);
        tableWidget->setMinimumSize(QSize(200, 148));
        tableWidget->setMaximumSize(QSize(210, 148));
        QFont font2;
        font2.setPointSize(14);
        tableWidget->setFont(font2);
        tableWidget->horizontalHeader()->setDefaultSectionSize(52);
        tableWidget->horizontalHeader()->setMinimumSectionSize(30);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setMinimumSectionSize(33);

        verticalLayout->addWidget(tableWidget);

        labelVersion = new QLabel(tab);
        labelVersion->setObjectName(QStringLiteral("labelVersion"));
        sizePolicy.setHeightForWidth(labelVersion->sizePolicy().hasHeightForWidth());
        labelVersion->setSizePolicy(sizePolicy);
        labelVersion->setMinimumSize(QSize(10, 0));

        verticalLayout->addWidget(labelVersion);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        sizePolicy2.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy2);
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setEnabled(true);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setMinimumSize(QSize(10, 10));
        scrollArea->setMaximumSize(QSize(210, 1000));
        scrollArea->setSizeIncrement(QSize(1, 1));
        scrollArea->setBaseSize(QSize(2, 2));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(10);
        scrollArea->setMidLineWidth(10);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 363, 350));
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        scrollAreaWidgetContents->setMinimumSize(QSize(363, 350));
        scrollAreaWidgetContents->setMaximumSize(QSize(363, 500));
        layoutWidget = new QWidget(scrollAreaWidgetContents);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 7, 191, 571));
        verticalLayout_11 = new QVBoxLayout(layoutWidget);
        verticalLayout_11->setSpacing(3);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButtonCalibrateOffset = new QPushButton(layoutWidget);
        pushButtonCalibrateOffset->setObjectName(QStringLiteral("pushButtonCalibrateOffset"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(pushButtonCalibrateOffset->sizePolicy().hasHeightForWidth());
        pushButtonCalibrateOffset->setSizePolicy(sizePolicy6);

        verticalLayout_11->addWidget(pushButtonCalibrateOffset);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        labelBigNone_5 = new QLabel(layoutWidget);
        labelBigNone_5->setObjectName(QStringLiteral("labelBigNone_5"));
        sizePolicy5.setHeightForWidth(labelBigNone_5->sizePolicy().hasHeightForWidth());
        labelBigNone_5->setSizePolicy(sizePolicy5);
        labelBigNone_5->setMinimumSize(QSize(160, 0));

        horizontalLayout_30->addWidget(labelBigNone_5);

        value_threshold = new QLabel(layoutWidget);
        value_threshold->setObjectName(QStringLiteral("value_threshold"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(value_threshold->sizePolicy().hasHeightForWidth());
        value_threshold->setSizePolicy(sizePolicy7);

        horizontalLayout_30->addWidget(value_threshold);


        verticalLayout_11->addLayout(horizontalLayout_30);

        slider_threshold = new QSlider(layoutWidget);
        slider_threshold->setObjectName(QStringLiteral("slider_threshold"));
        slider_threshold->setMinimum(5);
        slider_threshold->setMaximum(255);
        slider_threshold->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_threshold);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelBigNone_6 = new QLabel(layoutWidget);
        labelBigNone_6->setObjectName(QStringLiteral("labelBigNone_6"));
        sizePolicy5.setHeightForWidth(labelBigNone_6->sizePolicy().hasHeightForWidth());
        labelBigNone_6->setSizePolicy(sizePolicy5);
        labelBigNone_6->setMinimumSize(QSize(160, 0));

        horizontalLayout->addWidget(labelBigNone_6);

        value_cornerRefinementMinAccuracy = new QLabel(layoutWidget);
        value_cornerRefinementMinAccuracy->setObjectName(QStringLiteral("value_cornerRefinementMinAccuracy"));
        sizePolicy7.setHeightForWidth(value_cornerRefinementMinAccuracy->sizePolicy().hasHeightForWidth());
        value_cornerRefinementMinAccuracy->setSizePolicy(sizePolicy7);

        horizontalLayout->addWidget(value_cornerRefinementMinAccuracy);


        verticalLayout_11->addLayout(horizontalLayout);

        slider_cornerRefinementMinAccuracy = new QSlider(layoutWidget);
        slider_cornerRefinementMinAccuracy->setObjectName(QStringLiteral("slider_cornerRefinementMinAccuracy"));
        sizePolicy7.setHeightForWidth(slider_cornerRefinementMinAccuracy->sizePolicy().hasHeightForWidth());
        slider_cornerRefinementMinAccuracy->setSizePolicy(sizePolicy7);
        slider_cornerRefinementMinAccuracy->setMinimumSize(QSize(0, 0));
        slider_cornerRefinementMinAccuracy->setMinimum(10);
        slider_cornerRefinementMinAccuracy->setMaximum(1000);
        slider_cornerRefinementMinAccuracy->setValue(40);
        slider_cornerRefinementMinAccuracy->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_cornerRefinementMinAccuracy);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        labelMaxMiddle_5 = new QLabel(layoutWidget);
        labelMaxMiddle_5->setObjectName(QStringLiteral("labelMaxMiddle_5"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_5->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_5->setSizePolicy(sizePolicy5);
        labelMaxMiddle_5->setMinimumSize(QSize(160, 0));

        horizontalLayout_31->addWidget(labelMaxMiddle_5);

        labelMaxMiddleValue_5 = new QLabel(layoutWidget);
        labelMaxMiddleValue_5->setObjectName(QStringLiteral("labelMaxMiddleValue_5"));

        horizontalLayout_31->addWidget(labelMaxMiddleValue_5);


        verticalLayout_11->addLayout(horizontalLayout_31);

        slider_cornerRefinementMaxIterations = new QSlider(layoutWidget);
        slider_cornerRefinementMaxIterations->setObjectName(QStringLiteral("slider_cornerRefinementMaxIterations"));
        sizePolicy7.setHeightForWidth(slider_cornerRefinementMaxIterations->sizePolicy().hasHeightForWidth());
        slider_cornerRefinementMaxIterations->setSizePolicy(sizePolicy7);
        slider_cornerRefinementMaxIterations->setMinimumSize(QSize(0, 0));
        slider_cornerRefinementMaxIterations->setMinimum(1);
        slider_cornerRefinementMaxIterations->setMaximum(150);
        slider_cornerRefinementMaxIterations->setSingleStep(0);
        slider_cornerRefinementMaxIterations->setValue(40);
        slider_cornerRefinementMaxIterations->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_cornerRefinementMaxIterations);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        labelMaxMiddle_8 = new QLabel(layoutWidget);
        labelMaxMiddle_8->setObjectName(QStringLiteral("labelMaxMiddle_8"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_8->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_8->setSizePolicy(sizePolicy5);
        labelMaxMiddle_8->setMinimumSize(QSize(160, 0));

        horizontalLayout_34->addWidget(labelMaxMiddle_8);

        value_minMarkerPerimeterRate = new QLabel(layoutWidget);
        value_minMarkerPerimeterRate->setObjectName(QStringLiteral("value_minMarkerPerimeterRate"));

        horizontalLayout_34->addWidget(value_minMarkerPerimeterRate);


        verticalLayout_11->addLayout(horizontalLayout_34);

        slider_minMarkerPerimeterRate = new QSlider(layoutWidget);
        slider_minMarkerPerimeterRate->setObjectName(QStringLiteral("slider_minMarkerPerimeterRate"));
        slider_minMarkerPerimeterRate->setMinimum(1);
        slider_minMarkerPerimeterRate->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_minMarkerPerimeterRate);

        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        labelMaxMiddle_9 = new QLabel(layoutWidget);
        labelMaxMiddle_9->setObjectName(QStringLiteral("labelMaxMiddle_9"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_9->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_9->setSizePolicy(sizePolicy5);
        labelMaxMiddle_9->setMinimumSize(QSize(160, 0));

        horizontalLayout_35->addWidget(labelMaxMiddle_9);

        value_errorCorrectionRate = new QLabel(layoutWidget);
        value_errorCorrectionRate->setObjectName(QStringLiteral("value_errorCorrectionRate"));

        horizontalLayout_35->addWidget(value_errorCorrectionRate);


        verticalLayout_11->addLayout(horizontalLayout_35);

        slider_errorCorrectionRate = new QSlider(layoutWidget);
        slider_errorCorrectionRate->setObjectName(QStringLiteral("slider_errorCorrectionRate"));
        slider_errorCorrectionRate->setMinimum(10);
        slider_errorCorrectionRate->setMaximum(1000);
        slider_errorCorrectionRate->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_errorCorrectionRate);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        labelMaxMiddle_10 = new QLabel(layoutWidget);
        labelMaxMiddle_10->setObjectName(QStringLiteral("labelMaxMiddle_10"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_10->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_10->setSizePolicy(sizePolicy5);
        labelMaxMiddle_10->setMinimumSize(QSize(160, 0));

        horizontalLayout_36->addWidget(labelMaxMiddle_10);

        value_polygonalApproxAccuracyRate = new QLabel(layoutWidget);
        value_polygonalApproxAccuracyRate->setObjectName(QStringLiteral("value_polygonalApproxAccuracyRate"));

        horizontalLayout_36->addWidget(value_polygonalApproxAccuracyRate);


        verticalLayout_11->addLayout(horizontalLayout_36);

        slider_polygonalApproxAccuracyRate = new QSlider(layoutWidget);
        slider_polygonalApproxAccuracyRate->setObjectName(QStringLiteral("slider_polygonalApproxAccuracyRate"));
        slider_polygonalApproxAccuracyRate->setMinimum(1);
        slider_polygonalApproxAccuracyRate->setMaximum(100);
        slider_polygonalApproxAccuracyRate->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_polygonalApproxAccuracyRate);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelMaxMiddle_20 = new QLabel(layoutWidget);
        labelMaxMiddle_20->setObjectName(QStringLiteral("labelMaxMiddle_20"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_20->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_20->setSizePolicy(sizePolicy5);
        labelMaxMiddle_20->setMinimumSize(QSize(160, 0));

        horizontalLayout_8->addWidget(labelMaxMiddle_20);

        value_adaptiveThreshWinSizeStepMin = new QLabel(layoutWidget);
        value_adaptiveThreshWinSizeStepMin->setObjectName(QStringLiteral("value_adaptiveThreshWinSizeStepMin"));

        horizontalLayout_8->addWidget(value_adaptiveThreshWinSizeStepMin);


        verticalLayout_11->addLayout(horizontalLayout_8);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        labelMaxMiddle_13 = new QLabel(layoutWidget);
        labelMaxMiddle_13->setObjectName(QStringLiteral("labelMaxMiddle_13"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_13->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_13->setSizePolicy(sizePolicy5);
        labelMaxMiddle_13->setMinimumSize(QSize(160, 0));

        horizontalLayout_38->addWidget(labelMaxMiddle_13);

        value_adaptiveThreshConstant = new QLabel(layoutWidget);
        value_adaptiveThreshConstant->setObjectName(QStringLiteral("value_adaptiveThreshConstant"));

        horizontalLayout_38->addWidget(value_adaptiveThreshConstant);


        verticalLayout_11->addLayout(horizontalLayout_38);

        slider_adaptiveThreshWinSizeMin = new QSlider(layoutWidget);
        slider_adaptiveThreshWinSizeMin->setObjectName(QStringLiteral("slider_adaptiveThreshWinSizeMin"));
        slider_adaptiveThreshWinSizeMin->setMinimum(4);
        slider_adaptiveThreshWinSizeMin->setMaximum(10);
        slider_adaptiveThreshWinSizeMin->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_adaptiveThreshWinSizeMin);

        slider_adaptiveThreshConstant = new QSlider(layoutWidget);
        slider_adaptiveThreshConstant->setObjectName(QStringLiteral("slider_adaptiveThreshConstant"));
        slider_adaptiveThreshConstant->setMinimum(1);
        slider_adaptiveThreshConstant->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_adaptiveThreshConstant);

        slider_maxMarkerPerimeterRate = new QSlider(layoutWidget);
        slider_maxMarkerPerimeterRate->setObjectName(QStringLiteral("slider_maxMarkerPerimeterRate"));
        slider_maxMarkerPerimeterRate->setMinimum(100);
        slider_maxMarkerPerimeterRate->setMaximum(999);
        slider_maxMarkerPerimeterRate->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_maxMarkerPerimeterRate);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        labelMaxMiddle_15 = new QLabel(layoutWidget);
        labelMaxMiddle_15->setObjectName(QStringLiteral("labelMaxMiddle_15"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_15->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_15->setSizePolicy(sizePolicy5);
        labelMaxMiddle_15->setMinimumSize(QSize(160, 0));

        horizontalLayout_41->addWidget(labelMaxMiddle_15);

        value_perspectiveRemovePixelPerCell = new QLabel(layoutWidget);
        value_perspectiveRemovePixelPerCell->setObjectName(QStringLiteral("value_perspectiveRemovePixelPerCell"));

        horizontalLayout_41->addWidget(value_perspectiveRemovePixelPerCell);


        verticalLayout_11->addLayout(horizontalLayout_41);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        labelMaxMiddle_16 = new QLabel(layoutWidget);
        labelMaxMiddle_16->setObjectName(QStringLiteral("labelMaxMiddle_16"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_16->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_16->setSizePolicy(sizePolicy5);
        labelMaxMiddle_16->setMinimumSize(QSize(160, 0));

        horizontalLayout_42->addWidget(labelMaxMiddle_16);

        value_MinSizeofRects = new QLabel(layoutWidget);
        value_MinSizeofRects->setObjectName(QStringLiteral("value_MinSizeofRects"));

        horizontalLayout_42->addWidget(value_MinSizeofRects);


        verticalLayout_11->addLayout(horizontalLayout_42);

        slider_MinSizeofRects = new QSlider(layoutWidget);
        slider_MinSizeofRects->setObjectName(QStringLiteral("slider_MinSizeofRects"));
        slider_MinSizeofRects->setMinimum(4001);
        slider_MinSizeofRects->setMaximum(10000);
        slider_MinSizeofRects->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_MinSizeofRects);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        labelMaxMiddle_12 = new QLabel(layoutWidget);
        labelMaxMiddle_12->setObjectName(QStringLiteral("labelMaxMiddle_12"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_12->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_12->setSizePolicy(sizePolicy5);
        labelMaxMiddle_12->setMinimumSize(QSize(160, 0));

        horizontalLayout_37->addWidget(labelMaxMiddle_12);

        value_adaptiveThreshWinSizeStep = new QLabel(layoutWidget);
        value_adaptiveThreshWinSizeStep->setObjectName(QStringLiteral("value_adaptiveThreshWinSizeStep"));

        horizontalLayout_37->addWidget(value_adaptiveThreshWinSizeStep);


        verticalLayout_11->addLayout(horizontalLayout_37);

        slider_adaptiveThreshWinSizeStep = new QSlider(layoutWidget);
        slider_adaptiveThreshWinSizeStep->setObjectName(QStringLiteral("slider_adaptiveThreshWinSizeStep"));
        slider_adaptiveThreshWinSizeStep->setMinimum(1);
        slider_adaptiveThreshWinSizeStep->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_adaptiveThreshWinSizeStep);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        labelMaxMiddle_14 = new QLabel(layoutWidget);
        labelMaxMiddle_14->setObjectName(QStringLiteral("labelMaxMiddle_14"));
        sizePolicy5.setHeightForWidth(labelMaxMiddle_14->sizePolicy().hasHeightForWidth());
        labelMaxMiddle_14->setSizePolicy(sizePolicy5);
        labelMaxMiddle_14->setMinimumSize(QSize(160, 0));

        horizontalLayout_40->addWidget(labelMaxMiddle_14);

        value_maxMarkerPerimeterRate = new QLabel(layoutWidget);
        value_maxMarkerPerimeterRate->setObjectName(QStringLiteral("value_maxMarkerPerimeterRate"));

        horizontalLayout_40->addWidget(value_maxMarkerPerimeterRate);


        verticalLayout_11->addLayout(horizontalLayout_40);

        slider_perspectiveRemovePixelPerCell = new QSlider(layoutWidget);
        slider_perspectiveRemovePixelPerCell->setObjectName(QStringLiteral("slider_perspectiveRemovePixelPerCell"));
        slider_perspectiveRemovePixelPerCell->setMinimum(1);
        slider_perspectiveRemovePixelPerCell->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(slider_perspectiveRemovePixelPerCell);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 2, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_3->addWidget(tabWidget);

        tabMain->addTab(tabMain_Navigation, QString());
        tabMain_Calibration = new QWidget();
        tabMain_Calibration->setObjectName(QStringLiteral("tabMain_Calibration"));
        tabMain->addTab(tabMain_Calibration, QString());
        tabMain_Aruco = new QWidget();
        tabMain_Aruco->setObjectName(QStringLiteral("tabMain_Aruco"));
        horizontalLayoutWidget = new QWidget(tabMain_Aruco);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 1241, 561));
        horizontalLayout_ArucoMarker = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_ArucoMarker->setSpacing(6);
        horizontalLayout_ArucoMarker->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_ArucoMarker->setObjectName(QStringLiteral("horizontalLayout_ArucoMarker"));
        horizontalLayout_ArucoMarker->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_ArucoMarker->setContentsMargins(0, 0, 0, 0);
        label_arucomarker = new QLabel(horizontalLayoutWidget);
        label_arucomarker->setObjectName(QStringLiteral("label_arucomarker"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_arucomarker->sizePolicy().hasHeightForWidth());
        label_arucomarker->setSizePolicy(sizePolicy8);

        horizontalLayout_ArucoMarker->addWidget(label_arucomarker);

        verticalLayout_arucoList = new QVBoxLayout();
        verticalLayout_arucoList->setSpacing(6);
        verticalLayout_arucoList->setObjectName(QStringLiteral("verticalLayout_arucoList"));
        verticalLayout_arucoList->setSizeConstraint(QLayout::SetDefaultConstraint);
        tableWidget_Aruco = new QTableWidget(horizontalLayoutWidget);
        if (tableWidget_Aruco->columnCount() < 2)
            tableWidget_Aruco->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Aruco->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Aruco->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        tableWidget_Aruco->setObjectName(QStringLiteral("tableWidget_Aruco"));
        sizePolicy8.setHeightForWidth(tableWidget_Aruco->sizePolicy().hasHeightForWidth());
        tableWidget_Aruco->setSizePolicy(sizePolicy8);
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
        pushButton_addAruco = new QPushButton(horizontalLayoutWidget);
        pushButton_addAruco->setObjectName(QStringLiteral("pushButton_addAruco"));
        QSizePolicy sizePolicy9(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(1);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(pushButton_addAruco->sizePolicy().hasHeightForWidth());
        pushButton_addAruco->setSizePolicy(sizePolicy9);

        horizontalLayout_arucoButtons->addWidget(pushButton_addAruco);

        pushButton_deleteAruco = new QPushButton(horizontalLayoutWidget);
        pushButton_deleteAruco->setObjectName(QStringLiteral("pushButton_deleteAruco"));
        sizePolicy9.setHeightForWidth(pushButton_deleteAruco->sizePolicy().hasHeightForWidth());
        pushButton_deleteAruco->setSizePolicy(sizePolicy9);

        horizontalLayout_arucoButtons->addWidget(pushButton_deleteAruco);

        pushButton_SaveToImage = new QPushButton(horizontalLayoutWidget);
        pushButton_SaveToImage->setObjectName(QStringLiteral("pushButton_SaveToImage"));
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy10.setHorizontalStretch(2);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(pushButton_SaveToImage->sizePolicy().hasHeightForWidth());
        pushButton_SaveToImage->setSizePolicy(sizePolicy10);

        horizontalLayout_arucoButtons->addWidget(pushButton_SaveToImage);


        verticalLayout_arucoList->addLayout(horizontalLayout_arucoButtons);


        horizontalLayout_ArucoMarker->addLayout(verticalLayout_arucoList);

        tabMain->addTab(tabMain_Aruco, QString());

        verticalLayout_3->addWidget(tabMain);

        RobotDetectionMainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RobotDetectionMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RobotDetectionMainWindow->setStatusBar(statusBar);

        retranslateUi(RobotDetectionMainWindow);
        QObject::connect(slider_threshold, SIGNAL(valueChanged(int)), value_threshold, SLOT(setNum(int)));
        QObject::connect(slider_cornerRefinementMinAccuracy, SIGNAL(valueChanged(int)), value_cornerRefinementMinAccuracy, SLOT(setNum(int)));
        QObject::connect(slider_adaptiveThreshWinSizeMin, SIGNAL(valueChanged(int)), value_adaptiveThreshWinSizeStepMin, SLOT(setNum(int)));
        QObject::connect(slider_adaptiveThreshWinSizeStep, SIGNAL(valueChanged(int)), value_adaptiveThreshWinSizeStep, SLOT(setNum(int)));
        QObject::connect(slider_cornerRefinementMaxIterations, SIGNAL(valueChanged(int)), labelMaxMiddleValue_5, SLOT(setNum(int)));
        QObject::connect(slider_adaptiveThreshConstant, SIGNAL(valueChanged(int)), value_adaptiveThreshConstant, SLOT(setNum(int)));
        QObject::connect(slider_minMarkerPerimeterRate, SIGNAL(valueChanged(int)), value_minMarkerPerimeterRate, SLOT(setNum(int)));
        QObject::connect(slider_errorCorrectionRate, SIGNAL(valueChanged(int)), value_errorCorrectionRate, SLOT(setNum(int)));
        QObject::connect(slider_perspectiveRemovePixelPerCell, SIGNAL(valueChanged(int)), value_perspectiveRemovePixelPerCell, SLOT(setNum(int)));
        QObject::connect(slider_maxMarkerPerimeterRate, SIGNAL(valueChanged(int)), value_maxMarkerPerimeterRate, SLOT(setNum(int)));
        QObject::connect(slider_polygonalApproxAccuracyRate, SIGNAL(valueChanged(int)), value_polygonalApproxAccuracyRate, SLOT(setNum(int)));
        QObject::connect(slider_MinSizeofRects, SIGNAL(valueChanged(int)), value_MinSizeofRects, SLOT(setNum(int)));

        tabMain->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RobotDetectionMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RobotDetectionMainWindow)
    {
        RobotDetectionMainWindow->setWindowTitle(QApplication::translate("RobotDetectionMainWindow", "Robot Detection", Q_NULLPTR));
        labelImage->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonStartStop->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        pushButtonStartStop->setText(QApplication::translate("RobotDetectionMainWindow", "Start Detection", Q_NULLPTR));
        checkBox_Measurement->setText(QApplication::translate("RobotDetectionMainWindow", "Measurement", Q_NULLPTR));
        t4_label->setText(QString());
#ifndef QT_NO_TOOLTIP
        checkBoxLiveView->setToolTip(QApplication::translate("RobotDetectionMainWindow", "activates live view mode with lower framerate", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxLiveView->setText(QApplication::translate("RobotDetectionMainWindow", "Live View", Q_NULLPTR));
        labelFPS->setText(QApplication::translate("RobotDetectionMainWindow", "Frames per second:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        labelLogo->setToolTip(QApplication::translate("RobotDetectionMainWindow", "Gewerk 5 FTW !!!", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        labelLogo->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("RobotDetectionMainWindow", "Controls", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RobotDetectionMainWindow", "x", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RobotDetectionMainWindow", "y", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("RobotDetectionMainWindow", "phi", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("RobotDetectionMainWindow", "Robot 1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("RobotDetectionMainWindow", "Robot 2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("RobotDetectionMainWindow", "Robot 3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("RobotDetectionMainWindow", "Robot 4", Q_NULLPTR));
        labelVersion->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("RobotDetectionMainWindow", "Localization", Q_NULLPTR));
        pushButtonCalibrateOffset->setText(QApplication::translate("RobotDetectionMainWindow", "Calibrate Offset for Robots", Q_NULLPTR));
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
        labelMaxMiddle_8->setText(QApplication::translate("RobotDetectionMainWindow", "Min. Marker Perimet. Rate 0.0x", Q_NULLPTR));
        value_minMarkerPerimeterRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_9->setText(QApplication::translate("RobotDetectionMainWindow", "Error Correction Rate 0.x", Q_NULLPTR));
        value_errorCorrectionRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_10->setText(QApplication::translate("RobotDetectionMainWindow", "polygonal App. Acc. Rate 0.0x", Q_NULLPTR));
        value_polygonalApproxAccuracyRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_20->setText(QApplication::translate("RobotDetectionMainWindow", "Adaptive Thresh Win. Size min.", Q_NULLPTR));
        value_adaptiveThreshWinSizeStepMin->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_13->setText(QApplication::translate("RobotDetectionMainWindow", "Adaptive Thresh Constant", Q_NULLPTR));
        value_adaptiveThreshConstant->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_15->setText(QApplication::translate("RobotDetectionMainWindow", "Perspective Remove Pixel", Q_NULLPTR));
        value_perspectiveRemovePixelPerCell->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_16->setText(QApplication::translate("RobotDetectionMainWindow", "Max Size of detected  Rect\302\264s", Q_NULLPTR));
        value_MinSizeofRects->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_12->setText(QApplication::translate("RobotDetectionMainWindow", "Adaptive Thresh Win. Size Step", Q_NULLPTR));
        value_adaptiveThreshWinSizeStep->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        labelMaxMiddle_14->setText(QApplication::translate("RobotDetectionMainWindow", "Max. Marker Perimet. Rate 0.0", Q_NULLPTR));
        value_maxMarkerPerimeterRate->setText(QApplication::translate("RobotDetectionMainWindow", "0", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("RobotDetectionMainWindow", "Settings", Q_NULLPTR));
        tabMain->setTabText(tabMain->indexOf(tabMain_Navigation), QApplication::translate("RobotDetectionMainWindow", "Navigation", Q_NULLPTR));
        tabMain->setTabText(tabMain->indexOf(tabMain_Calibration), QApplication::translate("RobotDetectionMainWindow", "Calibration", Q_NULLPTR));
        label_arucomarker->setText(QString());
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Aruco->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("RobotDetectionMainWindow", "ID", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Aruco->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("RobotDetectionMainWindow", "Name", Q_NULLPTR));
        pushButton_addAruco->setText(QApplication::translate("RobotDetectionMainWindow", "+", Q_NULLPTR));
        pushButton_deleteAruco->setText(QApplication::translate("RobotDetectionMainWindow", "-", Q_NULLPTR));
        pushButton_SaveToImage->setText(QApplication::translate("RobotDetectionMainWindow", "Save To Image", Q_NULLPTR));
        tabMain->setTabText(tabMain->indexOf(tabMain_Aruco), QApplication::translate("RobotDetectionMainWindow", "Aruco Dictionary", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RobotDetectionMainWindow: public Ui_RobotDetectionMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTDETECTIONMAINWINDOW_H
