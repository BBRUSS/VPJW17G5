#------------------------------
#
# Project created by QtCreator
#
#------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CalibResizing
TEMPLATE = app


SOURCES += \
    main.cpp\
    mainwindow.cpp \
    cameracalibrator.cpp

HEADERS  += \
    mainwindow.h \
    cameracalibrator.h

FORMS    += mainwindow.ui


INCLUDEPATH += \
    "C:/OpenCv30/build/include"

LIBS += \
    "-LC:/OpenCv30/build/x64/vc14/lib" -lopencv_world341

DESTDIR = ./dist
CONFIG += c++11
