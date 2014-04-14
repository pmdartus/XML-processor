#include "tag.h"

Tag::Tag(string name, vector<Atts *> atts, vector<Item *> children) :
    name(name),
    atts(atts),
    children(children) {
        for(vector<Item *>::iterator it = children.begin(); it != children.end(); it++) {
            (*it)->setParent(this);
        }
}

Tag::~Tag() {
    vector<Atts *>::iterator attsIt = atts.begin();
    while (attsIt != atts.end()) {
        attsIt = atts.erase(attsIt);
    }

    vector<Item *>::iterator childrenIt = children.begin();
    while (childrenIt != children.end()) {
        childrenIt = children.erase(childrenIt);
    }
}

const string Tag::getName() const {
    return name;
}