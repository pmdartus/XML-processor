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

}