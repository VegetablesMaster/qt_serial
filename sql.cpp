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

void data_process(QString data_str){
    QString people_1 = " ";
    QString people_2 = " ";
    QString people_3 = " ";
    QStringList sl =QString(data_str).split(" ");
    int people_num = sl.at(4).toInt();
    qDebug()<<"x:"+hexToDec(sl.at(6))+'.'+hexToDec(sl.at(7))+" y:"+hexToDec(sl.at(8))+'.'+hexToDec(sl.at(9));
//    switch(people_num)
//    {
//        case 03:
//             people_3 = "x:"+sl.at(14)+'.'+sl.at(15)+" y:"+sl.at(16)+'.'+sl.at(17);
//        case 02:
//             people_2 = "x:"+sl.at(10)+'.'+sl.at(11)+" y:"+sl.at(16)+'.'+sl.at(17);
//        case 01:
//             people_1 = "x:"+sl.at(6)+'.'+sl.at(7)+" y:"+sl.at(8)+'.'+sl.at(9);
//        break;
//    }
//    qDebug()<<people_1;
//    qDebug()<<people_2;
//    qDebug()<<people_3;
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
