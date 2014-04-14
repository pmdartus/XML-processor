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
    vector<Item*> children;
    vector<Atts *> atts;
    string name;
public:
    Tag(string name, vector<Atts *> atts, vector<Item *> children);
    ~Tag();
    const string getName() const;
};

#endif
