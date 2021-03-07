#include "constant.h"

Constant::Constant(QObject *parent) : QObject(parent)
{}

QString Constant::workingDirApp()
{
    QString hPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    return hPath+"/.dts/";
}

QString Constant::settingIni()
{
    return workingDirApp()+"application.ini";
}


