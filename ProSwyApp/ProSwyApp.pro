#-------------------------------------------------
#
# Project created by QtCreator 2015-03-20T17:26:19
#
#-------------------------------------------------

QT       += core gui concurrent network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = icon.ico
TARGET = ProSwy
TEMPLATE = app

SOURCES += main.cpp

CONFIG(debug, debug|release): CONFIG += CodeCoverage

include(proswycommon.pri)

CodeCoverage{
    win32{
        QMAKE_POST_LINK += echo Executing main app &
        QMAKE_POST_LINK += $$DESTDIR\\ProSwy.exe
    }
}
