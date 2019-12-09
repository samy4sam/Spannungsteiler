#include "SpannungsteilerWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpannungsteilerWidget w;
    w.show();
    return a.exec();
}
