#ifndef BUFFERSUBSCRIPTION_H
#define BUFFERSUBSCRIPTION_H

#include <QObject>
#include <circularbuffer.h>
#include "I_Subscriber.h"

#include <QSharedPointer>


class BufferSubscription : public QObject {
    Q_OBJECT

public:
    BufferSubscription(CircularBuffer& buffer, QObject* parent = nullptr);


    void registerSubscriber(QSharedPointer<I_Subscriber> subscriber, int lookBackPeriodMS);
    void unregisterSubscriber(QSharedPointer<I_Subscriber> subscriber);

// signals :
    // void notifySubscribers(QSharedPointer<Subscriber> subscriber,const std::vector<double> values);

private slots:
    void onDataAddedToBuffer(int dataIntervalsMS);

private:

    CircularBuffer& _buffer;
    QVector<QSharedPointer<I_Subscriber>> _subscribers;
    QVector<int> _lookBackPeriods;

};

#endif // BUFFERSUBSCRIPTION_H
