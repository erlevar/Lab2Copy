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

//This is just Erin adding a comment
//Don't mind me

using namespace std;

//this function will activate all creature triggers that are based on the status of the user's inventory
//e.g. if the user has a flashlight that is turned on, they will see a certain creature as a result if that
//creature has such a trigger
void activateCreatureTriggers(room & current, player user);
//this function will activate all container triggers that are based on the status of the container.
//e.g. if the we have a container called "lock" that is locked we will activate a trigger that can say 
//"lock needs a key"
//once we give the lock the key then we will print "lock drops off" for example.
void activateContainerTriggers(room & current, player user);
//checks to see if there are any triggers present in the room. this is for the triggers activated by a user command. 
//return true if the user's input will activate a command
bool triggersInRoom(room current, string userinput);
//this does the same thing as above but for containers. 
bool triggersInContainers(room current, string userinput, container & triggerPresentContainer);
//both of these activate functions will activate room triggers and container triggers that are activated by user input commands. 
void activateRoomCommandTriggers(room current, string userinput, player user, bool & triggersPresentInContainers, bool & triggersPresentInRoom);
void activateContainerCommandTriggers(container triggerPresentContainer, string userinput, bool & triggersPresentInContainers, bool & triggersPresentInRoom);


int main (int argc, char ** argv) {

    string gameFile = "fullGame.xml";

    // this opens and parses the correct XML file:
    XMLNode xMainNode=XMLNode::openFileHelper(gameFile.c_str(),"map");
    int i = 0;
    // get the first room node
    XMLNode roomNode=xMainNode.getChildNode(i++);
    //make a room map indexed by room name. 
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
    //play the game!
    while (foundExit == false)
        {
        bool changedRooms = false;
        //reads current room information.
        room current = user.currentLocation();
        current.readDescription();
        //activates all creature and container triggers that aren't activated by user commands. 
        activateCreatureTriggers(current, user);
        activateContainerTriggers(current, user);
        //takes user input and separates words. 
        string userinput;
        getline(cin, userinput);
        vector<string> inputVect;
        separateWords(userinput, inputVect);


        //all this is to activate triggers that occur because of user commands.
        //for the room, we check if the user has a certain item or not
        //for the containers, we check the status of said container (e.g. locks on a door or whatnot)
        bool triggersPresentInRoom = triggersInRoom(current, userinput);
        container triggerPresentContainer;
        bool triggersPresentInContainers = triggersInContainers(current, userinput, triggerPresentContainer);

        if ((triggersPresentInRoom) && !(triggersPresentInContainers))
            {
            activateRoomCommandTriggers(current, userinput, user, triggersPresentInContainers, triggersPresentInRoom);
            }

        else if ((triggersPresentInContainers) && !(triggersPresentInRoom))
            {
            activateContainerCommandTriggers(triggerPresentContainer, userinput, triggersPresentInContainers, triggersPresentInRoom);
            }
        

        if (!(triggersPresentInContainers) && !(triggersPresentInRoom))
            {
                if (inputVect.size() == 1)
                {
                    userinput = inputVect[0];
                    //this allows the user to move to north, south, east, west if such a border exists. 
                    if ((userinput == "n") || (userinput == "s") || (userinput == "e") || (userinput == "w")) //change user's current location to n, s ,e, w if there are rooms in those directions
                        {
                        user.moveToBorder(roomMap, changedRooms, userinput);
                        }
                    //reads user inventory 
                    else if (userinput == "i")
                        {
                        user.readInventory();
                        }
                    //lets the user quit
                    else if (userinput == "quit")
                        {
                        foundExit = true;
                        }
                    //invalid input
                    else
                        {
                        cout << "Invalid input " << endl;
                        }
                }
                else if (inputVect.size() == 2)
                    {
                        //allows a user to take item, if the item is there. 
                        if (inputVect[0] == "take") 
                            {
                            string passItemName = inputVect[1];
                            user.userTakeItem(current, passItemName);
                            }
                        //allows a user to read an item's reading, if they have it in inventory
                        else if (inputVect[0] == "read") 
                            {
                            string passItemName = inputVect[1];
                            user.userReadItem(passItemName);
                            }
                        //user drops an item into the room, if they have such an item
                        else if (inputVect[0] == "drop") 
                            {
                            string dropItemName = inputVect[1];
                            user.userDropItem(current, dropItemName);
                            }
                        //user opens an exit or a container, if either of those things apply. 
                        else if (inputVect[0] == "open")
                            {
                            string secondWord = inputVect[1];
                            if (secondWord == "exit")
                                {
                                user.isAtExit (foundExit); //terminates the game if the user has made it to the exit
                                }
                            else
                                {
                                user.userOpenContainer(secondWord); //user opens a container, if the container is present in the room
                                }
                            }
                        //invalid input
                        else
                            {
                            cout << "Invalid input " <<endl;
                            }
                    }
                    else if (inputVect.size() == 3)
                        {
                            if ((inputVect[0] == "turn") && (inputVect[1] == "on")) //user turns on an item, if they have such an item in inventory
                                {
                                string turnonItem = inputVect[2];
                                user.userTurnonItem(turnonItem);
                                }
                            //invalid item
                            else
                                {
                                cout << "Invalid input " << endl;
                                }
                        }
                    else if (inputVect.size() == 4)
                        {
                            //user puts an item in a container, if the container exists and they have the item in inventory
                            if ((inputVect[0] == "put") && (inputVect[2] == "in"))
                                {
                                string itemName = inputVect[1];
                                string containerName = inputVect[3];
                                user.userPutItemInContainer(current, itemName, containerName);
                                }
                            //user attacks a creature with a specific item, if they have that item and if the creature exists. 
                            else if ((inputVect[0] == "attack") && (inputVect[2] == "with"))
                                {
                                string creatureName = inputVect[1];
                                string itemName = inputVect[3];
                                user.userAttackCreature(creatureName, itemName, current);
                                }
                            else
                                {
                                cout << "Invalid input " << endl;
                                }
                        }
                    else
                        {
                        cout << "Invalid input " << endl;
                        }
                }
        if (changedRooms == false)
            {
            user.updateLocation(current);
            }
        }
    return 0;
}


