#include "room.h"

room::room()
{
    name, description, type = "";
}

room::room(XMLNode node)
{
    name, description, type = "";
    //room information
    //room type
    XMLNode roomTypeNode = node.getChildNode("type");
    if (!roomTypeNode.isEmpty())
        {
        type = roomTypeNode.getText();
        }

    // Get the room name
    XMLNode nameNode = node.getChildNode("name");
    if (!nameNode.isEmpty())
        {
        name = nameNode.getText();
        }

    //Get the room description
    XMLNode descriptionNode = node.getChildNode("description");
    if (!descriptionNode.isEmpty())
        {
        description = descriptionNode.getText();
        }

    cout << "(room information)" << endl;
    cout << "Name of the room is : " << name << endl;
    cout << "Description of the room is : " << description << endl;
    cout << "Type of the room is : " <<  type << endl;

    getItems(node);
    for (int i = 0; i < items.size(); i++)
        {
        items[i].updateOwner(name);
        //itemMap[items[i].getName()] = items[i];
        }
    getTriggers(node);
    getBorders(node);
    getContainers(node);
    getCreatures(node);

}

void room::getBorders (XMLNode node)
{
    int numberBorders = node.nChildNode("border");
    for (int nBorders = 0; nBorders < numberBorders; nBorders++)
        {
            XMLNode borderNode = node.getChildNode("border", nBorders);
            border newBorder(borderNode);
            borders.push_back(newBorder);
        }
}


void room::getContainers(XMLNode node)
{
    int numberContainers = node.nChildNode("container");
    for (int nContainers = 0; nContainers < numberContainers; nContainers++)
        {
        XMLNode containerNode = node.getChildNode("container", nContainers);
        container newContainer(containerNode);
        containers.push_back(newContainer);
        }
}


void room::getCreatures(XMLNode node)
{
    int numberCreatures = node.nChildNode("creature");
    for (int nCreatures = 0; nCreatures < numberCreatures; nCreatures++)
        {
        XMLNode creatureNode = node.getChildNode("creature", nCreatures);
        creature newCreature(creatureNode);
        creatures.push_back(newCreature);
        }
}

void room::getTriggers(XMLNode node)
{
    int numberTriggers = node.nChildNode("trigger");
    for (int nTriggers = 0; nTriggers < numberTriggers; nTriggers++)
        {
            XMLNode triggerNode=node.getChildNode("trigger", nTriggers);
            trigger newTrigger(triggerNode);
            triggers.push_back(newTrigger);
        }
}


void room::getItems(XMLNode node)
{
    int numberItems = node.nChildNode("item");
    for (int nItems = 0; nItems < numberItems; nItems++)
        {
        XMLNode itemNode = node.getChildNode("item", nItems);
        item newItem(itemNode);
        items.push_back(newItem);
        }
}

string room::getName()
{
    return name;
}

void room::readDescription()
{
    cout << description << endl;
    return;
}

string room::checkBorders(string input)
{
    for (int i = 0; i<borders.size(); i++)
        {
        string direction = borders[i].getDirection();
        if (input == direction)
            {
            return borders[i].getName();
            }
        }
    string noBorder = "dummy";
    return noBorder;
}

item room::checkItems(string input)
{
    for (int i = 0; i<items.size(); i++)
        {
        string itemName = items[i].getName();
        cout << "itemName is : " << itemName << endl;
        if (input == itemName)
            {
            return items[i];
            }
        }
    string dummy = "dummy";
    item emptyItem(dummy);
    return emptyItem;
}

container room::checkContainers(string input)
{
    for (int i = 0; i < containers.size(); i++)
        {
        string containerName = containers[i].getName();
        if (input == containerName)
            {
            return containers[i];
            }
        }
    string dummy = "dummy";
    container emptyContainer(dummy);
    return emptyContainer;
}

trigger room::checkTriggersByCommand(string input)
{
    for (int i = 0; i<triggers.size(); i++)
        {
        string triggerName = triggers[i].getCommand();
        if (input == triggerName)
            {
            return triggers[i];
            }
        }
    string dummy = "dummy";
    trigger emptyTrigger(dummy);
    return emptyTrigger;
}


void room::removeItem(string itemName)
{
    std::vector<item>::iterator iter;
    for(iter = items.begin(); iter != items.end(); ++iter )
    {
        if((*iter).getName() == itemName)
        {
            items.erase(iter);
            break;
        }
    }
}

void room::addItem(item newItem)
{
    items.push_back(newItem);
    cout << "adding item with name " << newItem.getName() << "to the room"<<endl;
    cout << "items.size() after adding item " << items.size() << endl;
}


void room::getRoomTriggerCommands(vector<string> & commands)
{
    for (int i = 0; i < triggers.size(); i++)
        {
        commands.push_back(triggers[i].getCommand());
        }
}

string room::getRoomType()
{
    return type;
}

void room::readItems()
{
    cout << "Names of items in the room : " << endl;
    for (int i = 0; i<items.size(); i++)
        {
            cout << items[i].getName() << endl;
        }
}
