#include "element.h"
#include <iostream>

Element::Element() {

}

Element::Element(string name) {
}

Element::Element(string name, vector<Atts *> atts) {
    Element::name = name;
    Element::attList = atts;
    Element::parent = 0;
}

Element::~Element() {

}

const string Element::getName() const {
    return Element::name;
}

vector<Atts*> Element::getAtts() const {
    return Element::attList;
}