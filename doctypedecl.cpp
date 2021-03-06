#include "doctypedecl.h"


Doctypedecl::Doctypedecl(string root_element) :
    root_element(root_element) {}

Doctypedecl::Doctypedecl(string root_element, string external_id, string dtd_name) :
    root_element(root_element),
    external_id(external_id),
    dtd_name(dtd_name) {}

Doctypedecl::Doctypedecl(string root_element, string external_id, string dtd_name, string dtd_location) :
    root_element(root_element),
    external_id(external_id),
    dtd_name(dtd_name),
    dtd_location(dtd_location) {}


void Doctypedecl::print()
{
	cout << "<!DOCTYPE " << root_element;
	if (external_id != "")
	{
		cout << " " << external_id << " \"" << dtd_name << "\"";

		if (dtd_location != "")
		{
			cout << " \"" << dtd_location << "\"";
		}
	}
	cout << ">" << endl;
}
