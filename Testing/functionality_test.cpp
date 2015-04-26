#include "functionality_test.h"
#include "../AutoTest.h"
#include "coverage.h"
#include <QtTest>
#include <eventhelper.h>
#include <mainwindow.h>
#include <wlanhandler_p.h>
#include <QInputDialog>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>

#define SSID_CONNECTION "JAZZTEL_nwcX"
#define SSID_NONCONNECTION "sadjasdh"
#define ATTR "ProxyEnabled"

QString FunctionalityTest::data;
void (*FunctionalityTest::testFunc)(bool *) = NULL;

DECLARE_TEST(FunctionalityTest)


void FunctionalityTest::initTestCase()
{
    QVERIFY(!MainWindow::mainWindow);
    QSettings settings("Infernage", "ProSwy");
    QCOMPARE(settings.allKeys().size(), 0);
    EventHelper::init();
    QEvent::Type t = QEvent::None, d = QEvent::None;
    qDebug() << "Registering type event:" << (t = MessageEvent::type());
    qDebug() << "Registering type event:" << (d = DataEvent::type());
    EventHelper::subscribe(this, t);
    EventHelper::subscribe(this, d);
    MainWindow::mainWindow = new MainWindow;
    QVERIFY(MainWindow::mainWindow);
}

void FunctionalityTest::cleanupTestCase()
{
    delete MainWindow::mainWindow;
    MainWindow::mainWindow = NULL;
    clearSettings();
}

void FunctionalityTest::initTest()
{
    HandlerManager::init();
    QVERIFY(HandlerManager::data);
    QVERIFY(HandlerManager::data->winhandler);
    QVERIFY(HandlerManager::data->errorResult == ERROR_SUCCESS);
    QVERIFY(HandlerManager::data->chain->size() > 0);
    QVERIFY(HandlerManager::data->profiles->size() >= 0);
    QTRY_VERIFY(events.size() == 1 || events.size() == 2);
    DataEvent *lst = (DataEvent*) events.at(0);
    QVERIFY(lst);
    QCOMPARE(lst->getType(), QString("QStringList"));
    QVERIFY(lst->getData().isValid());
    QVERIFY(lst->getData().toStringList().size() >= 0);
    if (events.size() == 2){
        DataEvent *mark = (DataEvent*) events.at(1);
        QVERIFY(mark);
        QCOMPARE(mark->getType(), QString("Mark"));
        QVERIFY(mark->getData().isValid());
        QVERIFY(!mark->getData().toString().isEmpty());
    }
}

void FunctionalityTest::cleanupTest()
{
    clearEvents();
    HandlerManager::release();
    QVERIFY(HandlerManager::data == NULL);
}

void FunctionalityTest::store_Test()
{
    HandlerManager::save();
    checkStore();
}

void FunctionalityTest::getSSIDConnected_Test()
{
    QString ssid = HandlerManager::getSSIDConnected();
    QVERIFY(!ssid.isEmpty());
    QCOMPARE(ssid, QString(SSID_CONNECTION));
}

void FunctionalityTest::isConnectedFor_TestNonConnected()
{
    bool res = HandlerManager::isConnectedFor(SSID_NONCONNECTION);
    QVERIFY(!res);
}

void FunctionalityTest::isConnectedFor_TestConnected()
{
    bool res = HandlerManager::isConnectedFor(SSID_CONNECTION);
    QVERIFY(res);
}

void FunctionalityTest::addConnection_TestEmptyNonConnected()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 0);
    testFunc = &FunctionalityTest::testFuncAddConnection;
    data = SSID_NONCONNECTION;
    clearEvents();
    startTimer(0);

    HandlerManager::addConnection();

    QCOMPARE(HandlerManager::data->profiles->size(), 1);
    checkStore();

    QTRY_COMPARE(events.size(), 1);
    DataEvent *widget = (DataEvent*) events.at(0);
    QVERIFY(widget);
    QCOMPARE(widget->getType(), QString("QStringWidget"));
    QVERIFY(widget->getData().isValid());
    QCOMPARE(widget->getData().toString(), data);
}

