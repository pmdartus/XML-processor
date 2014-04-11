#ifndef DOCTYPEDECL_H
#define DOCTYPEDECL_H

#include <iostream>

class Doctypedecl {

private:
    char * root_element;
    char * external_id;
    char * dtd_name;
    char * dtd_location;

public:
    Doctypedecl(char * root_element);
    Doctypedecl(char * root_element, char * external_id, char * dtd_name);
    Doctypedecl(char * root_element, char * external_id, char * dtd_name, char * dtd_location);
    ~Doctypedecl();

};

#endif
