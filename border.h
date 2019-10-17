#ifndef BORDER_H
#define BORDER_H

#include <iostream>
#include "XMLParser.h"
using namespace std;

class border
{
public:
    border();
    border(XMLNode node);

private :
    string direction;
    string name;

};

#endif // BORDER_H
