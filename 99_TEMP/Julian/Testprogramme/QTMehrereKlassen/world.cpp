#include "world.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Ui-Pointer wird übergeben und im eigendem Pointer gespeichert.
world::world(Ui::MainWindow *dasUi)
{
    UiVonMain = dasUi;
}

void world::pushWorld()
{
   UiVonMain->labelWorld->setText("Hello World");
}
