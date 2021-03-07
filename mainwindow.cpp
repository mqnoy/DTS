#include "mainwindow.h"
#include "ui_mainwindow.h"

QSettings qsettings(Constant::settingIni(), QSettings::IniFormat);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set fullscreen mode
    setFullScreenMode();
}

void MainWindow::setFullScreenMode()
{
    if(qsettings.value("FULLSCREEN").toBool()){
        QTimer::singleShot(0, this, SLOT(showFullScreen()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_triggered()
{
    DialogAbout *dialog_about = new DialogAbout();
    dialog_about->setVisible(true);
}

void MainWindow::on_pushButton_7_clicked()
{
    close();
}

void MainWindow::setLcdNumberValues()
{
    ui->lcdNumber_ft->display(100);
}

void MainWindow::on_pushButton_clicked()
{
    // start button
    QByteArray payloads = QString("start command").toUtf8();
    emit writeSerial(com_port, payloads);
}

void MainWindow::on_pushButton_6_clicked()
{
    // connect button
    // initiate serial
    com_port = qsettings.value("SERIAL_PORT").toString();
    com_speed = qsettings.value("SERIAL_SPEED").toInt();
    if(com_port.length() <= 0 && com_speed == 0){
        qDebug()<<"Please fill value SERIAL_PORT and SERIAL_SPEED..";
    }else{
        serialReceiver = new SerialReceiver;
        serialReceiver->init(com_port, 115200);
        connect(this, &MainWindow::writeSerial,
                serialReceiver, &SerialReceiver::writeSerial);

        //thSerial = new QThread(this);
        //serialReceiver->moveToThread(thSerial);
        serialReceiver->start();
    }
}
