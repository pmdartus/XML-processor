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
    void choiceRegex(Tag* choice);
    void seqRegex(Tag* seq);
public:
    Xmlvalidator();
    ~Xmlvalidator();
    void mapsCreate(Document *xsd);
    void validityCheck(Document *xml);
};

#endif
