#include <QtWidgets/QApplication>
#include "Heterogeneous.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CHeterogeneous w;
    w.show();
    return a.exec();
}
