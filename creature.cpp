#include "creature.h"

creature::creature()
{
    name, vulnerability = "";
}

creature::creature(string s)
{
    name = s;
    vulnerability = "";
}
creature::creature(XMLNode node)
{
    name, vulnerability ="";

    XMLNode creatureNameNode = node.getChildNode("name");
    if (!creatureNameNode.isEmpty())
        {
        name = creatureNameNode.getText();
        }

    XMLNode creatureVulnerabilityNode = node.getChildNode("vulnerability");
    if (!creatureVulnerabilityNode.isEmpty())
        {
        vulnerability = creatureVulnerabilityNode.getText();
        }

    XMLNode attackNode = node.getChildNode("attack");
    attack tempAttack(attackNode);
    creatureAttack = tempAttack;
    XMLNode triggerNode = node.getChildNode("trigger");
    trigger tempTrigger(triggerNode);
    creatureTrigger = tempTrigger;
    XMLNode itemNode = node.getChildNode("item");
    item tempItem(itemNode);
    creatureItem = tempItem;
    creatureItem.updateOwner(name);

}

trigger creature::getTrigger()
{
    return creatureTrigger;
}

string creature::getName()
{
    return name;
}

attack creature::getAttack()
{
    return creatureAttack;
}

item creature::getItem()
{
    return creatureItem;
}

void creature::removeItem()
{
    item newItem;
    creatureItem = newItem;
}
