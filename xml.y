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
   // Perso
   Item* i;
   list<Attribut *>* la;
   list<Pi *>* lp;
   list<Item*> *c;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND
// Perso
%type <i> element; /* Element is an item because it can contain content ;) */
%type <i> item;
%type <la> atts;
%type <lp> lpi;
%type <c> content;

%parseparam {
	Document **d
	Doctypedecl ** dt;
} // retour du parseur

%%

document
 : lpi suiteprolog element lpi      { *d = new Document($1, $2, $3, $4); }
 ;

suiteprolog
 : doctypecl lpi { $$ = $1+$2; }
 | /* vide */
 ;

/* doctypecl param du parseur parsparam -> pointeur null qui sera affecté */
/* QUESTION : on peut mettre le *dt dans push back? */
doctypecl
 : DOCTYPE NAME NAME VALEUR         { $$ = $1; *dt = new Doctypedecl($2, $3, $4); $$->push_back(*dt); }
 | DOCTYPE NAME NAME VALEUR VALEUR  { $$ = $1; *dt = new Doctypedecl($2, $3, $4, $5); $$->push_back(*dt); }
 ;

element
 : INF NOM atts SLASH SUP /* emptytag */ { $$ }
 | INF NOM atts SUP
   content
   INF SLASH NOM SUP /* tag */
 | INF NOM COLON NOM atts SUP
   content
   INF SLASH NOM COLON NOM SUP /* tag avec espace de nom */
 ;

atts
 : atts NOM EGAL VALEUR
 | /* vide */
 ;

lpi
 : lpi INFSPECIAL NOM atts SUPSPECIAL		{ $$ = $1; $$ -> push_back(new Pi($3, $4)); }
 | /* vide */										{ $$ = new list <pi *>(); }
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

%%
