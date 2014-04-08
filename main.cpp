#include "commun.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

char* getCmdOption(char ** begin, char ** end, const string & option)
{
    char ** itr = find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const string& option)
{
    return find(begin, end, option) != end;
}

int xmlParse(char * filename)
{
    ifstream xml;
    xml.open(filename);

    if (xml.is_open())
    {
        string line;
        while (getline(xml, line))
        {
            cout<<line<<endl;
        }
    }

    return 0;
}

int main(int argc, char * argv[])
{

    if (cmdOptionExists(argv, argv+argc, "-h"))
    {
        cerr << "Available commands are:" << endl;
        cerr << "../xmltool -p file.xml : parse and display the xml file" << endl;
        cerr << "../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result" << endl;
        cerr << "../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl" << endl;
        cerr << "../xmltool -h : displays this help" << endl;
    }
    else if (cmdOptionExists(argv, argv+argc, "-p"))
    {
        char * filename = getCmdOption(argv, argv + argc, "-p");
        if (filename == NULL)
        {
            cerr << "You must provide an argument to the command -p" << endl;
        }
        else
        {
            return xmlParse(filename);
        }
    }
    else if (cmdOptionExists(argv, argv+argc, "-t"))
    {
        char * filename = getCmdOption(argv, argv + argc, "-t");
        if (filename == NULL)
        {
            cerr << "You must provide two arguments to the command -t: an xml file and an xsl file" << endl;
        }

    }
    else
    {
        cerr << "No argument given" << endl;
        cerr << "Available commands are:" << endl;
        cerr << "../xmltool -p file.xml : parse and display the xml file" << endl;
        cerr << "../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result" << endl;
        cerr << "../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl" << endl;
        cerr << "../xmltool -h : displays this help" << endl;
    }

    return 1;
}
