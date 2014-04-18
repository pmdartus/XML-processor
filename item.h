#ifndef ITEM_H
#define ITEM_H

#include "commun.h"
#include <vector>

class tag;

class Item
{

private:

public:
	Item* parent = 0;

    const Item * getParent() const;
    void setParent(Item *parent);
    virtual void print() = 0;
    virtual const vector<Item*> getChildren() const = 0;
};

#endif
