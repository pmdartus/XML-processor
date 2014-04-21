#include "item.h"


Item::~Item() {}

const Item * Item::getParent() const
{
    return Item::parent;
}

void Item::setParent(Item *parent)
{
    Item::parent = parent;
}


vector<Item*> Item::XMLApply(map<string, Item*> templates)
{
    return vector<Item*>();
}


vector<Item*> Item::find(string path) const
{
    return vector<Item*>();
}