void FunctionalityTest::addConnection_TestEmptyConnected()
{
    cleanup();
    clearSettings();
    init();

    QCOMPARE(HandlerManager::data->profiles->size(), 0);
    testFunc = &FunctionalityTest::testFuncAddConnection;
    data = SSID_CONNECTION;
    clearEvents();
    startTimer(0);

    HandlerManager::addConnection();

    QCOMPARE(HandlerManager::data->profiles->size(), 1);
    checkStore();

    QTRY_COMPARE(events.size(), 2);
    DataEvent *widget = (DataEvent*) events.at(0);
    QVERIFY(widget);
    QCOMPARE(widget->getType(), QString("QStringWidget"));
    QVERIFY(widget->getData().isValid());
    QCOMPARE(widget->getData().toString(), data);

    DataEvent *mark = (DataEvent*) events.at(1);
    QVERIFY(mark);
    QCOMPARE(mark->getType(), QString("Mark"));
    QVERIFY(mark->getData().isValid());
    QCOMPARE(mark->getData().toString(), data);
}

void FunctionalityTest::addConnection_TestNonRepeatedNonConnected()
{
    cleanup();
    clearSettings();
    init();

    addConnection_TestEmptyNonConnected();

    QCOMPARE(HandlerManager::data->profiles->size(), 1);
    data = "sakdjhaskdjshakd";
    startTimer(0);

    HandlerManager::addConnection();

    QCOMPARE(HandlerManager::data->profiles->size(), 2);
    checkStore();

    QTRY_COMPARE(events.size(), 2);
    DataEvent *widget = (DataEvent*) events.at(1);
    QVERIFY(widget);
    QCOMPARE(widget->getType(), QString("QStringWidget"));
    QVERIFY(widget->getData().isValid());
    QCOMPARE(widget->getData().toString(), data);
}

void FunctionalityTest::addConnection_TestNonRepeatedConnected()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 2);
    data = SSID_CONNECTION;
    startTimer(0);

    HandlerManager::addConnection();

    QCOMPARE(HandlerManager::data->profiles->size(), 3);
    checkStore();

    QTRY_COMPARE(events.size(), 3);
    DataEvent *widget = (DataEvent*) events.at(1);
    QVERIFY(widget);
    QCOMPARE(widget->getType(), QString("QStringWidget"));
    QVERIFY(widget->getData().isValid());
    QCOMPARE(widget->getData().toString(), data);

    DataEvent *mark = (DataEvent*) events.at(2);
    QVERIFY(mark);
    QCOMPARE(mark->getType(), QString("Mark"));
    QVERIFY(mark->getData().isValid());
    QCOMPARE(mark->getData().toString(), data);
}

void FunctionalityTest::addConnection_TestRepeatedRejected()
{
    addConnection_TestNonRepeatedNonConnected();

    data = SSID_NONCONNECTION;
    testFunc = &FunctionalityTest::testFuncAddConnectionRepeatReject;
    startTimer(0);

    HandlerManager::addConnection();

    QCOMPARE(HandlerManager::data->profiles->size(), 2);
    checkStore();
}

void FunctionalityTest::addConnection_TestRepeatedAccepted()
{
    addConnection_TestNonRepeatedNonConnected();

    QCOMPARE(HandlerManager::data->profiles->size(), 2);
    data = SSID_NONCONNECTION;
    testFunc = &FunctionalityTest::testFuncAddConnectionRepeatAccept;
    startTimer(0);

    HandlerManager::addConnection();

    QCOMPARE(HandlerManager::data->profiles->size(), 3);
    checkStore();

    QTRY_COMPARE(events.size(), 3);
    DataEvent *widget = (DataEvent*) events.at(2);
    QVERIFY(widget);
    QCOMPARE(widget->getType(), QString("QStringWidget"));
    QVERIFY(widget->getData().isValid());
    QCOMPARE(widget->getData().toString(), data);
}

void FunctionalityTest::removeConnection_TestEmpty()
{
    cleanup();
    clearSettings();
    init();

    QCOMPARE(HandlerManager::data->profiles->size(), 0);
    QVERIFY(!HandlerManager::removeConnection(SSID_CONNECTION));
}

void FunctionalityTest::removeConnection_TestContained()
{
    cleanup();
    clearSettings();
    init();

    addConnection_TestEmptyNonConnected();

    QVERIFY(HandlerManager::removeConnection(SSID_NONCONNECTION));
    QCOMPARE(HandlerManager::data->profiles->size(), 0);
}

void FunctionalityTest::removeConnection_TestNonContained()
{
    cleanup();
    clearSettings();
    init();

    addConnection_TestEmptyNonConnected();

    QVERIFY(!HandlerManager::removeConnection(SSID_CONNECTION));
    QCOMPARE(HandlerManager::data->profiles->size(), 1);
}

