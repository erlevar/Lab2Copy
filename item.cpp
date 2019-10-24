#include "item.h"

item::item()
{
    name, writing, status, owner = "";
    on = false;
}

item::item(string s)
{
    name = s;
    writing, status, owner="";
    on = false;
}

item::item(XMLNode node)
{
    name, writing, status, owner = "";
    on = false;

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

    //turnon information for the item
    XMLNode turnonNode = node.getChildNode("turnon");
    if (!turnonNode.isEmpty())
        {
        turnon tempTurnon(turnonNode);
        itemTurnon = tempTurnon;
        }

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

void item::readWriting()
{
    if (writing == "")
        {
        cout << "Nothing written" << endl;
        return;
        }
    cout << "Writing on the item : " << writing << endl;
}

void item::activateTurnon()
{
    if (on == false)
        {
        string action;
        action = itemTurnon.getAction();
        if (action != "")
            {
            itemTurnon.readPrint();
            vector<string> actionVect;
            separateWords(action, actionVect);
            status = actionVect[actionVect.size() - 1];
            on = true;
            }
        else
            {
            cout << "Item can't be turned on "<<endl;
            }

        //cout << "Updated status for item " << status << endl;
        }
    else
        {
        cout << "Item has already been turned on " << endl;
        }
}

item& item::operator=(const item& i)
{
    name = i.name;
    status = i.status;
    owner = i.owner;
    writing = i.writing;
    on = i.on;
    itemTurnon = i.itemTurnon;
    return *this;
}

string item::getStatus()
{
    return status;
}
