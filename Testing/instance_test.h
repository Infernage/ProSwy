#ifndef INSTANCE_TEST
#define INSTANCE_TEST

#include "coverage.h"

class InstanceTest : public Coverage
{
    Q_OBJECT

public:
    InstanceTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();
};

#endif // INSTANCE_TEST

