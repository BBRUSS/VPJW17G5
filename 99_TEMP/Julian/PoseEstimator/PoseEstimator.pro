#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T14:23:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PoseEstimator
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

INCLUDEPATH += \
    "D:/opencv/build/include" \

release:LIBS += \
    "-LD:/opencv/build/x64/vc14/lib" \
    -lopencv_world340

debug:LIBS += \
    "-LD:/opencv/build/x64/vc14/lib" \
    -lopencv_world340d

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    camera.cpp \
    settings.cpp

HEADERS += \
        mainwindow.h \
    camera.h \
    settings.h

FORMS += \
        mainwindow.ui


#DESTDIR = ./dist
CONFIG += c++11
