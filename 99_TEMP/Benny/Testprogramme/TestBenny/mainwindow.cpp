/** Testprogramm zur Veranschaulichung, wie mehrere Klassen in QT eingebunden werden
  * und die anderen Klassen auf das Mainwindow zugreifen können, z.B. um Texte zu ändern.
  * Funktioniert, Stand 11.01.2018 12:18
  **/


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)  // build mainwindow
{
    ui->setupUi(this);
    ui->labelGer->setText(" ");
    ui->labelWorld->setText(" ");
    ui->pushButtonGer->setText("Germany");
    ui->pushButtonWorld->setText("World");

    // Erstellen eines Pointer auf die Klasse World, bei der der Pointer auf das Ui übergaben wird.
    world *myWorld = new world(ui);
    // Durch connect wird der Button mit der Funktion aus der Klasse World verbunden.
    connect(ui->pushButtonWorld,SIGNAL(clicked()),myWorld,SLOT(pushWorld()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonGer_clicked()
{
   ui->labelGer->setText("Hello Germany");
}
