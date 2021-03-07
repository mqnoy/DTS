#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>
#include "dialogabout.h"
#include "receiver/serialreceiver.h"


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


private slots:
    void on_actionAbout_triggered();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    SerialReceiver *serialReceiver;

    // thread
    QThread *thSerial;

    //
    QString com_port;

    //
};
#endif // MAINWINDOW_H
