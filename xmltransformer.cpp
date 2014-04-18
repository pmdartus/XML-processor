#include "xmltransformer.h"

XMLTransformer::XMLTransformer(Document* xmlDoc, Document* xslSheet)
{
    XMLTransformer::xmlDoc = xmlDoc;

    const Tag* root = xslSheet->getRoot();
    vector<Item*> children = root->getChildren();

    for(vector<Item *>::iterator it = children.begin(); it != children.end(); ++it) {

        string pattern;
        Tag* currentTag = (Tag*) *it;
        vector<Atts*> atts = currentTag->getAtts();
        for(vector<Atts *>::iterator it = atts.begin(); it != atts.end(); ++it) {
            if ((*it)->name.compare("match") == 0)
            {
                pattern = (*it)->value;
            }
        }

        vector<Item*> currentTemplate = currentTag->getChildren();
        XMLTransformer::templates.insert(pair<string, vector<Item*>>(pattern, currentTemplate));
    }
}

void XMLTransformer::exec()
{
    vector<Item *> rootTemplate = XMLTransformer::templates["/"];
    Tag* rootTag = (Tag*) rootTemplate[0];
    Document* htmlDoc = new Document(rootTag);

    recusTemplating(htmlDoc->getRoot(), XMLTransformer::xmlDoc->getRoot());

    htmlDoc->print();
}

void XMLTransformer::recusTemplating(const Item* htmlTag, const Item* xmlTag) const
{
    Element* currentHtmlElement = (Element*)htmlTag;


    if (currentHtmlElement->getName().compare("xsl:value-of") == 0)
    {
        cout<<"add info"<<endl;
    }
    else if(currentHtmlElement->getName().compare("xsl:apply-templates") == 0)
    {
        cout<<"apply a template"<<endl;
    }
    else
    {
        vector<Item*> childrens = htmlTag->getChildren();

        for(vector<Item *>::iterator it = childrens.begin(); it != childrens.end(); ++it) {
            recusTemplating((*it), xmlTag);
        }
    }
}