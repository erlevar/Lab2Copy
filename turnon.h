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
    string action;
    string print;
};
#endif // TURNON_H
