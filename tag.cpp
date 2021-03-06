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

Tag::Tag(const Element& elem, vector<Item*> children) :
    Element(elem),
    children(children)
{
    for(vector<Item*>::iterator it = children.begin(); it != children.end(); it++)
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


vector<Item*> Tag::find(string path) const
{
    string current = path.substr(0, path.find("/"));
    string newPath = path.substr(path.find("/") + 1, path.length());
    
    vector<Item*> result;
    if(current.compare(Element::name) == 0 || current.compare(".") == 0)
    {
        if(newPath.compare(current) == 0)
        {
            result.push_back((Item*)this);
        }
        else
        {
            for(vector<Item*>::const_iterator it = children.begin(); it != children.end(); it++)
            {
                vector <Item*> elems = (*it)->find(newPath);
                result.insert(result.end(), elems.begin(), elems.end());
            }
        }
    }
    return result;
}



vector<Item*> Tag::XMLApply(map<string, Item*> templates)
{
    map<string, Item*>::iterator found = templates.find(Element::name);
    if(found != templates.end())
    {
        Item* xslptr = found->second;
        return xslptr->XSLTransform(this, templates);
    }
    else
    {
        vector<Item*> result;
        for(vector<Item*>::iterator it = children.begin(); it != children.end(); it++)
        {
            vector <Item*> html = (*it)->XMLApply(templates);
            result.insert(result.end(), html.begin(), html.end());
        }
        return result;
    }
}

vector<Item*> Tag::XSLTransform(Item* xml, map<string, Item*> templates)
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
        if(value.compare(".") == 0 || value.compare(Element::name) == 0)
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
    else if(name.compare("xsl:for-each") == 0)
    {
        string value = Element::getAtt("select");
        vector<Item*> found = xml->find(value);
        vector<Item*>::iterator foundIt = found.begin();
        vector<Item*>::iterator childrenIt = children.begin();
        
        for(; childrenIt != children.end(); childrenIt++)
        {
            for(; foundIt != found.end(); foundIt++)
            {
                vector<Item*> html = (*childrenIt)->XSLTransform((*foundIt), templates);
                result.insert(result.end(), html.begin(), html.end());
            }
        }
    }
    else
    {
        vector<Item*> tagChildren;
        for(vector<Item*>::iterator it = children.begin(); it != children.end(); it++)
        {
            vector<Item*> html = (*it)->XSLTransform(xml, templates);
            tagChildren.insert(tagChildren.end(), html.begin(), html.end());
        }
        result.push_back(new Tag(*this, tagChildren));
        if(name.compare("xsl:template") == 0)
        {
            return tagChildren;
        }
    }
    return result;
}