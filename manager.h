#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include "player.h"
#include "room.h"
#include <string>
#include <QTextEdit>
#include <stdlib.h>
#include <enemy.h>


class Manager
{

public:
    Manager( );
    ~Manager();

    //void userInput(QString input);
    void userInput(int input, string action);
    void userInput(QString input);
    void userInput(int input, int input2);
    int getPlayerHealth();
    QString getNarrative();
    void combatEvent();
    QString getItem(int index, int from);
    int howManyItems();

private:
    QString toOutput;

    //QThread god;

    Player theHero;
    room map;


};

#endif // MANAGER_H
