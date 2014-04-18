#include "xmltransformer.h"
#include "content.h"

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

    currentHtmlElement->print();

    cout<<endl;
    cout<<endl;


    if (currentHtmlElement->getName().compare("xsl:value-of") == 0)
    {
        vector<Item*> childrens = xmlTag->getChildren();
        Content* contentTag = (Content*) childrens[0];

        cout<<"add info : " <<contentTag->getText()<<endl;
    }
    else if(currentHtmlElement->getName().compare("xsl:apply-templates") == 0)
    {
        string select;
        vector<Atts*> atts = currentHtmlElement->getAtts();
        for(vector<Atts *>::iterator it = atts.begin(); it != atts.end(); ++it) {
            if ((*it)->name.compare("select") == 0)
            {
                select = (*it)->value;
            }
        }

        // If there is a select
        if (select.length())
        {
            Item* selectedChild;
            vector<Item*> childrens = xmlTag->getChildren();

            for(vector<Item *>::iterator it = childrens.begin(); it != childrens.end(); ++it) {
                Element* childTotemplate = (Element*) (*it);
                string childName = childTotemplate->getName();
                if (childName.compare(select) == 0)
                {
                    selectedChild = (*it);
                }
            }

            vector<Item *> associatedTemplate = XMLTransformer::templates.at(select);
            for(vector<Item *>::iterator it = associatedTemplate.begin(); it != associatedTemplate.end(); ++it) {
                recusTemplating((*it), selectedChild);
            }
        }

        // If it's a simple template
        vector<Item*> childrens = xmlTag->getChildren();
        for(vector<Item *>::iterator it = childrens.begin(); it != childrens.end(); ++it) {
            Element* selectedChild = (Element*) (*it);
            string templateToFind = selectedChild->getName();

            cout<<"apply a template " << templateToFind <<endl;

            vector<Item *> associatedTemplate = XMLTransformer::templates.at(templateToFind);
            for(vector<Item *>::iterator it = associatedTemplate.begin(); it != associatedTemplate.end(); ++it) {
                recusTemplating((*it), selectedChild);
            }
        }
    }
    else
    {
        vector<Item*> childrens = htmlTag->getChildren();

        for(vector<Item *>::iterator it = childrens.begin(); it != childrens.end(); ++it) {
            recusTemplating((*it), xmlTag);
        }
    }
}