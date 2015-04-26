#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <mainwindow.h>
#include <wlanhandler_p.h>
#include <gmock/gmock.h>
#include "../AutoTest.h"

// Mocks
class HandlerDataMock : public HandlerData
{
public:
    MOCK_METHOD0(init, void());
    MOCK_METHOD0(release, void());
    MOCK_METHOD0(refreshHandlerData, void());
    MOCK_METHOD1(contains, bool(WLANInfo *i));
    MOCK_METHOD0(addConnection, void());
    MOCK_METHOD0(store, void());
    MOCK_METHOD1(refresh, void(WLANProfile *profile));

protected:
    MOCK_METHOD0(enumInterfaces, void());
    MOCK_METHOD2(convertToText, QString(DWORD error, QString description));
    MOCK_METHOD1(refreshOptions, void(WLANProfile *profile));
    MOCK_METHOD0(registerHandler, void());
};

class MainWindowMock : public MainWindow
{
    Q_OBJECT
    // QObject interface
public:
    bool event(QEvent *)
    {
        return true;
    }

    MOCK_METHOD0(addConnectionMock, void());
    MOCK_METHOD0(removeConnectionMock, void());
    MOCK_METHOD1(selectionChangedMock, void(int row));
    MOCK_METHOD1(proxyNameChangedMock, void(QString text));
    MOCK_METHOD1(proxyPortChangedMock, void(QString text));
    MOCK_METHOD1(usernameChangedMock, void(QString text));
    MOCK_METHOD1(passwordChangedMock, void(QString text));
    MOCK_METHOD0(proxyChangedMock, void());
    MOCK_METHOD1(enableProxyMock, void(bool enable));
    MOCK_METHOD1(trayActivationMock, void(QSystemTrayIcon::ActivationReason reason));
    MOCK_METHOD0(showMessageMock, void());

    // QWidget interface
protected:
    MOCK_METHOD1(closeEvent, void(QCloseEvent *));


    // MainWindow interface
protected slots:
    void addConnection()
    {
        addConnectionMock();
    }
    void removeConnection()
    {
        removeConnectionMock();
    }
    void selectionChanged(int row)
    {
        selectionChangedMock(row);
    }
    void proxyNameChanged(QString text)
    {
        proxyNameChangedMock(text);
    }
    void proxyPortChanged(QString text)
    {
        proxyPortChangedMock(text);
    }
    void usernameChanged(QString text)
    {
        usernameChangedMock(text);
    }
    void passwordChanged(QString text)
    {
        passwordChangedMock(text);
    }
    void proxyChanged()
    {
        proxyChangedMock();
    }
    void enableProxy(bool enable)
    {
        enableProxyMock(enable);
    }
    void trayActivation(QSystemTrayIcon::ActivationReason reason)
    {
        trayActivationMock(reason);
    }
    void showMessage()
    {
        showMessageMock();
    }
};

// Test suite
class Integration : public QObject
{
    Q_OBJECT

public:
    Integration();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void test();
};

Integration::Integration()
{
}

void Integration::initTestCase()
{
}

void Integration::cleanupTestCase()
{
}

void Integration::test()
{
    QVERIFY2(true, "Failure");
}

DECLARE_TEST(Integration)

#include "tst_integration.moc"
