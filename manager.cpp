#include "Manager.h"
#include <iostream>

#include <QDebug>

//Ryan

Manager::Manager()
{
    toOutput = map.theBeginning();
    srand(8191);
    theHero = Player(Bard);
}

Manager::~Manager()
{

}

QString Manager::move(int input)
{
    return map.nextRoom(input);
}

QString Manager::inspect(int input)
{
    if(theHero.getInventory()[input] != nullptr)
    {
        return theHero.getInventory()[input]->display_message();
    }
    else
    {
        return "You have no item in that slot.";
    }
}

QString Manager::interact(int input)
{
    Item **items = map.getRoomItems();
    if(items[input] != nullptr)
    {
        return items[input]->display_message();
    }
}

void Manager::drop(int input)
{
    bool flag = false;
    Item **roomItems = map.getRoomItems();
    for(int i = 0; i < 4; ++i)
    {
        if(roomItems[i] == nullptr)
        {
            roomItems[i] = theHero.dropItem(input);
            flag = true;
            break;
        }
    }
    if(!flag)
    {
        delete theHero.dropItem(input);
    }
}

bool Manager::pickup(int input)
{
    Item *current = map.getRoomItems()[input];
    return theHero.collectItem(current);


}

void Manager::userInput(int input, int input2)
{
    Item *holder = theHero.getInventory()[input];
    theHero.getInventory()[input] = theHero.getInventory()[input2];
    theHero.getInventory()[input2] = holder;

}

int Manager::getPlayerHealth()
{
    return theHero.getHealth();
}

QString Manager::getNarrative()
{
    return toOutput;
}

QString Manager::combatEvent(QString action)
{
    //int comp = (rand() % 100) + 1;

    int enemyAttack = map.getEnemyAttack();
    int playerAttack = theHero.attack(action);
    //    int playerAttack = 5;
    //    int enemyAttack = 5;

    if(map.getEnemy())
    {
        //qDebug()<<"map has enemy 1";
        if(map.getEnemy())
        {
            map.getEnemy()->adjustHealth(playerAttack);
            theHero.adjustHealth(-enemyAttack);
            if(map.getEnemy()->getAlive() == false)
            {
                //qDebug()<<"enemy is not alive";
                map.cleared();
                int msg = rand() % 3;
                switch(msg)
                {
                case 0:
                {
                    return "You have defeated the beast.";

                }
                case 1:
                {
                    return "The creature is slain by your hand.";

                }
                case 2:
                {
                    return "The monster flees never to be seen again.";

                }
                }
            }
            else if(map.getEnemy()->getAlive() == true)
            {
                return "You did " + QString::number(playerAttack,10) + " damage to the creature and take "+QString::number(enemyAttack, 10);
            }
            if(theHero.getHealth() == 0)
            {
                int msg = rand() % 3;
                switch(msg)
                {
                case 0:
                {
                    return "<p style='color:darkred'><center><big>You're innards become outards!</big></center></p>";
                    break;
                }
                case 1:
                {
                    return "<p style='color:darkred'><center><big>Your body -Warning graphic content- by the creature!</big></center></p>";
                    break;
                }
                case 2:
                {
                    return "<p style='color:darkred'><center><big>You got slushed by the monster!</big></center></p>";
                    break;
                }
                }
            }
        }
    }
    else
    {
        //qDebug()<<"else executed";
        return "There's nothing to fight";
        //        toOutput = "Theres nothing to fight";
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
        vector<Item*> playerItems = theHero.getInventory();
        if(playerItems[index] == nullptr)
        {
            ret+="Empty Slot";
            return  ret;
        }
        else
        {
            return playerItems[index]->name;
        }
    }
}

int Manager::howManyItems()
{
    return theHero.getInventory().size();
}

