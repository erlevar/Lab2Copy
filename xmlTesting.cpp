#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#define XML_USE_STL
#include "xmlParser.h"
#include "room.h"
#include "creature.h"
#include "attack.h"
#include "container.h"
#include "border.h"
#include "item.h"
#include "trigger.h"
#include "turnon.h"
#include "condition.h"

using namespace std;


int main (int argc, char ** argv) {

    string gameFile = "testGame.xml";

    // this opens and parses the correct XML file:
    XMLNode xMainNode=XMLNode::openFileHelper(gameFile.c_str(),"map");
    int i = 0;
    // get the first room node
    XMLNode roomNode=xMainNode.getChildNode(i++);


    do {

    //room initializer
    room newRoom(roomNode);
    //get information for containers in the room
    //getContainers(roomNode);
    //get information for creatures in the room
    //getCreatures(roomNode);

    roomNode=xMainNode.getChildNode(i++);
    } while (!roomNode.isEmpty());

    cout << endl;
    return 0;
}







