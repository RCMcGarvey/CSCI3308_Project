#include "room.h"
#include <QString>

//Kelley

//call this after they move, pass it 1 for north, 2 for east
//3 for south, 4 for west, 5 for up a floor/level
QString room::nextRoom(int dir) {
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
            moving += currentRoom->description;
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
            moving += currentRoom->description;
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
            moving += currentRoom->description;
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
            moving += currentRoom->description;
            currentRoom->visited = true;
            return moving;
        }
    }
    return moving;
}

QString room::theBeginning() {
    currentRoom = &outside;
    return currentRoom->description;
}


room::room() {

    //outside
    outside.description = "You look over your shoulder. Tendrils of fog slither out from the encroaching forest like snakes, hissing as they slide over the dead ground. Menacing shadows watch you from the cover of the trees. The night is frigid; you pull your clothes tighter. If you spend any longer outside, you’ll freeze to death.";
    outside.description += "/nThe manor to the north you’ve stumbled upon sends a chill deep into your bones. Ancient vines crawl over a dilapidated, dry fountain. Gothic windows, high and imposing, line the massive building’s exterior. Light spills through the highest window. The wind pushes you from behind toward the house.";
    outside.tryS = "If you stay out here you'll freeze to death.";
    outside.tryE = "There is a scary looking mist that frightens you too much to go that way.";
    outside.tryW = "You trip, fall, and when you stand back up your facing Norht.";
    outside.north = &frontOfHouse;

    //front of house
    frontOfHouse.description = "Cautiously, you approach the manor. Loose shingles rattle from the roof above. As you step up the wooden stairs leading to the door, the creaking underfoot sends shivers up your spine. The door, black and glossy, stands before you.";


    //knocking on door

    //the foyer



}
