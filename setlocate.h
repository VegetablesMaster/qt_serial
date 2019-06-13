#ifndef SETLOCATE_H
#define SETLOCATE_H


#include "constants.h"

namespace Ui {
class SetLocate;
}

class SetLocate : public QDialog
{
    Q_OBJECT

signals:
    void send_location_data(QJsonObject json);

public slots:
    void set_location_data(QJsonObject json);

public:
    explicit SetLocate(QWidget *parent = nullptr);
    ~SetLocate();

private slots:
    void on_setButton_clicked();

private:
    Ui::SetLocate *ui;
    QJsonObject config_json;
};

#endif // SETLOCATE_H
