#include "Manager.h"

//Ryan

Manager::Manager()
{
    //prison.theBegining();
}

Manager::~Manager()
{

}

void Manager::userInput(int input, string action)
{
    if(action == "move")
    {
        prison.nextRoom(input);
    }
    else if(action == "weapon")
    {

    }
    else if(action == "spell")
    {

    }
    else if(1)
    {

    }
}

void Manager::userInput(QString input)
{

}



void Manager::userInput(int input, int input2)
{

}

int Manager::getPlayerHealth()
{

}

QString Manager::getNarrative()
{
    return toOutput;
}

void Manager::combatEvent()
{

}


