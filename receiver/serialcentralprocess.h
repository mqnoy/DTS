#ifndef SERIALCENTRALPROCESS_H
#define SERIALCENTRALPROCESS_H

#include <QObject>
#include <QThread>
#include <QDebug>

class SerialCentralProcess : public QObject
{
    Q_OBJECT
public:
    explicit SerialCentralProcess(QObject *parent = nullptr);

signals:
    // write payload
    void writeSerialFromCs(QString comPort, QByteArray payloads);


public slots:
    // receiving data from serial receiver class
    void receiveFromSerial(QString portName, QByteArray buff);

};

#endif // SERIALCENTRALPROCESS_H
