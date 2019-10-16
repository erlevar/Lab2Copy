#ifndef ATTACK_H
#define ATTACK_H

#include "xmlParser.h"
#include "condition.h"
#include <vector>


class attack
{
public:
    attack();
    attack(XMLNode node);

private:
    condition attackCondition;
    string print;
    vector<string> actions;

};

#endif