void FunctionalityTest::getAttributeFor_TestNonSSIDContained()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 1);

    QVariant res = HandlerManager::getAttributeFor(SSID_CONNECTION, ATTR);

    QVERIFY(!res.isValid());
}

void FunctionalityTest::getAttributeFor_TestSSIDContainedNonAttr()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 1);

    QVariant res = HandlerManager::getAttributeFor(SSID_NONCONNECTION, QString(ATTR) + QString("sad"));

    QVERIFY(!res.isValid());
}

void FunctionalityTest::getAttributeFor_TestSSIDContainedAttr()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 1);

    QVariant res = HandlerManager::getAttributeFor(SSID_NONCONNECTION, ATTR);

    QVERIFY(res.isValid());
    QVERIFY(!res.toBool());
}

void FunctionalityTest::getAttributeFor_TestEmpty()
{
    cleanup();
    clearSettings();
    init();

    QVariant res = HandlerManager::getAttributeFor(SSID_NONCONNECTION, ATTR);

    QVERIFY(!res.isValid());
}

void FunctionalityTest::setAttributeFor_TestNonSSIDContained()
{
    addConnection_TestEmptyNonConnected();

    HandlerManager::setAttributeFor(SSID_CONNECTION, ATTR, QVariant::fromValue(true));

    QCOMPARE(HandlerManager::data->profiles->size(), 1);
    QVERIFY(!HandlerManager::data->profiles->at(0)->proxyEnabled);
}

void FunctionalityTest::setAttributeFor_TestSSIDContainedNonAttr()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 1);

    HandlerManager::setAttributeFor(SSID_NONCONNECTION, "sahdk", QVariant::fromValue(true));

    QCOMPARE(HandlerManager::data->profiles->size(), 1);
    QVERIFY(!HandlerManager::data->profiles->at(0)->proxyEnabled);
}

void FunctionalityTest::setAttributeFor_TestSSIDContainedAttr()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 1);

    HandlerManager::setAttributeFor(SSID_NONCONNECTION, ATTR, QVariant::fromValue(true));

    QCOMPARE(HandlerManager::data->profiles->size(), 1);
    QVERIFY(HandlerManager::data->profiles->at(0)->proxyEnabled);
}

void FunctionalityTest::setAttributeFor_TestEmpty()
{
    cleanup();
    clearSettings();
    init();

    HandlerManager::setAttributeFor(SSID_NONCONNECTION, ATTR, QVariant::fromValue(true));

    QCOMPARE(HandlerManager::data->profiles->size(), 0);
}

void FunctionalityTest::refresh_TestEmpty()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 0);

    HandlerManager::refresh(SSID_CONNECTION);

    QCOMPARE(HandlerManager::data->profiles->size(), 0);
}

void FunctionalityTest::refresh_TestNonSSID()
{
    addConnection_TestEmptyConnected();

    HandlerManager::refresh(SSID_NONCONNECTION);

    // No verifies are used here. Instead, if an exception is thrown we'll know that it fails.
}

void FunctionalityTest::refresh_TestSSID()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 1);

    HandlerManager::refresh(SSID_CONNECTION);

    // No verifies are used here. Instead, if an exception is thrown we'll know that it fails.
}

void FunctionalityTest::notificationCallback_Test()
{
    QCOMPARE(HandlerManager::data->profiles->size(), 1);

    HandlerManager::notificationCallback(SSID_CONNECTION);

    QCOMPARE(events.size(), 3);
    DataEvent *mark = (DataEvent*) events.at(2);
    QVERIFY(mark);
    QCOMPARE(mark->getType(), QString("Mark"));
    QCOMPARE(mark->getData().toString(), QString(SSID_CONNECTION));
}

void FunctionalityTest::testFuncAddConnectionRepeatAccept(bool *kill)
{
    *kill = true;

    testFuncAddConnection(kill);

    data.append("sasasasasasa");
    testFunc = &FunctionalityTest::testFuncAddConnectionRepeatMessageBoxAccept;
}

void FunctionalityTest::testFuncAddConnectionRepeatMessageBoxAccept(bool *kill)
{
    *kill = true;

    checkMessageBox(MainWindow::mainWindow, "Adding failed",
                    "Not possible to add two configurations for the same SSID!", QMessageBox::Critical);

    testFunc = &FunctionalityTest::testFuncAddConnection;
}

