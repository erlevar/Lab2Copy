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
    void getBorders(XMLNode node);
    void getContainers(XMLNode node);
    void getCreatures(XMLNode node);
    void getTriggers(XMLNode node);
    void getItems(XMLNode node);
    string getName();
    void readDescription();
    string checkBorders(string input);
    item checkItems(string input);
    trigger checkTriggers(string input)
    void removeItem(string itemName);
    void addItem(item newItem);

    //void getRoomTriggerCommands(vector<string> & commands);
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
