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
    //int comp = (rand() % 100) + 1;
    int enemyAttack = -map.getEnemy()->attack();
    int playerAttack = -theHero.attack();
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
        theHero.adjustHealth(enemyAttack + theHero.getDefense());
        if(theHero.getHealth() == 0)
        {
            toOutput = "<p style='color:darkred'><center><big>You're innards become outards!</big></center></p>";
        }
    }
    else
    {
        toOutput = "Theres nothing here to fight";
    }

}

QString Manager::getItem(int index, int from)
{
    Item** roomItems = map.getRoomItems();
    QString ret;
    if(from == 1)
    {
//        return map.getRoomItems(index)->name;
        if(roomItems[index] == nullptr){
            ret+="Nothing there";
            return ret;
        }
        else return roomItems[index]->name;
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

