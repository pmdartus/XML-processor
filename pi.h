#ifndef PI_H
#define PI_H

#include "element.h"
#include "commun.h"

class Pi : public Element {

private:

public:
    Pi(string name, vector<Atts *> atts);

    void print();
    
    void XSLTransform(Item* xml, map<string, Item*> templates);
    void XMLApply(map<string, Item*> templates);
};

#endif
