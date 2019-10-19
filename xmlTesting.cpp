#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#define XML_USE_STL
#include "xmlParser.h"
#include "room.h"
#include "creature.h"
#include "attack.h"
#include "container.h"
#include "border.h"
#include "item.h"
#include "trigger.h"
#include "turnon.h"
#include "condition.h"
#include <map>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;


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



int main (int argc, char ** argv) {

    string gameFile = "testGame.xml";

    // this opens and parses the correct XML file:
    XMLNode xMainNode=XMLNode::openFileHelper(gameFile.c_str(),"map");
    int i = 0;
    // get the first room node
    XMLNode roomNode=xMainNode.getChildNode(i++);
    map<string, room> roomMap;

    do {

    //make map of rooms indexed by room name
    room newRoom(roomNode);
    string roomName = newRoom.getName();
    roomMap[roomName] = newRoom;
    roomNode=xMainNode.getChildNode(i++);
    } while (!roomNode.isEmpty());

    room entrance = roomMap["Entrance"];
    player user(entrance);
    bool foundExit = false;
    while (foundExit == false)
        {
        room current = user.currentLocation();
        current.readDescription();
        string userinput;
        getline(cin, userinput);
        vector<string> inputVect;
        separateWords(userinput, inputVect);

        vector<string> roomTriggerCommands;
        bool triggersPresent = false;
        //current.getRoomTriggerCommands(roomTriggerCommands);
        /*
        for (int t = 0; k < roomTriggerCommands.size(); k++)
            {
            if (userinput == roomTriggerCommands[t])
                {
                triggersPresent = true;
                }
            }
        if (triggersPresent)
            {
            current.activateTrigger(userinput);
            }
        */
        if (triggersPresent == false)
            {
                if (inputVect.size() == 1)
                {
                    userinput = inputVect[0];
                    if ((userinput == "n") || (userinput == "s") || (userinput == "e") || (userinput == "w"))
                    {
                    string passDirection;
                    if (userinput == "n")
                        {
                        passDirection = "north";
                        }
                    else if (userinput == "s")
                        {
                        passDirection = "south";
                        }
                    else if (userinput == "e")
                        {
                        passDirection = "east";
                        }
                    else if (userinput == "w")
                        {
                        passDirection = "west";
                        }
                    string returnRoomName = current.checkBorders(passDirection);
                    if (returnRoomName == "dummy")
                        {
                        cout << "No room to that direction"<<endl;
                        }
                    else
                        {
                        cout << "The name of the room to that direction is " << returnRoomName << endl;
                        cout << "You enter this room" << endl;
                        room newLocation = roomMap[returnRoomName];
                        user.updateLocation(newLocation);
                        }
                    }

                    else if (userinput == "i")
                        {
                        user.readInventory();

                        }
                    else if (userinput == "quit")
                        {
                        foundExit = true;
                        }
                }
                else if (inputVect.size() == 2)
                    {
                        if (inputVect[0] == "take")
                            {
                            string passItemName = inputVect[1];
                            item returnItem = current.checkItems(passItemName);
                            item checkInventory = user.checkItems(passItemName);
                            if (checkInventory.getName() == "dummy")
                                {
                                if (returnItem.getName() == "dummy")
                                    {
                                    cout << "No such item in the room " << endl;
                                    }
                                else
                                    {
                                    cout << "You picked up the " << returnItem.getName() << endl;
                                    cout << "Your current inventory is : " << endl;
                                    returnItem.updateOwner("inventory");
                                    current.removeItem(returnItem.getName());
                                    user.takeItem(returnItem);
                                    user.readInventory();
                                    }
                               }
                            else
                                {
                                cout << "You already have that item " << endl;
                                }
                            }

                        if (inputVect[0] == "read")
                            {
                            string passItemName = inputVect[1];
                            item returnItem = user.checkItems(passItemName);
                            if (returnItem.getName() == "dummy")
                                {
                                cout << "No such item in your inventory to be read " << endl;
                                }
                            else
                                {
                                returnItem.readWriting();
                                }
                            }

                        if (inputVect[0] == "drop")
                            {
                            string dropItemName = inputVect[1];
                            item returnItem = user.checkItems(dropItemName);
                            if (returnItem.getName() == "dummy")
                                {
                                cout << "No such item in your inventory to drop" << endl;
                                }
                            else
                                {
                                cout << "You dropped the " << returnItem.getName() << endl;
                                cout << "Your current inventory is : "<< endl;
                                returnItem.updateOwner(current.getName());
                                current.addItem(returnItem);
                                user.dropItem(returnItem.getName());
                                user.readInventory();
                                }

                            }
                        }
                    else if (inputVect.size() == 3)
                        {
                            if ((inputVect[0] == "turn") && (inputVect[1] == "on"))
                                {
                                string turnonItem = inputVect[2];
                                item returnItem = user.checkItems(turnonItem);
                                if (returnItem.getName() == "dummy")
                                    {
                                    cout << "No such item in your inventory to turn on " << endl;
                                    }
                                else
                                    {
                                    returnItem.activateTurnon();
                                    }
                                }
                        }
                }




        }
    return 0;
}


player::player(room startLocation)
{
    current = startLocation;
}

room player::currentLocation()
{
    return current;
}

void player::updateLocation(room newLocation)
{
    current = newLocation;
}

void player::readInventory()
{
    if (inventory.size() == 0)
        {
        cout << "No items in inventory" << endl;
        return;
        }
    for (int i = 0; i < inventory.size(); i ++)
        {
        inventory[i].readName();
        return;
        }
}

void player::takeItem(item newItem)
{
    inventory.push_back(newItem);
}

item player::checkItems(string input)
{
    for (int i = 0; i<inventory.size(); i++)
        {
        string itemName = inventory[i].getName();
        if (input == itemName)
            {
            return inventory[i];
            }
        }
    string dummy = "dummy";
    item emptyItem(dummy);
    return emptyItem;
}

void player::dropItem(string itemName)
{
    std::vector<item>::iterator iter;
    for(iter = inventory.begin(); iter != inventory.end(); ++iter )
    {
        if((*iter).getName() == itemName)
        {
            inventory.erase(iter);
            break;
        }
    }
}



