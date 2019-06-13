#ifndef SQL_H
#define SQL_H
#include "constants.h"

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

int generateorder_Online_mater(QString radar_addr, QString& order);
int generateorder_Read_mater(QString radar_addr, QString& order);

int resolveorder_Online_radar(QString data_str, QJsonObject& json);
int resolveorder_Read_radar(QString data_str,  QJsonObject& json);

#endif // SQL_H
