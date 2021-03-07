#include "serialreceiver.h"

SerialReceiver::SerialReceiver(QObject *parent) : QThread(parent)
{}

void SerialReceiver::run()
{
    while(1){
        //emit readSerial();
    }
}

void SerialReceiver::init(QString comPort, qint32 boudRate)
{

    serialport = new QSerialPort;
    serialport->setPortName(comPort);
    serialport->setBaudRate(boudRate);
    serialport->setDataBits(QSerialPort::Data8);
    serialport->setParity(QSerialPort::NoParity);
    serialport->setStopBits(QSerialPort::OneStop);
    serialport->setFlowControl(QSerialPort::NoFlowControl);

    if (!serialport->open(QSerialPort::ReadWrite)) {
        qDebug() << "Error opening serial port: " << serialport->errorString();
    }else{
        qDebug() << "Success opening serial port: " << serialport->errorString();
        connect(serialport, &QSerialPort::readyRead,
                this, &SerialReceiver::readSerial);
        serialport->write("Halo from me another side..\n");
    }
}

void SerialReceiver::readSerial()
{
    QByteArray buff;
    buff.append(serialport->readAll());

    qDebug() << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz")<<" Receiving from: "<<serialport->portName()<<" buff: "<<buff;
    // send data to central process
    emit sendFromSerial(serialport->portName(), buff);
    buff.clear();
}

void SerialReceiver::writeSerial(QString comPort, QByteArray payloads)
{
    qDebug() <<"writeSerial: "<<comPort <<"payloads : "<<payloads;
    serialport->write(payloads, payloads.length());
}
