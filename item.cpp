#include "item.h"

Item::Item() {
    
}

Item::~Item() {
    
}

const Item * Item::getParent() const {
    return Item::parent;
}

void Item::setParent(Item *parent) {
    Item::parent = parent;
}