#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSqlDatabase>
#include <QtNetwork>
#include <QTcpSocket>

class Parking;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    //初始化数据库
    int IdSqlInit();

    void display();
    void ReadMsg();
public slots:
    //连接服务器成功
    void connectToHostSuccess();
private slots:
    //用户登录
    void on_pushButton_Login_clicked();

    //跳转到注册用户界面
    void on_pushButton_Regist_clicked();

    //返回登录界面
    void on_pushButton_Back_2_clicked();

    //注册用户
    void on_pushButton_Regist_2_clicked();


private:
    Ui::Widget *ui;
    Parking *parking = NULL;
    QSqlDatabase IdSql;
    QTcpSocket *socket = NULL;
};


#endif // LOGIN_H
