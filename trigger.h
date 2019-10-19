#ifndef TRIGGER_H
#define TRIGGER_H

#include "condition.h"
#include "item.h"
#include "xmlParser.h"
#include <iostream>
#include <map>
using namespace std;

class trigger
{
public:
    trigger();
    trigger(string s);
    trigger(XMLNode node);
    string getCommand();
    string getPrint();
    string getType();
    string getAction();
    void checkCondition();

private :
    string type;
    string command;
    string print;
    string action;
    bool activated;
    condition triggerCondition;

};

#endif
