#include "trigger.h"

trigger::trigger()
{
    type, command, action, print = "";

}

trigger::trigger(string s)
{
    command = s;
    type, action, print = "";
}

trigger::trigger(XMLNode node)
{
    type, command, action, print = "";
    activated = false;

    XMLNode typeNode = node.getChildNode("type");
    if (!typeNode.isEmpty())
        {
        type = typeNode.getText();
        }

    XMLNode commandNode = node.getChildNode("command");
    if (!commandNode.isEmpty())
        {
        command = commandNode.getText();
        }

    XMLNode printNode = node.getChildNode("print");
    if (!printNode.isEmpty())
        {
        print = printNode.getText();
        }

    XMLNode actionNode = node.getChildNode("action");
    if (!actionNode.isEmpty())
        {
        action = actionNode.getText();
        }

    cout << "(trigger information)" << endl;
    cout << "type : " << type << endl;
    cout << "command : " << command << endl;
    cout << "print : " << print << endl;
    cout << "action : " << action << endl;

    cout << "condition information for trigger" << endl;
    XMLNode conditionNode = node.getChildNode("condition");
    condition tempCondition(conditionNode);
    triggerCondition = tempCondition;
}

string::trigger getCommand()
{
    return command;
}


string::trigger getPrint()
{
    return print;
}


string::trigger getType())
{
    return type;
}


string::trigger getAction()
{
    return action;
}

void::trigger checkCondition()
{
    bool hasItem = true;
    if (has == "no")
        {
        hasItem = false;
        }

}



