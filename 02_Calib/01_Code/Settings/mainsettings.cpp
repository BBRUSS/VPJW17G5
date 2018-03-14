#include "mainsettings.h"
#include "ui_mainsettings.h"
#include "settings.h"

#include <QDebug>
#include <QObjectList>
#include <QList>



MainSettings::MainSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainSettings)
{
    ui->setupUi(this);
    QObjectList cList (this->children());
//    all QPushButton children of parent
    QList<QPushButton *> cList2 = this->findChildren<QPushButton *>();
//    only immediate cildren of parent
    QList<QPushButton *> cList3 = this->findChildren<QPushButton *>(QString(), Qt::FindDirectChildrenOnly);
//    find children which insert RegExp
    QList<QPushButton *> cList4 = this->findChildren<QPushButton *>(QRegExp("Loade"));

    qDebug() << cList;
    qDebug() << cList2;
    qDebug() << cList3;
    qDebug() << cList4;
    this->setAttribute(Qt::WA_DeleteOnClose);
    this->parentWidget()->show();
}

MainSettings::~MainSettings()
{
    qDebug() << "delete";

    delete ui;
}
