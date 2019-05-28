#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

#include <qmenubar.h>
#include <qapplication.h>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(this))
{

    ui->setupUi(this);

    //连接信号和槽
    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);
    QObject::connect(&serial2, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead2);
    QObject::connect(&serial3, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead3);

    this->on_SerialButton_1_clicked();
    //发送按键失能
    ui->sendButton->setEnabled(false);
    //波特率默认选择下拉第三项：9600
    ui->baudrateBox->setCurrentIndex(4);

    scene->setSceneRect(-200, -300, 400, 500);  //初始化坐标轴
    QPixmap bg(TILE_SIZE, TILE_SIZE);
    QPainter p(&bg);
    p.setBrush(QBrush(Qt::gray));
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);

    scene->addText("Hello, world!");

    ui->graphicsView->setBackgroundBrush(QBrush(bg));
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::serialPort_readyRead()
{
    if (ui->SerialButton_1->isEnabled())
    {
       return;
    }
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
    QString recv = ui->recvTextEdit->toPlainText();
    recv += QString(buffer);
    //清空以前的显示
    ui->recvTextEdit->clear();
    //重新显示
    ui->recvTextEdit->append(recv);

    //显示单次的数据
    QStringList sl =QString(buffer).split(" ");
    recv = ui->sendTextEdit->toPlainText();
    if (sl.at(0) == QString("55")&&sl.at(1) == QString("DD")){
        recv = QString(buffer);
    }
    else {
        recv += QString(buffer);
    }
    ui->sendTextEdit->clear();
    ui->sendTextEdit->append(recv);

    int x,y;
    QString string;
    scene->clear();
    data_process(recv,x,y,string);
    Point *a1 = new Point(x,y);
    scene->addItem(a1);

    QGraphicsTextItem* b1 = scene->addText(string,QFont());



}

void MainWindow::serialPort_readyRead2()
{
    if (ui->SerialButton_2->isEnabled())
    {
       return;
    }
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
    QString recv = ui->recvTextEdit->toPlainText();
    recv += QString(buffer);
    //清空以前的显示
    ui->recvTextEdit->clear();
    //重新显示
    ui->recvTextEdit->append(recv);

    //显示单次的数据
    QStringList sl =QString(buffer).split(" ");
    recv = ui->sendTextEdit->toPlainText();
    if (sl.at(0) == QString("55")&&sl.at(1) == QString("DD")){
        recv = QString(buffer);
    }
    else {
        recv += QString(buffer);
    }
    ui->sendTextEdit->clear();
    ui->sendTextEdit->append(recv);
}

void MainWindow::serialPort_readyRead3()
{
    if (ui->SerialButton_3->isEnabled())
    {
       return;
    }
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
    QString recv = ui->recvTextEdit->toPlainText();
    recv += QString(buffer);
    //清空以前的显示
    ui->recvTextEdit->clear();
    //重新显示
    ui->recvTextEdit->append(recv);

    //显示单次的数据
    QStringList sl =QString(buffer).split(" ");
    recv = ui->sendTextEdit->toPlainText();
    if (sl.at(0) == QString("55")&&sl.at(1) == QString("DD")){
        recv = QString(buffer);
    }
    else {
        recv += QString(buffer);
    }
    ui->sendTextEdit->clear();
    ui->sendTextEdit->append(recv);
}

void MainWindow::on_searchButton_clicked()
{
    ui->portNameBox->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->portNameBox->addItem(info.portName());
    }
}

