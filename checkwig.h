#ifndef CHECKWIG_H
#define CHECKWIG_H

#include <QWidget>

namespace Ui {
class CheckWig;
}

class CheckWig : public QWidget
{
    Q_OBJECT

public:
    explicit CheckWig(QWidget *parent = 0);
    ~CheckWig();

private:
    Ui::CheckWig *ui;
};

#endif // CHECKWIG_H
