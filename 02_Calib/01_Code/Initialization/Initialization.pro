#-------------------------------------------------
#
# Project created by QtCreator 2018-03-29T14:19:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Initialization
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    settings.cpp \
    release/moc_mainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp

HEADERS += \
        mainwindow.h \
    release/moc_predefs.h \
    mainwindow.h \
    settings.h \
    ui_mainwindow.h

FORMS += \
        mainwindow.ui

INCLUDEPATH += "D:\opencv\build\include"

LIBS += -LD:/opencv/build/x64/vc14/lib -lopencv_world340
