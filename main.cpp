#include "display.h"
#include <QApplication>
#include "database.h"

int main(int argc, char *argv[])
{
    database db;
    db.addUser("aryan", "pass");
//    QApplication a(argc, argv);
//    Display w;
//    w.show();

//    return a.exec();
    return 0;
}
