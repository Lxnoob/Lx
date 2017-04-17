#include "checkwig.h"
#include "ui_checkwig.h"

CheckWig::CheckWig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckWig)
{
    ui->setupUi(this);
}

CheckWig::~CheckWig()
{
    delete ui;
}
