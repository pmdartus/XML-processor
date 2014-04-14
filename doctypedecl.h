#ifndef DOCTYPEDECL_H
#define DOCTYPEDECL_H

#include <string>

using namespace std;

class Doctypedecl {
    
private:
    string root_element;
    string external_id;
    string dtd_name;
    string dtd_location;

public:
    Doctypedecl(string root_element);
    Doctypedecl(string root_element, string external_id, string dtd_name);
    Doctypedecl(string root_element, string external_id, string dtd_name, string dtd_location);

};

#endif
