#include "document.h"

Document::Document(vector<Pi *> misc_prolog, vector<Pi *> misc_doctype, Tag *root, vector<Pi *> misc_element) :
    misc_prolog(misc_prolog),
    misc_doctype(misc_doctype),
    root(root),
    misc_element(misc_element) {
}

Document::Document(Tag* root) : root(root)
{
    
}

Document::~Document()
{
    vector<Pi *>::iterator it;

    it = misc_prolog.begin();
    while (it != misc_prolog.end())
    {
        it = misc_prolog.erase(it);
    }
    it = misc_doctype.begin();
    while (it != misc_doctype.end())
    {
        it = misc_doctype.erase(it);
    }
    it = misc_element.begin();
    while (it != misc_element.end())
    {
        it = misc_element.erase(it);
    }
    delete root;
}

const Tag * Document::getRoot() const
{
    return root;
}

void Document::setDoctypedecl(Doctypedecl *doctype)
{
    doctypedecl = doctype;
}

void Document::printPis(vector<Pi *> pis)
{
    vector<Pi *>::iterator it = pis.begin();
    while (it != pis.end()) {
        (*it)->print();
        it++;
    }
}

void Document::print()
{
    printPis(Document::misc_prolog);

    if (doctypedecl != 0)
    {
        doctypedecl->print();
    }

    printPis(Document::misc_doctype);
    root->print();
    printPis(Document::misc_element);
}




Document* Document::transform(Document* xslSheet)
{
    map<string, Item*> templates;
    
    const Tag* xslRoot = xslSheet->getRoot();
    vector<Item*> children = xslRoot->getChildren();
    
    for(vector<Item*>::iterator it = children.begin(); it != children.end(); ++it) {
        
        string pattern;
        Tag* currentTag = (Tag*) *it;
        vector<Atts*> atts = currentTag->getAtts();
        for(vector<Atts *>::iterator it = atts.begin(); it != atts.end(); ++it) {
            if ((*it)->name.compare("match") == 0)
            {
                pattern = (*it)->value;
            }
        }
        
        templates.insert(pair<string, Item*>(pattern, currentTag));
    }
    
    Item* xslptr = templates.find("/")->second;
    vector<Item*> res = xslptr->XSLTransform(this->root, templates);
    Tag* htmlroot = static_cast<Tag*>(*(res.begin()));
    
    vector<Item*> test = root->find("catalog/cd");
    for(vector<Item*>::iterator it = test.begin(); it != test.end(); ++it)
    {
          (*it)->print();
    }
    return new Document(htmlroot);
}
