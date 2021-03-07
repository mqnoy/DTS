#ifndef SERIALRECEIVER_H
#define SERIALRECEIVER_H

#include <QObject>

class SerialReceiver : public QObject
{
    Q_OBJECT
public:
    explicit SerialReceiver(QObject *parent = nullptr);

signals:

};

#endif // SERIALRECEIVER_H
