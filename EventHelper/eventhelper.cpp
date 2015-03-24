#include "eventhelper.h"
#include <QMutexLocker>
#include <QCoreApplication>
#include <QThread>
#include <QMultiMap>
#include <QDebug>

static QMultiMap<QObject*, int> *events = NULL;
static QMutex *mutex = NULL;
static void unload();
static void unsubscribeAll(QObject *obj);

void EventHelper::init()
{
    if (qApp->thread() != QThread::currentThread()){ // Only allow to initialize from main thread and once.
        return;
    }
    if (mutex != NULL) return; // Only initialize once time.
    mutex = new QMutex;
    QMutexLocker lock(mutex);
    Q_UNUSED(lock)

    // Connect signals
    QObject::connect(qApp, &QCoreApplication::aboutToQuit, unload);
    events = new QMultiMap<QObject*, int>;
}

void EventHelper::subscribe(QObject *obj, QEvent::Type event)
{
    if (!mutex || !events) return;
    QMutexLocker lock(mutex);
    Q_UNUSED(lock)

    events->insert(obj, event);
    QObject::connect(obj, &QObject::destroyed, unsubscribeAll);
}

void EventHelper::sendEvent(QEvent *event)
{
    if (!mutex || !events) return;
    QMutexLocker lock(mutex);
    Q_UNUSED(lock)

    QList<QObject*> list = events->keys(event->type()); // Get all subscribers
    if (list.size() > 0){
        bool shouldDelete = true;
        foreach (QObject *obj, list) {
            if (obj->thread() == QThread::currentThread()){
                // Send inmediatly with the QEventLoop from the QCoreApplication
                QCoreApplication::sendEvent(obj, event);
            } else{
                shouldDelete = false;
                // Post the event to the event queue
                QCoreApplication::postEvent(obj, event);
            }
        }
        if (shouldDelete) delete event;
    }
}

void EventHelper::unsubscribe(QObject *obj, QEvent::Type event)
{
    if (!mutex || !events) return;
    QMutexLocker lock(mutex);
    Q_UNUSED(lock)

    QMap<QObject*, int>::iterator i = events->find(obj);
    while (i != events->end() && i.key() == obj) {
        if (i.value() == event){
            events->erase(i); // Erase the current entry
            return;
        }
        ++i;
    }
}

// Ignored, only static functions used
EventHelper::EventHelper()
{}

static void unsubscribeAll(QObject *obj)
{
    if (!mutex || !events) return; // How the **** did you get here????
    QMutexLocker lock(mutex);
    Q_UNUSED(lock)
    events->remove(obj);
}

static void unload()
{
    // Unload this mechanism
    if (!mutex && !events) return;
    qDebug() << "Unloading event helper";
    if (mutex) mutex->lock();
    if (events){ // Remove all events associated
        events->clear();
        delete events;
        events = NULL;
    }
    if (mutex){
        mutex->unlock();
        delete mutex;
        mutex = NULL;
    }
}
