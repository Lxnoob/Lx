#include "login.h"
#include "ui_login.h"
#include "parking.h"

#include <QSqlQuery> //数据库查询
#include <QSqlError>
#include <QDebug>    //用于输出调试语句
#include <QMessageBox> //消息框
#include <QHostAddress>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->stackedWidget->setWindowTitle("用户登录");
    ui->stackedWidget->setCurrentIndex(0);

    //设置隐藏字符
    ui->lineEdit_Pwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_Pwd->setEchoMode(QLineEdit::Password);
    ui->lineEdit_PwdSure_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_Check_2->setEchoMode(QLineEdit::Password);
    parking = Parking::TheInstance();

    /* 服务器部分 */
    socket = new QTcpSocket(this);
    //捕获 网络连接成功信号
    connect(socket,SIGNAL(connected()),
            this,SLOT(connectToHostSuccess()));


    //初始化数据库
    IdSqlInit();
}

Widget::~Widget()
{
    delete ui;
    delete socket;
}
//初始化数据库
int Widget::IdSqlInit()
{
    //添加数据库驱动
    QSqlDatabase IdSql = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名称
    IdSql.setDatabaseName("UserInfo.db");
    if(IdSql.open())
    {
        qDebug()<<"Open Idsql Success!\n";
    }else
    {
        qDebug()<<"Open Idsql Fail!\n";
        return -1;
    }

    QSqlQuery *query = new QSqlQuery;

    query->exec("CREATE TABLE userinfo( \
                name varchar(20) primary key,\
                pwd varchar(20) not null,\
                card_ID int unique);");
    query->exec("INSERT INTO userinfo "
                "values('liu','123',123);");
    return 0;
}

//连接服务器
void Widget::display()
{
   //连接到服务器
   socket->connectToHost(QHostAddress("127.0.0.1"),8080);
}
void Widget::connectToHostSuccess()
{
    QHostAddress host = socket->peerAddress();//返回连接成功的主机地址
    qDebug()<<(QString("localPort: %4,host: %1,name: %2,port: %3 connect success!")
                        .arg(host.toString())
                        .arg(socket->peerName())
                        .arg(socket->peerPort())
                        .arg(socket->localPort()))<<endl;

    parking->show();
    return;
}

/* 读取服务器信息，协议部分 */
void Widget::ReadMsg()
{
//    qDebug() << "读取客户端的信息...";
//    QByteArray msg = socket->readAll();
//    qDebug() << msg;
//    /* 开始协议部分 */  /* 此处由具体而定 */
//    if(msg.startsWith("#Error")){
//        /* 出错 */
//        QMessageBox::information(NULL,"提示","出现错误!!!");
//        return;
//    }else if(msg.startsWith("#Login")){
//        /* 成功登录的指令 */
//        Widget *w = new Widget(this);
//        w->show();
//        this->hide();
//    }

}

void Widget::on_pushButton_Login_clicked()
{
    QString Id = ui->lineEdit_Id->text();
    QString Pwd = ui->lineEdit_Pwd->text();

    QString Id_true = "admin";
    QString Pwd_true = "1";
    if(Id == Id_true)
    {
        if(Pwd == Pwd_true)
        {
            this->display();//连接服务器

        }else
        {
            QMessageBox::warning(this,"警告","密码错误，请重新输入密码！",
                                     QMessageBox::Yes);
            //ui->lineEdit_Id->clear();
            ui->lineEdit_Pwd->clear();
        }
    }else
    {
        QMessageBox::warning(this,"警告","账号错误，请重新输入账号！",
                                 QMessageBox::Yes);
        ui->lineEdit_Id->clear();
        ui->lineEdit_Pwd->clear();
    }




}

void Widget::on_pushButton_Regist_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    return;
}

void Widget::on_pushButton_Back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    return;
}

void Widget::on_pushButton_Regist_2_clicked()
{
//    IdSqlInit();
    QString Id = ui->lineEdit_Id_2->text();
    QString Pwd = ui->lineEdit_Pwd_2->text();
    QString PwdSure = ui->lineEdit_PwdSure_2->text();
    QString Check = ui->lineEdit_Check_2->text();

    //注册成功
    QSqlQuery query;
    QString cmd;
    query.exec("select * from userinfo");

    while(query.next())
    {
        if(query.value(0) == Id  ||
                   Pwd != PwdSure ||
                   Check != "admin")
        {
            QMessageBox::information(this,tr("通知信息"),QString("注册失败"),
                                     QMessageBox::Yes);
            return;
        }
    }
    qDebug()<<Id<<endl;
    qDebug()<<Pwd<<endl;
    cmd = tr("INSERT INTO userinfo values('%1','%2')").arg(Id).arg(Pwd);
    bool success = query.exec(cmd);
    if(!success)
      {
          QSqlError lastError = query.lastError();
          qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
          return;
      }
    ui->lineEdit_Id_2->clear();
    ui->lineEdit_Pwd_2->clear();
    ui->lineEdit_PwdSure_2->clear();
    ui->lineEdit_Check_2->clear();
    QMessageBox::information(this,tr("通知信息"),QString("注册成功"),
                             QMessageBox::Yes);
    ui->stackedWidget->setCurrentIndex(0);
    return;
    //注册失败

}
/*代码备份*/
/* QSqlQuery query;
    //遍历用户信息表
   bool sucess = query.exec("select * from userinfo");
    if(sucess)
    {
        qDebug()<<"开始检索userinfo"<<endl;
    }
    while(query.next())
    {
        //数据库中第一项内容  第二项内容
        if(query.value(0) == Id)
        {
            if(query.value(1) == Pwd)
            {
               this->hide();
                //隐藏登录界面进入用户操作界面
                Parking *parking = new Parking;
                parking->show();
                ui->lineEdit_Id->clear();
                ui->lineEdit_Pwd->clear();
                return;
            }else
            {
                QMessageBox::warning(this,tr("登录失败"),QString("密码错误"),
                                         QMessageBox::Yes);
                return;
            }
        }
    }
    //登录失败
    QMessageBox::warning(this,tr("登录失败"),QString("用户不存在"),
                             QMessageBox::Yes);
    ui->lineEdit_Id->clear();
    ui->lineEdit_Pwd->clear();
*/

