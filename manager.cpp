#include "Manager.h"
#include <iostream>

#include <QDebug>

//Ryan

Manager::Manager()
{
    toOutput = map.theBeginning();
    srand(8191);
    //theHero = Player(Warrior);
    gameOver = false;
}

Manager::~Manager()
{

}

void Manager::setPlayerClass(int role)
{
    if(role == 1)
    {
        theHero = Player(Warrior);
    }
    else if(role == 2)
    {
        theHero = Player(Mage);
    }
    else if(role == 3)
    {
        theHero = Player(Bard);
    }
    else if(role == 4)
    {
        theHero = Player(Rogue);
    }
}

QString Manager::move(int input)
{
    if(map.getEnemy() != nullptr)
        return "An enemy blocks your path.";
   else
        return map.nextRoom(input);
}

QString Manager::use(int slot)
{
    return theHero.useItem(slot);
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
    if(current == nullptr)
        return true;
    if(theHero.collectItem(current) == false)
    {
        return false;
    }
    else
    {
        map.getRoomItems()[input] = nullptr;
        return true;
    }
}

void Manager::swap(int input, int input2)
{
    Item *holder = theHero.getInventory()[input];
    theHero.getInventory()[input] = theHero.getInventory()[input2];
    theHero.getInventory()[input2] = holder;

}

int Manager::getPlayerHealth()
{
    return theHero.getHealth();
}

QString Manager::startNarrative()
{
    return toOutput;
}

QString Manager::combatEvent(QString action)
{
    if(map.getEnemy() != nullptr)
    {
        int enemyAttack = map.getEnemyAttack() - theHero.getDefense();
        int playerAttack = theHero.attack(action);
        QString enemyname = map.getEnemy()->getEnemyName();
            map.getEnemy()->adjustHealth(-playerAttack);
            theHero.adjustHealth(-enemyAttack);
            if(map.getEnemy()->getAlive() == false)
            {
                //qDebug()<<"enemy is not alive";
                map.cleared();
                theHero.adjustHealth(enemyAttack);
                int msg = rand() % 3;
                switch(msg)
                {
                case 0:            
                    return "You have defeated the " + enemyname + ".";
                case 1:                
                    return "The "+ enemyname +" is slain by your hand.";
                case 2: 
                    return "The "+ enemyname +" flees never to be seen again.";
                }
            }
            else if(theHero.getHealth() == 0)
            {
                int msg = rand() % 3;
                switch(msg)
                {
                case 0:
                {
                    return "You take "+ QString::number(enemyAttack) +" damage.<br></br><p style='color:darkred'><center><big>You're innards become outards!</big></center></p>";
                }
                case 1:
                {
                    return "You take "+ QString::number(enemyAttack) +" damage.<br></br><p style='color:darkred'><center><big>The " + enemyname + " rips off your arms and beats you to death with them!</big></center></p>";
                }
                case 2:
                {
                    return "You take "+ QString::number(enemyAttack) +" damage.<br></br><p style='color:darkred'><center><big>You got slushed by the " + enemyname + "!</big></center></p>";
                }
                }
            }
            else if(map.getEnemy()->getAlive() == true)
            {
                return "You did " + QString::number(playerAttack,10) + " damage to the "+ enemyname +" and take "+QString::number(enemyAttack, 10)+" damage.";
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

int Manager::enemyHealth()
{
    if(map.getEnemy() == nullptr)
        return 0;
    return map.getEnemy()->getHealth();
}

void Manager::setUser(QString user)
{
    username = user;
}
void Manager::setPass(QString pass)
{
   password = pass;
}






