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
    qDebug()<<"x:"+hexToDec(sl.at(6))+'.'+hexToDec(sl.at(7))+" y:"+hexToDec(sl.at(8))+'.'+hexToDec(sl.at(9));
    point_x = hexToDec(sl.at(6)).toInt();
    point_y = hexToDec(sl.at(8)).toInt();
};

void data_process(QString data_str,int& point_x, int& point_y, QString& string){
    QStringList sl =QString(data_str).split(" ");
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

int generateorder_Online_mater(QString radar_addr, QString& order){
    order = Instruct_Frame_Start + Instruct_MasterPc_Addr;
    order = order + radar_addr + Instruct_Online_Mater;
    QString Frame_Lengh = "07 ";
    QString CRC = "00 ";
    order = order + Frame_Lengh + CRC + Instruct_Frame_End;
    return 0;
};

int generateorder_Read_mater(QString radar_addr, QString& order){
    order = Instruct_Frame_Start + Instruct_MasterPc_Addr;
    order = order + radar_addr + Instruct_Get_Data_Mater;
    QString Frame_Lengh = "07 ";
    QString CRC = "00 ";
    order = order + Frame_Lengh + CRC + Instruct_Frame_End;
    return 0;
};

int resolveorder_Online_radar(QString data_str, QJsonObject& json){
    QStringList sl =QString(data_str).split(" ");
    json.insert("radar_addr", sl.at(3));
    return 0;
};

int resolveorder_Read_radar(QString data_str,  QJsonObject& json){
    QStringList sl =QString(data_str).split(" ");
    json.insert("radar_addr", sl.at(3));
    //解析人数
    int frame_length = hexToDec(sl.at(4)).toInt();
    int data_length = frame_length - 7;
    if(data_length%4 == 0){
        // 接收到的数据有错误
        return 1;
    }
    int people_count = data_length/4;
    json.insert("people_count", people_count);
    //解析人的位置
    for(int i=0;i<people_count;i++)
    {
        int j = 6+i*4;
        float x=(hexToDec(sl.at(j))+'.'+hexToDec(sl.at(j+1))).toFloat();
        float y=(hexToDec(sl.at(j+2))+'.'+hexToDec(sl.at(j+3))).toFloat();
        float location[2] = {x,y};
        QString people_id = "people_no";
    }
    return 0;
};
