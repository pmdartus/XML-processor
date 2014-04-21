#include "pi.h"
#include <iostream>

Pi::Pi(string name, vector<Atts *> atts) : Element(name, atts)
{
}

void Pi::print()
{
    cout << "<?" << name << " " << attsToString() << "?>" << endl;
}


vector<Item*> Pi::XSLTransform(Item* xml, map<string, Item*> templates)
{
    return vector<Item*>();
}