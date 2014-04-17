#ifndef XMLVALIDATOR_H
#define XMLVALIDATOR_H

#include "commun.h"
#include "document.h"
#include "content.h"
#include "tag.h"
#include <map>
#include <iostream>
#include <exception>
using namespace std;


class Xmlvalidator {

private:
    map<string, string> mapType;
    map<string, string> mapRegex;
    string createRegex(Tag* construction, string elType);
    int checkNode(Item* node);
public:
    Xmlvalidator();
    ~Xmlvalidator();
    void mapsCreate(Document *xsd);
    int validityCheck(Document *xml);
};

#endif
