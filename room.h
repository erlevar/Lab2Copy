#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "xmlParser.h"
#include "item.h"
#include "border.h"
#include "container.h"
#include "trigger.h"
#include "creature.h"
using namespace std;


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
