#ifndef FUNCTIONALITY_TEST
#define FUNCTIONALITY_TEST

#include "coverage.h"
#include "../AutoTest.h"
#include <QMessageBox>

class FunctionalityTest : public Coverage
{
    Q_OBJECT

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void initTest();
    void cleanupTest();
    void store_Test();
    void getSSIDConnected_Test();
    void isConnectedFor_TestNonConnected();
    void isConnectedFor_TestConnected();
    void addConnection_TestEmptyNonConnected();
    void addConnection_TestEmptyConnected();
    void addConnection_TestNonRepeatedNonConnected();
    void addConnection_TestNonRepeatedConnected();
    void addConnection_TestRepeatedRejected();
    void addConnection_TestRepeatedAccepted();
    void removeConnection_TestEmpty();
    void removeConnection_TestContained();
    void removeConnection_TestNonContained();
    void getAttributeFor_TestNonSSIDContained();
    void getAttributeFor_TestSSIDContainedNonAttr();
    void getAttributeFor_TestSSIDContainedAttr();
    void getAttributeFor_TestEmpty();
    void setAttributeFor_TestNonSSIDContained();
    void setAttributeFor_TestSSIDContainedNonAttr();
    void setAttributeFor_TestSSIDContainedAttr();
    void setAttributeFor_TestEmpty();
    void refresh_TestEmpty();
    void refresh_TestNonSSID();
    void refresh_TestSSID();
    void notificationCallback_Test();
private:
    QList<QEvent*> events;

    static void (*testFunc)(bool *);
    static QString data;

    static void testFuncAddConnectionRepeatAccept(bool *kill);
    static void testFuncAddConnectionRepeatMessageBoxAccept(bool *kill);
    static void testFuncAddConnection(bool *kill);
    static void testFuncAddConnectionRepeatMessageBoxReject(bool *kill);
    static void testFuncAddConnectionRepeatNewInputReject(bool *kill);
    static void testFuncAddConnectionRepeatReject(bool *kill);
    static void checkMessageBox(QWidget *parent, QString title, QString text, QMessageBox::Icon icon);
    void checkStore();
    void clearEvents();
    void clearSettings();
public:
    bool event(QEvent *evt);
protected:
    void timerEvent(QTimerEvent *timer);
};

#endif // FUNCTIONALITY_TEST

