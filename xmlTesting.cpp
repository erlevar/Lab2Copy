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
                    foundExit == true;
                    }
            }
        else if (inputVect.size() == 2)
            {
                if (inputVect[0] == "take")
                    {
                    string passItemName = inputVect[1];
                    item returnItem = current.checkItems(passItemName);
                    if (returnItem.getName() == "dummy")
                        {
                        cout << "No such item in the room " << endl;
                        }
                    else
                        {
                        cout << "You picked up the " << returnItem.getName() << endl;
                        cout << "Your current inventory is : " << endl;
                        returnItem.updateOwner("inventory");
                        user.takeItem(returnItem);
                        user.readInventory();
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



