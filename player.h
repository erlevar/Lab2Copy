#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "item.h"
#include "room.h"

class player
{
public:
    player();
    player(room startLocation);
    room currentLocation();
    void updateLocation(room newLocation);
    void readInventory();
    void takeItem(item newItem);
    item checkItems(string s);
    void dropItem(string s);

private :
    room current;
    vector<item> inventory;
};


#endif // PLAYER_H
