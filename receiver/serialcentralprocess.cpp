#include "serialcentralprocess.h"

SerialCentralProcess::SerialCentralProcess(QObject *parent) : QObject(parent)
{
    qDebug()<<"SerialCentralProcess executed";
}

void SerialCentralProcess::receiveFromSerial(QString portName, QByteArray buff)
{
   qDebug()<<"receiveFromSerial, receive from: "<<portName<<" : "<<buff;
}
