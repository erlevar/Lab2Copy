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
    cout << "actions for attack " << endl;
    for (int nActions = 0; nActions < numberActions; nActions ++)
        {
        XMLNode actionNode = node.getChildNode("action", nActions);
        string actionInfo = actionNode.getText();
        actions.push_back(actionInfo);
        cout << "actionInfo " << actionInfo << endl;
        }

    cout << "condition for attack " <<endl;
    XMLNode conditionNode = node.getChildNode("condition");
    condition tempCondition(conditionNode);
    attackCondition = tempCondition;

}
