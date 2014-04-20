#ifndef ELEMENT_H
#define ELEMENT_H

#include "item.h"
#include "atts.h"
#include "commun.h"
#include <vector>

class Element : public Item
{

protected:
    string name;
    vector<Atts*> atts;
public:
    Element(string name, vector<Atts *> atts);
    virtual ~Element();

    const string getName() const;

    vector<Atts*> getAtts() const;
    const string getAtt(const string attName) const;
    string attsToString();
    
    virtual void print() = 0;
    virtual string textContent() const;
    
    virtual void XSLTransform(Item* xml, map<string, Item*> templates) = 0;
    virtual void XMLApply(map<string, Item*> templates) = 0;
};

#endif
