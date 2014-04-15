#include "xmltransformer.h"

XMLTransformer::XMLTransformer(Document* xmlDoc, Document* xslSheet)
{
    XMLTransformer::xmlDoc = xmlDoc;
    XMLTransformer::xslSheet = xslSheet;
}