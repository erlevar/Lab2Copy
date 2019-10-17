#ifndef CONDITION_H
#define CONDITION_H

#include "xmlParser.h"
#include <iostream>
using namespace std;

class condition
{
public:
    condition();
    condition(XMLNode node);

private:
    string object;
    string status;
    string has;
    string owner;
};

#endif // CONDITION_H
