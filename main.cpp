#include "commun.h"
#include <iostream>
#include <cstring>

using namespace std;

char* getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return find(begin, end, option) != end;
}

int xmlparse(void);

int main(int argc, char * argv[])
{
    if(cmdOptionExists(argv, argv+argc, "-h"))
    {
        cerr<<"Available commands are:"<<endl;
        cerr<<"../xmltool -p file.xml : parse and display the xml file"<<endl;
        cerr<<"../xmltool -v file.xml file.xsd : parse both xml and xsd files and display the validation result"<<endl;
        cerr<<"../xmltool -t file.xml file.xsl : parse both xml and xsl files and display de transformation result of file.xml by the stylesheet file.xsl"<<endl;
        cerr<<"../xmltool -h : displays this help"<<endl;
    }

    char * parsingFile = getCmdOption(argv, argv + argc, "-f");

    if (parsingFile)
    {
        cout<<"Parsing file"<<endl;
    }

    return 1;
}
