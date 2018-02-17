#------------------------------
#
# Project created by QtCreator
#
#------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CalibResizing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cameracalibrator.cpp

HEADERS  += mainwindow.h \
    cameracalibrator.h

FORMS    += mainwindow.ui

## SET THE CORRECT PATH HEREAFTER ##

INCLUDEPATH += "E:\Programme\opencv\build\include"

LIBS += -LE:/Programme/opencv/build/x64/vc14/lib -lopencv_world340

#DESTDIR = ./dist
#CONFIG += c++11
