#include "doctypedecl.h"


Doctypedecl::Doctypedecl(char * root_element) {
    this->root_element = root_element;
}

Doctypedecl::Doctypedecl(char * root_element, char * external_id, char * dtd_name) {
    this->root_element = root_element;
    this->external_id = external_id;
    this->dtd_name = dtd_name;
}
Doctypedecl::Doctypedecl(char * root_element, char * external_id, char * dtd_name, char * dtd_location) {
	this->root_element = root_element;
	this->external_id = external_id;
	this->dtd_name = dtd_name;
	this->dtd_location = dtd_location;
}



Doctypedecl::Doctypedecl() {
    
}

Doctypedecl::~Doctypedecl() {
    
}