void MainWindow::on_openButton_clicked()
{
    if(!ui->SerialButton_1->isEnabled()){
        if(ui->openButton->text()==QString("打开串口1"))
        {
            //设置串口名
            serial.setPortName(ui->portNameBox->currentText());
            //设置波特率
            serial.setBaudRate(ui->baudrateBox->currentText().toInt());
            //设置数据位数
            switch(ui->dataBitsBox->currentIndex())
            {
            case 8: serial.setDataBits(QSerialPort::Data8); break;
            default: break;
            }
            //设置奇偶校验
            switch(ui->ParityBox->currentIndex())
            {
            case 0: serial.setParity(QSerialPort::NoParity); break;
            default: break;
            }
            //设置停止位
            switch(ui->stopBitsBox->currentIndex())
            {
            case 1: serial.setStopBits(QSerialPort::OneStop); break;
            case 2: serial.setStopBits(QSerialPort::TwoStop); break;
            default: break;
            }
            //设置流控制
            serial.setFlowControl(QSerialPort::NoFlowControl);

            //打开串口
            if(!serial.open(QIODevice::ReadWrite))
            {
                qDebug()<<"提示,无法打开串口1！";
                return;
            }
            //下拉菜单控件失能
            this->serial_set_enable(false);
            ui->openButton->setText(QString("关闭串口1"));
            //发送按键使能

        }
        else
        {
            //关闭串口
            serial.close();
            //下拉菜单控件使能
            this->serial_set_enable(true);
            ui->openButton->setText(QString("打开串口1"));
        }
    }
    else if (!ui->SerialButton_2->isEnabled()) {
        if(ui->openButton->text()==QString("打开串口2"))
        {
            //设置串口名
            serial2.setPortName(ui->portNameBox->currentText());
            //设置波特率
            serial2.setBaudRate(ui->baudrateBox->currentText().toInt());
            //设置数据位数
            switch(ui->dataBitsBox->currentIndex())
            {
            case 8: serial2.setDataBits(QSerialPort::Data8); break;
            default: break;
            }
            //设置奇偶校验
            switch(ui->ParityBox->currentIndex())
            {
            case 0: serial2.setParity(QSerialPort::NoParity); break;
            default: break;
            }
            //设置停止位
            switch(ui->stopBitsBox->currentIndex())
            {
            case 1: serial2.setStopBits(QSerialPort::OneStop); break;
            case 2: serial2.setStopBits(QSerialPort::TwoStop); break;
            default: break;
            }
            //设置流控制
            serial2.setFlowControl(QSerialPort::NoFlowControl);

            //打开串口
            if(!serial2.open(QIODevice::ReadWrite))
            {
                qDebug()<<"提示,无法打开串口2！";
                return;
            }
            ui->openButton->setText(QString("关闭串口2"));
            //下拉菜单控件失能
            this->serial_set_enable(false);
        }
        else
        {
            //关闭串口
            serial2.close();
            ui->openButton->setText(QString("打开串口2"));
            this->serial_set_enable(true);
        }
    }
    else if (!ui->SerialButton_3->isEnabled()) {

    }

}

void MainWindow::on_sendButton_clicked()
{
    //获取界面上的数据并转换成utf8格式的字节流
    QByteArray data = ui->sendTextEdit->toPlainText().toUtf8();
    serial.write(data);
}

void MainWindow::on_clearButton_clicked()
{
    ui->recvTextEdit->clear();

}

void MainWindow::on_sqlselectButton_clicked()
{
    mysql_db.get_data();
}

void MainWindow::serial_set_enable(bool flag){
    //下拉菜单控件使能
    ui->portNameBox->setEnabled(flag);
    ui->baudrateBox->setEnabled(flag);
    ui->dataBitsBox->setEnabled(flag);
    ui->ParityBox->setEnabled(flag);
    ui->stopBitsBox->setEnabled(flag);
    //发送按键失能
    ui->sendButton->setEnabled(!flag);
}

void MainWindow::on_SerialButton_1_clicked()
{
    ui->SerialButton_1->setEnabled(false);
    ui->SerialButton_2->setEnabled(true);
    ui->SerialButton_3->setEnabled(true);
    if(serial.isOpen()){
        ui->openButton->setText(QString("关闭串口1"));
        this->serial_set_enable(false);
    }
    else {
        ui->openButton->setText(QString("打开串口1"));
        this->serial_set_enable(true);
    }
}

void MainWindow::on_SerialButton_2_clicked()
{

    this->draw_envent();
    ui->SerialButton_1->setEnabled(true);
    ui->SerialButton_2->setEnabled(false);
    ui->SerialButton_3->setEnabled(true);
    if(serial2.isOpen()){
        ui->openButton->setText(QString("关闭串口2"));
        this->serial_set_enable(false);
    }
    else {
        ui->openButton->setText(QString("打开串口2"));
        this->serial_set_enable(true);
    }
}

void MainWindow::on_SerialButton_3_clicked()
{
    ui->SerialButton_1->setEnabled(true);
    ui->SerialButton_2->setEnabled(true);
    ui->SerialButton_3->setEnabled(false);
    if(serial3.isOpen()){
        ui->openButton->setText(QString("关闭串口3"));
        this->serial_set_enable(false);
    }
    else {
        ui->openButton->setText(QString("打开串口3"));
        this->serial_set_enable(true);
    }
}

void MainWindow::draw_envent(){
    QPainter painter(ui->graphicsView);
    painter.drawLine(80, 100, 650, 500);
    painter.setPen(Qt::red);
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen(Qt::green, 5));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50, 150, 400, 200);
}
