#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QJsonObject>
#include <QPainter>
#include <QPainterPath>
#include <QPointF>
#include <QDialog>
#include <QIntValidator>
#include <QTimer>


const int TILE_SIZE = 50;

//毫米波雷达通信协议指令
QString const Instruct_MasterPc_Addr = "01 ";
QString const Instruct_Frame_Start = "81 ";
QString const Instruct_Frame_End = "77";

QString const Instruct_Online_Mater = "D5 ";
QString const Instruct_Online_Rador = "E5 ";
QString const Instruct_Get_Data_Mater = "D1 ";
QString const Instruct_Get_Data_Rador = "E1 ";

enum GameObjectsData {
    GD_Type
};

enum GameObjectTypes {
    GO_Food,
    GO_Wall
};

#endif // CONSTANTS_H
