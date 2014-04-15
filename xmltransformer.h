#ifndef XMLTRANSFORMER_H
#define XMLTRANSFORMER_H

#include "commun.h"
#include "document.h"

class XMLTransformer {

private:
  Document* xmlDoc;
  Document* xslSheet;

public:
    XMLTransformer(Document* xmlDoc, Document* xslSheet);
    ~XMLTransformer();

};

#endif
