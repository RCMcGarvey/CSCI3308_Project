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

//call this at the very start of the game to start the narrative
QString room::theBeginning() {
    currentRoom = &outside;
    return currentRoom->description;
}

//call this to see if there is an enemy in this room
bool room::hasEnemy() {
    return currentRoom->monsters;
}

//when the enemy is defeated call this
void room::cleared() {
    currentRoom->monsters = false;
}

room::room() {

    //outside
    outside.description = "You look over your shoulder. Tendrils of fog slither out from the encroaching forest like snakes, hissing as they slide over the dead ground. Menacing shadows watch you from the cover of the trees. The night is frigid; you pull your clothes tighter. If you spend any longer outside, you’ll freeze to death.";
    outside.description += "\nThe manor to the north you’ve stumbled upon sends a chill deep into your bones. Ancient vines crawl over a dilapidated, dry fountain. Gothic windows, high and imposing, line the massive building’s exterior. Light spills through the highest window. The wind pushes you from behind toward the house.\n";
    outside.tryS = "Your instincts kick in, and your legs freeze up. If you go that way you know, you will die a miserable cold death.\n";
    outside.tryE = "There is a scary looking mist that frightens you too much to go that way.\n";
    outside.tryW = "You trip, fall, and when you stand back up your facing north.\n";
    outside.north = &frontOfHouse;

    //front of house
    frontOfHouse.description = "Cautiously, you approach the manor. Loose shingles rattle from the roof above. As you step up the wooden stairs leading to the door, the creaking underfoot sends shivers up your spine. The door, black and glossy, stands before you.\n";
    frontOfHouse.tryS = "You just came from that way and it feels too counterproductive.\n";
    frontOfHouse.tryE = "A strong gust of chilly wind blows you back.\n";
    frontOfHouse.tryW = "You walk into the fountain. It trips you. You get out and are facing north. You better get indoors soon.\n";
    frontOfHouse.north = &knocking;

    //knocking on door
    knocking.description = "You knock on the door, sending a dull thud echoing through the inside of the house. After a moment’s pause, a shudder passes through the exterior of the house. You wait, but you don’t hear anyone come to open the door. The air is getting colder; your breath spirals around you.\n";
    knocking.description += "You reach for the doorknob, but when your hand touches the brass, a loud click comes from within the door. Soundlessly, the door swings open. The inside of the house is darker than the night but you can feel the air is a little warmer there.\n";

    //the foyer



}
