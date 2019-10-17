#include "xmlParser.h"
#include "trigger.h"
#include "item.h"
#include <sstream>
#include <vector>
using namespace std;

void getItems(XMLNode node, vector<item> & items);
void getTriggers(XMLNode node, vector<trigger> & triggers);
void separateWords(string s, vector<string> & separated);
