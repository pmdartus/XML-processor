#include "item.h"


Item::~Item() {}

const Item * Item::getParent() const {
    return Item::parent;
}

void Item::setParent(Item *parent) {
    Item::parent = parent;
}


void Item::XMLApply(map<string, Item*> templates) {
    
}