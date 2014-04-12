#include "tag.h"
#include <iostream>

Tag::Tag() {

}

Tag::Tag(string name, vector<Atts *> atts, vector<Item *> children) {
	Tag::children = children;

	// Set the parent of every child
	for (vector<Item *>::iterator it = children.begin() ; it != children.end(); ++it) {
		(*it)->parent = this;
		cout << "  > " << Tag::getName() << endl;
	}
}

Tag::~Tag() {

}