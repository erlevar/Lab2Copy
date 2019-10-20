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

}

string border::getDirection()
{
    return direction;
}

string border::getName()
{
    return name;
}
