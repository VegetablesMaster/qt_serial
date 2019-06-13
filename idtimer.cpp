#include "idtimer.h"
#include "ui_idtimer.h"

IdTimer::IdTimer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdTimer)
{
    ui->setupUi(this);
    QIntValidator *validator = new QIntValidator(0, 10000, this);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_6->setValidator(validator);
    ui->lineEdit_8->setValidator(validator);
    ui->lineEdit_10->setValidator(validator);
    ui->lineEdit_12->setValidator(validator);
    validator = new QIntValidator(2, 99, this);
    ui->lineEdit_1->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_7->setValidator(validator);
    ui->lineEdit_9->setValidator(validator);
    ui->lineEdit_11->setValidator(validator);
}

IdTimer::~IdTimer()
{
    delete ui;
}

void IdTimer::on_pushButton_clicked()
{
    config_json["No1_ID"]=ui->lineEdit_1->text();
    config_json["No1_Timer"]=ui->lineEdit_2->text().toInt();
    config_json["No1_enable"]=ui->checkBox_1->isChecked();
    config_json["No2_ID"]=ui->lineEdit_3->text();
    config_json["No2_Timer"]=ui->lineEdit_4->text().toInt();
    config_json["No2_enable"]=ui->checkBox_2->isChecked();
    config_json["No3_ID"]=ui->lineEdit_5->text();
    config_json["No3_Timer"]=ui->lineEdit_6->text().toInt();
    config_json["No3_enable"]=ui->checkBox_3->isChecked();
    config_json["No4_ID"]=ui->lineEdit_7->text();
    config_json["No4_Timer"]=ui->lineEdit_8->text().toInt();
    config_json["No4_enable"]=ui->checkBox_4->isChecked();
    config_json["No5_ID"]=ui->lineEdit_9->text();
    config_json["No5_Timer"]=ui->lineEdit_10->text().toInt();
    config_json["No5_enable"]=ui->checkBox_5->isChecked();
    config_json["No6_ID"]=ui->lineEdit_11->text();
    config_json["No6_Timer"]=ui->lineEdit_12->text().toInt();
    config_json["No6_enable"]=ui->checkBox_6->isChecked();
    emit send_location_data(config_json);
}


void IdTimer::set_location_data(QJsonObject json)
{
    config_json = json;
    ui->lineEdit_1->setText(config_json["No1_ID"].toString());
    ui->lineEdit_2->setText(config_json["No1_Timer"].toString());
    ui->lineEdit_3->setText(config_json["No2_ID"].toString());
    ui->lineEdit_4->setText(config_json["No2_Timer"].toString());
    ui->lineEdit_5->setText(config_json["No3_ID"].toString());
    ui->lineEdit_6->setText(config_json["No3_Timer"].toString());
    ui->lineEdit_7->setText(config_json["No4_ID"].toString());
    ui->lineEdit_8->setText(config_json["No4_Timer"].toString());
    ui->lineEdit_9->setText(config_json["No5_ID"].toString());
    ui->lineEdit_10->setText(config_json["No5_Timer"].toString());
    ui->lineEdit_11->setText(config_json["No6_ID"].toString());
    ui->lineEdit_12->setText(config_json["No6_Timer"].toString());

    ui->checkBox_1->setChecked(config_json["No1_enable"].toBool());
    ui->checkBox_2->setChecked(config_json["No2_enable"].toBool());
    ui->checkBox_3->setChecked(config_json["No3_enable"].toBool());
    ui->checkBox_4->setChecked(config_json["No4_enable"].toBool());
    ui->checkBox_5->setChecked(config_json["No5_enable"].toBool());
    ui->checkBox_6->setChecked(config_json["No6_enable"].toBool());
}
