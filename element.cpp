#include "element.h"

Element::Element() {

}

Element::Element(char *name, vector<Atts *> atts) {
	std::cout << "Element's constructor" << std::endl;
    this->name = name;
    this->attList = atts;
}

Element::~Element() {
    
}

const string Element::getName() const {
    return Element::name;
}

vector<Atts*> Element::getAtts() const {
    return Element::attList;
}