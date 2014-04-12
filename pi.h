#ifndef PI_H
#define PI_H

#include  "element.h"
#include <string>

using namespace std;

class Pi : public Element {

private:

public:
    Pi();
    Pi(string name, vector<Atts *> atts);
    ~Pi();

};

#endif
