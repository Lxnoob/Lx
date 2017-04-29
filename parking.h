#ifndef PARKING_H
#define PARKING_H

#include <QMainWindow>
#include <QSqlDatabase>//数据库
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QTcpSocket>
class carport;

namespace Ui {
class Parking;
}

class Parking : public QMainWindow
{
    Q_OBJECT

public:
    explicit Parking(QWidget *parent = 0);
    ~Parking();
    //返回停车界面指针
    static Parking* TheInstance();//获取主界面指针

    QLabel *statusTime = NULL;

    QStackedWidget *ParkWidget = NULL;
    /********************************************/
    //              框架
    void PersonInfo();		//个人信息  ——》登陆成功后进入，显示个人信息
    void Part();			//停车场车位
    void Money();			//计费显示
    void Error();			//出现异常
    /*********************************************/

    //初始化 停车场数据库
    int initCarPortSql();
    void setInit();//刷新界面显示

    int setOne();   //一区
    int setTwo();   //二区
    int setThree(); //三区
    int setFour();  //四区
    void carportParking(int &carportNum);//响应车位界面停车

signals:
public slots:
    void updataTime();

private slots:

    void on_actionExit_triggered();

    void on_actionEnter_triggered();

    void on_actionOut_triggered();

    void on_actionSysInfo_triggered();

    void on_pushButtonCheck_clicked();

    void on_pushButtonEnter_clicked();

    void on_pushButtonOut_clicked();

    void on_pushButtonSysInfo_clicked();

    void on_pushButtonSure_clicked();

    void on_pushButton_2_clicked();

    void outCarPort();//出库

    void on_action_triggered();

private:
    double mon;			//余额
    int n;				//车位标号
    int Cflag;			//车位状态标记
    double time;		//停车时间
    int Eflag;			//出现异常标记

private:
    Ui::Parking *ui;
    QTimer *timer;
    QSqlDatabase carPortDb;//停车位信息数据库
    QTcpSocket *tcpSocket;

    carport *car = NULL;

    QVBoxLayout *vBoxOne;
    QVBoxLayout *vBoxTwo;
    QVBoxLayout *vBoxThree;
    QVBoxLayout *vBoxFour;

    QVector<carport *> vecOne;
    QVector<carport *> vecTwo;
    QVector<carport *> vecThree;
    QVector<carport *> vecFour;
};

#endif // PARKING_H
