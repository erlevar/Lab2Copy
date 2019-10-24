#include "container.h"

container::container()
{
    name, status, accept = "";
}

container::container(string s)
{
    name = s;
    status, accept = "";
}

container::container(XMLNode node)
{
    name, status, accept = "";

    XMLNode containerNameNode = node.getChildNode("name");
    if (!containerNameNode.isEmpty())
        {
        name = containerNameNode.getText();
        }

    XMLNode containerStatusNode = node.getChildNode("status");
    if (!containerStatusNode.isEmpty())
        {
        status = containerStatusNode.getText();
        }

    XMLNode containerAcceptNode = node.getChildNode("accept");
    if (!containerAcceptNode.isEmpty())
        {
        accept = containerAcceptNode.getText();
        }

    setItems(node);
    for (int i =0; i<items.size(); i++)
        {
            items[i].updateOwner(name);
        }

    setTriggers(node);

}

void container::setItems(XMLNode node)
{
    int numberItems = node.nChildNode("item");
    for (int nItems = 0; nItems < numberItems; nItems++)
        {
        XMLNode itemNode = node.getChildNode("item", nItems);
        item newItem(itemNode);
        items.push_back(newItem);
        }
}

void container::setTriggers(XMLNode node)
{
    int numberTriggers = node.nChildNode("trigger");
    for (int nTriggers = 0; nTriggers < numberTriggers; nTriggers++)
        {
            XMLNode triggerNode=node.getChildNode("trigger", nTriggers);
            trigger newTrigger(triggerNode);
            triggers.push_back(newTrigger);
        }
}

string container::getName()
{
    return name;
}

void container::readItems()
{
    cout << "Contents of the container " << endl;
    if (items.size() == 0)
        {
        cout << "Container is empty " << endl;
        }
    for (int i =0; i < items.size(); i++)
        {
        items[i].readName();
        }
    return;
}

container& container::operator=(const container& c)
{
    name = c.name;
    status = c.status;
    accept = c.accept;
    items.clear();
    triggers.clear();
    for (int i = 0; i < c.items.size(); i++)
        {
            items.push_back(c.items[i]);
        }
    for (int i = 0; i < c.triggers.size(); i++)
        {
            triggers.push_back(c.triggers[i]);
        }
    return *this;
}

item container::checkItems(string input)
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

void container::getItems(vector<item> &  returnItems)
{
    for (int i =0; i<items.size(); i++)
        {
        returnItems.push_back(items[i]);
        }
    return;
}


void container::removeItem(string itemName)
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

void container::addItem(item newItem)
{
    items.push_back(newItem);
}

void container::getContainerTriggerComands(vector<string> & commands )
{

    for (int i = 0; i < triggers.size(); i++)
        {
            commands.push_back(triggers[i].getCommand());
        }

}

trigger container::checkTriggersByCommand(string input)
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

string container::getStatus()
{
    return status;
}

trigger container::getTriggerWithoutCommand()
{
    for (int i = 0; i < triggers.size(); i++)
        {
        if (triggers[i].getCommand() == "")
            {
            return triggers[i];
            }
        }
    string emptyS = "dummy";
    trigger emptyTrigger(emptyS);
    return emptyTrigger;
}

void container::removeTriggerWithoutCommand()
{
    vector<trigger>::iterator iter;
    for(iter = triggers.begin(); iter != triggers.end(); ++iter )
    {
        if((*iter).getCommand() == "")
        {
            triggers.erase(iter);
            break;
        }
    }
}

void container::addTrigger(trigger newTrigger)
{
    triggers.push_back(newTrigger);
}

void container::updateStatus(string newStatus)
{
    status = newStatus;
}

