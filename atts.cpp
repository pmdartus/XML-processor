#include "atts.h"

Atts::Atts(string name, string value) : name(name), value(value)
{
    
}


Atts::Atts(const Atts& att)
{
    name = att.name;
    value = att.value;
}