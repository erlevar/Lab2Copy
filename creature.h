#ifndef CREATURE_H
#define CREATURE_H

#include "attack.h"
#include "trigger.h"
#include "xmlParser.h"

class creature
{
public :
    creature();
    creature(XMLNode node);
    void getAttack(XMLNode node);

private :
    string name;
    string vulnerability;
    attack creatureAttack;
    trigger creatureTrigger;

};
#endif
