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
CONFIG += c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    wlanhandler.cpp

HEADERS  += mainwindow.h \
    wlanhandler.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EventHelper/release/ -lEventHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EventHelper/debug/ -lEventHelper
else:unix: LIBS += -L$$OUT_PWD/../EventHelper/ -lEventHelper

INCLUDEPATH += $$PWD/../EventHelper
DEPENDPATH += $$PWD/../EventHelper

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EventHelper/release/libEventHelper.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EventHelper/debug/libEventHelper.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EventHelper/release/EventHelper.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../EventHelper/debug/EventHelper.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../EventHelper/libEventHelper.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../QSingleApplication/release/ -lQSingleApplication
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../QSingleApplication/debug/ -lQSingleApplication
else:unix: LIBS += -L$$PWD/../../QSingleApplication/ -lQSingleApplication

INCLUDEPATH += $$PWD/../../QSingleApplication
DEPENDPATH += $$PWD/../../QSingleApplication

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../QSingleApplication/release/libQSingleApplication.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../QSingleApplication/debug/libQSingleApplication.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../QSingleApplication/release/QSingleApplication.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../QSingleApplication/debug/QSingleApplication.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../QSingleApplication/libQSingleApplication.a
