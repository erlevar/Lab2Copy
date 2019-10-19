#include "xmlParser.h"
#include "trigger.h"
#include "item.h"
#include <sstream>
#include <vector>
using namespace std;


void getTriggers(XMLNode node, vector<trigger> & triggers);
void getItems(XMLNode node, vector<item> & items);
void separateWords(string s, vector<string> & separated);
