#include "commun.h"
#include "document.h"
#include "doctypedecl.h"
#include "xmlvalidator.h"

#include <unistd.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

extern FILE *xmlin;
int xmlparse (Document **d, Doctypedecl **dt);

/**
 * Return if the passed option existor not in the command
 */
bool cmdOptionExists(char** begin, char** end, const string& option)
{
    return find(begin, end, option) != end;
}

/**
 * Display help in the error channel
 */
bool cmdHelp(bool argumentsFound = true) {
    if (!argumentsFound)
    {
        cerr << "No argument given" << endl;
    }
    cerr << "Available commands are:" << endl;
    cerr << "../xmltool -p file.xml : parse and display the xml file" << endl;
    cerr << "../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result" << endl;
    cerr << "../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl" << endl;
    cerr << "../xmltool -h : displays this help" << endl;

    return 1;
}

/**
 * Check if the file exist, if not the program exit and return a 1 status
 */
void checkFileExistence(char* filename)
{

    FILE *fid = fopen(filename, "r");
    if (fid == NULL) {
       cerr << "Unable to open file " <<filename<< endl;
       exit(1);
    }
    xmlin = fid;
}

/**
 * Parse and display the passed document
 */
int xmlParse(char* filename, Document* doc)
{
    checkFileExistence(filename);
    Doctypedecl *doctype = 0;
    int retStatus = xmlparse(&doc, &doctype);

    if (doc != 0)
    {
        if (doctype != 0)
        {
            doc->setDoctypedecl(doctype);
        }

        return 1;
    }
    else
    {
        return 0;
    }
}

int xmlTransform(char* xmlFileName, char* xslFileName)
{
   checkFileExistence(xmlFileName);
   checkFileExistence(xslFileName);

   return 1;
}

int xmlValidate(char* xmlFileName, char* xsdFileName)
{
    Document *xsd = 0;
    int parseXsd = xmlParse(xsdFileName, xsd);
    Xmlvalidator* xval = new Xmlvalidator();
    if (parseXsd)
    {
        xval->mapsCreate(xsd);
    }

    Document *xml = 0;
    int parseXml = xmlParse(xmlFileName, xml);

    return 1;
}

int main(int argc, char* argv[])
{

    if (cmdOptionExists(argv, argv+argc, "-p"))
    {
        if (argc != 3)
        {
            cerr << "You must provide an argument to the command -p" << endl;
        }
        else
        {
            char *fileName = argv[2];
            Document *doc = 0;
            int parse = xmlParse(fileName, doc);
            doc->print();
            return parse;
        }
    }
    else if (cmdOptionExists(argv, argv+argc, "-t"))
    {
        if (argc != 4)
        {
            cerr << "You must provide two arguments to the command -t: an xml file and an xsl file" << endl;
        }
        else
        {
            char *xmlFileName = argv[2];
            char *xslFileName = argv[3];
            return xmlTransform(xmlFileName, xslFileName);
        }

    }
    else if (cmdOptionExists(argv, argv+argc, "-v"))
    {
        if (argc != 4)
        {
            cerr << "You must provide two arguments to the command -v: an xml file and an xsd file" << endl;
        }
        else
        {
            char *xmlFileName = argv[2];
            char *xsdFileName = argv[3];
            return xmlValidate(xmlFileName, xsdFileName);
        }

    }
    else if (cmdOptionExists(argv, argv+argc, "-h"))
    {
        return cmdHelp();
    }
    else
    {
        bool argumentFound = false;
        return cmdHelp(argumentFound);
    }

    return 1;
}
