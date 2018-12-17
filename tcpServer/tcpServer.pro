#-------------------------------------------------
#
# Project created by QtCreator 2018-02-01T11:40:57
#
#-------------------------------------------------

QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpServer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    database.cpp

HEADERS  += widget.h \
    database.h

FORMS    += widget.ui
