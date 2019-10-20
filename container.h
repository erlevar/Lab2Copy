#ifndef CONTAINER_H
#define CONTAINER_H

#include "xmlParser.h"
#include "item.h"
#include "trigger.h"
#include "extraFunctions.h"
#include <vector>
using namespace std;


class container
{
public:
    container();
    container(string s);
    container(XMLNode node);
    void getTriggers(XMLNode node);
    void getItems(XMLNode node);
    string getName();
    void readItems();

private :
    string name;
    string status;
    string accept;
    vector<item> items;
    vector<trigger> triggers;

};

#endif
