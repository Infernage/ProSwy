#include "wlanhandler_p.h"
#include "mainwindow.h"
#include "eventhelper.h"
#include <QThread>
#include <QCoreApplication>
#include <QNetworkProxyQuery>
#include <QSettings>
#include <QMessageBox>
#include <QInputDialog>

HandlerData *HandlerManager::data = NULL;
QEvent::Type DataEvent::eType = QEvent::None;
QMutex HandlerManager::lock(QMutex::Recursive);

void HandlerManager::init()
{
    QMutexLocker lck(&lock);
    if (!data){
        data = new HandlerData;
        data->init();
    }
}

void HandlerManager::release()
{
    QMutexLocker lck(&lock);
    if (!data) return;
    data->release();
    delete data;
    data = NULL;
}

void HandlerManager::addConnection()
{
    QMutexLocker lck(&lock);
    if (!data) return;
    data->addConnection();
}

bool HandlerManager::removeConnection(QString ssid)
{
    ssid = ssid.replace(" - (Connected)", "");
    QMutexLocker lck(&lock);
    if (!data) return false;
    for (int i = 0; i < data->profiles->size(); ++i) {
        if (data->profiles->at(i)->ssid == ssid){
            WLANProfile *profile = data->profiles->takeAt(i);
            delete profile;
            return true;
        }
    }
    return false;
}

QVariant HandlerManager::getAttributeFor(QString ssid, QString attr)
{
    ssid = ssid.replace(" - (Connected)", "");
    QMutexLocker lck(&lock);
    QVariant res;
    if (!data) return res;
    for (int i = 0; i < data->profiles->size(); ++i) {
        if (data->profiles->at(i)->ssid == ssid){
            WLANProfile *pro = data->profiles->at(i);
            if (attr == "ProxyEnabled"){
                res.setValue(pro->proxyEnabled);
            } else if (attr == "ProxyHost"){
                res.setValue(pro->proxy);
            } else if (attr == "ProxyPort"){
                res.setValue(pro->port);
            } else if (attr == "Username"){
                res.setValue(pro->username);
            } else if (attr == "Password"){
                res.setValue(pro->password);
            } else if (attr == "SSID"){
                res.setValue(data->profiles->at(i)->ssid);
            }
            return res;
        }
    }
    return res;
}

void HandlerManager::setAttributeFor(QString ssid, QString attr, QVariant value)
{
    ssid = ssid.replace(" - (Connected)", "");
    QMutexLocker lck(&lock);
    if (!data) return;
    for (int i = 0; i < data->profiles->size(); ++i) {
        if (data->profiles->at(i)->ssid == ssid){
            WLANProfile *pro = data->profiles->at(i);
            if (attr == "ProxyEnabled"){
                pro->proxyEnabled = value.toBool();
            } else if (attr == "ProxyHost"){
                pro->proxy = value.toString();
            } else if (attr == "ProxyPort"){
                pro->port = value.toULongLong();
            } else if (attr == "Username"){
                //pro->username = value.toString();
            } else if (attr == "Password"){
                //pro->password = value.toString();
            }
            break;
        }
    }
    data->store();
}

QString HandlerManager::getSSIDConnected()
{
    QMutexLocker lck(&lock);
    if (!data) return "";
    for (int i = 0; i < data->chain->size(); ++i) {
        WLANInfo *inf = data->chain->at(i);
        if (inf->state == Connected) return QString(inf->ssid);
    }
    return "";
}

bool HandlerManager::isConnectedFor(QString ssid)
{
    ssid = ssid.replace(" - (Connected)", "");
    return ssid == getSSIDConnected();
}

void HandlerManager::refresh(QString ssid)
{
    ssid = ssid.replace(" - (Connected)", "");
    if (!isConnectedFor(ssid)) return;
    QMutexLocker lck(&lock);
    if (!data) return;
    for (int i = 0; i < data->profiles->size(); ++i) {
        if (data->profiles->at(i)->ssid == ssid){
            data->refresh(data->profiles->at(i));
            return;
        }
    }
}

void HandlerManager::save()
{
    QMutexLocker lck(&lock);
    if (!data) return;
    data->store();
}

HandlerManager::HandlerManager()
{}

HandlerManager::~HandlerManager()
{}

