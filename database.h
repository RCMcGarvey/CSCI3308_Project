#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>


using namespace std;


class database
{
public:
    database();
    ~database();
    //Do a check to see if the user already exists when these are called
    int addUser(QString username, QString usr_password);
    int addChar(QString char_name, QString user);
    bool signIn(QString username, QString usr_password);
    //look for the save file under the name then overwrite it with the new string
    //the methods above can probably be merged into this
    void saveGame(QString char_name, QString game_data);
    //Should return the save string for the character
    QString loadGame(QString char_name);

private:
    QSqlDatabase db;
    int getUid(QString username);
    int getCharId(QString char_name);
};

#endif // DATABASE_H

