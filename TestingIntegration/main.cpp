#include "../AutoTest.h"
#include <qsingleapplication.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleMock(&argc, argv);
    QSingleApplication app("ProSwy", argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);
    app.setQuitOnLastWindowClosed(false);
    return AutoTest::run(argc, argv);
}

#ifndef QT_DEBUG
#error "The test application must run under a debug configuration"
#endif
