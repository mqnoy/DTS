#ifndef SERIALCENTRALPROCESS_H
#define SERIALCENTRALPROCESS_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLCDNumber>

class SerialCentralProcess : public QObject
{
    Q_OBJECT
public:
    explicit SerialCentralProcess(QObject *parent = nullptr);

    // init ptr lcd
    void recInitPtrLCD(QLCDNumber* ft_a, QLCDNumber* et_a, QLCDNumber* rt_a, QLCDNumber* spd_a,
                       QLCDNumber* ft_b, QLCDNumber* et_b, QLCDNumber* rt_b, QLCDNumber* spd_b);

signals:
    // write payload
    void writeSerialFromCs(QString comPort, QByteArray payloads);


public slots:
    // receiving data from serial receiver class
    void receiveFromSerial(QString portName, QByteArray buff);

private:

    // ptr LCD
    QLCDNumber* _ft_a;
    QLCDNumber* _et_a;
    QLCDNumber* _rt_a;
    QLCDNumber* _spd_a;
    QLCDNumber* _ft_b;
    QLCDNumber* _et_b;
    QLCDNumber* _rt_b;
    QLCDNumber* _spd_b;

};

#endif // SERIALCENTRALPROCESS_H
