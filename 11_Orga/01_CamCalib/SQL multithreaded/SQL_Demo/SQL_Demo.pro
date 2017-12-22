#-------------------------------------------------
#
# Project created by QtCreator 2017-12-05T19:39:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQL_Demo
TEMPLATE = app

LIBS += -L"C:/Program Files/MySQL/MySQL Connector C 6.1/lib"
    -llibmysql

SOURCES += main.cpp\
        mainwindow.cpp\
        sqlquerythread.cpp

HEADERS  += mainwindow.h \
            sqlquerythread.h

FORMS    += mainwindow.ui
