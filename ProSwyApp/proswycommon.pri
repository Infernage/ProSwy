CONFIG += c++14

INCLUDEPATH += $$PWD
DEPENDPATH  += $$PWD

SOURCES += $$PWD/mainwindow.cpp \
           $$PWD/wlanhandler.cpp

HEADERS  += $$PWD/mainwindow.h \
            $$PWD/wlanhandler.h \
            $$PWD/wlanhandler_p.h

FORMS    += $$PWD/mainwindow.ui

RESOURCES += $$PWD/resources.qrc

CONFIG(release, debug|release): DESTDIR = $$PWD/../build_release
else: CONFIG(debug, debug|release): DESTDIR = $$PWD/../build_debug

include($$PWD/../EventHelper/eventhelper.pri)
include($$PWD/../../QSingleApplication/qsingleapplication.pri)

win32{
    QMAKE_POST_LINK = windeployqt $$DESTDIR\\$$TARGET.exe &
}

CodeCoverage{
    COVERAGE_OPTIONS = --cs-count --cs-full-instrumentation --cs-qt4 --cs-output=$$TARGET --cs-exclude-file-regex=qrc_.*
    QMAKE_CFLAGS += $$COVERAGE_OPTIONS
    QMAKE_CXXFLAGS += $$COVERAGE_OPTIONS
    QMAKE_LFLAGS += $$COVERAGE_OPTIONS

    QMAKE_CC = cs$$QMAKE_CC
    QMAKE_CXX = cs$$QMAKE_CXX
    QMAKE_LINK = cs$$QMAKE_LINK
    QMAKE_LINK_SHLIB = cs$$QMAKE_LINK_SHLIB
    QMAKE_AR = cs$$QMAKE_AR
}
