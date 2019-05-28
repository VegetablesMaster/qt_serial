#include "sql.h"

Mysql::Mysql(void){
    db=QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    db.setPort(3306);                 //连接数据库端口号，与设置一致
    db.setDatabaseName("serial_qt");      //连接数据库名，与设置一致
    db.setUserName("root");          //数据库用户名，与设置一致
    db.setPassword("mysql");    //数据库密码，与设置一致
    db.open();
    if(!db.open())
    {
        qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
    }
    else
    {
         qDebug()<<"连接成功"<<"connect to mysql OK";
    }
    return ;
};

void Mysql::get_data(void){
    QSqlQuery query(db);
    query.exec("select * from student");
    while(query.next()){
        qDebug()<<query.value(0).toString();
    }
};

void data_process(QString data_str,int& point_x, int& point_y){
    QString people_1 = " ";
    QString people_2 = " ";
    QString people_3 = " ";
    QStringList sl =QString(data_str).split(" ");
    int people_num = sl.at(4).toInt();
    qDebug()<<"x:"+hexToDec(sl.at(6))+'.'+hexToDec(sl.at(7))+" y:"+hexToDec(sl.at(8))+'.'+hexToDec(sl.at(9));
    point_x = hexToDec(sl.at(6)).toInt();
    point_y = hexToDec(sl.at(8)).toInt();
};

void data_process(QString data_str,int& point_x, int& point_y, QString& string){

    QStringList sl =QString(data_str).split(" ");
    int people_num = sl.at(4).toInt();
    QString temp = "people num: " + people_num;
    string = "x:"+hexToDec(sl.at(6))+'.'+hexToDec(sl.at(7))+" y:"+hexToDec(sl.at(8))+'.'+hexToDec(sl.at(9));
    qDebug()<<string;
    point_x = hexToDec(sl.at(6)).toInt();
    point_y = hexToDec(sl.at(8)).toInt();
};

int hex2(unsigned char ch){          //十六进制转换工具
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    return 0;
};

QString hexToDec(QString strHex){  //十六进制转十进制
    int i;
    int v = 0;
    for(i=0;i<strHex.length();i++)
    {
        v*=16;
        v+=hex2(strHex[i].toLatin1());
    }
    return QString::number(v);
};
