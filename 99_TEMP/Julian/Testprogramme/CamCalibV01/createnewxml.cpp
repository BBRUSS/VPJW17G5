#include "createnewxml.h"
#include "ui_createnewxml.h"
/** TODO: Window zur Eingabe von Einstellungen, aufgerufen wenn keine Settings.xml gefunden wurde oder
 *  wenn der User die Settings neu einstellen möchte.
 * Globale Settings werden direkt eingestellt (in aufrufender Funktion zwischenspeichern)
 * Kameraspezifische Einstellungen werden dann abhängig von der zu wählenden ID eingestellt.
 * Dazu sollte in der aufrufenden Funktion ein Array von Camera structs erstellt werden, und die Werte
 * mit <<camArray[id].wert = wert;>> zwischengespeichert werden.
 * Mit Klick auf "OK" werden die Werte dann an die Klasse <<Settings>> übergeben und gespeichert.
  *
  **/


/**
 * @brief createNewXML::createNewXML
 * @param parent
 */
createNewXML::createNewXML(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createNewXML)
{
    ui->setupUi(this);
}

createNewXML::~createNewXML()
{
    delete ui;
}