void HandlerManager::notificationCallback(QString ssid)
{
    QMutexLocker lck(&lock);
    if (!data){
        throw 0x2; // Application already closed?
    }
    data->refreshHandlerData();
    for (int i = 0; i < data->profiles->size(); ++i) {
        WLANProfile *pro = data->profiles->at(i);
        if (pro->ssid == ssid){
            EventHelper::sendEvent(new DataEvent("Mark", QVariant::fromValue(ssid)));
            // Network changed, apply profile stored.
            QNetworkProxyQuery npq(QUrl("http://www.google.com"));
            QList<QNetworkProxy> proxies = QNetworkProxyFactory::systemProxyForQuery(npq);
            if (!pro->proxyEnabled
                    && proxies.at(0).type() == QNetworkProxy::NoProxy){
                qDebug() << "Proxy already disabled";
                return;
            } else if (pro->proxyEnabled
                     && proxies.at(0).type() != QNetworkProxy::NoProxy &&
                     pro->port == proxies.at(0).port() &&
                     pro->proxy == proxies.at(0).hostName()){
                qDebug() << "Proxy already enabled";
                return;
            }
            try {
                data->refresh(pro);
                EventHelper::sendEvent(new MessageEvent("Profile changed",
                                                             QString("The network has changed, applied stored profile ")
                                                             + pro->ssid));
            } catch (int e) {
                EventHelper::sendEvent(new MessageEvent("Refresh failed",
                                                             "Failed to refresh wlan options. Error code: "
                                                             + QString::number(e),
                                                             QSystemTrayIcon::Warning));
                qDebug() << "refreshOptions function failed with error code:" << e;
            }
            return;
        }
    }
}


DataEvent::DataEvent(QString dataType, QVariant data) : QEvent(type()), dType(dataType), data(data)
{}

QEvent::Type DataEvent::type()
{
    if (eType == QEvent::None){
        int eventid = QEvent::registerEventType(1565);
        if (eventid == -1){
            qDebug() << "FAILED TO INSTALL EVENT!";
            exit(1);
        }
        eType = static_cast<QEvent::Type>(eventid);
    }
    return eType;
}

HandlerData::HandlerData()
{
    createdAt = QThread::currentThread();
    chain = new QList<WLANInfo*>;
    profiles = new QList<WLANProfile*>;
}

void HandlerData::init()
{
#ifdef Q_OS_WIN
    winhandler = NULL;
    errorDescription = "";
    DWORD version = 0;
    errorResult = WlanOpenHandle(2, NULL, &version, &winhandler);
    if (errorResult != ERROR_SUCCESS){
        errorDescription = convertToText(errorResult, "WlanOpenHandle failed with error "
                                         + QString::number(errorResult) + ": ");
        throw errorDescription;
    }
    qDebug() << "Using WLAN Win API version" << version;
    enumInterfaces();
    registerHandler();

    // Load from persistent storage
    QSettings settings("Infernage", "ProSwy");
    int size = settings.value("profilesCreated").toInt();
    settings.beginReadArray("profiles");
    QStringList lst;
    QString connected;
    for (int i = 0; i < size; ++i) {
        settings.setArrayIndex(i);
        WLANProfile *profile = new WLANProfile;
        profile->ssid = settings.value("ssid").toString();
        profile->proxy = settings.value("proxy").toString();
        profile->port = settings.value("port").toULongLong();
        profile->proxyEnabled = settings.value("active").toBool();
#ifndef Q_OS_WIN
        // Set username and password using cipher mode
#endif
        for (int j = 0; j < chain->size(); ++j) {
            if (chain->at(j)->ssid == profile->ssid && chain->at(j)->state == Connected){
                try {
                    connected = profile->ssid;
                    refreshOptions(profile);
                } catch (int e) {
                    qApp->postEvent(MainWindow::mainWindow, new MessageEvent("Refresh failed",
                                                                 "Failed to refresh wlan options. Error code: "
                                                                 + QString::number(e),
                                                                 QSystemTrayIcon::Warning),
                                    Qt::HighEventPriority);
                    qDebug() << "refreshOptions function failed with error code:" << e;
                }
            }
        }
        profiles->append(profile);
        lst.append(profile->ssid);
    }
    settings.endArray();
    EventHelper::sendEvent(new DataEvent("QStringList", QVariant::fromValue(lst)));
    if (!connected.isEmpty()) EventHelper::sendEvent(new DataEvent("Mark", QVariant::fromValue(connected)));
#endif
}

