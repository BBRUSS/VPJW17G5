#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonHelloWorld, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(react()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClicked()
{
    ui->textEdit->setText("Hallo Welt!");
}
