%{

#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#include "commun.h"

extern char xmltext[];

int xmllex(void);  

void xmlerror(const char * msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char * s;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND

%%

document
 : lpi suiteprolog element lpi
 ;

suiteprolog
 : doctypecl lpi
 | /* vide */
 ;

doctypecl
 : DOCTYPE NAME NAME VALEUR
 | DOCTYPE NAME NAME VALEUR VALEUR
 ;

element
 : INF NOM atts SLASH SUP /* emptytag */
 | INF NOM atts SUP content
   INF SLASH NOM SUP /* tag */
 | INF NOM COLON NOM atts SUP content
   INF SLASH NOM COLON NOM SUP /* tag avec espace de nom */
 ;

atts
 : atts NOM EGAL VALEUR
 | /* vide */
 ;

lpi
 : lpi INFSPECIAL NOM atts SUPSPECIAL
 | /* vide */
 ;

content
 : content item          
 | /* vide */              
 ;

item
 : element
 | CDATABEGIN CDATAEND /* cdsect */
 | INFSPECIAL NOM atts SUPSPECIAL /* pi */
 | COMMENT
 | DONNEES
 ;
