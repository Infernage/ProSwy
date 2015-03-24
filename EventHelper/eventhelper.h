#ifndef EVENTHELPER_H
#define EVENTHELPER_H

#include <QEvent>
#include <QObject>
#include <QList>

/*!
 * \brief Helper class used to avoid passing always the pointer to the object receiver.
 */
class EventHelper
{

public:

    /*!
     * \brief Initializes the mechanism.
     */
    static void init();

    /*!
     * \brief Subscribes a QObject pointer with the given QEvent. This mechanism WON'T take the ownership
     * of the QObject pointer.
     * \param obj The QObject to associate.
     * \param event The QEvent associated.
     */
    static void subscribe(QObject *obj, QEvent::Type event);

    /*!
     * \brief Sends an event to the subscribed object. This method WILL take the ownership of the pointer.
     * \param event A QEvent pointer allocated in the heap.
     */
    static void sendEvent(QEvent *event);

    /*!
     * \brief Unsubscribes a QObject with a QEvent.
     * \param obj The QObject to dissasociate.
     * \param event The QEvent associated.
     */
    static void unsubscribe(QObject *obj, QEvent::Type event);

private:
    EventHelper();
};

#endif // EVENTHELPER_H
