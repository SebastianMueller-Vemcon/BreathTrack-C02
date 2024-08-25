#ifndef DATABUFFERMANAGER_H
#define DATABUFFERMANAGER_H

#include <QObject>

#include <circularbuffer.h>
#include <types.h>
#include <emaaverager.h>
#include <smaaverager.h>
#include <sensorsimulator.h>


class DataBufferManager : public QObject
{
    Q_OBJECT
public:
    DataBufferManager(QObject *parent = nullptr);

    //TODO: Include Buffer Subscription Class
    /* TODO: add data into buffers from..
     *      .. sensor
     *      .. sma
     *      .. ema
     */

    /* TODO: add subscribers to each buffer ..
     *      .. raw: Trend Calculator, FrontendAPI
     *      .. sma: Trend Calculator, FrontendAPI
     *      .. ema: Trend Calculator, FrontendAPI
     */

    //Singleton
    static std::shared_ptr<DataBufferManager> instance();


    CircularBuffer* getBuffer(SensorDataType type);

private slots:
    void onNewData(double newData, SensorDataType sensorDataType);

private:
    std::map<SensorDataType, CircularBuffer*> _buffers;
    size_t _rawCapacity = 600;   // Example: 10 minutes at 1-second intervals
    size_t _averageCapacity = 60; // Example: 5 minutes at 5-second intervals

    static std::shared_ptr<DataBufferManager> _instance;

};

#endif // DATABUFFERMANAGER_H
