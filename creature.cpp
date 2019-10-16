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

    cout << "(creature information)"<<endl;
    cout << "creature name : "<< name << endl;
    cout << "creature vulnerability : " << vulnerability << endl;
    cout << "attack for creature : " << endl;
    XMLNode attackNode = node.getChildNode("attack");
    attack tempAttack(attackNode);
    creatureAttack = tempAttack;
    cout << "trigger for creature : " << endl;
    XMLNode triggerNode = node.getChildNode("trigger");
    trigger tempTrigger(triggerNode);
    creatureTrigger = tempTrigger;


}

