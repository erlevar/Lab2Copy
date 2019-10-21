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
    setItems(node);
    for (int i = 0; i < items.size(); i++)
        {
        items[i].updateOwner(name);
        //itemMap[items[i].getName()] = items[i];
        }
    setTriggers(node);
    setBorders(node);
    setContainers(node);
    setCreatures(node);

}

void room::setBorders (XMLNode node)
{
    int numberBorders = node.nChildNode("border");
    for (int nBorders = 0; nBorders < numberBorders; nBorders++)
        {
            XMLNode borderNode = node.getChildNode("border", nBorders);
            border newBorder(borderNode);
            borders.push_back(newBorder);
        }
}


void room::setContainers(XMLNode node)
{
    int numberContainers = node.nChildNode("container");
    for (int nContainers = 0; nContainers < numberContainers; nContainers++)
        {
        XMLNode containerNode = node.getChildNode("container", nContainers);
        container newContainer(containerNode);
        containers.push_back(newContainer);
        }
}


void room::setCreatures(XMLNode node)
{
    int numberCreatures = node.nChildNode("creature");
    for (int nCreatures = 0; nCreatures < numberCreatures; nCreatures++)
        {
        XMLNode creatureNode = node.getChildNode("creature", nCreatures);
        creature newCreature(creatureNode);
        creatures.push_back(newCreature);
        }
}

void room::setTriggers(XMLNode node)
{
    int numberTriggers = node.nChildNode("trigger");
    for (int nTriggers = 0; nTriggers < numberTriggers; nTriggers++)
        {
            XMLNode triggerNode=node.getChildNode("trigger", nTriggers);
            trigger newTrigger(triggerNode);
            triggers.push_back(newTrigger);
        }
}


void room::setItems(XMLNode node)
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
    vector<item>::iterator iter;
    for(iter = items.begin(); iter != items.end(); ++iter )
    {
        if((*iter).getName() == itemName)
        {
            items.erase(iter);
            break;
        }
    }
}

void room::removeContainer(string containerName)
{
    vector<container>::iterator iter;
    for (iter = containers.begin(); iter!= containers.end(); ++iter)
        {
        if ((*iter).getName() == containerName)
            {
                containers.erase(iter);
                break;
            }
        }
}


void room::addItem(item newItem)
{
    items.push_back(newItem);
}

void room::addContainer(container newContainer)
{
    containers.push_back(newContainer);
}


void room::getRoomTriggerCommands(vector<string> & commands)
{
    for (int i = 0; i < triggers.size(); i++)
        {
        //if (triggers[i].getCommand() != "")
            //{
            commands.push_back(triggers[i].getCommand());
            //}
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


room& room::operator=(const room& r)
{
    name = r.name;
    type = r.type;
    description = r.description;
    items.clear();
    triggers.clear();
    borders.clear();
    creatures.clear();
    containers.clear();
    for (int i = 0; i < r.items.size(); i++)
        {
        items.push_back(r.items[i]);
        }
    for (int i = 0; i < r.triggers.size(); i++)
        {
        triggers.push_back(r.triggers[i]);
        }
    for (int i = 0; i < r.borders.size(); i++)
        {
        borders.push_back(r.borders[i]);
        }
    for (int i = 0; i < r.creatures.size(); i++)
        {
        creatures.push_back(r.creatures[i]);
        }
    for (int i = 0; i < r.containers.size(); i++)
        {
        containers.push_back(r.containers[i]);
        }
    return *this;
}

void room::readBorders()
{
    for (int i = 0; i<borders.size(); i++)
        {
            cout << "Border.name " << borders[i].getName() << endl;
            cout << "Border.direction " << borders[i].getDirection() << endl;
        }
}

void room::getContainers(vector<container> & returnContainers)
{
    for (int i = 0; i<containers.size(); i++)
        {
        returnContainers.push_back(containers[i]);
        }
    return;
}
