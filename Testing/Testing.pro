#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T16:03:54
#
#-------------------------------------------------

QT       += widgets concurrent network testlib

TARGET = TestApp
CONFIG   += console CodeCoverage
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += functionality_test.cpp \
    instance_test.cpp \
    main.cpp \
    coverage.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\" TEST_PRO

HEADERS += ../AutoTest.h \
    coverage.h \
    functionality_test.h \
    instance_test.h

include($$PWD/../ProSwyApp/proswycommon.pri)

CodeCoverage {
    QMAKE_CFLAGS += --cs-include-path=../ProSwyApp
    QMAKE_CXXFLAGS += --cs-include-path=../ProSwyApp
    QMAKE_LFLAGS += --cs-include-path=../ProSwyApp

    win32{
        QMAKE_POST_LINK = echo Executing unit tests &
        QMAKE_POST_LINK += $$shell_path($$DESTDIR)\\TestApp.exe &
        QMAKE_POST_LINK += echo Importing coverage report &
        QMAKE_POST_LINK += MOVE /Y $$shell_path($$OUT_PWD)\\TestApp.csexe $$shell_path($$DESTDIR)\\TestApp.csexe &
        QMAKE_POST_LINK += cmcsexeimport -m $$shell_path($$DESTDIR)\\TestApp.exe.csmes \
                           -e $$shell_path($$DESTDIR)\\TestApp.csexe -t UnitTest &
        QMAKE_POST_LINK += del /F $$shell_path($$DESTDIR)\\TestApp.csexe &
        QMAKE_POST_LINK += echo Merging unit test result into the main application &
        QMAKE_POST_LINK += cmmerge -o $$shell_path($$DESTDIR)\\ProSwy_unit.exe.csmes -i
        QMAKE_POST_LINK += $$shell_path($$DESTDIR)\\ProSwy.exe.csmes $$shell_path($$DESTDIR)\\TestApp.exe.csmes &
        QMAKE_POST_LINK += MOVE /Y $$shell_path($$DESTDIR)\\ProSwy_unit.exe.csmes $$shell_path($$DESTDIR)\\ProSwy.exe.csmes &
        QMAKE_POST_LINK += cmreport -m $$shell_path($$DESTDIR)\\TestApp.exe.csmes --html=report
    }

    unix{
        QMAKE_POST_LINK = rm $$DESTDIR/TestApp.exe.csexe ;
        QMAKE_POST_LINK += $$DESTDIR/TestApp.exe ;
        QMAKE_POST_LINK += cmcsexeimport -m $$DESTDIR/TestApp.exe.csmes \
                           -e $$DESTDIR/TestApp.exe.csexe -t UnitTest ;
        QMAKE_POST_LINK += cmreport -m $$DESTDIR/TestApp.exe.csmes --html=report
    }
}
