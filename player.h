#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "item.h"
#include "room.h"
#include <map>
#include <vector>

class player
{
public:
    player();
    player(room startLocation);
    room currentLocation();
    void updateLocation(room newLocation);
    void addItem(item newItem);
    item checkItems(string s);
    void removeItem(string s);
    player& operator=(const player & p);

    //all for executing user commands
    void readInventory(); //i commands
    void moveToBorder(map<string, room> roomMap, bool & changedRooms, string input);  //n, s, e, w commands
    void userTakeItem(room & current, string input); //take (item) commands
    void userReadItem(string input); //read (item) commands
    void userDropItem(room & current, string input); //drop (item) commands
    void isAtExit(bool & foundExit); //used for open exit commands
    void userOpenContainer(string input); //used for open container commands
    void userTurnonItem (string input); //used for turn on (item) commands
    void userPutItemInContainer(room & current, string itemName, string containerName); //user for put (item) in (container) commands

private :
    room current;
    vector<item> inventory;
};


#endif // PLAYER_H
