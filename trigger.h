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
    std::string getCommand();
    std::string getPrint();
    std::string getType();
    std::string getAction();
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
