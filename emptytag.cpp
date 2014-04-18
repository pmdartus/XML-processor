#include "emptytag.h"

EmptyTag::EmptyTag(string name, vector<Atts *> atts) : Element(name, atts){
}

void EmptyTag::print()
{
    cout << "<" << name << Element::attsToString() << "/>" << endl;
}

const vector<Item*> EmptyTag::getChildren() const
{
    vector<Item*> ret;
    return ret;
}