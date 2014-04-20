#include "comment.h"

Comment::Comment(string text) : Content(text) {

}

void Comment::print()
{
    cout << Content::text;
}