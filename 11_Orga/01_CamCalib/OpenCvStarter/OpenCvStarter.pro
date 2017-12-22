#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T12:15:43
#
#-------------------------------------------------

QT       += core gui widgets

INCLUDEPATH += "C:/opencv/build/include"
LIBS += "-LC:/opencv/build/x64/vc14/lib" \
    #-lopencv_world331
    -lopencv_world340


TARGET = OpenCvStarter
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
