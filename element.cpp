#include "element.h"
#include <iostream>
#include <string>

Element::Element(string name, vector<Atts *> atts) : Item()
{
    Element::name = name;
    Element::atts = atts;
    Element::parent = 0;
}

Element::Element(const Element& elem) : Item()
{
    name = elem.name;
    vector<Atts*>::const_iterator it = elem.atts.begin();
    for (; it != elem.atts.end(); it++)
    {
        atts.push_back(new Atts(**it));
    }
}

Element::~Element() {
    vector<Atts *>::iterator it = atts.begin();
    while (it != atts.end()) {
        delete (*it);
        it = atts.erase(it);
    }
}

const string Element::getName() const {
    return name;
}

vector<Atts*> Element::getAtts() const {
    return atts;
}

const string Element::getAtt(const string attName) const
{
    for (vector<Atts*>::const_iterator it = atts.begin(); it != atts.end(); it++)
    {
        if((*it)->name.compare(attName) == 0)
        {
            return (*it)->value;
        }
    }
    return "";
}

string Element::attsToString()
{
    string ret;
    vector<Atts *>::iterator it = Element::atts.begin();
    while (it != atts.end()) {
        ret += (*it)->name + "=" + "\"" + (*it)->value + "\" ";
        it++;
    }

    return ret.substr(0, ret.size()-1);;
}


string Element::textContent() const
{
    return "";
}

vector<Item*> Element::XMLApply(map<string, Item*> templates)
{
    return vector<Item*>();
}
