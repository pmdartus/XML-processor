#include "content.h"

Content::Content(string text) : text(text) {}

const string Content::getText() const {
    return Content::text;
}

void Content::print()
{
    cout << getText();
}