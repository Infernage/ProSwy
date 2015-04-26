#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTimer>
#include <QSystemTrayIcon>
#include "wlanhandler.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief Event used to show a message on the system tray if it's supported.
 */
class MessageEvent : public QEvent
{
public:
    /*!
     * \brief Default constructor.
     * \param title The title message.
     * \param message The string message.
     * \param icon The icon type to display.
     */
    MessageEvent(QString title, QString message, QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information);

    /*!
     * \brief Obtains the type assigned to this event.
     * \return A QEvent::Type containing the int ID for this event.
     */
    static QEvent::Type type();

    /* Getters */
    QString getTitle(){
        return title;
    }
    QString getMessage(){
        return message;
    }
    QSystemTrayIcon::MessageIcon getIcon(){
        return icon;
    }

private:
    static QEvent::Type eType; //! The QEvent type containing the int ID for this event.

    /* Private members */
    QString title, message;
    QSystemTrayIcon::MessageIcon icon;
};

#if defined(TEST_PRO) && defined(QT_DEBUG)
class FunctionalityTest;
class InstanceTest;
#endif

/*!
 * \brief Class used to show the main application window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Default QMainWindow constructor.
     * \param parent The QWidget parent. By default is NULL.
     */
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow(); //! Default destructor.

    static MainWindow *mainWindow; //! Singleton instance.

protected:
    /*!
     * \brief Reimplemented from QMainWindow::closeEvent(QCloseEvent).
     * Simply ignores the event and hides the window.
     * \param event The QCloseEvent pointer.
     */
    virtual void closeEvent(QCloseEvent *event);

    /*!
     * \brief Reimplemented from QMainWindow::event(QEvent). Used for transmit custom events
     * with the observer pattern.
     * \param event The QEvent pointer.
     * \return \code true if the event has been identified or \code false in otherwise.
     */
   virtual  bool event(QEvent *event);

protected slots:
    /*!
     * \brief Adds the current connection. See HandlerManager::addConnection()
     */
    virtual void addConnection();

    /*!
     * \brief Removes the selected connection. See HandlerManager::removeConnection(QString)
     */
    virtual void removeConnection();

    /*!
     * \brief Refresh the UI with the changed profile.
     * \param row The new row selected.
     */
    virtual void selectionChanged(int row);

    /*!
     * \brief Refresh the proxy host in the internal settings.
     * \param text A QString with the proxy host.
     */
    virtual void proxyNameChanged(QString text);

    /*!
     * \brief Refresh the proxy port in the internal settings.
     * \param text A QString with the proxy port.
     */
    virtual void proxyPortChanged(QString text);

    /*!
     * \brief Refresh the proxy username in the internal settings.
     * \warning This only works on UNIX systems.
     * \param text A QString with the proxy username.
     */
    virtual void usernameChanged(QString text);

    /*!
     * \brief Refresh the proxy password in the internal settings.
     * \warning This only works on UNIX systems.
     * \param text A QString with the proxy password.
     */
    virtual void passwordChanged(QString text);

    /*!
     * \brief Refresh the selected profile in the system if is possible.
     * See HandlerManager::refresh(QString)
     */
    virtual void proxyChanged();

    /*!
     * \brief Refresh the proxy settings in the internal settings and UI.
     * This also will refresh the system proxy by calling MainWindow::proxyChanged()
     * \param enable
     */
    virtual void enableProxy(bool enable);

    /*!
     * \brief Performs an action depending of the possible activation reason.
     * \param reason The activation reason.
     */
    virtual void trayActivation(QSystemTrayIcon::ActivationReason reason);

    /*!
     * \brief Shows an information message of the current network system status.
     */
    virtual void showMessage();

private: // Private members
    Ui::MainWindow *ui;
    QSystemTrayIcon *tray;
    QTimer timer;
    QString last;

#if defined(TEST_PRO) && defined(QT_DEBUG)
    friend class FunctionalityTest;
    friend class InstanceTest;
#endif
};

#endif // MAINWINDOW_H