HandlerData::~HandlerData()
{
    if (chain != NULL){
        if (chain->size() > 0){
            for (int i = 0; i < chain->size(); ++i) {
                if (chain->at(i) != NULL) delete chain->at(i);
            }
        }
        delete chain;
    }
    if (profiles != NULL){
        if (profiles->size() > 0){
            for (int i = 0; i < profiles->size(); ++i) {
                if (profiles->at(i) != NULL){
                    delete profiles->at(i);
                }
            }
        }
        delete profiles;
    }
}

void HandlerData::release()
{
#ifdef Q_OS_WIN
    if (winhandler == NULL) return;
    // Be sure to unregister the handler for notifications!
    DWORD previous;
    WlanRegisterNotification(winhandler, WLAN_NOTIFICATION_SOURCE_NONE, TRUE, NULL, NULL, NULL, &previous);
    WlanCloseHandle(winhandler, NULL);
#endif
}

void HandlerData::refreshHandlerData()
{
#ifdef Q_OS_WIN
    enumInterfaces();
#endif
}

bool HandlerData::contains(WLANInfo *i)
{
    for (int j = 0; j < profiles->size(); ++j) {
        if (i->ssid == profiles->at(j)->ssid) return true;
    }
    return false;
}

void HandlerData::addConnection()
{
    QString ssid = HandlerManager::getSSIDConnected();
    bool ok = true;
    do{
        ssid = QInputDialog::getText(MainWindow::mainWindow, "Adding network",
                                     "Add the SSID of the network to connect", QLineEdit::Normal, ssid);
        if (ssid.isNull() || ssid.isEmpty()) return;
        ok = true;
        for (int i = 0; i < profiles->size(); ++i) {
            if (ssid == profiles->at(i)->ssid){
                QMessageBox::critical(MainWindow::mainWindow, "Adding failed",
                                      "Not possible to add two configurations for the same SSID!");
                ok = false;
            }
        }
    } while(!ok);

    WLANProfile *profile = new WLANProfile;
    profile->ssid = ssid;

    QNetworkProxyQuery npq(QUrl("http://www.google.com"));
    QList<QNetworkProxy> proxies = QNetworkProxyFactory::systemProxyForQuery(npq);
    profile->proxyEnabled = proxies.at(0).type() != QNetworkProxy::NoProxy;
    if (profile->proxyEnabled){
        profile->port = proxies.at(0).port();
        profile->proxy = proxies.at(0).hostName();
    }
    profile->username = proxies.at(0).user();
    profile->password = proxies.at(0).password();
    profiles->append(profile);
    EventHelper::sendEvent(new DataEvent("QStringWidget", QVariant::fromValue(ssid)));
    store();
    if (HandlerManager::isConnectedFor(ssid)) EventHelper::sendEvent(new DataEvent("Mark", QVariant::fromValue(ssid)));
}

void HandlerData::store()
{
    QSettings settings("Infernage", "ProSwy");
    settings.setValue("profilesCreated", profiles->size());
    settings.beginWriteArray("profiles");
    for (int i = 0; i < profiles->size(); ++i) {
        settings.setArrayIndex(i);
        WLANProfile *profile = profiles->at(i);
        settings.setValue("ssid", profile->ssid);
        settings.setValue("proxy", profile->proxy);
        settings.setValue("port", profile->port);
        settings.setValue("active", profile->proxyEnabled);
    }
    settings.endArray();
}

void HandlerData::refresh(WLANProfile *profile)
{
#ifdef Q_OS_WIN
    refreshOptions(profile);
#endif
}

