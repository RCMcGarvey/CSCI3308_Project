#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include "player.h"
#include "room.h"
#include <string>
#include <QTextEdit>

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

    Item** getRoomItems(){return prison.getRoomItems();}

private:
    void combatEvent();
    QString toOutput;


    Player theHero;
    room prison;

};

#endif // MANAGER_H
