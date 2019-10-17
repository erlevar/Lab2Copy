#include "turnon.h"

turnon::turnon()
{
    print, action = "";

}
turnon::turnon(XMLNode node)
{
    if (!node.isEmpty())
        {
        string print, action = "";

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

        cout << "(item turnon information)" << endl;
        cout << "Item turnon print : " << print << endl;
        cout << "Item turnon action : " << action << endl;
        }
}

string turnon::readPrint()
{
    cout << print << endl;
}

string turnon::getAction()
{
    return action;
}


