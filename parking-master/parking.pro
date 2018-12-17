#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T17:14:15
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT += xml
QT += network
QT += widgets axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = parking
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    in.cpp \
    out.cpp \
    admin.cpp \
    map.cpp \
    drawmap.cpp \
    tileset.cpp \
    nav.cpp \
    config.cpp \
    database.cpp \
    dialog.cpp \
    register_show.cpp \
    login_show.cpp \
    guanli.cpp \
    youche.cpp \
    cheg.cpp \
    reng.cpp \
    mapp.cpp \
    mibao.cpp

HEADERS  += mainwindow.h \
    in.h \
    out.h \
    admin.h \
    map.h \
    drawmap.h \
    tileset.h \
    nav.h \
    config.h \
    database.h \
    dialog.h \
    register_show.h \
    login_show.h \
    guanli.h \
    proto.h \
    youche.h \
    cheg.h \
    reng.h \
    mapp.h \
    webaxwidget.h \
    mibao.h

FORMS    += mainwindow.ui \
    in.ui \
    out.ui \
    admin.ui \
    nav.ui \
    dialog.ui \
    register_show.ui \
    login_show.ui \
    guanli.ui \
    youche.ui \
    cheg.ui \
    reng.ui \
    mapp.ui \
    mibao.ui
