#include "setlocate.h"
#include "ui_setlocate.h"

SetLocate::SetLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetLocate)
{
    ui->setupUi(this);
    QIntValidator *validator = new QIntValidator(-500, 500, this);
    ui->lineEdit_1->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);
    ui->lineEdit_4->setValidator(validator);
    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_6->setValidator(validator);
    ui->lineEdit_7->setValidator(validator);
    ui->lineEdit_8->setValidator(validator);
    ui->lineEdit_9->setValidator(validator);
    ui->lineEdit_10->setValidator(validator);
    ui->lineEdit_11->setValidator(validator);
    ui->lineEdit_12->setValidator(validator);
}

SetLocate::~SetLocate()
{
    delete ui;
}

void SetLocate::on_setButton_clicked()
{
    config_json["No1_X"]=ui->lineEdit_1->text().toInt();
    config_json["No1_Y"]=ui->lineEdit_2->text().toInt();
    config_json["No2_X"]=ui->lineEdit_3->text().toInt();
    config_json["No2_Y"]=ui->lineEdit_4->text().toInt();
    config_json["No3_X"]=ui->lineEdit_5->text().toInt();
    config_json["No3_Y"]=ui->lineEdit_6->text().toInt();
    config_json["No4_X"]=ui->lineEdit_7->text().toInt();
    config_json["No4_Y"]=ui->lineEdit_8->text().toInt();
    config_json["No5_X"]=ui->lineEdit_9->text().toInt();
    config_json["No5_Y"]=ui->lineEdit_10->text().toInt();
    config_json["No6_X"]=ui->lineEdit_11->text().toInt();
    config_json["No6_Y"]=ui->lineEdit_12->text().toInt();
    emit send_location_data(config_json);
}


void SetLocate::set_location_data(QJsonObject json)
{
    config_json = json;
    ui->lineEdit_1->setText(config_json["No1_X"].toString());
    ui->lineEdit_2->setText(config_json["No1_Y"].toString());
    ui->lineEdit_3->setText(config_json["No2_X"].toString());
    ui->lineEdit_4->setText(config_json["No2_Y"].toString());
    ui->lineEdit_5->setText(config_json["No3_X"].toString());
    ui->lineEdit_6->setText(config_json["No3_Y"].toString());
    ui->lineEdit_7->setText(config_json["No4_X"].toString());
    ui->lineEdit_8->setText(config_json["No4_Y"].toString());
    ui->lineEdit_9->setText(config_json["No5_X"].toString());
    ui->lineEdit_10->setText(config_json["No5_Y"].toString());
    ui->lineEdit_11->setText(config_json["No6_X"].toString());
    ui->lineEdit_12->setText(config_json["No6_Y"].toString());
}
