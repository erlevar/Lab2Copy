#ifndef TRIGGER_H
#define TRIGGER_H

#include "condition.h"
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
    condition getCondition();
    void executePrint();
    bool getActivated();
    void updateActivated();
    trigger& operator(const trigger & t);

private :
    string type;
    string command;
    string print;
    string action;
    bool activated;
    condition triggerCondition;

};

#endif
