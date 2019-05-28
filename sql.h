#ifndef SQL_H
#define SQL_H
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>

class Mysql{
public:  
    QSqlDatabase db;
    Mysql(void);
    void get_data(void);
};

void data_process(QString data_str,int& point_x, int& point_y);
void data_process(QString data_str,int& point_x, int& point_y, QString& string);

int hex2(unsigned char ch);
QString hexToDec(QString strHex);

#endif // SQL_H
