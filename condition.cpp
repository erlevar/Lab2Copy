#include "condition.h"

condition::condition()
{
    object, status, owner, has = "";
}

condition::condition(XMLNode node)
{
    object, status, owner, has = "";

    XMLNode hasNode = node.getChildNode("has");
    if (!hasNode.isEmpty())
        {
        has = hasNode.getText();
        }

    XMLNode ownerNode = node.getChildNode("owner");
    if (!ownerNode.isEmpty())
        {
        owner = ownerNode.getText();
        }

    XMLNode objectNode = node.getChildNode("object");
    if (!objectNode.isEmpty())
        {
        object = objectNode.getText();
        }

    XMLNode statusNode = node.getChildNode("status");
    if (!statusNode.isEmpty())
        {
        status = statusNode.getText();
        }
}

string condition::getHas()
{
    return has;
}

string condition::getOwner()
{
    return owner;
}

string condition::getObject()
{
    return object;
}

string condition::getStatus()
{
    return status;
}

bool condition::checkCondition(player user)
{
    if (has == "no")
        {
        if (owner == "inventory")
            {
                item returnItem = user.checkItems(object);
                if (returnItem.getName() == "dummy")
                    {
                    commandTrigger.executePrint();
                    }
                else
                    {
                    triggersPresent = false;
                    }
            }

        }
}
