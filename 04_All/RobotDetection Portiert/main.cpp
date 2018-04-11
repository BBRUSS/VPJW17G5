#include "robotdetectionmainwindow.h"
#include <QApplication>
#include <QStyleFactory>

void setFusionDarkStyle();

int main(int argc, char *argv[])
{
    setFusionDarkStyle();
    QApplication a(argc, argv);
    RobotDetectionMainWindow w;  
    w.show();

    return a.exec();
}

void setFusionDarkStyle()
{
    qApp->setStyle(QStyleFactory::create("fusion"));

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
    palette.setColor(QPalette::Base, QColor(35,35,35));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, QColor(53,53,53));
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
    palette.setColor(QPalette::Dark,QColor(35,35,35));
    palette.setColor(QPalette::Shadow,QColor(20,20,20));
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
    palette.setColor(QPalette::BrightText, Qt::red);
    palette.setColor(QPalette::Link,QColor(42,130,218));

    palette.setColor(QPalette::Highlight,QColor(42,130,218));
    //palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    palette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
    //palette.setColor(QPalette::HighlightedText, Qt::black);
    palette.setColor(QPalette::HighlightedText,Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));


    qApp->setPalette(palette);


   // qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}
