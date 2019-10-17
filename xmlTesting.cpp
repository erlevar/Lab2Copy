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
#include <map>
#include <iostream>
#include <string>

using namespace std;


class player
{
public:
    player();
    player(room startLocation);
    room currentLocation();
private :
    room current;
};



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
    map<string, room> roomMap;
    string roomName = newRoom.getName();
    roomMap[roomName] = newRoom;
    //get information for containers in the room
    //getContainers(roomNode);
    //get information for creatures in the room
    //getCreatures(roomNode);
    roomNode=xMainNode.getChildNode(i++);
    } while (!roomNode.isEmpty());

    room entrance = roomMap["Entrance"];
    player user(entrance);
    bool foundExit = false;
    while (foundExit == false)
        {
        room current = player.currentLocation();
        current.readDescription();

        string userinput;
        getline(userinput);

        if ((userinput == "n") || (userinput == "s") || (userinput == "e") || (userinput == "w"))
            {
            string passDirection;
            if (userinput == "n")
                {
                passDirection = "north";
                }
            else if (userinput == "s")
                {
                passDirection = "south";
                }
            else if (userinput == "e")
                {
                passDirection = "east";
                }
            else if (userinput == "w")
                {
                passDirection = "west";
                }
            string returnRoomName = current.checkBorders(passDirection);
            if (returnRoomName == "dummy")
                {
                cout << "No room to that direction";
                }
            else
                {
                cout << "returnRoomName is " << returnRoomName << endl;
                }
            }




        }
    return 0;
}


player::player(room startLocation)
{
    current = startLocation;
}

player::currentLocation()
{
    return current;
}





