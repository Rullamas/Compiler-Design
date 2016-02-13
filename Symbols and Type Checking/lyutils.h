#ifndef __LYUTILS_H__
#define __LYUTILS_H__

#include <stdio.h>

#include "astree.h"
//Nico Williams and Brandon Rullamas
//nijowill and brullama
//Assignment 4 - Symbols and Type Checking

#include "auxlib.h"

#define YYEOF 0

extern FILE* yyin;
extern astree* yyparse_astree;
extern int yyin_linenr;
extern char* yytext;
extern int yy_flex_debug;
extern int yydebug;
extern int yyleng;

int yylex (void);
int yyparse (void);
void yyerror (const char* message);
int yylex_destroy (void);
const char* get_yytname (int symbol);
bool is_defined_token (int symbol);

const string* scanner_filename (int filenr);
void scanner_newfilename (const char* filename);
void scanner_badchar (unsigned char bad);
void scanner_badident (char* lexeme);
void scanner_badstring(char* lexeme);
void scanner_badtoken (char* lexeme);
void scanner_newline (void);
void scanner_setecho (bool echoflag);
void scanner_useraction (void);

astree* new_parseroot (void);
int yylval_token (int symbol);

void scanner_include (void);

typedef astree* astree_pointer;
#define YYSTYPE astree_pointer
#include "yyparse.h"


#endif
