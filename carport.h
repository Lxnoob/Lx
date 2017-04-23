#ifndef CARPORT_H
#define CARPORT_H
#include <QWidget>
#include <QPushButton>

namespace Ui {
class carport;
}

class carport : public QWidget
{
    Q_OBJECT

public:
    explicit carport(QWidget *parent = 0);
    ~carport();
    QPushButton *PushBtnParking;

    //每个车位的车位号
    int carPortId_carPort;
    int setWidget(QString carPortId,QString cardId,QString carPortStatus);//设置一个界面
signals:
    void showPageEnter(int &carportNum);//发送停车信号，用于显示停车界面
private slots:
    void on_pushButtonStatus_clicked();

private:
    Ui::carport *ui;
};

#endif // CARPORT_H
