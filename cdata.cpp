#include "cdata.h"

CData::CData(string text) : Content(text) {

}

void CData::print()
{
    cout << "<![CDATA[" << Content::text << "]]>  ";
}