#ifndef IDTIMER_H
#define IDTIMER_H

#include "constants.h"

namespace Ui {
class IdTimer;
}

class IdTimer : public QDialog
{
    Q_OBJECT

public:
    explicit IdTimer(QWidget *parent = nullptr);
    ~IdTimer();

signals:
    void send_location_data(QJsonObject json);

public slots:
    void set_location_data(QJsonObject json);

private slots:
    void on_pushButton_clicked();

private:
    Ui::IdTimer *ui;
    QJsonObject config_json;
};

#endif // IDTIMER_H
