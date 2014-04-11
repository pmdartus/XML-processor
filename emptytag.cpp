#include "emptytag.h"


EmptyTag::EmptyTag() {
    
}

EmptyTag::EmptyTag(char *name, list<Attribut *> atts) {
	std::cout << "EmptyTag's constructor" << std::endl;
}

EmptyTag::~EmptyTag() {
    
}