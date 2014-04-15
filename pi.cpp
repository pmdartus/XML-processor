#include "pi.h"
#include <iostream>

Pi::Pi(string name, vector<Atts *> atts) : Element(name, atts)
{
	cout << "Pi's constructor" << endl;
}

void Pi::print()
{
    cout << "<?" << name << attsToString() << "?>" << endl;
}
