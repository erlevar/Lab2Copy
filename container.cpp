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
    getItems(node, items);

    cout << "(triggers for container)" << endl;
    getTriggers(node, triggers);

}

