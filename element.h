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
    ~Element();

    const string getName() const;
    vector<Atts*> getAtts() const;

};

#endif
