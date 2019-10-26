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
    //"dummy" constructor used for returning null values
    trigger(string s);
    //constructor that takes information from XML file
    trigger(XMLNode node);
    //accessor functions
    string getCommand();
    string getPrint();
    string getType();
    string getAction();
    bool getActivated();
    condition getCondition();
    //executes the print information if all trigger conditions fulfilled
    void executePrint();
    //for one time use triggers, we update activated to be true. 
    void updateActivated();
    //overloaded assignment operator 
    trigger& operator=(const trigger & t);

private :
    string type;
    string command;
    string print;
    string action;
    //used to control one time use triggers
    bool activated;
    //stores condition information 
    condition triggerCondition;

};

#endif
