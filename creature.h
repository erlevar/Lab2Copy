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
    //"dummy" constructor, only used to return null values
    creature(string s);
    //constructor that takes information from XML node to initialize data members
    creature(XMLNode node);
    //accessor functions
    trigger getTrigger();
    string getName();
    attack getAttack();
    item getItem();
    //removes item from the creature (this will happen, for example, when the creature is attacked and killed)
    void removeItem();
    //change the creatureTrigger to newTrigger
    void updateTrigger(trigger newTrigger);
private :
    string name;
    string vulnerability;
    attack creatureAttack;
    trigger creatureTrigger;
    item creatureItem;

};
#endif
