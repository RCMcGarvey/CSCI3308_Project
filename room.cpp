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
    int tempprob;

    //outside
    outside.description = "You look over your shoulder. Tendrils of fog slither out from the encroaching forest like snakes, hissing as they slide over the dead ground. Menacing shadows watch you from the cover of the trees. The night is frigid; you pull your clothes tighter. If you spend any longer outside, you’ll freeze to death.\n";
    outside.description += "The manor to the north you’ve stumbled upon sends a chill deep into your bones. Ancient vines crawl over a dilapidated, dry fountain. Gothic windows, high and imposing, line the massive building’s exterior. Light spills through the highest window. The wind pushes you from behind toward the house.\n";
    outside.tryS = "Your instincts kick in, and your legs freeze up. If you go that way you know, you will die a miserable cold death.\n";
    outside.tryE = "There is a foreboding looking mist that frightens you too much to go that way.\n";
    outside.tryW = "You trip and fall. When you stand back up, you face north.\n";
    outside.north = &frontOfHouse;
    outside.roomName = "You're outside.\n";
    if(true) {
        outside.monster = outsideSnowman;
        outside.enemyDes = "A snowman rushes toward you! It has a vicious look in its coal eyes and a wicked grin to its sinister mouth. The carrot sticking out of it is twisted.\n";
    }
    outside.items[0] = ItemPool[1];

    //front of house
    frontOfHouse.roomName = "Cautiously, you approach the manor. Loose shingles rattle from the roof above. As you step up the wooden stairs leading to the door, the creaking underfoot sends shivers up your spine. The door, black and glossy, stands before you.\n";
    frontOfHouse.tryS = "You just came from that way; it feels too counterproductive.\n";
    frontOfHouse.tryE = "A strong gust of wind blows you back.\n";
    frontOfHouse.tryW = "You walk into the fountain. It trips you. You get out and are facing north. You better get indoors soon!\n";
    frontOfHouse.description = "You are standing in front of the hosue.\n";
    frontOfHouse.north = &knocking;
    frontOfHouse.items[0] = ItemPool[3];

    //knocking on door
    knocking.roomName = "You knock on the door, sending a dull thud echoing through the inside of the house. After a moment’s pause, a shudder passes through the exterior of the house. You wait, but you don’t hear anyone come to open the door. The air is getting colder; your breath spirals around you.\n";
    knocking.roomName += "You reach for the doorknob, but when your hand touches the brass, a loud click comes from within. Soundlessly, the door swings open. The inside of the house is darker than the night, but you can feel the air is a little warmer there.\n";
    knocking.tryS = "The warm air of the mansion pulls you in. You shouldn't stay outside.\n";
    knocking.tryE = "Wooden porch railing blocks that way.\n";
    knocking.tryW = "You trip on a loose board. When you stand back, up you're facing the door of the mansion.\n";
    knocking.north = &foyer;
    knocking.items[0] = ItemPool[2];

    //the foyer
    foyer.description = "You step inside, and the sound of the wind immediately dies behind you. Shivering, you let the warmer air thaw the chill set in your bones. There is a lone candle sitting on the floorboards whose light lets you discern the features of the room.";
    foyer.description += "It's a large foyer with doors to the north, east, and west. You look behind you, but strangely the door you came through is gone! An enormous chandelier hangs above, but none of its candles are lit.\n";
    foyer.roomName = "You enter the foyer.\n";
    foyer.visited = false;
    foyer.north = &diningRoom;
    foyer.west = &leftHallway;
    foyer.east = &rightHallway;
    foyer.tryS = "The wall is made of solid wood; you cannot go this direction.\n";
    if(rand()%4 == 1) {
        foyer.monster = new enemy(Ghost);
        foyer.enemyDes = "You hear a wail, and the ghost of a small girl flies toward you!\n";
    }
    foyer.items[0] = ItemPool[4];
    foyer.items[1] = ItemPool[5];
    foyer.items[2] = ItemPool[17];


    //the diningRoom
    diningRoom.description = "You enter a long, unlit dining room. A sturdy oak table spans the length of the room with enough chairs to fit more than twenty people. The table is set with plates, knives, glasses, and forks, but there's no food; however, you can smell something delivious in the air. There are doors leading north, east, and south\n";
    diningRoom.north = &trophyRoom;
    diningRoom.south = &foyer;
    diningRoom.east = &kitchen;
    diningRoom.tryW = "You try to go west but trip over a dining room chair and tumble majestically to the floor. When you stand back up, you are facing north.";
    diningRoom.roomName = "You enter the dining room.\n";
    if(rand()%2 == 1) {
        diningRoom.monster = new enemy(Zombie);
        diningRoom.enemyDes = "A Zombie gets up from the table and slowly hobbles over to you.\n";
    }
    diningRoom.items[0] = ItemPool[18]; //knife
    diningRoom.items[1] = ItemPool[19]; //plate
    diningRoom.items[2] = ItemPool[20]; //chair
    diningRoom.items[3] = ItemPool[16];


    //right hallway
    rightHallway.description = "The hallway you step into is short but has doors leading north, east, south, and west. A painting of an old man hangs on one of the walls. You hear the door behind you creak shut.\n";
    rightHallway.east = &office;
    rightHallway.west = &foyer;
    rightHallway.south = &roomWithCouch;
    rightHallway.tryN = "You try to open the door, but it's locked.\n";
    rightHallway.roomName = "You enter a small hallway.\n";
    rightHallway.items[0] = ItemPool[rand()%3 + 21];

    //left hallway
    leftHallway.description = "You open the door to a small hallway. Stepping through, you see doors leading to the north, east, south, and west. A painting of an ancient woman is hanging next to the north door. The hinges of the door quietly scream as they shut.\n";
    leftHallway.north = &barrenRoom;
    leftHallway.south = &library;
    leftHallway.east = &foyer;
    leftHallway.west = &foggyGreenhouse;
    leftHallway.roomName = "You enter a small hallway.\n";
    leftHallway.items[0] = ItemPool[5];
    leftHallway.items[1] = ItemPool[rand()%6 + 7];


    //foggy Greenhouse
    foggyGreenhouse.description = "You step into a greenhouse bustling with dead plants and malignant fungus. Though the walls are made of tinted glass, a thick, wet fog clings to the surface, obscuring your view of the manor’s grounds. Some of the plants look content in their small pots, but a few have spread like a plague out of their containers and over the floorboards all the way to the only door leading East. The air is repugnant here.\n";
    foggyGreenhouse.east = &leftHallway;
    foggyGreenhouse.tryW = "You trip over some fog and land on some pots that break.";
    foggyGreenhouse.tryN = "You dissappear into the mist. You can't see and when you finally escape the mist you are back where you started walking from.";
    foggyGreenhouse.tryS = "There is a wall there.\n";
    foggyGreenhouse.roomName = "You enter the foggy greenhouse.\n";
    foggyGreenhouse.monster = new enemy(Ghoul);
    foggyGreenhouse.enemyDes = "A ghoul slowly approaches, barely visible through the fog.\n";
    tempprob = rand()%3;
    for (int i = 0; i < tempprob; i++){
        foggyGreenhouse.items[i] = ItemPool[rand()%48];
    }


    //library
    library.description = "Shelves spilling with books line the walls and fill the room. Long cobwebs hang from the ceiling, their sticky fibers running between the shelves like bridges. You can feel the dust tickle your lungs from the air you breathe in. A hushed creaking comes from behind the shelves where you cannot see.\n";
    library.north = &leftHallway;
    library.tryS = "A bookcase blocks that way.\n";
    library.tryE = "Through a crack between books, you can see shadows dance.\n";
    library.tryW = "You trip over a pile of books. When you stand back up, you are facing north.\n";
    library.roomName = "You enter the library.\n";
    library.items[0] = ItemPool[rand() % 3 + 45];
    library.items[1] = ItemPool[rand() % 4 + 36];
    library.items[2] = ItemPool[rand() % 5 + 40];


    //barren room
    barrenRoom.description = "The ceiling of the room you enter is high and arched with cracked beams barely supporting it. Empty of furniture or windows, your candle’s light is all that reveals the interior of the barren room. Doors leading north and south stand on either side of the room. The floorboards beneath you moan against your weight, breaking the oppressive silence.\n";
    barrenRoom.north = &sittingRoom;
    barrenRoom.south = &leftHallway;
    barrenRoom.tryE = "There is nothing over there.\n";
    barrenRoom.tryW = "You take a tentative step forward, but your fear of tripping causes you to fall backward.\n";
    barrenRoom.roomName = "You enter the barren room.\n";
    barrenRoom.items[0] = ItemPool[0];
    barrenRoom.items[1] = ItemPool[8];

    //sitting room
    sittingRoom.description = "Whispering fills your ears as you step into the sitting room. A table and set of three dilapidated chairs stand in the center of the room. The sole window is covered by thick, black curtains. Along one of the walls, five portraits of a family hang: a mother, father, daughter, and two sons; their eyes watch you. To the south, east, and west, doors lead.\n";
    sittingRoom.east = &trophyRoom;
    sittingRoom.west = &bathroom2;
    sittingRoom.south = &barrenRoom;
    sittingRoom.roomName = "You enter the sitting room.\n";
    if(rand()%3 == 1) {
        sittingRoom.monster = new enemy(Skeleton);
        sittingRoom.enemyDes = "A skeleton stands before you. It hobbles toward you, still clutching some jewels. When it stands, everything falls through its body. It angrily wobbles in your direction.\n";
    }
    if(rand()%4 == 1) {
        sittingRoom.items[0] = ItemPool[rand()%4 + 24];
    }

    //trophy room
    trophyRoom.description = "Taxidermied heads of animals dot the wall and the pelts of exotic creatures line the floor. The beady eyes of the dead creatures stare blankly into the space before them. Two doors to the south and the west lead from the room. You can hear a faint dripping noise.\n";
    trophyRoom.south = &diningRoom;
    trophyRoom.west = &sittingRoom;
    trophyRoom.roomName = "You enter the trophy room.\n";
    trophyRoom.items[0] = ItemPool[rand()%8 + 28];
    trophyRoom.items[1] = ItemPool[42];
    trophyRoom.items[2] = ItemPool[7];
    if (rand()%10 == 1) {
        trophyRoom.items[3] = ItemPool[rand()%4+24];
    }


    //kitchen
    kitchen.description = "A clatter splits the air as you step into the kitchen. You see a door swiftly close, then the room returns to silence. On the floor lays a bloody knife, the source of the noise. An array of pantries wrap around the room, and a large island rests in the center. You can see a wooden cutting board on the island drenched in blood. Doors lead to the north and west.\n";
    kitchen.north = &cellar;
    kitchen.west = &diningRoom;
    kitchen.roomName = "You enter the kitchen.\n";
    kitchen.items[0] = ItemPool[18];
    kitchen.items[1] = ItemPool[18];
    kitchen.items[2] = ItemPool[7];
    if (rand()%10 == 1) {
        kitchen.items[3] = ItemPool[27];
    }
    //cellar
    cellar.description = "You feel the dank air on your skin as you step into the cellar. Barrels are stacked throughout the room, rotten and cracked. Water drips from the ceiling above and hits the shallow puddle along the floor with a splash. The only door is from the way you came: south.\n";
    cellar.south = &kitchen;
    cellar.roomName = "You enter the cellar.\n";
    if(rand()%2==1) {
        cellar.monster = new enemy(Vampire);
        cellar.enemyDes = "A vampire rises from its coffin and goes for your neck!\n";
        cellar.items[1] = ItemPool[rand()%4 + 24];
        cellar.items[2] = ItemPool[rand()%8 + 28];
    }
    cellar.items[0] = ItemPool[rand()%11 + 7];

    //room with couch
    roomWithCouch.description = "A long couch, cleaved in two and splattered with dried blood, is the only furniture in an otherwise empty room. You can see red eyes glint through the window on the opposite wall. Creaking comes through the ceiling above. The only door is to the north.\n";
    roomWithCouch.north = &rightHallway;
    roomWithCouch.roomName = "You enter the couch room.\n";
    roomWithCouch.monster = new enemy(Ghost, 113, 113, 7, 0.3);
    roomWithCouch.enemyDes = "Oh sh*t a ghost girl crawls out of the couch and kills your head off!\n";
    roomWithCouch.items[0] = ItemPool[rand()%3 + 21];
    roomWithCouch.items[1] = ItemPool[17];
    roomWithCouch.items[2] = ItemPool[rand()%3 + 45];
    roomWithCouch.items[3] = ItemPool[7];

    //piano room
    pianoRoom.description = "As you step into the room, you spy a decaying grand piano. Faint as a breath, quiet notes suffuse the air, their eerie tune making your hair stand on end. You can see nothing striking the keys to make the music. A door leads north.\n";
    pianoRoom.north = &office;
    pianoRoom.roomName = "You enter the piano room.\n";
    tempprob = rand()%101;
    if (rand()%4 == 1) {
        pianoRoom.monster = new enemy(Skeleton, tempprob, tempprob, rand()%21, 0.01);
        pianoRoom.enemyDes = "The jangling of bones approaches! A skeleton attacks!";
    }

    //office
    office.description = "The office you enter is perfectly in order. A large desk is stacked neatly with letters and papers, the contents of which are written in an unintelligible script. What sounds like scratching comes from within the walls. Doors lead to the west, north, and south.\n";
    office.north = &bathroom1;
    office.west = &rightHallway;
    office.south = &roomWithCouch;
    office.roomName = "You enter the office.\n";
    tempprob = rand()%3;
    for (int i = 0; i < tempprob; i++) {
        office.items[i + 1] = ItemPool[rand()%7];
    }
    office.items[0] = ItemPool[rand()%3 + 21];

    //bathroom 1
    bathroom1.description = "You enter a bathroom made of white marble. The mirror, sink, and toilet are all cracked and crumbling. The sole door is to the south. An ominous gurgling comes from inside the toilet basin.\n";
    bathroom1.south = &office;
    bathroom1.roomName = "You enter the white bathroom.\n";
    tempprob = rand()%5;
    if(tempprob != 4) {
        bathroom1.monster = new enemy(ZippyFlap);
        bathroom1.enemyDes = "A zippyflap was lying in wait. It attacks you!\n";
        bathroom1.items[0] = ItemPool[43];
        bathroom1.items[1] = ItemPool[rand()%4 + 37];
        bathroom1.items[2] = ItemPool[rand()%3 + 28];
    }

    //bathroom 2
    bathroom2.description = "You step into a bathroom of dark, creaking wood. The bathroom looks long since used, and a foul smell seeps into the air. You can hear creaking come the ceiling above you. A door leads to the east.\n";
    bathroom2.east = &sittingRoom;
    bathroom2.roomName = "You enter the dark bathroom.\n";
    bathroom2.monster = new enemy(Diary);
    bathroom2.enemyDes = "The final boss, a diary attacks you.";
    //haha you'll never beat it lmao
}

