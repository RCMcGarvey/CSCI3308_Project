#ifndef ROOM_H
#define ROOM_H
#include <QString>

class room
{
public:
    room();
    QString nextRoom(int dir);
    QString where[5][5][2];
    bool locked[5][5][2];
    bool stairs[5][5][2];
    int x = 0, y = 0, z = 0;
    QString cant = "You can't go that way.";
};

#endif // ROOM_H
