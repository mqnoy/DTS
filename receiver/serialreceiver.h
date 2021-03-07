#ifndef SERIALRECEIVER_H
#define SERIALRECEIVER_H

#include <QSerialPort>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QDateTime>

class SerialReceiver : public QThread
{
    Q_OBJECT
public:
    explicit SerialReceiver(QObject *parent = nullptr);
signals:

public slots:
    // init
    void init(QString comPort, qint32 boudRate);

    // read serial
    void readSerial();

    // write serial
    void writeSerial(QString comPort, QByteArray payloads);

protected:
    void run() override;

private:
    QSerialPort *serialport;

};

#endif // SERIALRECEIVER_H
