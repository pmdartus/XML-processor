#include "tag.h"
#include <iostream>


Tag::Tag() {

}

Tag::Tag(char *name, vector<Atts *> atts, vector<Item *> children) {
	std::cout << "Tag's constructor" << std::endl;
	this->children = children;

	// Set the parent of every child
	for (std::vector<Item *>::iterator it = myvector.begin() ; it != myvector.end(); ++it) {
		it->parent = this;
		std::cout << "  > " << it.name << " = " << this.name << std::endl;
	}
}

Tag::~Tag() {

}