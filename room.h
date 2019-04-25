/* Added to Room class:
-enemy* Room::getEnemy (returns NULL if no enemy in room)
-player attack interaction with enemy
-basic implementation of a few dynamic items placed in rooms
 * Added to Enemy class:
getAlive() -- returns whether enemy is alive

 */



#ifndef ROOM_H
#define ROOM_H
#include <QString>

#include "item.h"
#include "enemy.h"

class room
{
public:
    struct roms {
        QString description;
        bool visited = true;
        roms *south = nullptr;
        QString tryS;
        QString southGo;
        roms *north = nullptr;
        QString tryN;
        QString northGo;
        roms *east = nullptr;
        QString tryE;
        QString eastGo;
        roms *west = nullptr;
        QString tryW;
        QString westGo;
        QString enemyDes;
        QString roomName;

        Item* items[4] = {nullptr};//items in the room

        enemy* monster = nullptr;//enemy in the room, if any
    };


    enemy* outsideSnowman = new enemy(Snowman);

    QString meunster = "There is a monster blocking your movements.\n";

    roms *currentRoom;
    room();
    QString nextRoom(int dir);
    QString moving = "";
    QString nothing = "There is nothing that way\n";
    QString theBeginning();
    QString lookAround();

    roms outside;
    roms frontOfHouse;
    roms knocking;
    roms foyer;
    roms diningRoom;
    roms rightHallway;
    roms leftHallway;
    roms library;
    roms barrenRoom;
    roms foggyGreenhouse;
    roms sittingRoom;
    roms trophyRoom;
    roms kitchen;
    roms cellar;
    roms roomWithCouch;
    roms pianoRoom;
    roms office;
    roms bathroom1;
    roms bathroom2;

    roms smallBedroom;
    roms longHallway;
    roms longerHallway;
    roms spookyBathroom;
    roms masterBedroom;
    roms monsterBedroom;
    roms spookyBathroom2;
    roms childBedroom;
    roms galleryOfMirrors;
    roms paintingOfADemonChildRoom;

    bool hasEnemy();
    void cleared();
    int howManyItems;

    //Added implementations:
    //returns a pointer to the enemy, if manager needs it
    enemy* getEnemy(){return currentRoom->monster;}
    //returns an array (length 4) of item pointers
    Item** getRoomItems(){return currentRoom->items;}

//    Item* getRoomItems(int itemNum){return currentRoom->items[itemNum];}
    //if the enemy is alive, returns enemy's attack
    int getEnemyAttack();//-1 means enemy has died or doesn't exist
    //player can attack and destroy the enemy
    void playerAttack(int);
    //if room can fit another item, it is added to the array in the
    //first available place. Otherwise, returns false
    bool addItem(Item*);

    //save the game
    QString saveGame();
    QString loadGame(QString load);
};

#endif // ROOM_H
