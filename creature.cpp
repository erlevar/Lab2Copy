#include "creature.h"

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


}

