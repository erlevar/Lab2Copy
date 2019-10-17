#ifndef ITEM_H
#define ITEM_H

#include "turnon.h"
#include "xmlParser.h"
#include <iostream>
using namespace std;


class item
{
public:
    item();
    item(string s);
    item(XMLNode node);
    void readName();
    string getName();
    void updateOwner(string newOwner);
    void readWriting();
    //void drop();
    //void take();
    //void read();
    //void turnOn();
    //void putInContainer(); //probably should pass the current owner and new owner (e.g. user to container)
private:
    string name;
    string writing;
    string status;
    string owner;
    turnon itemTurnon;
    //bool on;
    //trigger itemTrigger;
};

#endif // ITEM_H
