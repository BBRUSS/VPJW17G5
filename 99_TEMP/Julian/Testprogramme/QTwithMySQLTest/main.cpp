#include "mainwindow.h"
#include <QApplication>

#include <QtCore/QCoreApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost:82");
    db.setDatabaseName("qt_mysql_test");

    // login data
    db.setUserName("root");
    db.setPassword("");

    if(!db.open())
    {
        qDebug() << db.lastError();
        //qFatal( "Failed to connect");
    } else {
        qDebug("Connected!");
    }

    return a.exec();
}
