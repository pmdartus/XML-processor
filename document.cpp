#include "document.h"

Document::Document(vector<Pi *> misc_prolog, vector<Pi *> misc_doctype, Tag * root, vector<Pi *> misc_element) {
    this->misc_prolog = misc_prolog;
    this->misc_doctype = misc_doctype;
    this->root = root;
    this->misc_element = misc_element;
    
}

Document::~Document() {
    delete Document::root;
}