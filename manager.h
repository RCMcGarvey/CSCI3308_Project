#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include "player.h"
#include "room.h"
#include "database.h"
#include <string>
#include <QTextEdit>
#include <stdlib.h>
#include <enemy.h>
#include <vector>
#include <QCryptographicHash>


class Manager
{

public:
    Manager( );
    ~Manager();

    //void userInput(QString input);
    void setPlayerClass(int role);
    QString move(int input);
    QString startNarrative();
    void setUser(QString user);
    void setPass(QString pass);
    void setPlayerName(QString name);
    //void loadGame();
    //void saveGame();

    void drop(int input);
    bool pickup(int input);
    QString interact(int input);
    QString inspect(int input);
    void swap(int input, int input2);
    QString use(int slot);
    QString lookAround();

    int getPlayerHealth();
    int enemyHealth();
    QString combatEvent(QString);

    QString getItem(int index, int from);
    int howManyItems();

    void loadGame();
    void saveGame();
    bool signIn();
    void startGame();
    void addChar();
    void createUser();


    bool gameOver;
    int role;

    //Anton's Functions
    Item** getRoomItems(){return map.getRoomItems();}

private:
    database db;
    QString playername;
    QString username;
    QString password;
    QString toOutput;
    Player theHero;
    room map;


};

#endif // MANAGER_H
