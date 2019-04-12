#include "Manager.h"
#include <iostream>

//Ryan

Manager::Manager()
{
    toOutput = map.theBeginning();
    srand(8191);
}

Manager::~Manager()
{

}

void Manager::userInput(int input, string action)
{
    if(action == "move")
    {
        toOutput = map.nextRoom(input);
    }
}

void Manager::userInput(QString input)
{

}

void Manager::userInput(int input, int input2)
{
    Item holder;

}

int Manager::getPlayerHealth()
{
    return theHero.getHealth();
}

QString Manager::getNarrative()
{
    return toOutput;
}

void Manager::combatEvent()
{
    int comp = (rand() % 100) + 1;
    int enemyAttack = map.getEnemy()->attack();
    int playerAttack = theHero.attack();
    if(map.hasEnemy() == true)
    {
        map.getEnemy()->adjustHealth(playerAttack);
        if(map.getEnemy()->getAlive() == false)
        {
            int msg = rand() % 3;
            switch(msg)
            {
            case 0:
            {
                toOutput = "You have defeated the beast.";
                break;
            }
            case 1:
            {
                toOutput = "The creature is slain by your hand.";
                break;
            }
            case 2:
            {
                toOutput = "The monster flees never to be seen again.";
                break;
            }
            }
        }

    }
    else
    {

    }

}

QString Manager::getItem(int index, int from)
{
    if(from == 1)
    {
        return map.getRoomItems(index)->name;
    }
    else if(from == 2)
    {
        return theHero.getInventory(index)->name;
    }
}

int Manager::howManyItems()
{
    return map.howManyItems;
}

