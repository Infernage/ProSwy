#ifndef WLANHANDLER_H
#define WLANHANDLER_H

#include <QObject>
#include <QList>
#include <QEvent>
#include <QVariant>

class DataEvent : public QEvent
{
public:
    DataEvent(QString dataType, QVariant data);
    static QEvent::Type type();

    QString getType(){
        return dType;
    }

    QVariant getData(){
        return data;
    }

private:
    static QEvent::Type eType;

    QString dType;
    QVariant data;
};

class HandlerData;

class HandlerManager
{
public:
    /*!
     * \brief Initializes the handler for WIFI notifications.
     * \warning This method can throw exceptions of QString type.
     */
    static void init();

    /*!
     * \brief Releases all system resources. MUST be invoked before the program finalizes.
     */
    static void release();

    /*!
     * \brief Add the current connection as a profile.
     */
    static void addConnection();

    /*!
     * \brief Removes the given connection.
     * \param id The connection ID. Should be the SSID and the MAC address.
     * \return \code true if the connection was removed successfully, or \code false in otherwise.
     */
    static bool removeConnection(QString id);

    /*!
     * \brief Gets an attribute from a connection profile.
     * \param id The connection ID. Should be the SSID and the MAC address.
     * \param attr The attribute to request.
     * \return A QVariant with the value of the attribute.
     */
    static QVariant getAttributeFor(QString id, QString attr);

    /*!
     * \brief Sets an attribute of a connection profile.
     * \param id The connection ID. Should be the SSID and the MAC address.
     * \param attr The attribute to set.
     * \param value The value to set.
     */
    static void setAttributeFor(QString id, QString attr, QVariant value);

    /*!
     * \brief Obtains the SSID for the connected network.
     * \return A QString with the SSID or an empty QString.
     */
    static QString getSSIDConnected();

    /*!
     * \brief Checks if the connection is currently connected.
     * \param id The connection ID. Should be the SSID and the MAC address.
     * \return \code true if the connection is actually connected.
     */
    static bool isConnectedFor(QString id);

    /*!
     * \brief Refresh the wlan options for the given connection. \warning The connection
     * MUST be connected. \warning This method can throw exceptions of type integer.
     * \param id The connection ID. Should be the SSID and the MAC address.
     */
    static void refresh(QString id);

    /*!
     * \brief Saves all profiles to the disk.
     */
    static void save();

private:
    static HandlerData *data;
    static QMutex lock;
    explicit HandlerManager();
    ~HandlerManager();

    static void notificationCallback(QString ssid, QString mac);

    friend class HandlerData;
};

#endif // WLANHANDLER_H
