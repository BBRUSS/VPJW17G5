#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "sqlquerythread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    SqlQueryThread sqlQueryThread;


protected slots:
    void onTimer();
    void queryFinished(QSqlQuery);
private slots:
    void on_pushButtonStartQuery_clicked();
};

#endif // MAINWINDOW_H
