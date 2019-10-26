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
    //constructor that initializes player current location to startLocation
    player(room startLocation);
    //returns currentLocation
    room currentLocation();
    //updates Location
    void updateLocation(room newLocation);
    //updates inventory
    void addItem(item newItem);
    //check user inventory by item name
    item checkItems(string s);
    //remove item from user inventory, by name
    void removeItem(string s);
    //overloaded assignment operator
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
    void userPutItemInContainer(room & current, string itemName, string containerName); //used for put (item) in (container) commands
    void userAttackCreature(string creatureName, string itemName, room & current); //used for attack (creature) with (item) commands

private :
    room current;
    vector<item> inventory;
};


#endif // PLAYER_H
