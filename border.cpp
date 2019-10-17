#include "border.h"

border::border(XMLNode node)
{
    direction, name = "";

    XMLNode borderDirectionNode = node.getChildNode("direction");
    if (!borderDirectionNode.isEmpty())
        {
        direction = borderDirectionNode.getText();
        }

    XMLNode borderNameNode = node.getChildNode("name");
    if (!borderNameNode.isEmpty())
        {
        name = borderNameNode.getText();
        }

    cout << "(border information)"<<endl;
    cout << "direction : " << direction << endl;
    cout << "name : " << name << endl;
}

string border::getDirection()
{
    return direction;
}

string border::getName()
{
    return name;
}
