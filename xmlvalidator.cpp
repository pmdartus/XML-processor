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

            string regex = createRegex(construction, construction->getName());

			mapRegex.insert(pair<string, string>(name, regex));
			cout << "Regex added : " << regex << " for " << name << endl;
        }
		// TODO
	}
	else
	{
		cout << "Error: Wrong syntax for the given xsd while creating the maps." << endl;
	}
}

string Xmlvalidator::createRegex(Tag* construction, string elType) {
	string regex = "^(";

	vector<Item *> children = construction->getChildren();
	for(vector<Item *>::iterator itCh = children.begin(); itCh != children.end(); itCh++) {
		vector<Atts *> params = ((Tag *) (*itCh))->getAtts();
		string nameElem = "";
		string type = "";
		string nb = "";

		for(vector<Atts *>::iterator itPar = params.begin(); itPar != params.end(); itPar++) {
			if ((*itPar)->name == "name" || (*itPar)->name == "ref") {
				nameElem = (*itPar)->value;

				// Adding it into the regex
				regex += "(<"+nameElem+">)";
			}
			else if ((*itPar)->name == "type") {
				type = (*itPar)->value;
			}
			else if ((*itPar)->name == "maxOccurs") {
				nb = (*itPar)->value;

				// Adding it into the regex
				regex += "{,"+nb+"}";
			}
		}

		mapType.insert(pair<string, string>(nameElem, type));
		cout << nameElem << " is added to mapType as a " << type  << endl;

		if ((elType == "xsd:choice") && (itCh != children.end()-1)) {
			regex += "|";
		}
	}

	regex += ")$";
	
	return regex;
}

int Xmlvalidator::validityCheck(Document *xml) {
	int valid = checkNode((Item *) xml->getRoot());

	cout << "The document is " << valid << endl;

	return valid;
}

// 0 -> not valid; 1 -> valid
int Xmlvalidator::checkNode(Item* node) {
	Tag* tagNode = dynamic_cast<Tag *>(node);

	if (tagNode) {
		string name = tagNode->getName();
		string transfo = "";

		vector<Item *> children = tagNode->getChildren();
		for(vector<Item *>::iterator itCh = children.begin(); itCh != children.end(); itCh++) {
			Element* elNode = dynamic_cast<Element *>(*itCh);
			if (elNode)
			{
				transfo += "<"+elNode->getName()+">";
			}
			else
			{
				Content* ctNode = dynamic_cast<Content *>(*itCh);
				if (ctNode)
				{
					transfo += ctNode->getText();
				}

			}

			// Recursive call for each children
			if (checkNode((*itCh)) == 0)
			{
				// if it is not valid
				return 0;
			}
		}

		std::map<string,string>::iterator itRegex = mapRegex.find(name);

		if (itRegex->second == "") {
			std::map<string,string>::iterator itType = mapType.find(name);
		 	itRegex = mapRegex.find(itType->second);
		 	cout << "New regex " << itRegex->second << " for " << itType->second << endl;
		}

		string regex = itRegex->second;

		cout << "DO THE CHECK " << regex << " on " << transfo << " for the node " << name << endl;
	}

	return 1;
}
