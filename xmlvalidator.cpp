#include "xmlvalidator.h"


Xmlvalidator::Xmlvalidator() {}

void Xmlvalidator::mapsCreate(Document *xsd) {
	// Check that the root is a schema
	if (xsd->getRoot()->getName() == "xsd:schema")
	{
		vector<Item*> children = xsd->getRoot()->getChildren();
		cout << "Start creating the maps" << endl;
		// TODO
	}
	else
	{
		cout << "Error: Wrong syntax for the given xsd while creating the maps." << endl;
	}
}

void Xmlvalidator::validityCheck(Document *xml) {
}
