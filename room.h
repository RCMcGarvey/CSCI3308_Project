#ifndef ROOM_H
#define ROOM_H
#include <QString>


class room
{
public:
    struct roms {
        QString description;
        bool visited = false;
        bool monsters = false;
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
    };
    roms *currentRoom;
    room();
    QString nextRoom(int dir);  
    QString moving = "";
    QString nothing = "There is nothing that way";
    QString theBeginning();
    roms outside;
    roms frontOfHouse;
    roms knocking;
    roms foyer;
    bool hasEnemy();
    void cleared();
};

#endif // ROOM_H

