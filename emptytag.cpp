#include "emptytag.h"
#include <iostream>


EmptyTag::EmptyTag() {

}

EmptyTag::EmptyTag(char *name, vector<Atts *> atts) {
	cout << "EmptyTag's constructor" << endl;
	this->name = string(name);
	this->attList = atts;
}

EmptyTag::~EmptyTag() {

}
