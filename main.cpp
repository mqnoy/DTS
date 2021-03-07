#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QSettings>
#include <QDir>
#include "constant.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style/assets/css/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    qApp->setStyleSheet(styleSheet);

    // check working directory application
    QString WORKING_DIR_APP = Constant::workingDirApp();
    qDebug()<<"prepare check working directory application..";
    QDir checking_workingdirapp(WORKING_DIR_APP);
    if(!checking_workingdirapp.exists()){
        qDebug()<<"make dir:"<<WORKING_DIR_APP;
        checking_workingdirapp.mkdir(WORKING_DIR_APP);
    }else{
        qDebug()<<"WORKING_DIR_APP found !! on "<<WORKING_DIR_APP;
    }


    QSettings qsettings(Constant::settingIni(), QSettings::IniFormat);
    qsettings.sync();
    qDebug()<<"application setting on : "<<Constant::settingIni();


    MainWindow w;
    w.show();
    return a.exec();
}
