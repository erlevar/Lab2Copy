#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "xmlParser.h"
#include "item.h"
#include "border.h"
#include "container.h"
#include "trigger.h"
#include "creature.h"
#include "turnon.h"
#include <iostream>
#include <iterator>
#include <map>
using namespace std;


class room
{
public :
    room();
    //initializes room based on information from XML file. 
    room(XMLNode node);
    //set room's borders
    void setBorders(XMLNode node);
    //set room's containers
    void setContainers(XMLNode node);
    //sets room's creatures
    void setCreatures(XMLNode node);
    //sets room's triggers
    void setTriggers(XMLNode node);
    //sets room's items
    void setItems(XMLNode node);
    //accessor for room's name
    string getName();
    //reads description of the room. this happens after every command is input by the user. 
    void readDescription();
    //checks borders based on border name. all of these check functions will return name = "dummy" if no such thing is present.
    string checkBorders(string input);
    //checks items based on item name. 
    item checkItems(string input);
    //checks containers based on container name
    container checkContainers(string input);
    //checks triggers based on the input command 
    trigger checkTriggersByCommand(string input);
    //checks creatures based on creature name
    creature checkCreatures(string input);
    //remove things from the room based on their name
    void removeItem(string itemName);
    void removeContainer(string containerName);
    void removeCreature(string creatureName);
    //add item to the room
    void addItem(item newItem);
    //add container to the room
    void addContainer(container newContainer);
    //add creature to the room
    void addCreature(creature newCreature);
    //gets the commands for every trigger in the room
    void getRoomTriggerCommands(vector<string> & commands);
    string getRoomType();
    void readItems();
    //overloaded assignment operator
    room& operator = (const room & r);
    void readBorders();
    //accessors for containers and creatures
    void getContainers(vector<container> & returnContainers);
    void getCreatures(vector<creature> & returnCreatures);

private :
    string name;
    string description;
    string type;
    //all these things stored in vectors so that we can have many of them.
    vector<item> items;
    vector<trigger> triggers;
    vector<border> borders;
    vector<container> containers;
    vector<creature> creatures;
};

#endif
