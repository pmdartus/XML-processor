#include "tag.h"
#include "content.h"

Tag::Tag(string name, vector<Atts *> atts, vector<Item *> children) :
    Element(name, atts),
    children(children) {
        for(vector<Item *>::iterator it = children.begin(); it != children.end(); it++) {
            (*it)->setParent(this);
        }
}

Tag::~Tag() {
    vector<Item *>::iterator it = children.begin();
    while (it != children.end()) {
        it = children.erase(it);
    }
}

void Tag::print() {
        cout << "<" << name << Element::attsToString() << ">";

        for(vector<Item *>::iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->print();
        }

        cout << "</" << name << ">"<<endl;
}

vector<Item*> Tag::getChildren() const {
    return children;
}