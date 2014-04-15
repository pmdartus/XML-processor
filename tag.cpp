#include "tag.h"

Tag::Tag(string name, vector<Atts *> atts, vector<Item *> children) :
    Element(name, atts),
    children(children) {
        cout << "Tag's constructor"<< name << endl;
        for(vector<Item *>::iterator it = children.begin(); it != children.end(); it++) {
            (*it)->setParent(this);
        }
}

Tag::~Tag() {
    cout << "Tag's destructor" << endl;
    vector<Item *>::iterator it = children.begin();
    while (it != children.end()) {
        it = children.erase(it);
    }
}

void Tag::print() {
        cout << "<" << name;
        // TODO args
        cout << ">"<<endl;

        // TODO childs

        cout << "</" << name << ">"<<endl;
}