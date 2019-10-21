#ifndef CONDITION_H
#define CONDITION_H

#include "xmlParser.h"
#include <iostream>
#include <map>
using namespace std;

class condition
{
public:
    condition();
    condition(XMLNode node);
    string getHas();
    string getObject();
    string getStatus();
    string getOwner();
    bool checkCondition();

private:
    string object;
    string status;
    string has;
    string owner;
};

#endif // CONDITION_H
