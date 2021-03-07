#ifndef SERIALCENTRALPROCESS_H
#define SERIALCENTRALPROCESS_H

#include <QObject>

class SerialCentralProcess : public QObject
{
    Q_OBJECT
public:
    explicit SerialCentralProcess(QObject *parent = nullptr);

signals:

};

#endif // SERIALCENTRALPROCESS_H
