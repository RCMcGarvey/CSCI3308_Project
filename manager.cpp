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

QString Manager::move(int input)
{
    return map.nextRoom(input);
}

QString Manager::inspect(int input)
{

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
    Item **holder = map.getRoomItems();
    if(theHero.collectItem(holder[input]) == false)
    {
        return  false;
    }
    else
    {
        return true;
    }


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
            int msg = rand() % 3;
            switch(msg)
            {
            case 0:
            {
                toOutput = "<p style='color:darkred'><center><big>You're innards become outards!</big></center></p>";
                break;
            }
            case 1:
            {
                toOutput = "<p style='color:darkred'><center><big>Warning graphic content!</big></center></p>";
                break;
            }
            case 2:
            {
                toOutput = "<p style='color:darkred'><center><big>You got slushed by the monster!</big></center></p>";
                break;
            }
            }
        }
    }
    else
    {
        toOutput = "Theres nothing to fight";
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

