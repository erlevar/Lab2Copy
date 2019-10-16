#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "item.h"
#include "border.h"
#include "creature.h"
#include "container.h"
#include "trigger.h"
#include "xmlParser.h"

class room
{
public :
    room();
    room(XMLNode node);
    void getBorders(XMLNode node);
    void getContainers(XMLNode node);
    void getCreatures(XMLNode node);


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
