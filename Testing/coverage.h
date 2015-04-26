#ifndef COVERAGE_H
#define COVERAGE_H

#include <QObject>

class Coverage : public QObject
{
    Q_OBJECT
public:
    virtual void initTest() {}
    virtual void cleanupTest() {}
protected slots:
    void init();
    void cleanup();
};

#endif // COVERAGE_H
