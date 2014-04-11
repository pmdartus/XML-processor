#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "doctypedecl.h"
#include "pi.h"
#include "tag.h"
#include <vector>

using namespace std;

class Document {

private:
    Doctypedecl* doctype;
    vector<Pi *> prologs;
    vector<Pi *> doctypes;
    vector<Pi *> elements;
    Tag * root;
    
public:
    Document();
    ~Document();
    
};

#endif
