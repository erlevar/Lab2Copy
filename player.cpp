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
        return;
        }
}

void player::takeItem(item newItem)
{
    cout << "takeItem testing !!" << endl;
    cout << "newItem.getName() " << endl;
    cout << newItem.getName();
    inventory.push_back(newItem);
    cout << "Inventory after adding item" << endl;
    for (int i = 0; i < inventory.size(); i++)
        {
        cout << inventory[i].getName();
        }
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

void player::dropItem(string itemName)
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
