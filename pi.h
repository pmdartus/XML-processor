#ifndef PI_H
#define PI_H

#include  "element.h"

class Pi : public Element {

private:

public:
    Pi();
    Pi(char *name, vector<Atts *> atts);
    ~Pi();

};

#endif
