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
        cout << "item turnon information " << endl;
        cout << "action : " << action << endl;
        cout << "print : " << print << endl;
}

void turnon::readPrint()
{
    cout << print << endl;
}

string turnon::getAction()
{
    return action;
}


