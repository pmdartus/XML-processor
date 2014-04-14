#include "doctypedecl.h"


Doctypedecl::Doctypedecl(string root_element) {
    Doctypedecl::root_element = root_element;
}

Doctypedecl::Doctypedecl(string root_element, string external_id, string dtd_name) {
    Doctypedecl::root_element = root_element;
    Doctypedecl::external_id = external_id;
    Doctypedecl::dtd_name = dtd_name;
}
Doctypedecl::Doctypedecl(string root_element, string external_id, string dtd_name, string dtd_location) {
	Doctypedecl::root_element = root_element;
	Doctypedecl::external_id = external_id;
	Doctypedecl::dtd_name = dtd_name;
	Doctypedecl::dtd_location = dtd_location;
}

Doctypedecl::~Doctypedecl() {

}