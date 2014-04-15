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
        for(vector<Atts *>::iterator it = atts.begin(); it != atts.end(); ++it) {
            cout << " " << (*it)->name << "=" << "\"" << (*it)->value << "\"";
        }
        cout << ">"<<endl;

        for(vector<Item *>::iterator it = children.begin(); it != children.end(); ++it) {
            (*it)->print();
        }

        cout << "</" << name << ">"<<endl;
}