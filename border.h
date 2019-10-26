#ifndef BORDER_H
#define BORDER_H

#include <iostream>
#include "xmlParser.h"
using namespace std;

class border
{
public:
    border();
    //constructor that takes information from XMLNode
    border(XMLNode node);
    //accessor functions
    string getDirection();
    string getName();

private :
    string direction;
    string name;

};

#endif // BORDER_H
