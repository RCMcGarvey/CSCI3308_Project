#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>


using namespace std;


class database
{
public:
    database();
    void addUser(QString username, QString usr_password);
    void addChar(QString char_name, QString stats, QString inventory, QString level, QString user);
    void addLevel();
    void addItem();
    void addInventory();
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
