#include "login.h"
#include "parking.h"
#include "carport.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Widget w;
    Parking w;
//    carport w;
    w.show();

    return a.exec();
}
