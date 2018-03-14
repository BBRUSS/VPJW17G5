#ifndef MAINSETTINGS_H
#define MAINSETTINGS_H

#include <QDialog>
#include <iostream>

namespace Ui {
class MainSettings;
}

class MainSettings : public QDialog
{
    Q_OBJECT

public:
    explicit MainSettings(QWidget *parent = 0);
    ~MainSettings();

private slots:
//    void on_pushButtonSave_clicked();

private:
    Ui::MainSettings *ui;

};

#endif // MAINSETTINGS_H
