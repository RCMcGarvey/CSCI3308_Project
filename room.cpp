#include "room.h"
#include <QString>
#include <cstdlib>
#include <time.h>

//Kelley

//call this after they move, pass it 1 for north, 2 for east
//3 for south, 4 for west, 5 for up a floor/level
QString room::nextRoom(int dir) {
    if(currentRoom->monster != nullptr) {
        return meunster;
    } else {
        switch(dir) {
        case 1:
            if(currentRoom->north == nullptr) {
                if(currentRoom->tryN != "") {
                    return currentRoom->tryN;
                } else {
                    return nothing;
                }
            } else {
                moving = currentRoom->northGo;
                currentRoom = currentRoom->north;
                if(currentRoom->visited) {
                    moving += currentRoom->roomName;
                } else {
                    moving += currentRoom->description;
                }
                if(currentRoom->monster != nullptr) {
                    moving += currentRoom->enemyDes;
                }
                currentRoom->visited = true;
                return moving;
            }
        case 2:
            if(currentRoom->east == nullptr) {
                if(currentRoom->tryE != "") {
                    return currentRoom->tryE;
                } else {
                    return nothing;
                }
            } else {
                moving = currentRoom->eastGo;
                currentRoom = currentRoom->east;
                if(currentRoom->visited) {
                    moving += currentRoom->roomName;
                } else {
                    moving += currentRoom->description;
                }
                if(currentRoom->monster != nullptr) {
                    moving += currentRoom->enemyDes;
                }
                currentRoom->visited = true;
                return moving;
            }
        case 3:
            if(currentRoom->south == nullptr) {
                if(currentRoom->tryS != "") {
                    return currentRoom->tryS;
                } else {
                    return nothing;
                }
            } else {
                moving = currentRoom->southGo;
                currentRoom = currentRoom->south;
                if(currentRoom->visited) {
                    moving += currentRoom->roomName;
                } else {
                    moving += currentRoom->description;
                }
                if(currentRoom->monster != nullptr) {
                    moving += currentRoom->enemyDes;
                }
                currentRoom->visited = true;
                return moving;
            }
        case 4:
            if(currentRoom->west == nullptr) {
                if(currentRoom->tryW != "") {
                    return currentRoom->tryW;
                } else {
                    return nothing;
                }
            } else {
                moving = currentRoom->westGo;
                currentRoom = currentRoom->west;
                if(currentRoom->visited) {
                    moving += currentRoom->roomName;
                } else {
                    moving += currentRoom->description;
                }
                if(currentRoom->monster != nullptr) {
                    moving += currentRoom->enemyDes;
                }
                currentRoom->visited = true;
                return moving;
            }
        }
        return moving;
    }
}

//call this at the very start of the game to start the narrative
QString room::theBeginning() {
    currentRoom = &outside;
    if(currentRoom->monster != nullptr)
        currentRoom->description += currentRoom->enemyDes;
    return currentRoom->description;
}

//call this to see if there is an enemy in this room
bool room::hasEnemy() {
    return currentRoom->monster;
}

//when the enemy is defeated call this
void room::cleared() {
    currentRoom->monster = nullptr;
}

