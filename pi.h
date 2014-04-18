#ifndef PI_H
#define PI_H

#include "element.h"
#include "commun.h"

class Pi : public Element {

private:

public:
    Pi(string name, vector<Atts *> atts);

    void print();
    const vector<Item*> getChildren() const;
};

#endif
