#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "doctypedecl.h"
#include "pi.h"
#include "tag.h"
#include <vector>

class Document {

private:
    vector<Pi *> misc_prolog;
    vector<Pi *> misc_doctype;
    Tag * root;
    vector<Pi *> misc_element;
    
public:
    Document(vector<Pi *> misc_prolog, vector<Pi *> misc_doctype, Tag * root, vector<Pi *> misc_element);
    ~Document();
    Tag getRoot();
};

#endif
