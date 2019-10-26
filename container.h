#ifndef CONTAINER_H
#define CONTAINER_H

#include "xmlParser.h"
#include "item.h"
#include "trigger.h"
#include "extraFunctions.h"
#include <vector>
#include <iterator>
using namespace std;


class container
{
public:
    container();
    //"dummy" constructor. used to return null values essentially
    container(string s);
    //constructor that takes infromation from an XML node
    container(XMLNode node);
    //mutator functions to set triggers and items contained in a container. Takes an XMLNode to get info from XML file. 
    void setTriggers(XMLNode node);
    void setItems(XMLNode node);
    //accessors
    string getName();
    string getStatus();
    void getItems(vector<item> & returnItems);
    void getContainerTriggerComands(vector<string> & commands);
    //this is used to get the triggers that have no command to prompt them. certain triggers are prompted by commands
    //whereas other triggers are prompted by the status of the inventory of the container.
    trigger getTriggerWithoutCommand();
    void readItems();
    //overloaded assignment operator. This makes sure all the stuff in the vectors below is properly copied over. 
    container& operator = (const container& c);
    //check items in the container based on item name
    item checkItems(string input);
    //remove item by name
    void removeItem(string itemName);
    void removeTriggerWithoutCommand();
    //adds a new item or trigger to 
    void addItem(item newItem);
    void addTrigger(trigger newTrigger);
    //returns a trigger based on the command , (input). 
    trigger checkTriggersByCommand(string input);
    //updates status for a trigger
    void updateTrigger(trigger newTrigger);
    //update status of the container
    void updateStatus(string newStatus);

private :
    string name;
    string status;
    string accept;
    //items and triggers stored in vectors because there can be many. 
    vector<item> items;
    vector<trigger> triggers;

};

#endif
