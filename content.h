#ifndef CONTENT_H
#define CONTENT_H

#include "element.h"
#include "commun.h"

class Content : public Item
{

protected:
    string text;

public:
    Content(string text);
    virtual ~Content();
    
    void print();
    virtual string textContent() const;
    
    virtual vector<Item*> XSLTransform(Item* xml, map<string, Item*> templates);
};

#endif
