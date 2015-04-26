#include "../AutoTest.h"
#include <QSingleApplication.h>
#include <QTest>

int main(int argc, char *argv[])
{
    QSingleApplication app("ProSwy", argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);
    app.setQuitOnLastWindowClosed(false);
    return AutoTest::run(argc, argv);
}

#ifndef QT_DEBUG
#error "The test application must run under a debug configuration"
#endif