#ifdef Q_OS_WIN
void HandlerData::enumInterfaces()
{
    PWLAN_INTERFACE_INFO_LIST list = NULL;

    errorResult = WlanEnumInterfaces(winhandler, NULL, &list);
    // Failed to obtain available interfaces
    if (errorResult != ERROR_SUCCESS){
        errorDescription = convertToText(errorResult, "WlanEnumInterfaces failed with error "
                                         + QString::number(errorResult) + ": ");
        throw errorDescription;
    }

    qDebug() << "Num entries found: " << list->dwNumberOfItems;
    WCHAR GuidString[39] = { 0 };

    for (int i = 0; i < chain->size(); ++i) {
        delete chain->at(i);
    }
    chain->clear();

    for (unsigned int i = 0; i < list->dwNumberOfItems; ++i) {
        PWLAN_INTERFACE_INFO info = (WLAN_INTERFACE_INFO *)&list->InterfaceInfo[i];
        WLANInfo *wInfo = new WLANInfo;
        chain->append(wInfo);
        if (StringFromGUID2(info->InterfaceGuid,
                            (LPOLESTR) & GuidString,
                            sizeof (GuidString) / sizeof (*GuidString)) == 0)
            qDebug() << "StringFromGUID2 function call failed!";
        else{
            qDebug() << "Interface GUID[" << i << "]:" << QString::fromWCharArray(GuidString);
            wInfo->guid = QString::fromWCharArray(GuidString);
        }
        qDebug() << "Interface description[" << i << "]:" << QString::fromWCharArray(info->strInterfaceDescription);
        wInfo->description = QString::fromWCharArray(info->strInterfaceDescription);
        qDebug() << "Interface state:";
        switch (info->isState) {
        case wlan_interface_state_not_ready:
            qDebug() << "Not ready";
            wInfo->state = Not_ready;
            break;
        case wlan_interface_state_connected:
            qDebug() << "Connected";
            wInfo->state = Connected;
            break;
        case wlan_interface_state_ad_hoc_network_formed:
            qDebug() << "First node in an ad hoc network";
            wInfo->state = AD_HOC;
            break;
        case wlan_interface_state_disconnecting:
            qDebug() << "Disconnecting";
            wInfo->state = Disconnecting;
            break;
        case wlan_interface_state_disconnected:
            qDebug() << "Not connected";
            wInfo->state = Disconnected;
            break;
        case wlan_interface_state_associating:
            qDebug() << "Attempting to associate with a network";
            wInfo->state = Associating;
            break;
        case wlan_interface_state_discovering:
            qDebug() << "Auto configuration is discovering settings for the network";
            wInfo->state = Discovering;
            break;
        case wlan_interface_state_authenticating:
            qDebug() << "In process of authenticating";
            wInfo->state = Authenticating;
            break;
        default:
            qDebug() << "Unknown state";
            wInfo->state = Undefined;
            break;
        }

        if (info->isState == wlan_interface_state_connected){
            DWORD size = sizeof(WLAN_CONNECTION_ATTRIBUTES);
            PWLAN_CONNECTION_ATTRIBUTES attrs = NULL;
            WLAN_OPCODE_VALUE_TYPE opcode = wlan_opcode_value_type_invalid;

            DWORD result = WlanQueryInterface(winhandler, &info->InterfaceGuid, wlan_intf_opcode_current_connection, NULL,
                                        &size, (PVOID *) &attrs, &opcode);

            if (result != ERROR_SUCCESS){
                wInfo->errorCode = result;
                wInfo->errorDescription = convertToText(result, "WlanQueryInterface failed with error "
                                                        + QString::number(result) + ": ");
                continue;
            }
            qDebug() << "Association Attributes for this connection" << endl << "SSID:";
            if (attrs->wlanAssociationAttributes.dot11Ssid.uSSIDLength != 0) {
                QString ssid;
                for (unsigned int j = 0; j < attrs->wlanAssociationAttributes.dot11Ssid.uSSIDLength; ++j) {
                    ssid.append(attrs->wlanAssociationAttributes.dot11Ssid.ucSSID[j]);
                }
                wInfo->ssid = ssid;
                qDebug() << ssid << endl << "MAC address:";
                QString mac;
                for (int j = 0; j < sizeof (attrs->wlanAssociationAttributes.dot11Bssid); ++j) {
                    if (j == 5) mac.append(QString("%1").arg(attrs->wlanAssociationAttributes.dot11Bssid[j], 2, 16, QChar('0')).toUpper());
                    else mac.append(QString("%1-").arg(attrs->wlanAssociationAttributes.dot11Bssid[j], 2, 16, QChar('0')).toUpper());
                }
                wInfo->mac = mac;
                qDebug() << mac;
            }
            if (attrs != NULL){
                WlanFreeMemory(attrs);
            }
        }
    }

    if (list != NULL) {
        WlanFreeMemory(list);
    }
}

QString HandlerData::convertToText(DWORD error, QString description)
{
    LPWSTR msg;
    FormatMessageW(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
                   NULL, error, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPWSTR) &msg, 0, NULL);
    QString data = QString::fromWCharArray((LPWSTR) msg);
    data.chop(1);
    LocalFree(msg);
    return description + data;
}

