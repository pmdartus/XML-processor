#ifndef TAG_H
#define TAG_H

#include "element.h"
#include "item.h"
#include "content.h"
#include "commun.h"

class Tag : public Element
{

private:
    vector<Item*> children;
    
public:
    Tag(string name, vector<Atts*> atts, vector<Item*> children);
    Tag(const Element& elem, vector<Item*> children);
    ~Tag();
    void print();
    vector<Item*> getChildren() const;

    string textContent() const;
    
    vector<Item*> XSLTransform(Item* xml, map<string, Item*> templates);
    vector<Item*> XMLApply(map<string, Item*> templates);

};

#endif
