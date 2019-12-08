#include "iamgewidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IamgeWidget w;
    w.show();

    return a.exec();
}
