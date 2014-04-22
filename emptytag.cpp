#include "emptytag.h"

EmptyTag::EmptyTag(string name, vector<Atts *> atts) : Element(name, atts)
{
}

EmptyTag::EmptyTag(const Element& elem) : Element(elem)
{
    
}

void EmptyTag::print()
{
    cout << "<" << name << Element::attsToString() << "/>" << endl;
}


vector<Item*> EmptyTag::XSLTransform(Item* xml, map<string, Item*> templates)
{
    vector<Item*> result;
    if(name.compare("xsl:apply-templates") == 0)
    {
        string value = Element::getAtt("select");
        if (value.empty())
        {
            return xml->XMLApply(templates);
        }
        else
        {
            map<string, Item*> temp;
            map<string, Item*>::iterator it = templates.find(value);
            temp.insert((*it));
            
            return xml->XMLApply(temp);
        }
    }
    else if(name.compare("xsl:value-of") == 0)
    {
        
        string value = Element::getAtt("select");
        string content;
        xml->print();
        if(value.compare(".") == 0)
        {
            content = xml->textContent();
        }
        else
        {
            Item* item = *(xml->find("./" + value).begin());
            content = item->textContent();
        }
        result.push_back(new Content(content));
    }
    else
    {
        result.push_back(new EmptyTag(*this));
    }
    return result;
}