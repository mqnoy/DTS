#ifndef CONSTANT_H
#define CONSTANT_H

#include <QObject>
#include <QStandardPaths>

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
