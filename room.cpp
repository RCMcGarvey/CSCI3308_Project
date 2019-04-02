#include "room.h"
#include <QString>

//Kelley

//call this after they move, pass it 1 for north, 2 for east
//3 for south, 4 for west, 5 for up a floor/level
QString room::nextRoom(int dir)
{
    switch(dir)
    {
    case 1://north
        y++;
        if(y > 4) {
            y = 4;
            return cant;
        }
        break;
    case 2://east
        x++;
        if(x > 4) {
            x = 4;
            return cant;
        }
        break;
    case 3://south
        y--;
        if(y < 0) {
            y = 0;
            return cant;
        }
        break;
    case 4://west
        x--;
        if(x < 0) {
            x = 0;
            return cant;
        }
        break;
    case 5://up
        if(stairs[x][y][z]) {
            z++;
        } else {
            return cant;
        }
        break;
    default:
        break;
    }
    return where[x][y][z];
}

room::room()
{
    int i;
    int f;
    for(i = 0; i < 5; i++) {
        for(f = 0; f < 5; f++) {
            where[i][f][0] = "Nothing in here yet";
        }
    }
}
