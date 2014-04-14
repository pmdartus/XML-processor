#ifndef CONTENT_H
#define CONTENT_H

#include "element.h"
#include "commun.h"

class Content : public Item
{
    
private:
    string text;
    
public:
    Content(string text);
    const string getText() const;
    
};

#endif
