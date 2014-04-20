#ifndef DOCUMENT_H
#define DOCUMENT_H


#include "commun.h"
#include "doctypedecl.h"
#include "pi.h"
#include "tag.h"
#include <vector>


class Document {

private:
    vector<Pi *> misc_prolog;
    vector<Pi *> misc_doctype;
    Tag *root;
    vector<Pi *> misc_element;
    Doctypedecl *doctypedecl = 0;
    
    void printPis(vector<Pi *> pis);
    
public:
    Document(vector<Pi *> misc_prolog, vector<Pi *> misc_doctype, Tag *root, vector<Pi *> misc_element);
    ~Document();
    const Tag * getRoot() const;
    void setDoctypedecl(Doctypedecl *doctype);
    void print();

    
    Document* transform(Document* xslSheet);
};

#endif
