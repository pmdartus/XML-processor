#include "pi.h"
#include <iostream>

Pi::Pi(string name, vector<Atts *> atts) : Element(name, atts)
{
}

void Pi::print()
{
    cout << "<?" << name << " " << attsToString() << "?>" << endl;
}


void Pi::XSLTransform(Item* xml, map<string, Item*> templates)
{
    
}

void Pi::XMLApply(map<string, Item*> templates)
{
    
}