void activateCreatureTriggers(room & current, player user)
{
    vector<creature> roomCreatures;
    current.getCreatures(roomCreatures);
    for (int i = 0; i < roomCreatures.size(); i++)
        {
            trigger creatureTrigger = roomCreatures[i].getTrigger();
            if (creatureTrigger.getActivated() == false)
                {
                condition creatureTriggerCondition = creatureTrigger.getCondition();
                string object, status, owner;
                object = creatureTriggerCondition.getObject();
                status = creatureTriggerCondition.getStatus();
                owner = creatureTriggerCondition.getOwner();
                if (owner == "inventory")
                    {
                        item returnItem = user.checkItems(object);
                        if (returnItem.getName() == object)
                            {
                            if (returnItem.getStatus() == status)
                                {
                                creatureTrigger.executePrint();
                                creatureTrigger.updateActivated();
                                roomCreatures[i].updateTrigger(creatureTrigger);
                                }
                            }
                    }
                current.removeCreature(roomCreatures[i].getName());
                current.addCreature(roomCreatures[i]);
                }
        }
}

void activateContainerTriggers(room & current, player user)
{
    vector<container> roomContainers;
    current.getContainers(roomContainers);
    for (int i = 0; i < roomContainers.size(); i++)
        {
            trigger containerTrigger = roomContainers[i].getTriggerWithoutCommand();
            if (containerTrigger.getActivated() == false)
                {
                condition containerTriggerCondition = containerTrigger.getCondition();
                string object, status, owner, has;
                object = containerTriggerCondition.getObject();
                status = containerTriggerCondition.getStatus();
                owner = containerTriggerCondition.getOwner();
                has = containerTriggerCondition.getHas();
                if (has == "yes")
                    {
                    if (owner == roomContainers[i].getName())
                        {
                        item returnItem = roomContainers[i].checkItems(object);
                        if (returnItem.getName() == object)
                            {
                            containerTrigger.executePrint();
                            containerTrigger.updateActivated();
                            roomContainers[i].removeTriggerWithoutCommand();
                            roomContainers[i].addTrigger(containerTrigger);
                            string action = containerTrigger.getAction();
                            vector<string> actionVect;
                            separateWords(action, actionVect);
                            roomContainers[i].updateStatus(actionVect[actionVect.size()-1]);
                            }
                        }
                    }
                current.removeContainer(roomContainers[i].getName());
                current.addContainer(roomContainers[i]);
                }
        }
}

bool triggersInRoom(room current, string userinput)
{
    vector<string> roomTriggerCommands;
    current.getRoomTriggerCommands(roomTriggerCommands);
    for (int t = 0; t < roomTriggerCommands.size(); t++)
        {
        if (userinput == roomTriggerCommands[t])
            {
            return true;
            }
        }
    return false;
}

bool triggersInContainers(room current, string userinput, container & triggerPresentContainer)
{
    vector<container> roomContainers;
    current.getContainers(roomContainers);
    vector<string> containerTriggerCommands;
    for (int t = 0; t < roomContainers.size(); t++)
        {
            containerTriggerCommands.clear();
            roomContainers[t].getContainerTriggerComands(containerTriggerCommands);
            for (int j = 0; j<containerTriggerCommands.size(); j++)
                {
                    if(userinput == containerTriggerCommands[j])
                        {
                        triggerPresentContainer = roomContainers[t];
                        return true;
                        }
                }
        }
    return false;

}

void activateRoomCommandTriggers(room current, string userinput, player user, bool & triggersPresentInContainers, bool & triggersPresentInRoom)
{
    trigger commandTrigger = current.checkTriggersByCommand(userinput);
    condition triggerCondition = commandTrigger.getCondition();
    string has, object, owner;
    has = triggerCondition.getHas();
    object = triggerCondition.getObject();
    owner = triggerCondition.getOwner();
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
                triggersPresentInContainers = false;
                triggersPresentInRoom = false;
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
                triggersPresentInContainers = false;
                triggersPresentInRoom = false;
                }
            else
                {
                commandTrigger.executePrint();
                }
            }
        }
}

void activateContainerCommandTriggers(container triggerPresentContainer, string userinput, bool & triggersPresentInContainers, bool & triggersPresentInRoom)
{
    trigger commandTrigger = triggerPresentContainer.checkTriggersByCommand(userinput);
    condition triggerCondition = commandTrigger.getCondition();
    string status = triggerCondition.getStatus();
    if (triggerPresentContainer.getStatus() == status)
        {
        commandTrigger.executePrint();

        }
    else
        {
        triggersPresentInContainers = false;
        triggersPresentInRoom = false;
        }
}
