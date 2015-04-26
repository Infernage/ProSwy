#ifndef WLANHANDLER_P
#define WLANHANDLER_P

#include "wlanhandler.h"

#ifdef Q_OS_WIN
#include <Windows.h>
#include <wlanapi.h>
#include <windot11.h>
#include <objbase.h>
#include <wtypes.h>
#include <WinInet.h>

#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "WinInet.lib")
#endif

enum State{
    Not_ready,
    Connected,
    AD_HOC,
    Disconnecting,
    Disconnected,
    Associating,
    Discovering,
    Authenticating,
    Undefined
};

struct WLANInfo{
    QString mac = "";
    QString guid = "";
    QString description = "";
    State state;
    QString ssid = "";
    unsigned long errorCode = 0;
    QString errorDescription = "";
};

struct WLANProfile{
    bool proxyEnabled = false;
    QString proxy = "";
    qulonglong port = 0;
    QString username = "";
    QString password = "";
    QString ssid = "";
};

class HandlerData
{
public:
    HandlerData();

    virtual void init();

    virtual ~HandlerData();

    virtual void release();

    virtual void refreshHandlerData();

    virtual bool contains(WLANInfo *i);

    virtual void addConnection();

    virtual void store();

    virtual void refresh(WLANProfile *profile);

protected:
#ifdef Q_OS_WIN
    /*!
     * \brief Enum the WLAN interfaces from the computer.
     * \warning This method can throw exceptions of QString type.
     * \param handler The WLANHandler pointer to work with.
     */
    virtual void enumInterfaces();

    /*!
     * \brief Parses a DWORD error to a string
     * \param error The error code
     * \param description An optional description for the error cause
     * \return The error string with the description.
     */
    virtual QString convertToText(DWORD error, QString description);

    /*!
     * \brief Refresh the internet options of the system with the profile passed as argument.
     * WARNING: This method can throw exceptions.
     * \param profile The profile with the proxy data
     */
    virtual void refreshOptions(WLANProfile *profile);

    /*!
      Callback function used when something happens with the wlan connection.
     */
    static void WINAPI wlanNotification(PWLAN_NOTIFICATION_DATA data, PVOID p);

    /*!
     * \brief Registers the handler to listen the updates for the wlan connection.
     * If the registration fails, it throws an exception.
     */
    virtual void registerHandler();

#endif

private:
#ifdef Q_OS_WIN
    HANDLE winhandler;
    unsigned long errorResult;
    QString errorDescription;
#endif

#if defined(TEST_PRO) && defined(QT_DEBUG)
    friend class FunctionalityTest;
    friend class InstanceTest;
#endif

public:
    QList<WLANInfo*> *chain;
    QList<WLANProfile*> *profiles;
    const QThread *createdAt;
};

#endif // WLANHANDLER_P

