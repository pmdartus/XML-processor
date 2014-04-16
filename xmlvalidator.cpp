#include "xmlvalidator.h"


Xmlvalidator::Xmlvalidator() {}

void Xmlvalidator::mapsCreate(Document *xsd) {
	// Check that the root is a schema
	if (xsd->getRoot()->getName() == "xsd:schema")
	{
		cout << "Start creating the maps" << endl;

		// Get all the childrens
		vector<Item*> children = xsd->getRoot()->getChildren();

		for(vector<Item *>::iterator itElem = children.begin(); itElem != children.end(); itElem++) {
			// Get the actual element name
            string name = ((Tag *) (*itElem))->getAtts().front()->value;

            cout << "Get ready for the regex of " << name << endl;
            // mapRegex.insert(pair<string, string>(name, regex));
        }
		// TODO
	}
	else
	{
		cout << "Error: Wrong syntax for the given xsd while creating the maps." << endl;
	}
}

void Xmlvalidator::validityCheck(Document *xml) {
}
