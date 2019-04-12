#include "Manager.h"

//Ryan

Manager::Manager()
{
    toOutput = prison.theBeginning();
}

Manager::~Manager()
{

}

void Manager::userInput(int input, string action)
{
    if(action == "move")
    {
        toOutput = prison.nextRoom(input);
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
    Item** items = prison.getRoomItems();
    toOutput+="The following items are in the room:\n";
    for(int i = 0; i<4; i++){
        if(!items[i]){
            i = 5;
        }
        else{

            toOutput+=QString::fromStdString(items[i]->name);
            toOutput+="\n";
        }
    }


    return toOutput;
}

void Manager::combatEvent()
{

}
