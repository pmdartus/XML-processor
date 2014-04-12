#ifndef ELEMENT_H
#define ELEMENT_H

#include "item.h"
#include "atts.h"
#include <string>
#include <vector>

using namespace std;

class Element : public Item
{

protected:
    string name;
    vector<Atts*> attList;
public:
    Element();
    Element(string name);
    Element(string name, vector<Atts *> atts);
    ~Element();
    const string getName() const;
    vector<Atts*> getAtts() const;

};

#endif
