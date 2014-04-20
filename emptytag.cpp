#include "emptytag.h"

EmptyTag::EmptyTag(string name, vector<Atts *> atts) : Element(name, atts)
{
}

void EmptyTag::print()
{
    cout << "<" << name << Element::attsToString() << "/>" << endl;
}



void EmptyTag::XSLTransform(Item* xml, map<string, Item*> templates)
{
    if(name.compare("xsl:apply-templates") == 0)
    {
        string value = Element::getAtt("select");
        if (value.empty())
        {
            xml->XMLApply(templates);
        }
        else
        {
            map<string, Item*> temp;
            map<string, Item*>::iterator it = templates.find(value);
            temp.insert((*it));

            xml->XMLApply(temp);
        }
    }
    else if(name.compare("xsl:value-of") == 0)
    {
        //TODO : Handle a path instead of just .
        cout << xml->textContent() << endl;
    }
    else
    {
        cout << Element::name << endl;
    }
}


void EmptyTag::XMLApply(map<string, Item*> templates)
{
    
}