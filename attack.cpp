#include "attack.h"

attack::attack()
{
    print = "";
}

attack::attack(XMLNode node)
{

    print ="";
    XMLNode printNode = node.getChildNode("print");
    if (!printNode.isEmpty())
        {
        print = printNode.getText();
        }
    int numberActions = node.nChildNode("action");
    for (int nActions = 0; nActions < numberActions; nActions ++)
        {
        XMLNode actionNode = node.getChildNode("action", nActions);
        string actionInfo = actionNode.getText();
        actions.push_back(actionInfo);
        }
    XMLNode conditionNode = node.getChildNode("condition");
    condition tempCondition(conditionNode);
    attackCondition = tempCondition;

}

condition attack::getCondition()
{
    return attackCondition;
}

string attack::getAction()
{
    return actions[1];
}

void attack::executePrint()
{
    cout << print << endl;
}
