#include "display.h"
#include <QApplication>
#include "item.h"

int main(int argc, char *argv[])
{
    populateItems();
    QApplication a(argc, argv);
    Display w;

    w.show();

    return a.exec();
}
