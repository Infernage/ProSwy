#include "instance_test.h"
#include <QString>
#include <QtTest>
#include <QApplication>

InstanceTest::InstanceTest()
{
}

void InstanceTest::initTestCase()
{
}

void InstanceTest::cleanupTestCase()
{
}

void InstanceTest::testCase1()
{
    QVERIFY2(true, "Failure");
}