void FunctionalityTest::testFuncAddConnection(bool *kill)
{
    Q_UNUSED(kill)
    QInputDialog *dialog = MainWindow::mainWindow->findChild<QInputDialog*>();
    QVERIFY(dialog);
    QLineEdit *line = dialog->findChild<QLineEdit*>();
    QVERIFY(line);
    QPushButton *ok = dialog->findChild<QPushButton*>();
    QVERIFY(ok);
    QVERIFY(line->hasAcceptableInput());
    QVERIFY(ok->isEnabled());
    line->selectAll();
    QTest::keyClicks(line, data);
    dialog->accept();
}

void FunctionalityTest::testFuncAddConnectionRepeatMessageBoxReject(bool *kill)
{
    *kill = true;

    checkMessageBox(MainWindow::mainWindow, "Adding failed",
                    "Not possible to add two configurations for the same SSID!", QMessageBox::Critical);

    testFunc = &FunctionalityTest::testFuncAddConnectionRepeatNewInputReject;
}

void FunctionalityTest::testFuncAddConnectionRepeatNewInputReject(bool *kill)
{
    Q_UNUSED(kill)

    QInputDialog *ndialog = MainWindow::mainWindow->findChild<QInputDialog*>();
    QVERIFY(ndialog);
    ndialog->reject();
}

void FunctionalityTest::testFuncAddConnectionRepeatReject(bool *kill)
{
    *kill = true;

    testFuncAddConnection(kill);

    testFunc = &FunctionalityTest::testFuncAddConnectionRepeatMessageBoxReject;
}

void FunctionalityTest::checkMessageBox(QWidget *parent, QString title, QString text, QMessageBox::Icon icon)
{
    QMessageBox *box = parent->findChild<QMessageBox*>();
    QVERIFY(box);
    QCOMPARE(box->windowTitle(), title);
    QCOMPARE(box->text(), text);
    QCOMPARE(box->icon(), icon);
    box->accept();
}

void FunctionalityTest::checkStore()
{
    QSettings settings("Infernage", "ProSwy");
    QVERIFY(settings.contains("profilesCreated"));
    QVERIFY(settings.value("profilesCreated").isValid());
    QCOMPARE(settings.value("profilesCreated").toInt(), HandlerManager::data->profiles->size());
    QVERIFY(settings.contains("profiles/size"));
    QVERIFY(settings.value("profiles/size").isValid());
    QCOMPARE(settings.value("profiles/size").toInt(), HandlerManager::data->profiles->size());
    settings.beginReadArray("profiles");
    for(int i = 0; i < HandlerManager::data->profiles->size(); ++i){
        settings.setArrayIndex(i);
        WLANProfile *p = HandlerManager::data->profiles->at(i);
        QCOMPARE(p->ssid, settings.value("ssid").toString());
        QCOMPARE(p->proxy, settings.value("proxy").toString());
        QCOMPARE(p->port, settings.value("port").toULongLong());
        QCOMPARE(p->proxyEnabled, settings.value("active").toBool());
    }
    settings.endArray();
}

void FunctionalityTest::clearEvents()
{
    foreach (QEvent *e, events) {
        delete e;
    }
    events.clear();
}

void FunctionalityTest::clearSettings()
{
    QSettings settings("Infernage", "ProSwy");
    settings.clear();
    settings.sync();
    QCOMPARE(settings.allKeys().size(), 0);
}

bool FunctionalityTest::event(QEvent *evt)
{
    if (evt->type() == MessageEvent::type() || evt->type() == DataEvent::type()){
        QEvent *clone;
        if (evt->type() == MessageEvent::type()){
            MessageEvent *e = (MessageEvent*) evt;
            qDebug() << "Icon:" << e->getIcon() << "\nTitle:" << e->getTitle()
                     << "\nMessage:" << e->getMessage();
            clone = new MessageEvent(e->getTitle(), e->getMessage(), e->getIcon());
        } else{
            DataEvent *e = (DataEvent*) evt;
            qDebug() << "Type:" << e->getType() << "\nData:" << e->getData();
            clone = new DataEvent(e->getType(), e->getData());
        }
        events.append(clone);
        return true;
    } else return QObject::event(evt);
}

void FunctionalityTest::timerEvent(QTimerEvent *timer)
{
    killTimer(timer->timerId());
    bool generateTimer = false;
    if (testFunc) testFunc(&generateTimer);
    if (generateTimer) startTimer(0);
}
