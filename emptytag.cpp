#include "emptytag.h"


EmptyTag::EmptyTag() {
    
}

EmptyTag::EmptyTag(char *name, vector<Atts *> atts) {
	std::cout << "EmptyTag's constructor" << std::endl;
}

EmptyTag::~EmptyTag() {
    
}