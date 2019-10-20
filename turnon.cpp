#include "turnon.h"

turnon::turnon()
{
    print, action = " ";

}
turnon::turnon(XMLNode node)
{
    print, action = " ";

    XMLNode turnonPrintNode = node.getChildNode("print");
    if (!turnonPrintNode.isEmpty())
        {
        print  = turnonPrintNode.getText();
        }

    XMLNode turnonActionNode = node.getChildNode("action");
    if(!turnonActionNode.isEmpty())
        {
        action = turnonActionNode.getText();
        }
}

void turnon::readPrint()
{
    cout << print << endl;
}

string turnon::getAction()
{
    return action;
}


