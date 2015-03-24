#include "mainwindow.h"
#include "wlanhandler.h"
#include "eventhelper.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setQuitOnLastWindowClosed(false);
    EventHelper::init();
    QEvent::Type t = QEvent::None, d = QEvent::None;
    qDebug() << "Registering type event:" << (t = MessageEvent::type());
    qDebug() << "Registering type event:" << (d = DataEvent::type());
    MainWindow w;
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
