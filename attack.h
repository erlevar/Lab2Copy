#ifndef ATTACK_H
#define ATTACK_H

#include "xmlParser.h"
#include "condition.h"
#include <vector>


class attack
{
public:
    attack();
    //initializer reads from XMLNode
    attack(XMLNode node);
    //accessors
    condition getCondition();
    string getAction();
    void executePrint();


private:
    condition attackCondition;
    string print;
    vector<string> actions;

};

#endif
