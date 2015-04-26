#include "coverage.h"
#include <QTest>
#include <QMetaObject>
#include <QString>

void Coverage::init()
{
#ifdef __COVERAGESCANNER__
    __coveragescanner_clear();
#endif
    initTest();
}

void Coverage::cleanup()
{
    cleanupTest();
#ifdef __COVERAGESCANNER__
    QString test_name="unittest/";
    test_name+=metaObject()->className();
    test_name+="/";
    test_name+=QTest::currentTestFunction();
    __coveragescanner_testname(test_name.toLatin1());
    if (QTest::currentTestFailed()) __coveragescanner_teststate("FAILED");
    else __coveragescanner_teststate("PASSED") ;
    __coveragescanner_save();
    __coveragescanner_testname("");
#endif
}
