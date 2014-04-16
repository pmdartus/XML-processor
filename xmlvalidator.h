#ifndef XMLVALIDATOR_H
#define XMLVALIDATOR_H

#include "commun.h"
#include "document.h"
#include "tag.h"
#include <map>


class Xmlvalidator {

private:
    map<string, string> mapType;
    map<string, string> mapRegex;
    string createRegex(Tag* construction, string elType);
public:
    Xmlvalidator();
    ~Xmlvalidator();
    void mapsCreate(Document *xsd);
    void validityCheck(Document *xml);
};

#endif
