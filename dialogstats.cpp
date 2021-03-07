#include "dialogstats.h"
#include "ui_dialogstats.h"

DialogStats::DialogStats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStats)
{
    ui->setupUi(this);
}

DialogStats::~DialogStats()
{
    delete ui;
}
