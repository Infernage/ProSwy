#-------------------------------------------------
#
# Project created by QtCreator 2015-04-25T23:55:44
#
#-------------------------------------------------

QT       += widgets concurrent network testlib

TARGET = TestAppIntegration
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += /MTd
QMAKE_CFLAGS += /MTd

SOURCES += tst_integration.cpp \
    main.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\" \
    TEST_PRO

HEADERS += ../AutoTest.h


INCLUDEPATH += $$PWD/../../gmock-1.7.0/gtest/include
DEPENDPATH += $$PWD/../../gmock-1.7.0/gtest/include

INCLUDEPATH += $$PWD/../../gmock-1.7.0/include
DEPENDPATH += $$PWD/../../gmock-1.7.0/include

contains(QMAKE_TARGET.arch, x86){

win32: LIBS += -L$$PWD/../../gmock-1.7.0-build/gtest/ -lgtest

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build/gtest/gtest.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build/gtest/libgtest.a

win32: LIBS += -L$$PWD/../../gmock-1.7.0-build/ -lgmock

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build/gmock.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build/libgmock.a

}

contains(QMAKE_TARGET.arch, x86_64){

win32: LIBS += -L$$PWD/../../gmock-1.7.0-build64/gtest/ -lgtest

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build64/gtest/gtest.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build64/gtest/libgtest.a

win32: LIBS += -L$$PWD/../../gmock-1.7.0-build64/ -lgmock

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build64/gmock.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../../gmock-1.7.0-build64/libgmock.a

}

include($$PWD/../ProSwyApp/proswycommon.pri)
