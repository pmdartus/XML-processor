#ifndef TAG_H
#define TAG_H

#include "element.h"
#include "item.h"
#include "commun.h"
#include <vector>

class Tag : public Element
{

private:
    vector<Item*> children;
    
public:
    Tag(string name, vector<Atts *> atts, vector<Item *> children);
    ~Tag();
    void print();
    vector<Item*> getChildren() const;
};

#endif
