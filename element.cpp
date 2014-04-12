#include "element.h"
#include <iostream>

Element::Element() {

}

Element::Element(char *name, vector<Atts *> atts) {
    cout << "Element's constructor" << endl;
    this->name = name;
    this->attList = atts;
    this->parent = 0;
}

Element::~Element() {

}

const string Element::getName() const {
    return Element::name;
}

vector<Atts*> Element::getAtts() const {
    return Element::attList;
}