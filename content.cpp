#include "content.h"

Content::Content(string text) : text(text) {}

Content::~Content() {}


const string Content::getText() const {
    return Content::text;
}

void Content::print()
{
    cout << getText()<<endl;
}