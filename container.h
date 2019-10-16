#ifndef CONTAINER_H
#define CONTAINER_H

#include "xmlParser.h"
#include "item.h"
#include "trigger.h"
#include "extraFunctions.h"
#include <vector>


class container
{
public:
    container();
    container(XMLNode node);

private :
    string name;
    string status;
    string accept;
    vector<item> items;
    vector<trigger> triggers;

};

#endif
