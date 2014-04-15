#include "commun.h"
#include "document.h"
#include "doctypedecl.h"

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
int xmlParse(char* filename)
{
    checkFileExistence(filename);
    Document *doc = 0;
    Doctypedecl *doctype = 0;
    int retStatus = xmlparse(&doc, &doctype);

    if (doc != 0)
    {
        if (doctype != 0)
        {
            doc->setDoctypedecl(doctype);
        }

        doc->print();

        return 0;
    }
    else
    {
        cerr << "No root markup" << endl;
        return 1;
    }
}

int xmlTransform(char* xmlFileName, char* xslFileName)
{
    checkFileExistence(xmlFileName);
    checkFileExistence(xslFileName);

    Document *xml = 0;
    Doctypedecl *xmlDoctype = 0;
    xmlparse(&xml, &xmlDoctype);

    if (xml != 0 && xmlDoctype != 0)
    {
        xml->setDoctypedecl(xmlDoctype);
    }

    Document *xsl = 0;
    Doctypedecl *xslDoctype = 0;
    xmlparse(&xsl, &xslDoctype);

    if (xsl != 0 && xslDoctype != 0)
    {
        xsl->setDoctypedecl(xslDoctype);
    }

    cout<<"coucou"<<endl;

   return 1;
}

int xmlValidate(char* xmlFileName, char* xsdFileName)
{
   checkFileExistence(xmlFileName);
   checkFileExistence(xsdFileName);

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
            return xmlParse(fileName);
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
