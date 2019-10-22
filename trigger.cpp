#include "trigger.h"



trigger::trigger()
{
    type, command, action, print = " ";
    activated = false;

}

trigger::trigger(string s)
{
    command = s;
    type, action, print = " ";
    activated = false;
}

trigger::trigger(XMLNode node)
{
    type, command, action, print = " ";
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
    XMLNode conditionNode = node.getChildNode("condition");
    condition tempCondition(conditionNode);
    triggerCondition = tempCondition;
}

string trigger::getCommand()
{
    return command;

}


string trigger::getPrint()
{
    return print;
}


string trigger::getType()
{
    return type;
}


string trigger::getAction()
{
    return action;
}

condition trigger::getCondition()
{
    return triggerCondition;
}

void trigger::executePrint()
{
    cout << print << endl;
}

bool trigger::getActivated()
{
    return activated;
}

void trigger::updateActivated()
{
    if (type == "single")
        {
        activated = true;
        return;
        }

}
