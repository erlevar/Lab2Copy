#ifndef CONDITION_H

#include "xmlParser.h"


class condition
{
public:
    condition();
    condition(XMLNode node);

private:
    string object;
    string status;
    string has;
    string owner;
};

#endif // CONDITION_H
