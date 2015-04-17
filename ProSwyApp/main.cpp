#include "mainwindow.h"
#include "wlanhandler.h"
#include "eventhelper.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QSingleApplication.h>
#include <QElapsedTimer>
#include <QThread>
#include <QSettings>

static void messageReceived(const QString message)
{
    if (message == "exit"){
        qApp->quit();
    } else if (message == "show"){
        EventHelper::sendEvent(new MessageEvent("Application already running!", ""));
    }
}

void uninstallSettings()
{
    QSettings settings("Infernage", "ProSwy");
    settings.clear();
    settings.remove("");
}

int main(int argc, char *argv[])
{
    QSingleApplication a("ProSwy", argc, argv);
    if (a.isRunning()){
        if (argc > 1){
            QString arg(argv[1]);
            if (arg.toLower() == "uninstall"){
                a.sendMessage("exit");
                QElapsedTimer timer;
                timer.start();
                while(a.isRunning() && !timer.hasExpired(3000)) QThread::msleep(100);
                if ((argc > 2 && QString(argv[2]) == "0") || argc == 2) uninstallSettings();
            } else{
                a.sendMessage("show");
            }
        } else{
            a.sendMessage("show");
        }
        return 0;
    } else if (argc > 1){
        QString arg(argv[1]);
        if (arg.toLower() == "uninstall"){
            if (((argc > 2 && QString(argv[2]) == "0") || argc == 2)) uninstallSettings();
            return 0;
        }
    }
    QObject::connect(&a, &QSingleApplication::messageReceived, messageReceived);
    QApplication::setQuitOnLastWindowClosed(false);
    EventHelper::init();
    QEvent::Type t = QEvent::None, d = QEvent::None;
    qDebug() << "Registering type event:" << (t = MessageEvent::type());
    qDebug() << "Registering type event:" << (d = DataEvent::type());
    MainWindow w;
    a.setActivationWindow(&w, false);
    EventHelper::subscribe(&w, t);
    EventHelper::subscribe(&w, d);
    w.hide();
    EventHelper::sendEvent(new MessageEvent("Application started!", ""));
    try {
        HandlerManager::init();
    } catch (QString e) {
        HandlerManager::release();
        qDebug() << "HandlerManager::init failed with code" << e;
        QMessageBox::critical(NULL, "Application crashed!",
                              "WLAN handler initialization failed: " + e);
        return 1;
    }
    return a.exec();
}
