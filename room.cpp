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

    itemList[0] = oldSword;
    itemList[1] = woodenBow;
    itemList[2] = rustyDagger;
    itemList[3] = healingPotion;
    itemList[4] = stick;
    itemList[5] = dryTwig;
    itemList[6] = brick;
    itemList[7] = board;
    itemList[8] = knife;
    itemList[9] = chair;

    //outside
    outside.description = "You look over your shoulder. Tendrils of fog slither out from the encroaching forest like snakes, hissing as they slide over the dead ground. Menacing shadows watch you from the cover of the trees. The night is frigid; you pull your clothes tighter. If you spend any longer outside, you’ll freeze to death.\n";
    outside.description += "The manor to the north you’ve stumbled upon sends a chill deep into your bones. Ancient vines crawl over a dilapidated, dry fountain. Gothic windows, high and imposing, line the massive building’s exterior. Light spills through the highest window. The wind pushes you from behind toward the house.\n";
    outside.tryS = "Your instincts kick in, and your legs freeze up. If you go that way you know, you will die a miserable cold death.\n";
    outside.tryE = "There is a foreboding looking mist that frightens you too much to go that way.\n";
    outside.tryW = "You trip and fall. When you stand back up, you face north.\n";
    outside.north = &frontOfHouse;
    outside.items[0] = stick;
    outside.items[1] = dryTwig;
    outside.roomName = "You're outside";
    if(rand()%2 == 1) { // (rand() % 2 == 1) -> random num between (0, 1)
        outside.monster = outsideSnowman;
        outside.enemyDes = "A snowman rushes toward you! It has a vicious look in its coal eyes and a wicked grin to sinister mouth. The carrot sticking out of it is twisted.\n";
    }

    //front of house
    frontOfHouse.description = "Cautiously, you approach the manor. Loose shingles rattle from the roof above. As you step up the wooden stairs leading to the door, the creaking underfoot sends shivers up your spine. The door, black and glossy, stands before you.\n";
    frontOfHouse.tryS = "You just came from that way; it feels too counterproductive.\n";
    frontOfHouse.tryE = "A strong gust of wind blows you back.\n";
    frontOfHouse.tryW = "You walk into the fountain. It trips you. You get out and are facing north. You better get indoors soon!\n";
    frontOfHouse.north = &knocking;
    frontOfHouse.items[0] = brick;
    frontOfHouse.roomName = "You're at the front of house";

    //knocking on door
    knocking.description = "    You knock on the door, sending a dull thud echoing through the inside of the house. After a moment’s pause, a shudder passes through the exterior of the house. You wait, but you don’t hear anyone come to open the door. The air is getting colder; your breath spirals around you.\n";
    knocking.description += "   You reach for the doorknob, but when your hand touches the brass, a loud click comes from within. Soundlessly, the door swings open. The inside of the house is darker than the night, but you can feel the air is a little warmer there.\n";
    knocking.tryS = "The warm air of the mansion pulls you in. The cold air chills your borns instinctively making you step back towards the door.\n";
    knocking.tryE = "Porch railing blocks your path that way.\n";
    knocking.tryW = "There is a loose board and you trip on it. When you stand back up you are facing the door of the mansion.\n";
    knocking.north = &foyer;
    knocking.items[0] = brick;
    knocking.items[1] = stick;
    knocking.roomName = "You're knocking";

    //the foyer
    foyer.description = "   You step inside, and the sound of the wind immediately dies behind you. Shivering, you let the warmer air thaw the chill set in your bones. There is a lone candle sitting on the floorboards whose light lets you discern the features of the room.";
    foyer.description += "It's a large foyer with doors to the north, east, and west. You look behind you, but strangely the door you came through is gone! An enormous chandelier hangs above, but none of its candles are lit.\n";
    foyer.north = &diningRoom;
    foyer.west = &leftHallway;
    foyer.east = &rightHallway;
    foyer.tryS = "The wall is made of solid wood; you cannot go this direction.\n";
    foyer.items[0] = board;
    foyer.roomName = "You enter the Foyer\n";


    //the diningRoom
    diningRoom.description = "You enter a long, unlit dining room. A sturdy oak table spans the length of the room with enough chairs to fit more than twenty people. The table is set with plates, knives, glasses, and forks, but there's no food; however, you can smell something delivious in the air. There are doors leading north, east, and south\n";
    diningRoom.north = &trophyRoom;
    diningRoom.south = &foyer;
    diningRoom.east = &kitchen;
    diningRoom.tryW = "//HELP";
    diningRoom.items[0] = knife;
    diningRoom.items[1] = chair;
    diningRoom.roomName = "You enter the Dining Room\n";

    //right hallway


    //left hallway
    leftHallway.description = "You open the door to a small hallway. Stepping through, you see doors leading to the north, east, south, and west. A painting of an ancient woman is hanging next to the north door. The hinges of the door quietly scream as they shut.\n";
    leftHallway.north = &barrenRoom;
    leftHallway.south = &library;
    leftHallway.east = &foyer;
    leftHallway.west = &foggyGreenhouse;
    leftHallway.roomName = "You enter a small hallway.\n";


    //library
    library.description = "Shelves spilling with books line the walls and fill the room. Long cobwebs hang from the ceiling, their sticky fibers running between the shelves like bridges. You can feel the dust tickle your lungs from the air you breathe in. A hushed creaking comes from behind the shelves where you cannot see.\n";
    library.north = &leftHallway;
    library.roomName = "You enter the library.\n";


    //barren room
    barrenRoom.description = "The ceiling of the room you enter is high and arched with cracked beams barely supporting it. Empty of furniture or windows, your candle’s light is all that reveals the interior of the barren room. Doors leading north and south stand on either side of the room. The floorboards beneath you moan against your weight, breaking the oppressive silence.\n";
    barrenRoom.north = &sittingRoom;
    barrenRoom.south = &leftHallway;
    barrenRoom.roomName = "You enter the barren room.\n";

    //sitting room
    sittingRoom.description = "Whispering fills your ears as you step into the sitting room. A table and set of three dilapidated chairs stand in the center of the room. The sole window is covered by thick, black curtains. Along one of the walls, five portraits of a family hang: a mother, father, daughter, and two sons; their eyes watch you. To the south, east, and west, doors lead.\n";
    sittingRoom.east = &trophyRoom;
    sittingRoom.west = &bathroom2;
    sittingRoom.south = &barrenRoom;
    sittingRoom.roomName = ".\n";

    //trophy room
    trophyRoom.description = "Taxidermied heads of animals dot the wall and the pelts of exotic creatures line the floor. The beady eyes of the dead creatures stare blankly into the space before them. Two doors to the south and the west lead from the room. You can hear a faint dripping noise.\n";
    trophyRoom.south = &diningRoom;
    trophyRoom.west = &sittingRoom;

    //kitchen
    kitchen.description = "A clatter splits the air as you step into the kitchen. You see a door swiftly close, then the room returns to silence. On the floor lays a bloody knife, the source of the noise. An array of pantries wrap around the room, and a large island rests in the center. You can see a wooden cutting board on the island drenched in blood. Doors lead to the north and west.\n";
    kitchen.north = &cellar;
    kitchen.west = &diningRoom;

    //cellar
    cellar.description = "You feel the dank air on your skin as you step into the cellar. Barrels are stacked throughout the room, rotten and cracked. Water drips from the ceiling above and hits the shallow puddle along the floor with a splash. The only door is from the way you came: south.\n";
    cellar.south = &kitchen;

    //room with couch
    roomWithCouch.description = "A long couch, cleaved in two and splattered with dried blood, is the only furniture in an otherwise empty room. You can see red eyes glint through the window on the opposite wall. Creaking comes through the ceiling above. The only door is to the north.\n";
    roomWithCouch.north = &rightHallway;

    //piano room
    pianoRoom.description = "As you step into the room, you spy a decaying grand piano. Faint as a breath, quiet notes suffuse the air, their eerie tune making your hair stand on end. You can see nothing striking the keys to make the music. A door leads north.\n";
    pianoRoom.north = &office;

    //office
    office.description = "The office you enter is perfectly in order. A large desk is stacked neatly with letters and papers, the contents of which are written in an unintelligible script. What sounds like scratching comes from within the walls. Doors lead to the west, north, and south.\n";
    office.north = &bathroom2;
    office.north = &rightHallway;
    office.south = &roomWithCouch;

    //bathroom 1
    bathroom1.description = "You enter a bathroom made of white marble. The mirror, sink, and toilet are all cracked and crumbling. The sole door is to the south. An ominous gurgling comes from inside the toilet basin.\n";
    bathroom1.east = &sittingRoom;

    //bathroom 2
    bathroom2.description = "You step into a bathroom of dark, creaking wood. The bathroom looks long since used, and a foul smell seeps into the air. You can hear creaking come the ceiling above you. A door leads to the east.\n";
    bathroom2.south = &office;
}

QString room::saveGame() {
    QString help = "";
    return help;
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

Item* room::getItem(int id) {
    return itemList[id];
}

int room::getItemID(Item *itemPtr) {
    if(itemPtr != nullptr) {
        if(itemPtr->name == "Old Sword")
            return 0;
        if(itemPtr->name == "Wooden Bow")
            return 1;
        if(itemPtr->name == "Rusty Dagger")
            return 2;
        if(itemPtr->name == "Potion of Healing")
            return 3;
        if(itemPtr->name == "A Dry Stick")
            return 4;
        if(itemPtr->name == "A Dry Twig")
            return 5;
        if(itemPtr->name == "A Brick")
            return 6;
        if(itemPtr->name == "A Wooden Board")
            return 7;
        if(itemPtr->name == "A Dining Knife")
            return 8;
        if(itemPtr->name == "A Dining Chair")
            return 9;
        return 99;
    } else {
        return 99;
    }
}

