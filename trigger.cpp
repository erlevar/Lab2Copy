#include "trigger.h"



trigger::trigger()
{
    type, command, action, print = " ";

}

trigger::trigger(string s)
{
    command = s;
    type, action, print = " ";
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
    cout << "Command after being initalized: " << command << endl;
    XMLNode conditionNode = node.getChildNode("condition");
    condition tempCondition(conditionNode);
    triggerCondition = tempCondition;
}

string trigger::getCommand()
{
    return command;
    //cout << "calling trigger.getCommand()" << endl;
    //if (command != " " )
      //  {
     //   cout << "returning command " << endl;
        //return command;
      //  }
   // else
     //   {
     //   string emptyS = "empty";
     //   cout << "returning emptyS" << endl;
     //   return emptyS;
      //  }
    //string fucked = "whatthehell";
    //cout << "returning " << fucked << endl;
    //return fucked;
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
