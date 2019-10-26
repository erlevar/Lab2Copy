#ifndef ITEM_H
#define ITEM_H

#include "turnon.h"
#include "xmlParser.h"
#include <iostream>
#include <vector>
#include "extraFunctions.h"
using namespace std;


class item
{
public:
    item();
    //"dummy" constructor, used to return null values
    item(string s);
    //constructor that takes an XMLnode to get information from XML file. 
    item(XMLNode node);
    //reads item name
    void readName();
    //mutator function for owner
    void updateOwner(string newOwner);
    //reads writing on item
    void readWriting();
    //activates turn on information for item
    void activateTurnon();
    //overloaded assignment operator
    item& operator=(const item& i);
    //accessor function s
    string getStatus();
    string getName();

private:
    string name;
    string writing;
    string status;
    string owner;
    bool on;
    //stores turn on information for item. 
    turnon itemTurnon;
};

#endif // ITEM_H
