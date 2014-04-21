#include "content.h"

Content::Content(string text) : Item(), text(text) {}


Content::~Content() {}


void Content::print()
{
    cout << text << endl;
}

string Content::textContent() const
{
    return text;
}

vector<Item*> Content::XSLTransform(Item* xml, map<string, Item*> templates)
{
    vector<Item*> vector;
    vector.push_back(new Content(text));
    return vector;
}
