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
#include "player.h"
#include <map>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

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
    room current;
    while (foundExit == false)
        {
        cout << "we are now fucking calling the assignment operator fuck jim skon " << endl;
        current = user.currentLocation();
        current.readDescription();
        cout << "At the onset, " << endl;
        current.readItems();
        current.readBorders();
        string userinput;
        getline(cin, userinput);
        vector<string> inputVect;
        separateWords(userinput, inputVect);
        vector<string> roomTriggerCommands;
        bool triggersPresent = false;
        current.getRoomTriggerCommands(roomTriggerCommands);

        for (int t = 0; t < roomTriggerCommands.size(); t++)
            {
            if (userinput == roomTriggerCommands[t])
                {
                triggersPresent = true;
                }
            }
        if (triggersPresent)
            {
                trigger commandTrigger = current.checkTriggersByCommand(userinput);
                condition triggerCondition = commandTrigger.getCondition();
                string has, object, owner;
                has = triggerCondition.getHas();
                object = triggerCondition.getObject();
                owner = triggerCondition.getOwner();
                if (has == "") //one kind of room trigger
                    {

                    }
                else if (has!= "") //other kind of room trigger. checks user inventory
                    {
                    if (has == "no")
                        {
                        if (owner == "inventory")
                            {
                            item returnItem = user.checkItems(object);
                            if (returnItem.getName() == "dummy")
                                {
                                commandTrigger.executePrint();
                                }
                            else
                                {
                                triggersPresent = false;
                                }
                            }
                        }
                    else
                        {
                        if (owner == "inventory")
                            {
                            item returnItem = user.checkItems(object);
                            if (returnItem.getName() == "dummy")
                                {
                                triggersPresent = false;
                                }
                            else
                                {
                                commandTrigger.executePrint();
                                }
                            }

                        }
                    }
            }

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
                        cout << "Can't go that way"<<endl;
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
                            cout << "current.readItems fuck jim skon"<<endl;
                            current.readItems();
                            vector<container> roomContainers;
                            current.getContainers(roomContainers);

                            bool itemPresent = false;
                            bool itemInRoom = false;
                            bool itemInContainer = false;
                            container presentContainer;
                            item presentItem;
                            for (int i =0; i < roomContainers.size(); i++)
                                {
                                vector<item> itemsInContainer;
                                roomContainers[i].getItems(itemsInContainer);

                                for (int j = 0; j < itemsInContainer.size(); j++)
                                    {
                                    if (itemsInContainer[j].getName() == passItemName)
                                        {
                                        itemInContainer = true;
                                        presentContainer = roomContainers[i];
                                        presentItem = itemsInContainer[j];
                                        break;
                                        }
                                    }
                                }

                            if (returnItem.getName() == passItemName)
                                {
                                itemInRoom = true;
                                }
                            cout << "returnItem.getName() is equal to FUCK C++ I HATE SKON SO FUCKING MUCH "  << returnItem.getName() << endl;
                            item checkInventory = user.checkItems(passItemName);
                            if (checkInventory.getName() == "dummy")
                                {
                                if ((itemInContainer == false) && (itemInRoom == false))
                                    {
                                    cout << "No such item to pick up" << endl;
                                    }
                                else if (itemInRoom == true)
                                    {
                                    cout << returnItem.getName() << " added to inventory " << endl;
                                    //cout << "Your current inventory is : " << endl;
                                    returnItem.updateOwner("inventory");
                                    current.removeItem(returnItem.getName());
                                    user.takeItem(returnItem);
                                    //user.readInventory();
                                    }
                                else if (itemInContainer == true)
                                    {
                                    cout << presentItem.getName() << " added to inventory " << endl;
                                    presentItem.updateOwner("inventory");
                                    presentContainer.removeItem(presentItem.getName());
                                    user.takeItem(presentItem);
                                    }
                               }
                            else
                                {
                                cout << "You already have that item " << endl;
                                }
                            }

                        else if (inputVect[0] == "read")
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

                        else if (inputVect[0] == "drop")
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
                                returnItem.updateOwner(current.getName());

                                current.addItem(returnItem);
                                cout << "After dropping the item, " <<endl;
                                current.readItems();
                                user.dropItem(returnItem.getName());
                                }

                            }
                        else if (inputVect[0] == "open")
                            {
                            string secondWord = inputVect[1];
                            if (secondWord == "exit")
                                {
                                string roomType = current.getRoomType();
                                if (roomType == "exit")
                                    {
                                    cout << "VICTORY!!!"<<endl;
                                    foundExit = true;
                                    }
                                else
                                    {
                                    cout << "You have not made it to the exit yet " << endl;
                                    }
                                }
                            else
                                {
                                container returnContainer = current.checkContainers(secondWord);
                                if (returnContainer.getName() == "dummy")
                                    {
                                    cout << "No such container in the room to open" << endl;
                                    }
                                else
                                    {
                                    cout << "You open the " << returnContainer.getName() <<endl;
                                    returnContainer.readItems();
                                    }
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
                                    cout << "You turn on the " << returnItem.getName() << endl;
                                    returnItem.activateTurnon();
                                    }
                                }
                        }
                }

        }
    return 0;
}






