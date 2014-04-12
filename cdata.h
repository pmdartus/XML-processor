#ifndef CDATA_H
#define CDATA_H

#include "content.h"
#include <string>

using namespace std;

class CData : public Content {
    
private:
    
    
public:
    CData(string text);
    ~CData();
    
};

#endif
