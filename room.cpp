#include "player.h"

player::player(room startLocation)
{
    current = startLocation;
}

room player::currentLocation()
{
    return current;
}

void player::updateLocation(room newLocation)
{
    current = newLocation;
}

void player::readInventory()
{
    if (inventory.size() == 0)
        {
        cout << "Inventory : empty" << endl;
        return;
        }
    for (int i = 0; i < inventory.size(); i ++)
        {
        inventory[i].readName();

        }
    return;
}

void player::addItem(item newItem)
{
    inventory.push_back(newItem);
}

item player::checkItems(string input)
{
    for (int i = 0; i<inventory.size(); i++)
        {
        string itemName = inventory[i].getName();
        if (input == itemName)
            {
            return inventory[i];
            }
        }
    string dummy = "dummy";
    item emptyItem(dummy);
    return emptyItem;
}

void player::removeItem(string itemName)
{
    std::vector<item>::iterator iter;
    for(iter = inventory.begin(); iter != inventory.end(); ++iter )
    {
        if((*iter).getName() == itemName)
        {
            inventory.erase(iter);
            break;
        }
    }
}

player& player::operator=(const player & p)
{
    current = p.current;
    for (int i =0; i < p.inventory.size(); i++)
        {
        inventory.push_back(p.inventory[i]);
        }
    return *this;
}

void player::moveToBorder(map<string, room> roomMap, bool & changedRooms, string input)
{
    string passDirection;
    if (input == "n")
        {
        passDirection = "north";
        }
    else if (input == "s")
        {
        passDirection = "south";
        }
    else if (input == "e")
        {
        passDirection = "east";
        }
    else if (input == "w")
        {
        passDirection = "west";
        }
    room current = currentLocation();
    string returnRoomName = current.checkBorders(passDirection);
    if (returnRoomName == "dummy")
        {
        cout << "Can't go that way"<<endl;
        }
    else
        {
        cout << "The name of the room to that direction is " << returnRoomName << endl;
        cout << "You enter this room" << endl;
        changedRooms = true;
        room newLocation = roomMap[returnRoomName];
        updateLocation(newLocation);
        }

}

void player::userTakeItem(room & current, string input)
{
    item returnItem = current.checkItems(input);
    vector<container> roomContainers;
    current.getContainers(roomContainers);

    bool itemPresent = false;
    bool itemInRoom = false;
    bool itemInContainer = false;
    container presentContainer;
    item presentItem;

    for (int i =0; i < roomContainers.size(); i++)
        {
        vector<item> itemsInContainer;
        roomContainers[i].getItems(itemsInContainer);
        for (int j = 0; j < itemsInContainer.size(); j++)
            {
            if (itemsInContainer[j].getName() == input)
                {
                itemInContainer = true;
                presentContainer = roomContainers[i];
                presentItem = itemsInContainer[j];
                break;
                }
            }
        }

    if (returnItem.getName() == input)
        {
        itemInRoom = true;
        }

    item checkInventory = checkItems(input);
    if (checkInventory.getName() == "dummy")
        {
        if ((itemInContainer == false) && (itemInRoom == false))
            {
            cout << "No such item to pick up" << endl;
            }
        else if (itemInRoom == true)
            {
            cout << returnItem.getName() << " added to inventory " << endl;
            returnItem.updateOwner("inventory");
            current.removeItem(returnItem.getName());
            addItem(returnItem);
            }
        else if (itemInContainer == true)
            {
            cout << presentItem.getName() << " added to inventory " << endl;
            presentItem.updateOwner("inventory");
            presentContainer.removeItem(presentItem.getName());
            current.removeContainer(presentContainer.getName());
            current.addContainer(presentContainer);
            addItem(presentItem);
            }
       }
    else
        {
        cout << "You already have that item " << endl;
        }
}

void player::userReadItem(string input)
{
    room currnet = currentLocation();
    item returnItem = checkItems(input);
    if (returnItem.getName() == "dummy")
        {
        cout << "No such item in your inventory to be read " << endl;
        }
    else
        {
        returnItem.readWriting();
        }
}

void player::userDropItem(room & current, string input)
{
    item returnItem = checkItems(input);
    if (returnItem.getName() == "dummy")
        {
        cout << "No such item in your inventory to drop" << endl;
        }
    else
        {
        cout << "You dropped the " << returnItem.getName() << endl;
        returnItem.updateOwner(current.getName());
        current.addItem(returnItem);
        removeItem(returnItem.getName());
        }
}

void player::isAtExit(bool & foundExit)
{
    string roomType = current.getRoomType();
    if (roomType == "exit")
        {
        cout << "VICTORY!!!"<<endl;
        foundExit = true;
        }
    else
        {
        cout << "You have not made it to the exit yet " << endl;
        }
}

void player::userOpenContainer(string input)
{
    container returnContainer = current.checkContainers(input);
    if (returnContainer.getName() == "dummy")
        {
        cout << "No such container in the room to open" << endl;
        }
    else
        {
        cout << "You open the " << returnContainer.getName() <<endl;
        returnContainer.readItems();
        }
}

void player::userTurnonItem(string input)
{
    item returnItem = checkItems(input);
    if (returnItem.getName() == "dummy")
        {
        cout << "No such item in your inventory to turn on " << endl;
        }
    else
        {
        cout << "You turn on the " << returnItem.getName() << endl;
        returnItem.activateTurnon();
        removeItem(returnItem.getName());
        addItem(returnItem);
        }
}

void player::userPutItemInContainer(room & current, string itemName, string containerName)
{
    item returnItem = checkItems(itemName);
    container returnContainer = current.checkContainers(containerName);
    if (returnItem.getName() == "dummy")
        {
        cout << "No such item in your inventory to be placed in the container " << endl;
        return;
        }

    if (returnContainer.getName() == "dummy")
        {
        cout << "No such container in the room to place the item in " << endl;
        return;
        }

    cout << "You put the " << returnItem.getName() << " in the " << returnContainer.getName() << endl;
    removeItem(itemName);
    returnContainer.addItem(returnItem);
    current.removeContainer(returnContainer.getName());
    curretn.addContainer(returnContainer);

}


