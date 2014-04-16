#ifndef XMLTRANSFORMER_H
#define XMLTRANSFORMER_H

#include "commun.h"
#include "document.h"
#include <map>

typedef map<string,vector<Item*>> TemplatesLib;

class XMLTransformer {

private:
  Document* xmlDoc;
  TemplatesLib templates;

public:
    XMLTransformer(Document* xmlDoc, Document* xslSheet);
    ~XMLTransformer();

    void exec();
    void recusTemplating(const Item* htmlTag, const Item* xmlTag) const;
};

#endif
