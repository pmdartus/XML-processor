#include "tag.h"
#include "content.h"

Tag::Tag(string name, vector<Atts *> atts, vector<Item *> children) :
    Element(name, atts),
    children(children)
{
        for(vector<Item *>::iterator it = children.begin(); it != children.end(); it++)
        {
            (*it)->setParent(this);
        }
}

Tag::~Tag()
{
    vector<Item *>::iterator it = children.begin();
    while (it != children.end())
    {
        delete (*it);
        it = children.erase(it);
    }
}

void Tag::print()
{
        cout << "<" << name;

        if (!Tag::atts.empty())
        {
            cout << " " << Element::attsToString();
        }
        cout << ">" << endl;

        for(vector<Item *>::iterator it = children.begin(); it != children.end(); it++)
        {
            (*it)->print();
        }

        cout << "</" << name << ">"<<endl;
}

vector<Item*> Tag::getChildren() const
{
    return children;
}


string Tag::textContent() const
{
    string content;
    for(vector<Item*>::const_iterator it = children.begin(); it != children.end(); it++)
    {
        content += (*it)->textContent();
    }
    return content;
}


void Tag::XMLApply(map<string, Item*> templates)
{

    map<string, Item*>::iterator found = templates.find(Element::name);
    if(found != templates.end())
    {
        Item* xslptr = found->second;
        xslptr->XSLTransform(this, templates);
    }
    else
    {
        for(vector<Item*>::iterator it = children.begin(); it != children.end(); it++)
        {
            (*it)->XMLApply(templates);
        }
    }
}

void Tag::XSLTransform(Item* xml, map<string, Item*> templates)
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
        for(vector<Item*>::iterator it = children.begin(); it != children.end(); it++)
        {
            (*it)->XSLTransform(xml, templates);
            if(name.compare("xsl:template") != 0)
            {
                cout << "Transformed: " << Element::name << endl;
            }
        }
    }
}