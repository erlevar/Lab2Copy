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
    room(XMLNode node);
    void setBorders(XMLNode node);
    void setContainers(XMLNode node);
    void setCreatures(XMLNode node);
    void setTriggers(XMLNode node);
    void setItems(XMLNode node);
    string getName();
    void readDescription();
    string checkBorders(string input);
    item checkItems(string input);
    container checkContainers(string input);
    trigger checkTriggersByCommand(string input);
    creature checkCreatures(string input);
    void removeItem(string itemName);
    void removeContainer(string containerName);
    void removeCreature(string creatureName);
    void addItem(item newItem);
    void addContainer(container newContainer);
    void addCreature(creature newCreature);
    void getRoomTriggerCommands(vector<string> & commands);
    string getRoomType();
    void readItems();
    room& operator = (const room & r);
    void readBorders();
    void getContainers(vector<container> & returnContainers);
    void getCreatures(vector<creature> & returnCreatures);
    //void checkTriggerConditionss(string command);




private :
    string name;
    string description;
    string type;
    vector<item> items;
    vector<trigger> triggers;
    vector<border> borders;
    vector<container> containers;
    vector<creature> creatures;
};

#endif
