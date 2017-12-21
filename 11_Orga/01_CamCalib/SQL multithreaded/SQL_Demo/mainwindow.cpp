#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<QSqlQuery>("QSqlQuery");
    connect(&sqlQueryThread, SIGNAL(queryFinished(QSqlQuery)), this,SLOT(queryFinished(QSqlQuery)));

    connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    sqlQueryThread.start();
    timer.start(33);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimer()
{
    int time = QTime::currentTime().msecsSinceStartOfDay()%3000;
    ui->horizontalSlider->setValue(128+127*qSin(2*time*3.14/3000));

}

void MainWindow::queryFinished(QSqlQuery query)
{
    qDebug() << "Query finished";

   if (query.isActive())
   {
    while(query.next()) // for each row
    {
       ui->plainTextEdit->appendPlainText( query.record().value("idtable1").toString() +" " + query.record().value("table1col").toString());
    }

    query.clear();
   }
}

void MainWindow::on_pushButtonStartQuery_clicked()
{
    QString query = "select * from table1";

    sqlQueryThread.execute(query);
}
