#include "item.h"

item::item()
{
    name, writing, status, owner = "";
}

item::item(string s)
{
    name = s;
    writing, status, owner="";
}

item::item(XMLNode node)
{
    name, writing, status, owner = "";

    XMLNode itemNameNode = node.getChildNode("name");
    if (!itemNameNode.isEmpty())
        {
        name = itemNameNode.getText();
        }

    XMLNode itemWritingNode = node.getChildNode("writing");
    if(!itemWritingNode.isEmpty())
        {
        writing = itemWritingNode.getText();
        }

    XMLNode itemStatusNode = node.getChildNode("status");
    if (!itemStatusNode.isEmpty())
        {
        status = itemStatusNode.getText();
        }

    cout << "(item information)" << endl;
    cout << "Item name : " << name<< endl;
    cout << "Item writing : " << writing << endl;
    cout << "Item status : " << status  << endl;
    cout << "Item owner : " << owner << endl;

    //turnon information for the item
    XMLNode turnonNode = node.getChildNode("turnon");
    turnon tempTurnon(turnonNode);
    itemTurnon = tempTurnon;
}

void item::readName()
{
    cout << "Name of item : " << name << endl;
}

string item::getName()
{
    return name;
}

void item::updateOwner(string newOwner)
{
    owner = newOwner;
}
