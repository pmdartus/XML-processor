#include "doctypedecl.h"


Doctypedecl::Doctypedecl(char *root_element) {
    Doctypedecl::root_element = root_element;
}

Doctypedecl::Doctypedecl(char *root_element, char *external_id, char *dtd_name) {
    Doctypedecl::root_element = root_element;
    Doctypedecl::external_id = external_id;
    Doctypedecl::dtd_name = dtd_name;
}
Doctypedecl::Doctypedecl(char * root_element, char * external_id, char * dtd_name, char * dtd_location) {
	Doctypedecl::root_element = root_element;
	Doctypedecl::external_id = external_id;
	Doctypedecl::dtd_name = dtd_name;
	Doctypedecl::dtd_location = dtd_location;
}

Doctypedecl::~Doctypedecl() {

}