#ifndef CREATURE_H
#define CREATURE_H

#include "attack.h"
#include "trigger.h"
#include "item.h"
#include "xmlParser.h"
using namespace std;


class creature
{
public :
    creature();
    creature(string s);
    creature(XMLNode node);
    trigger getTrigger();
    string getName();
    attack getAttack();
    item getItem();
    void removeItem();
    void updateTrigger(trigger newTrigger);
private :
    string name;
    string vulnerability;
    attack creatureAttack;
    trigger creatureTrigger;
    item creatureItem;

};
#endif
