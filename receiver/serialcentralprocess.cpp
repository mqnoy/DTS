#include "serialcentralprocess.h"

SerialCentralProcess::SerialCentralProcess(QObject *parent) : QObject(parent)
{
    qDebug()<<"SerialCentralProcess executed";
}

void SerialCentralProcess::receiveFromSerial(QString portName, QByteArray buff)
{
    QJsonDocument document = QJsonDocument::fromJson(buff.data());
    QJsonObject object = document.object();

    if(object.value("kind").toString() == "A"){
        // lane A
        _ft_a->display(object.value("ft").toInt());
        _et_a->display(object.value("et").toInt());
        _rt_a->display(object.value("rt").toInt());
        _spd_a->display(object.value("spd").toInt());

    }else if(object.value("kind").toString() == "B"){
        // lane B
        _ft_b->display(object.value("ft").toInt());
        _et_b->display(object.value("et").toInt());
        _rt_b->display(object.value("rt").toInt());
        _spd_b->display(object.value("spd").toInt());

    }
    qDebug()<<"receiveFromSerial, receive from: "<<portName<<" : "<<buff;
}

void SerialCentralProcess::recInitPtrLCD(QLCDNumber* ft_a, QLCDNumber* et_a, QLCDNumber* rt_a, QLCDNumber* spd_a,
                                         QLCDNumber* ft_b, QLCDNumber* et_b, QLCDNumber* rt_b, QLCDNumber* spd_b)
{
    qDebug()<<"recInitPtrLCD ..";
    _ft_a = ft_a;
    _et_a = et_a;
    _rt_a = rt_a;
    _spd_a = spd_a;
    _ft_b = ft_b;
    _et_b = et_b;
    _rt_b = rt_b;
    _spd_b = spd_b;
}
