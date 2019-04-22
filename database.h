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
    ~database();
    //Do a check to see if the user already exists when these are called
    void addUser(QString username, QString usr_password);
    void addChar(QString char_name, QString stats, QString inventory, QString level, QString user);
    void addLevel();
    void addItem();
    void addInventory();
    //look for the save file under the name then overwrite it with the new string
    //the methods above can probably be merged into this
    void saveGame(QString char_name,QString savefile);
    //Should return the save string for the character
    QString loadGame(QString char_name);

private:
    QSqlDatabase db;
};

#endif // DATABASE_H

