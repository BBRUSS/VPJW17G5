#ifndef CREATENEWXML_H
#define CREATENEWXML_H

#include <QDialog>

namespace Ui {
class createNewXML;
}

class createNewXML : public QDialog
{
    Q_OBJECT

public:
    explicit createNewXML(QWidget *parent = 0);
    ~createNewXML();

private:
    Ui::createNewXML *ui;
};

#endif // CREATENEWXML_H
