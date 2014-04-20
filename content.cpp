#include "content.h"

Content::Content(string text) : text(text) {}

Content::~Content() {}


void Content::print()
{
    cout << text << endl;
}

void Content::XSLTransform(Item* xml, map<string, Item*> templates)
{
    cout << text << endl;
}

string Content::textContent() const
{
    return text;
}