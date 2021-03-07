#ifndef DIALOGSTATS_H
#define DIALOGSTATS_H

#include <QDialog>

namespace Ui {
class DialogStats;
}

class DialogStats : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStats(QWidget *parent = nullptr);
    ~DialogStats();

private:
    Ui::DialogStats *ui;
};

#endif // DIALOGSTATS_H
