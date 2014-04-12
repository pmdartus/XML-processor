#include "tag.h"
#include <iostream>

Tag::Tag() {

}

Tag::Tag(char *name, vector<Atts *> atts, vector<Item *> children) {
	cout << "Tag's constructor" << endl;
	this->children = children;

	// Set the parent of every child
	for (vector<Item *>::iterator it = children.begin() ; it != children.end(); ++it) {
		(*it)->parent = this;
		cout << "  > " << this->getName() << endl;
	}
}

Tag::~Tag() {

}