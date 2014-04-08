#include "element.h"

Element::Element() {
    
}

Element::~Element() {
    
}

const string Element::getName() const {
    return Element::name;
}

vector<Atts*> Element::getAtts() const {
    return Element::attList;
}