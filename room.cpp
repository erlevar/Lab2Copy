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

    getItems(node, items);
    for (int i = 0; i < items.size(); i++)
        {
        items[i].updateOwner(name);
        }
    getTriggers(node, triggers);
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

void room::removeItem(string itemName)
{
    //vector<item> newItems;
    //string removeName = r.getName();
    //for (int i = 0; i <)
    std::vector<item>::iterator iter;
    for(iter = items.begin(); iter != items.end(); ++iter )
    {
        if((*iter).getName() == itemName)
        {
            items.erase(iter);
            cout << "Removing item from room with name " << itemName;
            break;
        }
}


}

