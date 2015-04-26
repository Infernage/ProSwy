#-------------------------------------------------
#
# Project created by QtCreator 2015-03-17T03:40:36
#
#-------------------------------------------------

QT       -= gui

TARGET = EventHelper
TEMPLATE = lib
CONFIG += staticlib c++14

SOURCES += eventhelper.cpp

HEADERS += eventhelper.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    eventhelper.pri
