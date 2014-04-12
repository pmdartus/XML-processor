#ifndef TAG_H
#define TAG_H

#include "element.h"
#include "item.h"
#include <vector>
#include <string>

using namespace std;

class Tag : public Element
{

private:
    vector<Item *> children;

public:
    Tag();
    Tag(string name, vector<Atts *> atts, vector<Item *> children);
    ~Tag();

};

#endif
