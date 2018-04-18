#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //F5 Shortcut for Start/Stop Camera
    QShortcut *shortcutF5 = new QShortcut(QKeySequence(Qt::Key_F5), this);
    connect(shortcutF5, SIGNAL(activated()), ui->pushButton_startStop, SLOT(click()));

    QShortcut *shortcutF9 = new QShortcut(QKeySequence(Qt::Key_F9), this);
    connect(shortcutF9, SIGNAL(activated()), ui->pushButton_takeSnap, SLOT(click()));

    // UI init
    ui->pushButton_startStop->setText("start (F5)");
    ui->pushButton_takeSnap->setText("take snap (F9)");

    // attribut init
    isStart = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_startStop_clicked()
{
    if (isStart){
        // end
        isStart = false;
        ui->pushButton_startStop->setText("start (F5)");
    }else{
        // start
        isStart = true;
        ui->pushButton_startStop->setText("end (F5)");
    }
}

void MainWindow::on_pushButton_takeSnap_clicked()
{
    qDebug() << "clciked";
}
