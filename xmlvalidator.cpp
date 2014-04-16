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

            // Get the contruction node
            Tag * type = (Tag *) ((Tag *) (*itElem))->getChildren().front();
            Tag * construction = (Tag *) type->getChildren().front();
            cout << "Will create a regex for " << construction->getName() << endl;

            if (construction->getName() == "xsd:choice")
            {
            	choiceRegex(construction);
            }
            else if (construction->getName() == "xsd:sequence")
            {
            	seqRegex(construction);
            }
        }
		// TODO
	}
	else
	{
		cout << "Error: Wrong syntax for the given xsd while creating the maps." << endl;
	}
}

void Xmlvalidator::choiceRegex(Tag* choice) {
	cout << "Processing a choice complexType " << endl;
	// TODO
    // mapRegex.insert(pair<string, string>(name, regex));
}

void Xmlvalidator::seqRegex(Tag* seq) {
	cout << "Processing a sequence complexType " << endl;
	// TODO
}

void Xmlvalidator::validityCheck(Document *xml) {
}
