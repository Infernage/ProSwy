#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QTest>
#include <QList>
#include <QString>
#include <QSharedPointer>

namespace AutoTest
{
    typedef QList<QObject*> TestList;

    inline TestList &testList()
    {
        static TestList list;
        return list;
    }

    inline bool findObject(QObject *obj)
    {
        TestList &list = testList();
        if (list.contains(obj)) return true;
        foreach (QObject *testCase, list) {
            if (testCase->objectName() == obj->objectName()) return true;
        }
        return false;
    }

    inline void addTest(QObject *obj)
    {
        TestList &list = testList();
        if (!findObject(obj)) list.append(obj);
    }

    inline void addTest(int i, QObject *obj)
    {
        TestList &list = testList();
        if (!findObject(obj)) list.insert(i > list.size() ? list.size() : i, obj);
    }

    inline int run(int argc, char **argv)
    {
        int res = 0;
        foreach (QObject *testCase, testList()) {
            res += QTest::qExec(testCase, argc, argv);
        }
        return res;
    }
}

template <class T>
class Test
{
public:
    QSharedPointer<T> child;

    Test(const QString& name) : child(new T)
    {
        child->setObjectName(name);
        AutoTest::addTest(child.data());
    }

    Test(const QString &name, int position) : child(new T)
    {
        child->setObjectName(name);
        AutoTest::addTest(position, child.data());
    }
};

#define DECLARE_TEST(className) static Test<className> t(#className);

#define DECLARE_P_TEST(position, className) static Test<className> pTest(#className, #position);

#define TEST_MAIN \
    int main(int argc, char *argv[]) \
    { \
      return AutoTest::run(argc, argv); \
  }

#endif // AUTOTEST_H
