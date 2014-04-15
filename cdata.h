#ifndef CDATA_H
#define CDATA_H

#include "commun.h"
#include "content.h"

class CData : public Content {

public:
    CData(string text);

    void print();
};

#endif
