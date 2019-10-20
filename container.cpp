#include "container.h"

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

    cout << "(container information)"<<endl;
    cout << "container name : " << name << endl;
    cout << "container status : " << status << endl;
    cout << "container accept :" << accept << endl;

    cout << "(items in container)" << endl;
    getItems(node);
    for (int i =0; i<items.size(); i++)
        {
            items[i].updateOwner(name);
        }


    cout << "(triggers for container)" << endl;
    getTriggers(node);

}

void container::getItems(XMLNode node)
{
    int numberItems = node.nChildNode("item");
    for (int nItems = 0; nItems < numberItems; nItems++)
        {
        XMLNode itemNode = node.getChildNode("item", nItems);
        item newItem(itemNode);
        items.push_back(newItem);
        }
}

void container::getTriggers(XMLNode node)
{
    int numberTriggers = node.nChildNode("trigger");
    for (int nTriggers = 0; nTriggers < numberTriggers; nTriggers++)
        {
            XMLNode triggerNode=node.getChildNode("trigger", nTriggers);
            trigger newTrigger(triggerNode);
            triggers.push_back(newTrigger);
        }
}
