#include "element.h"
#include <iostream>
#include <string>

Element::Element(string name, vector<Atts *> atts) {
    Element::name = name;
    Element::atts = atts;
    Element::parent = 0;
}

Element::~Element() {
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

string Element::attsToString()
{
    string ret;
    vector<Atts *>::iterator it = Element::atts.begin();
    while (it != atts.end()) {
        ret += (*it)->name + "=" + "\"" + (*it)->value + "\" ";
        it++;
    }

    return ret.substr(0, ret.size()-1);;
}

