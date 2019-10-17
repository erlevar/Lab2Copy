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

string room::readDescription()
{
    cout << description << endl;
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