room::room() {
    srand(time(NULL));
    //Found somewhere in the building

    //outside
    outside.description = "You look over your shoulder. Tendrils of fog slither out from the encroaching forest like snakes, hissing as they slide over the dead ground. Menacing shadows watch you from the cover of the trees. The night is frigid; you pull your clothes tighter. If you spend any longer outside, you’ll freeze to death.\n";
    outside.description += "The manor to the north you’ve stumbled upon sends a chill deep into your bones. Ancient vines crawl over a dilapidated, dry fountain. Gothic windows, high and imposing, line the massive building’s exterior. Light spills through the highest window. The wind pushes you from behind toward the house.\n";
    outside.tryS = "Your instincts kick in, and your legs freeze up. If you go that way you know, you will die a miserable cold death.\n";
    outside.tryE = "There is a scary looking mist that frightens you too much to go that way.\n";
    outside.tryW = "You trip, fall, and when you stand back up your facing north.\n";
    outside.north = &frontOfHouse;
    outside.items[0] = stick;
    outside.items[1] = dryTwig;
    outside.roomName = "Outside";
    if(rand()%2 == 1) {
        outside.monster = outsideSnowman;
        outside.enemyDes = "There is a snowman coming towards you. It has a vicious look in its coal eyes and mouth. The carrot sticking out of it is twisted.\n";
    }

    //front of house
    frontOfHouse.description = "Cautiously, you approach the manor. Loose shingles rattle from the roof above. As you step up the wooden stairs leading to the door, the creaking underfoot sends shivers up your spine. The door, black and glossy, stands before you.\n";
    frontOfHouse.tryS = "You just came from that way and it feels too counterproductive.\n";
    frontOfHouse.tryE = "A strong gust of chilly wind blows you back.\n";
    frontOfHouse.tryW = "You walk into the fountain. It trips you. You get out and are facing north. You better get indoors soon.\n";
    frontOfHouse.north = &knocking;
    frontOfHouse.items[0] = brick;
    frontOfHouse.roomName = "Front of House";

    //knocking on door
    knocking.description = "You knock on the door, sending a dull thud echoing through the inside of the house. After a moment’s pause, a shudder passes through the exterior of the house. You wait, but you don’t hear anyone come to open the door. The air is getting colder; your breath spirals around you.\n";
    knocking.description += "You reach for the doorknob, but when your hand touches the brass, a loud click comes from within the door. Soundlessly, the door swings open. The inside of the house is darker than the night but you can feel the air is a little warmer there.\n";
    knocking.tryS = "The warm air of the mansion pulls you in. The cold air chills your borns instinctively making you step back towards the door.\n";
    knocking.tryE = "Porch railing blocks your path that way.\n";
    knocking.tryW = "There is a loose board and you trip on it. When you stand back up you are facing the door of the mansion.\n";
    knocking.north = &foyer;
    knocking.items[0] = brick;
    knocking.items[1] = stick;
    knocking.roomName = "Knocking";

    //the foyer
    foyer.description = "You step inside and the sound of the wind immediately dies behind you. Shivering you let the warmer air thaw the chill set in your bones. There is a lone candle sitting on the floorboards.\n";
    foyer.description += "The light of the candle lets you discern the room you are standing in. It's a large foyer with doors to the north, east, and west. You look behind you, but strangely the door you came through is gone; replaced by an empty frame. There is an enormous chandelier hanging from above, but none of its candles are lit.\n";
    foyer.north = &diningRoom;
    foyer.west = &leftHallway;
    foyer.east = &rightHallway;
    foyer.tryS = "You turn to look at the empty frame, but now there resides a barely visible lady, shrouded by shadows. She appears to be looking behind you. Suddenly, you hear a noise behind your back. You try to turn but the woman captivates your muscles. The sound of scurrying gets closer, until something brushes your shoulder. Feeling this, you snap out of your trance and rapidle turn around, however, there is nothing there. When you look back to the painting, the lady is gone.\n";
    foyer.items[0] = board;
    foyer.roomName = "You Enter The Foyer\n";


    //the diningRoom
    diningRoom.description = "You enter a long, unlit dining room. A sturdy oak tbale spans the length of the room with enough chairs to fit more than twenty people. The table is set with plates, knives, glasses, and forks, but there's no food; however, you can smell something delivious in the air. There are doors leading north, east, and south\n";
    diningRoom.north = &trophyRoom;
    diningRoom.south = &foyer;
    diningRoom.east = &kitchen;
    diningRoom.tryW = "You start walking towards the west wall. On your way though you trip over a chair. After flipping and rolling a few times, you appear to be facing north.\n";
    diningRoom.items[0] = knife;
    diningRoom.items[1] = chair;
    diningRoom.roomName = "You enter the Dining Room\n";

    //right hallway


    //left hallway


    //library


    //barren room


    //sitting room


    //trophy room


    //kitchen


    //cellar


    //room with couch


    //piano room


    //office


    //bathroom 1


    //bathroom 2


    //small bedroom


    //long hallway


    //longer hallway


    //spooky bathroom


    //master bedroom


    //monster bedroom


    //spooky bathroom 2


    //child bedroom


    //gallery of mirrors


    //painting of a demon child room


}

QString room::saveGame() {
    return "your mom was in my room ;)";
}

void room::loadGame(QString load) {

}

QString room::lookAround() {
    return currentRoom->description;
}

int room::getEnemyAttack(){
    //if there is no enemy, room->enemy should be null
    if(currentRoom->monster == nullptr){
        return -1;
    }

    return currentRoom->monster->attack();

}

void room::playerAttack(int atk){
    enemy* currEnemy = currentRoom->monster;
    if(currentRoom->monster == nullptr){
        return; //no enemy in room
    }
    //enemy is definitely alive at this point...
    currEnemy->adjustHealth(-1*atk);
    //if the enemy is dead, let's get rid of it
    if(!currEnemy->getAlive()){
        delete currEnemy;
        currentRoom->monster = nullptr;
    }
}

bool  room::addItem(Item* newItem){
    //assuming items array can hold only 4 items
    for(int i = 0; i<4; i++){
        if(currentRoom->items[i] == nullptr){
            currentRoom->items[i] = newItem;
            return true;
        }
        ++howManyItems;
    }
    return false;
}

