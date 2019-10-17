#include "extraFunctions.h"

void getItems(XMLNode node, vector<item> & items)
{
    int numberItems = node.nChildNode("item");
    for (int nItems = 0; nItems < numberItems; nItems++)
        {
        XMLNode itemNode = node.getChildNode("item", nItems);
        item newItem(itemNode);
        items.push_back(newItem);
        }
}

void getTriggers(XMLNode node, vector<trigger> & triggers)
{
    int numberTriggers = node.nChildNode("trigger");
    for (int nTriggers = 0; nTriggers < numberTriggers; nTriggers++)
        {
            XMLNode triggerNode=node.getChildNode("trigger", nTriggers);
            trigger newTrigger(triggerNode);
            triggers.push_back(newTrigger);
        }
}

void separateWords(string s, vector<string> & separated)
{
    /*
    vector<char> newWord;
    for (int j = 0; j<s.length(); j++)
        {
        //enters all non null characters into a character array
        if(s[j] != '\0')
            {
            newWord.push_back(s[j]);
            }
        else
            {
            //if null character is found immediately just skip
            if (newWord.size() == 0)
                {
                continue;
                }
            //otherwise we make a cstring and fill it with the character array, add the terminating value '\0', then add that to the full name vector.
            char cString[newWord.size()+1];
            for (int k = 0; k<newWord.size(); k++)
                {
                cString[k] = newWord[k];
                }
            cString[newWord.size()] = '\0';
            fullName.push_back(cString);
            newWord.clear();
            }
        }
        */
    stringstream stream(s);
    string word;
    getline(stream, word, ' ');
    separated.push_back(word);

}
