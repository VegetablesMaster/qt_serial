#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<iostream>
#include<algorithm>
#include<vector>

#include "constants.h"
#include "sql.h"
#include "painter.h"
#include "setlocate.h"
#include "idtimer.h"

class QGraphicsScene;
class QGraphicsView;

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    //串口回调函数
    void serialPort_readyRead();
    void serialPort_readyRead2();
    void serialPort_readyRead3();
    void process_serial_data(QByteArray buffer);

    //时钟回调     TODO::其实我应该写一个类来封装radar，可惜当我想起来时已经太晚了，如果再版的话。
    void timer1_ready();
//    void timer2_ready();
//    void timer3_ready();
//    void timer4_ready();
//    void timer5_ready();
//    void timer6_ready();

    //串口操作
    void on_searchButton_clicked();
    void on_openButton_clicked();
    void on_sendButton_clicked();
    void send_data(QString data);
    void on_clearButton_clicked();

    //数据库
    void on_sqlselectButton_clicked();

    //切换串口
    void on_SerialButton_1_clicked();
    void on_SerialButton_2_clicked();
    void on_SerialButton_3_clicked();
    void serial_set_enable(bool flag);

    //图像绘制
    void draw_envent();

    // 导航栏相关
    void on_actionNo_1_triggered();

    //子窗口相关
    void set_config(QJsonObject json);
    void on_action_Id_Timer_triggered();

signals:
    void read_config(QJsonObject json);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    SetLocate *setlocate;
    IdTimer *idtimer;
    QSerialPort serial;
    QSerialPort serial2;
    QSerialPort serial3;
    Mysql mysql_db;

    //请求雷达的时间间隔
    QTimer *timerNo1;
    QTimer *timerNo2;
    QTimer *timerNo3;
    QTimer *timerNo4;
    QTimer *timerNo5;
    QTimer *timerNo6;
    std::vector<QTimer*> timerlist = {timerNo1, timerNo2, timerNo3, timerNo4, timerNo5, timerNo6};

    //雷达config_json的key值
    std::vector<QString> json_X_list      = {"No1_X","No2_X","No3_X","No4_X","No5_X","No6_X"};
    std::vector<QString> json_Y_list      = {"No1_Y","No2_Y","No3_Y","No4_Y","No5_Y","No6_Y"};
    std::vector<QString> json_ID_list     = {"No1_ID","No2_ID","No3_ID", "No4_ID","No5_ID","No6_ID"};
    std::vector<QString> json_Timer_list  = {"No1_Timer","No2_Timer","No3_Timer","No4_Timer",
                                             "No5_Timer","No6_Timer"};
    std::vector<QString> json_enable_list = {"No1_enable","No2_enable","No3_enable","No4_enable",
                                             "No5_enable","No6_enable"};
    //雷达坐标相关的参数
    QJsonObject config_json{
        {"No1_X",0},
        {"No1_Y",0},
        {"No1_ID",0},
        {"No1_Timer",0},
        {"No1_enable",false},
        {"No2_X",0},
        {"No2_Y",0},
        {"No2_ID",0},
        {"No2_Timer",0},
        {"No2_enable",false},
        {"No3_X",0},
        {"No3_Y",0},
        {"No3_ID",0},
        {"No3_Timer",0},
        {"No3_enable",false},
        {"No4_X",0},
        {"No4_Y",0},
        {"No4_ID",0},
        {"No4_Timer",0},
        {"No4_enable",false},
        {"No5_X",0},
        {"No5_Y",0},
        {"No5_ID",0},
        {"No5_Timer",0},
        {"No5_enable",false},
        {"No6_X",0},
        {"No6_Y",0},
        {"No6_ID",0},
        {"No6_Timer",0},
        {"No6_enable",false},
    };
};

#endif // MAINWINDOW_H
