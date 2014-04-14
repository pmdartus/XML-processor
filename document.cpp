#include "document.h"

Document::Document(vector<Pi *> misc_prolog, vector<Pi *> misc_doctype, Tag *root, vector<Pi *> misc_element) {
    Document::misc_prolog = misc_prolog;
    Document::misc_doctype = misc_doctype;
    Document::root = root;
    Document::misc_element = misc_element;
    
}

Document::~Document() {
    delete Document::root;
}