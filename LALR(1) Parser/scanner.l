%{

//Nico Williams and Brandon Rullamas
//nijowill and brullama
//Assignment 3 - LALR(1) Parser using bison

#include <stdlib.h>
#include <stdbool.h>
#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION 	{ lexer_useraction (); }
#define YY_USER_INIT 	{lexer_userinit (); }
#define IGNORE(THING) 	{ }

%}

%option 8bit
%option backup
%option debug
%option ecs
%option nodefault
%option nounput
%option noyywrap
%option perf-report
%option verbose

LETTER          [A-Za-z_]
DIGIT           [0-9]
MANTISSA        ({DIGIT}+\.?{DIGIT}*|\.{DIGIT}+)
EXPONENT        ([Ee][+-]?{DIGIT}+)
NUMBER          ({MANTISSA}{EXPONENT}?)
NOTNUMBER       ({MANTISSA}[Ee][+-]?)
TOK_IDENT       ({LETTER}({LETTER}|{DIGIT})*)
TOK_CHARCON		('([^\\'\n]|\\[\\'"0nt])')
TOK_STRINGCON	(\"([^\\"\n]|\\[\\'"0nt])*\")

%%

"[]"            { return yylval_token (TOK_ARRAY); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }
";"             { return yylval_token (';'); }
","             { return yylval_token (','); }
"."             { return yylval_token ('.'); }
"="             { return yylval_token ('='); }
"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<"             { return yylval_token (TOK_LT); }
"<="            { return yylval_token (TOK_LE); }
">"             { return yylval_token (TOK_GT); }
">="            { return yylval_token (TOK_GE); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"%"             { return yylval_token ('%'); }
"!"             { return yylval_token ('!'); }
{TOK_IDENT}		{ return yylval_token (TOK_IDENT); }
{TOK_CHARCON}	{ return yylval_token (TOK_CHARCON); }
{TOK_STRINGCON} { return yylval_token (TOK_STRINGCON); }
{NUMBER}        { return yylval_token (TOK_INTCON); }


"void"          { return yylval_token (TOK_VOID); }
"bool"          { return yylval_token (TOK_BOOL); }
"char"          { return yylval_token (TOK_CHAR); }
"int"           { return yylval_token (TOK_INT); }
"string"        { return yylval_token (TOK_STRING); }
"struct"        { return yylval_token (TOK_STRUCT); }
"if"            { return yylval_token (TOK_IF); }
"else"          { return yylval_token (TOK_ELSE); }
"while"         { return yylval_token (TOK_WHILE); }
"return"        { return yylval_token (TOK_RETURN); }
"false"         { return yylval_token (TOK_FALSE); }
"true"          { return yylval_token (TOK_TRUE); }
"null"          { return yylval_token (TOK_NULL); }
"ord"           { return yylval_token (TOK_ORD); }
"chr"           { return yylval_token (TOK_CHR); }
"new"           { return yylval_token (TOK_NEW); }

"#".*           { lexer_include(); }
[ \t]+          { IGNORE (white space) }
\n              { lexer_newline(); }

{NOTNUMBER}     { lexer_badtoken (yytext);
                  return yylval_token (TOK_INT); }

.               { lexer_badchar (*yytext); }

%%