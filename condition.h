#ifndef CONDITION_H
#define CONDITION_H

#include "xmlParser.h"
#include <iostream>
using namespace std;

class condition
{
public:
    condition();
    //constructor that takes information from XMLNode
    condition(XMLNode node);
    //accessor functions
    string getHas();
    string getObject();
    string getStatus();
    string getOwner();
    //checks if condition is fulfilled
    bool checkCondition();

private:
    string object;
    string status;
    string has;
    string owner;
};

#endif // CONDITION_H
