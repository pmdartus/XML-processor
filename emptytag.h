#ifndef EMPTYTAG_H
#define EMPTYTAG_H

#include "element.h"
#include <string>

using namespace std;

class EmptyTag : public Element {

private:
public:
    EmptyTag();
    EmptyTag(string name, vector<Atts *> atts);
    ~EmptyTag();
};

#endif
