#ifndef CONTENT_H
#define CONTENT_H

#include "element.h"
#include <string>

using namespace std;

class Content : public Element
{
    
private:
    string text;
    
public:
    Content();
    ~Content();
    const string getText() const;
    
};

#endif