#include "display.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Display w;

    w.show();

    return a.exec();
}
