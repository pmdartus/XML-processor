#ifndef EMPTYTAG_H
#define EMPTYTAG_H

#include "element.h"
#include "commun.h"

class EmptyTag : public Element {

private:
public:
    EmptyTag(string name, vector<Atts *> atts);

    void print();
    
    void XSLTransform(Item* xml, map<string, Item*> templates);
    void XMLApply(map<string, Item*> templates);
};

#endif
