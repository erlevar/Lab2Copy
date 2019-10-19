#ifndef CONDITION_H
#define CONDITION_H

#include "xmlParser.h"
#include "item.h"
#include <iostream>
using namespace std;

class condition
{
public:
    condition();
    condition(XMLNode node, map<string, item> itemMap);

private:
    string object;
    string status;
    string has;
    string owner;
    item conditionItem;
};

#endif // CONDITION_H
