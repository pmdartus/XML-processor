#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "doctypedecl.h"
#include "pi.h"
#include "tag.h"
#include <vector>

using namespace std;

class Document {

private:
    vector<Pi *> misc_prolog;
    vector<Pi *> misc_doctype;
    Item* root;
    vector<Pi *> misc_element;
    
public:
    Document(vector<Pi *> misc_prolog, vector<Pi *> misc_doctype, Item *root, vector<Pi *> misc_element);
    ~Document();
    //const Item* getRoot() const;
};

#endif
