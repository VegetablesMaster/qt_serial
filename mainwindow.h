#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPainter>
#include <QGraphicsView>

#include "constants.h"
#include "sql.h"
#include "painter.h"

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
    void serialPort_readyRead();
    void serialPort_readyRead2();
    void serialPort_readyRead3();

    void on_searchButton_clicked();

    void on_openButton_clicked();

    void on_sendButton_clicked();

    void on_clearButton_clicked();

    void on_sqlselectButton_clicked();

    void on_SerialButton_1_clicked();

    void on_SerialButton_2_clicked();

    void on_SerialButton_3_clicked();

    void serial_set_enable(bool flag);

    void draw_envent();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QSerialPort serial;
    QSerialPort serial2;
    QSerialPort serial3;
    Mysql mysql_db;
};

#endif // MAINWINDOW_H
