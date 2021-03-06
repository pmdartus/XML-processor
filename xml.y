%{

#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;
#include "commun.h"
#include "item.h"
#include "atts.h"
#include "cdata.h"
#include "content.h"
#include "doctypedecl.h"
#include "document.h"
#include "element.h"
#include "emptytag.h"
#include "tag.h"
#include "pi.h"
#include "comment.h"

extern char xmltext[];

int xmllex(void);

void xmlerror(Document ** d,
               Doctypedecl ** dt,
               const char *msg)
{
   fprintf(stderr,"%s\n",msg);
}

%}

%union {
   char *s;
   // Perso
   Item *i;
   Element *e;
   EmptyTag *et;
   Tag *t;
   Doctypedecl *doc;
   vector<Atts *> *la;
   vector<Pi *> *lp;
   vector<Item *> *c;
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE COLON INFSPECIAL INF CDATABEGIN
%token <s> VALEUR DONNEES COMMENT NOM CDATAEND
// Perso
%type <e> element /* Element is an item because it can contain content ;) */
%type <i> item
%type <et> emptytag
%type <t> tag
%type <la> atts
%type <lp> lpi
%type <lp> suiteprolog
%type <c> content
%type <doc> doctypecl

%parse-param { Document **d }
%parse-param { Doctypedecl **dt } // retour du parseur

%%

// Document :: $1 => vector<Pi *> * | $2 => vector<Pi *> * | $3 => Tag * | $4 => vector<Pi *> *
// Dereferencing the pointer to fit the constructor
document
 : lpi suiteprolog tag lpi      { if ($2) {
                                    *d = new Document(*$1, *$2, $3, *$4);
                                 } else {
                                    *d = new Document(*$1, vector<Pi *>(), $3, *$4);
                                 } }
 ;

suiteprolog
 : doctypecl lpi                    { $$ = $2; }
 | /* vide */                       { $$ = 0; }
 ;

/* doctypecl param du parseur parsparam -> pointeur null qui sera affecté */
doctypecl
 : DOCTYPE NOM SUP                      { *dt = new Doctypedecl(string($2)); }
 | DOCTYPE NOM NOM VALEUR SUP           { *dt = new Doctypedecl(string($2), string($3), string($4)); }
 | DOCTYPE NOM NOM VALEUR VALEUR SUP    { *dt = new Doctypedecl(string($2), string($3), string($4), string($5)); }
 ;

// EmptyTag :: $1 => char * | $2 => vector<Atts *> *
// Tag :: $2 => char * | $3 => vector<Atts *> * | $5 => vector<Item *> *
element
 : emptytag                { $$ = $1; }
 | tag                     { $$ = $1; }
 ;

// Atts :: $2 => char * | $3 => char *
atts
 : atts NOM EGAL VALEUR                { $$ = $1; $$ -> push_back(new Atts(string($2), string($4))); }
 | atts NOM COLON NOM EGAL VALEUR      { $$ = $1; $$ -> push_back(new Atts(string($2) + ":" + string($4), string($6))); }
 | /* vide */                          { $$ = new vector <Atts *>(); }
 ;

// Pi :: $3 => char * | $4 => vector<Atts *> *
lpi
 : lpi INFSPECIAL NOM atts SUPSPECIAL     { $$ = $1; $$ -> push_back(new Pi(string($3), *$4)); }
 | /* vide */                             { $$ = new vector <Pi *>(); }
 ;

content
 : content item         { $$ = $1; if($2) { $$ -> push_back($2); } }
 | /* vide */           { $$ = new vector <Item *>(); }
 ;


// Content :: $2 => char *
// CData :: $2 => char *
item
 : element                                   { $$ = $1; }
 | CDATABEGIN CDATAEND /* cdsect */          { $$ = new CData(string($2)); }
 | INFSPECIAL NOM atts SUPSPECIAL /* pi */   { $$ = new Pi(string($2), *$3); }
 | COMMENT                                   { $$ = new Comment(string($1)); }
 | DONNEES                                   { $$ = new Content(string($1)); }
 ;

emptytag
 : INF NOM atts SLASH SUP /* emptytag */           { $$ = new EmptyTag(string($2), *$3); }
 | INF NOM COLON NOM atts SLASH SUP /* emptytag */ { $$ = new EmptyTag(string($2) + ":" + string($4), *$5); }
 ;

tag
 : INF NOM atts SUP
   content
   INF SLASH NOM SUP /* tag */            {
                                             string tagNameBegin = string($2);
                                             string tagNameEnd = string($8);
                                             if(tagNameBegin.compare(tagNameEnd) != 0)
                                             {
                                                string msg = "Non matching element names " + tagNameBegin + " and " + tagNameEnd;
                                                fprintf(stderr,"%s\n",msg.c_str());
                                             }
                                             $$ = new Tag(string($2), *$3, *$5);
                                          }
 | INF NOM COLON NOM atts SUP
   content
   INF SLASH NOM COLON NOM SUP /* tag avec espace de nom */ {
                                                               string tagNSBegin = string($2);
                                                               string tagNSEnd = string($10);
                                                               if(tagNSBegin.compare(tagNSEnd) != 0)
                                                               {
                                                                  string msg = "Non matching element namespaces " + tagNSBegin + " and " + tagNSEnd;
                                                                  fprintf(stderr,"%s\n",msg.c_str());
                                                               }

                                                               string tagNameBegin = string($4);
                                                               string tagNameEnd = string($12);
                                                               if(tagNameBegin.compare(tagNameEnd) != 0)
                                                               {
                                                                  string msg = "Non matching element names " + tagNameBegin + " and " + tagNameEnd;
                                                                  fprintf(stderr,"%s\n",msg.c_str());
                                                               }
                                                               $$ = new Tag(string($2) + ":" + string($4), *$5, *$7);
                                                            }
 ;
