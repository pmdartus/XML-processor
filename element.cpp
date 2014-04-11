#include "element.h"
#include <iostream>

Element::Element() {

}

Element::Element(char *name, vector<Atts *> atts) {
	std::cout << "Element's constructor" << std::endl;
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