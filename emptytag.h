#ifndef EMPTYTAG_H
#define EMPTYTAG_H

#include "element.h"
#include "content.h"
#include "commun.h"

class EmptyTag : public Element {

private:
public:
    EmptyTag(string name, vector<Atts *> atts);
    EmptyTag(const Element& elem);
    void print();
    
    vector<Item*> XSLTransform(Item* xml, map<string, Item*> templates);
};

#endif
