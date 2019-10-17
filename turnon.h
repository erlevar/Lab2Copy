#ifndef TURNON_H
#define TURNON_H

#include "xmlParser.h"
#include <iostream>
using namespace std;


class turnon
{
public :
    turnon();
    turnon(XMLNode node);
    void readPrint();
    string getAction();

private:
    string print;
    string action;
};
#endif // TURNON_H
