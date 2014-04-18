#ifndef CONTENT_H
#define CONTENT_H

#include "element.h"
#include "commun.h"
#include <vector>

class Content : public Item
{

private:
    string text;

public:
    Content(string text);
    const string getText() const;

    void print();
    const vector<Item*> getChildren() const;
};

#endif
