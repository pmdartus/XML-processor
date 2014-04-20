#ifndef ITEM_H
#define ITEM_H

#include "commun.h"
#include <map>
class tag;

class Item
{

private:

public:
	Item* parent = 0;
    virtual ~Item();
    
    const Item * getParent() const;
    void setParent(Item *parent);
    
    virtual string textContent() const = 0;
    virtual void print() = 0;
    
    virtual void XMLApply(map<string, Item*> templates);
    virtual void XSLTransform(Item* xml, map<string, Item*> templates) = 0;
    
};

#endif
