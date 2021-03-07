#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include <QSettings>
#include <QJsonObject>
#include "dialogabout.h"
#include "receiver/serialreceiver.h"
#include "receiver/serialcentralprocess.h"
#include "constant.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void writeSerial(QString comPort, QByteArray payloads);

public slots:
    void setLcdNumberValues();

    // function fullscreen mode
    void setFullScreenMode();


private slots:
    void on_actionAbout_triggered();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_rd_delay_tree500_clicked();

    void on_rd_delay_tree400_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();

    void on_rb_full_tree_clicked();

    void on_rb_pro_tree_clicked();

private:
    Ui::MainWindow *ui;

    //
    SerialReceiver *serialReceiver;
    SerialCentralProcess *serialCentralProc;

    // thread
    QThread *thSerial;

    //
    QString com_port= "";
    qint32 com_speed = 0;

    //
    QJsonObject tempPayloads;
};
#endif // MAINWINDOW_H