void HandlerData::refreshOptions(WLANProfile *profile)
{
    QString addr = profile->proxy + ":" + QString::number(profile->port);
    WCHAR *connAddr = new WCHAR[addr.size() + 1];
    connAddr[addr.toWCharArray(connAddr)] = 0;

    INTERNET_PER_CONN_OPTION_LIST list;
    BOOL    bReturn;
    DWORD   dwBufSize = sizeof(list);
    // Fill out list struct.
    list.dwSize = sizeof(list);
    // NULL == LAN, otherwise connectoid name.
    list.pszConnection = NULL;
    // Set three options.
    list.dwOptionCount = !profile->proxyEnabled ? 1 : 3;
    list.pOptions = new INTERNET_PER_CONN_OPTION[list.dwOptionCount];
    // Make sure the memory was allocated.
    if(list.pOptions == NULL)
    {
        delete connAddr;
        throw 0x5; // ERROR CODE = Failed to allocate memory
    }
    // Set flags.
    list.pOptions[0].dwOption = INTERNET_PER_CONN_FLAGS;
    if (!profile->proxyEnabled){
        qDebug() << "Disabling proxy...";
        list.pOptions[0].Value.dwValue = PROXY_TYPE_DIRECT;
    } else{
        qDebug() << "Enabling proxy with address" << addr;
        list.pOptions[0].Value.dwValue = PROXY_TYPE_DIRECT | PROXY_TYPE_PROXY;

        // Set proxy name.
        list.pOptions[1].dwOption = INTERNET_PER_CONN_PROXY_SERVER;
        list.pOptions[1].Value.pszValue = connAddr;

        // Set proxy override.
        list.pOptions[2].dwOption = INTERNET_PER_CONN_PROXY_BYPASS;
        list.pOptions[2].Value.pszValue = (LPWSTR) L"<local>";
    }

    // Set the options on the connection.
    bReturn = InternetSetOption(NULL, INTERNET_OPTION_PER_CONNECTION_OPTION, &list, dwBufSize);

    if (!bReturn){
        LPWSTR lpMsgBuf;
        DWORD e = GetLastError();
        qDebug() << e;
        FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                      FORMAT_MESSAGE_IGNORE_INSERTS,
                      NULL,
                      e,
                      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                      (LPTSTR) &lpMsgBuf,
                      0, NULL );
        qDebug() << "ERROR" << QString::fromWCharArray(lpMsgBuf);
    }

    // Free the allocated memory.
    delete [] list.pOptions;
    delete connAddr;
    InternetSetOption(NULL, INTERNET_OPTION_SETTINGS_CHANGED, NULL, 0);
    InternetSetOption(NULL, INTERNET_OPTION_REFRESH , NULL, 0);
    if (!bReturn){
        throw 0x4; // ERROR CODE = Failed to set options
    }
}

void HandlerData::wlanNotification(PWLAN_NOTIFICATION_DATA data, PVOID p)
{
    Q_UNUSED(p)
    if (!data) return;
    if (data->NotificationSource == WLAN_NOTIFICATION_SOURCE_MSM){
        if (data->NotificationCode == wlan_notification_msm_connected){
            // Check for stored and configured connection
            PWLAN_MSM_NOTIFICATION_DATA nData = (PWLAN_MSM_NOTIFICATION_DATA) data->pData;
            qDebug() << "Windows changed to profile" << QString::fromWCharArray(nData->strProfileName);
            QString ssid;
            for (unsigned int j = 0; j < nData->dot11Ssid.uSSIDLength; ++j) {
                ssid.append(nData->dot11Ssid.ucSSID[j]);
            }
            try {
                HandlerManager::notificationCallback(ssid);
            } catch (QString s) {
                qDebug() << "Exception catched:" << s;
                EventHelper::sendEvent(new MessageEvent("Notification callback failed!",
                                                    s, QSystemTrayIcon::Critical));
            } catch (int e){
                qDebug() << "Exception code catched:" << e;
            }
        }
    }
}

void HandlerData::registerHandler()
{
    if (errorResult != 0 && !errorDescription.isEmpty()){
        qDebug() << "Catched error!" << errorDescription;
        throw errorResult;
    }
    DWORD previous = 0;
    DWORD value = WlanRegisterNotification(winhandler,
                                           WLAN_NOTIFICATION_SOURCE_ALL, TRUE,
                                           &HandlerData::wlanNotification, NULL, NULL, &previous);
    qDebug() << "Using WLAN_NOTIFICATION_SOURCE_ALL, previous was" << previous;
    if (value != ERROR_SUCCESS){
        QString err = convertToText(value, "registerHandler failed with error "
                                    + QString::number(value) + ": ");
        qDebug() << "Function failed!" << err;
        throw err;
    }
}
#endif
