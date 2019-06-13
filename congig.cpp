#include "congig.h"
#include "ui_congig.h"

Congig::Congig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Congig)
{
    ui->setupUi(this);
}

Congig::~Congig()
{
    delete ui;
}
