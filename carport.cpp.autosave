#include "carport.h"
#include "ui_carport.h"
#include "parking.h"
#include <QDebug>

carport::carport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::carport)
{
    ui->setupUi(this);
//    Parking *main = Parking::TheInstance();
    PushBtnParking = new QPushButton();
    PushBtnParking = ui->pushButtonStatus;

//    connect(ui->pushButtonStatus,SIGNAL(clicked()),this
}

carport::~carport()
{
    delete ui;
}

//将数据库内容显示
int carport::setWidget(QString carPortId, QString cardId, QString carPortStatus)
{
    ui->labelCarPortId->setText(carPortId);
    ui->labelCardId->setText(cardId);
    QVariant tempValue = carPortStatus;
    bool tempFinished = tempValue.toBool();
    ui->pushButtonStatus->setEnabled(tempFinished);

    return 0;
}

//停车按钮
void carport::on_pushButtonStatus_clicked()
{
    carPortId_carPort = ui->labelCarPortId->text().toInt();
    //显示停车界面
    qDebug()<<"jinru"<<endl;

    emit showPageEnter(carPortId_carPort);

//  int cardId = ui->labelCardId->text();
    //将按钮状态转化为string类型
//  QString carPortStatus = QString::number(ui->pushButtonStatus->isEnabled());
}
