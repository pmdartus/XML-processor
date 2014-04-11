#ifndef TAG_H
#define TAG_H

#include "element.h"
#include "item.h"
#include <vector>

using namespace std;

class Tag : public Element
{
    
private:
    vector<Item*> children;
    
public:
    Tag();
    Tag(char *name, list<Attribut *> atts);
    ~Tag();
    
};

#endif
