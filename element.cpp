#include "element.h"
#include <iostream>

Element::Element(string name, vector<Atts *> atts) {
    Element::name = name;
    Element::atts = atts;
    Element::parent = 0;
    cout << "Element's constructor" << endl;
}

Element::~Element() {
    cout << "Element's destructor" << endl;
    vector<Atts *>::iterator it = atts.begin();
    while (it != atts.end()) {
        it = atts.erase(it);
    }
}

const string Element::getName() const {
    return name;
}

vector<Atts*> Element::getAtts() const {
    return atts;
}

