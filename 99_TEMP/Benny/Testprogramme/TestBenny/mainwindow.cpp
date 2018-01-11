#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelGer->setText("");
    ui->labelWorld->setText("");
    ui->pushButtonGer->setText("Germany");
    ui->pushButtonWorld->setText("World");

//    world *myWorld = new world(ui);


//    connect(ui->pushButtonWorld,SIGNAL(clicked(bool)),myWorld,SLOT(pushWorld()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
