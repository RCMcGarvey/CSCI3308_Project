#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include "player.h"
#include "room.h"
#include <string>
#include <QTextEdit>
#include <stdlib.h>
#include <enemy.h>
#include <vector>


class Manager
{

public:
    Manager( );
    ~Manager();

    //void userInput(QString input);
    void setPlayerClass(int role);
    QString move(int input);
    bool pickup(int input);
    void drop(int input);
    QString interact(int input);
    QString inspect(int input);
    void swap(int input, int input2);
    int getPlayerHealth();
    QString startNarrative();
    QString combatEvent(QString);
    QString getItem(int index, int from);
    int howManyItems();
    int enemyHealth();


    bool gameOver;

    //Anton's Functions
    Item** getRoomItems(){return map.getRoomItems();}

private:
    QString toOutput;
    Player theHero;
    room map;


};

#endif // MANAGER_H
