#include "mainwindow.h"
#include "ui_mainwindow.h"

QSettings qsettings(Constant::settingIni(), QSettings::IniFormat);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // serial central process
    serialCentralProc = new SerialCentralProcess;

    // init ptr LCD
    serialCentralProc->recInitPtrLCD(ui->lcdNumber_ft, ui->lcdNumber_et, ui->lcdNumber_rt, ui->lcdNumber_spd,
                                     ui->lcdNumber_ft2, ui->lcdNumber_et2, ui->lcdNumber_rt2, ui->lcdNumber_spd2);


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
    if(!tempPayloads.contains("kind")){
        qDebug()<<"payload not contains kind";
    }else{
        QJsonDocument doc(tempPayloads);
        QByteArray payloads = doc.toJson(QJsonDocument::Compact);
        emit serialCentralProc->writeSerialFromCs(com_port, payloads);
    }

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
        serialReceiver->init(com_port, com_speed);
        connect(this, &MainWindow::writeSerial,
                serialReceiver, &SerialReceiver::writeSerial);
        serialReceiver->start();

        // connect for sending n receiving data
        connect(serialReceiver, &SerialReceiver::sendFromSerial,
                serialCentralProc, &SerialCentralProcess::receiveFromSerial);

        // connect for sending payloads to serial receiver class
        connect(serialCentralProc, &SerialCentralProcess::writeSerialFromCs,
                serialReceiver, &SerialReceiver::writeSerial);


        thSerial = new QThread;
        serialCentralProc->moveToThread(thSerial);
        thSerial->start();
    }
}

void MainWindow::on_rd_delay_tree500_clicked()
{
    tempPayloads.insert("delay_tree", 500);
}

void MainWindow::on_rd_delay_tree400_clicked()
{
    tempPayloads.insert("delay_tree", 400);
}

void MainWindow::on_radioButton_clicked()
{
    tempPayloads.insert("kind", "A");
}

void MainWindow::on_radioButton_3_clicked()
{
    tempPayloads.insert("kind", "B");
}

void MainWindow::on_radioButton_2_clicked()
{
    tempPayloads.insert("kind", "AB");
}

void MainWindow::on_rb_full_tree_clicked()
{
    tempPayloads.insert("tree_type", "FULL");
}

void MainWindow::on_rb_pro_tree_clicked()
{
    tempPayloads.insert("tree_type", "PRO");
}
