#include "emptytag.h"
#include <iostream>


EmptyTag::EmptyTag() {

}

EmptyTag::EmptyTag(string name, vector<Atts *> atts) {
	EmptyTag::name = string(name);
	EmptyTag::attList = atts;
}

EmptyTag::~EmptyTag() {

}
