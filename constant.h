#ifndef CONSTANT_H
#define CONSTANT_H

#include <QObject>
#include <QStandardPaths>


enum SERIAL_DEFINITION{
    RECEIVE_FT = 100,
    RECEIVE_ET = 101,
    RECEIVE_RT = 102,
    RECEIVE_SPD = 103
};


class Constant : public QObject
{
    Q_OBJECT
public:
    explicit Constant(QObject *parent = nullptr);

    static QString settingIni();

    // working dir app
    static QString workingDirApp();

signals:

};

#endif // CONSTANT_H
