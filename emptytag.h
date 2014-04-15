#ifndef EMPTYTAG_H
#define EMPTYTAG_H

#include "element.h"
#include "commun.h"

class EmptyTag : public Element {

private:
public:
    EmptyTag(string name, vector<Atts *> atts);

    void print();
};

#endif
