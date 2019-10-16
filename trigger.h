#ifndef TRIGGER_H
#define TRIGGER_H

#include "condition.h"
#include "xmlParser.h"
using namespace std;

class trigger
{
public:
    trigger();
    trigger(XMLNode node);

private :
    string type;
    string command;
    string print;
    string action;
    condition triggerCondition;

};

#endif
