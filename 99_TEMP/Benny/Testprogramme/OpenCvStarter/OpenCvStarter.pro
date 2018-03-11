#-------------------------------------------------
#
# Project created by QtCreator 2013-11-21T12:15:43
#
#-------------------------------------------------

QT       += core gui widgets

INCLUDEPATH += "D:\opencv\build\include"

LIBS += -LD:/opencv/build/x64/vc14/lib -lopencv_world340


TARGET = OpenCvStarter
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