QString room::saveGame() {
    QString saves;
    if(outside.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(frontOfHouse.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(knocking.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(foyer.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(diningRoom.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(rightHallway.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(leftHallway.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(library.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(barrenRoom.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(sittingRoom.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(trophyRoom.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(kitchen.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(cellar.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(roomWithCouch.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(pianoRoom.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(office.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(bathroom1.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(bathroom2.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    if(foggyGreenhouse.roomName == currentRoom->roomName) {
        saves += "1";
    } else {
        saves += "0";
    }
    return saves;
}

QString room::loadGame(QString load) {
    if(load[0] == "1")
        currentRoom = &outside;
    if(load[1] == "1")
        currentRoom = &frontOfHouse;
    if(load[2] == "1")
        currentRoom = &knocking;
    if(load[3] == "1")
        currentRoom = &foyer;
    if(load[4] == "1")
        currentRoom = &diningRoom;
    if(load[5] == "1")
        currentRoom = &rightHallway;
    if(load[6] == "1")
        currentRoom = &leftHallway;
    if(load[7] == "1")
        currentRoom = &library;
    if(load[8] == "1")
        currentRoom = &barrenRoom;
    if(load[9] == "1")
        currentRoom = &sittingRoom;
    if(load[10] == "1")
        currentRoom = &trophyRoom;
    if(load[11] == "1")
        currentRoom = &kitchen;
    if(load[12] == "1")
        currentRoom = &cellar;
    if(load[13] == "1")
        currentRoom = &roomWithCouch;
    if(load[14] == "1")
        currentRoom = &pianoRoom;
    if(load[15] == "1")
        currentRoom = &office;
    if(load[16] == "1")
        currentRoom = &bathroom1;
    if(load[17] == "1")
        currentRoom = &bathroom2;
    if(load[18] == "1")
        currentRoom = &foggyGreenhouse;
    return currentRoom->roomName;
}

QString room::lookAround() {
   QString roomDes = currentRoom->description;
   QString observations = "You see a ";
   for(int i = 0; i < 4; ++i)
   {
       if(currentRoom->items[i] != nullptr)
       {
           observations += currentRoom->items[i]->name + ", ";
       }
       if(i == 3 && currentRoom->items[i] != nullptr)
       {
           observations += "and a " + currentRoom->items[i]->name;
       }
   }
   return roomDes + "\n" + observations;

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

