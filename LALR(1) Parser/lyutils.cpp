
#include <vector>
#include <string>
using namespace std;

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "auxlib.h"
#include "astree.h"

astree* yyparse_astree = NULL;
int scan_linenr = 1;
int scan_offset = 0;
extern FILE *tokfile;
bool scan_echo = false;
vector<string> included_filenames;
astree* new_tree = NULL;

struct{
    char **filenames;
    int size;
    int last_filenr;
    
} filename_stack = {NULL, 0,-1};

const string* lexer_filename (int filenr) {
   return &included_filenames.at(filenr);
}

void lexer_newfilename (const char* filename) {
   included_filenames.push_back (filename);
}

void lexer_newline (void) {
   ++scan_linenr;
   scan_offset = 0;
}

void lexer_setecho (bool echoflag) {
   scan_echo = echoflag;
}


void lexer_useraction (void) {
   if (scan_echo) {
      if (scan_offset == 0) printf (";%5d: ", scan_linenr);
      printf ("%s", yytext);
   }
   scan_offset += yyleng;
}

void yyerror (const char* message) {
   assert (not included_filenames.empty());
   errprintf ("%:%s: %d: %s\n",
              included_filenames.back().c_str(),
              scan_linenr, message);
}

void lexer_badchar (unsigned char bad) {
   char char_rep[16];
   sprintf (char_rep, isgraph (bad) ? "%c" : "\\%03o", bad);
   errprintf ("%:%s: %d: invalid source character (%s)\n",
              included_filenames.back().c_str(),
              scan_linenr, char_rep);
}

void lexer_badtoken (char* lexeme) {
   errprintf ("%:%s: %d: invalid token (%s)\n",
              included_filenames.back().c_str(),
              scan_linenr, lexeme);
}

int yylval_token (int symbol) {
   int offset = scan_offset - yyleng;
   yylval = new astree (symbol, included_filenames.size() - 1,
                        scan_linenr, offset, yytext);
   return symbol;
}

astree* new_parseroot (void) {
   yyparse_astree = new astree (TOK_ROOT, 0, 0, 0, "");
   return yyparse_astree;
}

astree* new_function (void){
    new_tree = new_astree(TOK_FUNCTION, filename_stack.last_filenr,scan_linenr ,yyleng, "Function");
    return new_tree;
}

astree* new_protonode(void){
    new_tree = new_astree(TOK_PROTOTYPE, filename_stack.last_filenr,scan_linenr ,yyleng, "");
    return new_tree;
}

astree* new_node(string name){
    new_tree = new_astree(TOK_NONTERMINAL, filename_stack.last_filenr, scan_linenr, yyleng, name.c_str());
    return new_tree;
}

astree* new_tokenStruct(void){
    new_tree = new_astree(TOK_STRUCT, filename_stack.last_filenr,scan_linenr ,yyleng, "Struct");
    return new_tree;
}
astree* new_vardecl(void){
    new_tree = new_astree(TOK_VARDECL, filename_stack.last_filenr,scan_linenr ,yyleng, "Vardecl");
    return new_tree;
}
astree* new_if(void){
    new_tree = new_astree(TOK_IF, filename_stack.last_filenr,scan_linenr ,yyleng, "If");
    return new_tree;
}

astree* new_else(void){
    new_tree = new_astree(TOK_ELSE, filename_stack.last_filenr,scan_linenr ,yyleng, "Else");
    return new_tree;
}

astree* new_leave(void){
    new_tree = new_astree(TOK_LEAVE, filename_stack.last_filenr,scan_linenr ,yyleng, "Leave");
    return new_tree;
}

astree* new_while(void){
    new_tree = new_astree(TOK_WHILE, filename_stack.last_filenr,scan_linenr ,yyleng, "While");
    return new_tree;
}
astree* new_binop(void){
    new_tree = new_astree(TOK_BINOP, filename_stack.last_filenr,scan_linenr ,yyleng, "Binop");
    return new_tree;
}


void lexer_include (void) {
   lexer_newline();
   char filename[strlen (yytext) + 1];
   int linenr;
   int scan_rc = sscanf (yytext, "# %d \"%[^\"]\"",
                         &linenr, filename);
   if (scan_rc != 2) {
      errprintf ("%: %d: [%s]: invalid directive, ignored\n",
                 scan_rc, yytext);
   }else {
      printf (";# %d \"%s\"\n", linenr, filename);
      lexer_newfilename (filename);
      scan_linenr = linenr - 1;
      DEBUGF ('m', "filename=%s, scan_linenr=%d\n",
              included_filenames.back().c_str(), scan_linenr);
   }
}

RCSC("$Id: lyutils.cpp,v 1.5 2015-04-09 19:34:17-07 - - $")
