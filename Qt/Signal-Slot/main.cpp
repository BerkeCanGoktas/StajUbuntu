#include <QCoreApplication>
#include <QObject>
#include "counter.h"
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Counter x, y;
    QObject::connect(&x, &Counter::valueChanged, &y, &Counter::setValue);
    x.setValue(12);     // a.value() == 12, b.value() == 12
    qDebug() << x.value() << "    " << y.value();
    y.setValue(48);     // a.value() == 12, b.value() == 48
    qDebug() << x.value() << "    " << y.value();
    return a.exec();
}
