#ifndef EMPTYTAG_H
#define EMPTYTAG_H

#include "element.h"

class EmptyTag : public Element {

private:

public:
    EmptyTag();
    EmptyTag(char *name, vector<Attribut *> atts);
    ~EmptyTag();
};

#endif
