#ifndef COMMENT_H
#define COMMENT_H

#include "commun.h"
#include "content.h"

class Comment : public Content {

public:
    Comment(string text);

    void print();
};

#endif
