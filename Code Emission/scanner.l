%{

#include "auxlib.h"
#include "lyutils.h"

#define YY_USER_ACTION  { scanner_useraction (); }
#define IGNORE(THING)   { }

%}


%option 8bit
%option debug
%option ecs
%option nodefault
%option nounput
%option noyywrap
%option perf-report
%option verbose
%option warn


BOOL            (bool)
VOID            (void)
CHAR            (char)
INT             (int)
STRING          (string)
IF              (if)
ELSE            (else)
WHILE           (while)
RETURN          (return)
STRUCT          (struct)
NEW             (new)
FALSE           (false)
TRUE            (true)
NULL            (null)
ORD             (ord)
CHR             (chr)

LETTER          [A-Za-z_]
DIGIT           [0-9]
IDENT           ({LETTER}({LETTER}|{DIGIT})*)
INTCON          ({DIGIT}+)
CHARCON         ('([^\\'\n]|\\[\\'"0nt])')
STRINGCON       (\"([^\\"\n]|\\[\\'"0nt])*\")
BADIDENT        ({DIGIT}({LETTER}|{DIGIT})*)
BADSTRING1      (\"([^\\"\n]|\\[\\'"0nt])*)
BADSTRING2      (\"([^\\"\n]|\\)*\")



%%

"#".*           { scanner_include(); }
[ \t]+          { IGNORE (white space) }
\n              { scanner_newline(); }

{BOOL}          { return yylval_token (TOK_BOOL); }
{VOID}          { return yylval_token (TOK_VOID); }
{CHAR}          { return yylval_token (TOK_CHAR); }
{INT}           { return yylval_token (TOK_INT); }
{STRING}        { return yylval_token (TOK_STRING); }
{IF}            { return yylval_token (TOK_IF); }
{ELSE}          { return yylval_token (TOK_ELSE); }
{WHILE}         { return yylval_token (TOK_WHILE); }
{RETURN}        { return yylval_token (TOK_RETURN); }
{STRUCT}        { return yylval_token (TOK_STRUCT); }
{NEW}           { return yylval_token (TOK_NEW); }
{FALSE}         { return yylval_token (TOK_FALSE); }
{TRUE}          { return yylval_token (TOK_TRUE); }
{NULL}          { return yylval_token (TOK_NULL); }
{ORD}           { return yylval_token (TOK_ORD); }
{CHR}           { return yylval_token (TOK_CHR); }

{IDENT}         { return yylval_token (TOK_IDENT); }
{INTCON}        { return yylval_token (TOK_INTCON); }
{CHARCON}       { return yylval_token (TOK_CHARCON); }
{STRINGCON}     { return yylval_token (TOK_STRINGCON); }

"=="            { return yylval_token (TOK_EQ); }
"!="            { return yylval_token (TOK_NE); }
"<="            { return yylval_token (TOK_LE); }
">="            { return yylval_token (TOK_GE); }

"="             { return yylval_token ('='); }
"+"             { return yylval_token ('+'); }
"-"             { return yylval_token ('-'); }
"*"             { return yylval_token ('*'); }
"/"             { return yylval_token ('/'); }
"^"             { return yylval_token ('^'); }
"("             { return yylval_token ('('); }
")"             { return yylval_token (')'); }
"[]"            { return yylval_token (TOK_ARRAY); }
"["             { return yylval_token ('['); }
"]"             { return yylval_token (']'); }
"{"             { return yylval_token ('{'); }
"}"             { return yylval_token ('}'); }
";"             { return yylval_token (';'); }
"!"             { return yylval_token ('!'); }
","             { return yylval_token (','); }
"."             { return yylval_token ('.'); }
"%"             { return yylval_token ('%'); }
"<"             { return yylval_token (TOK_LT); }
">"             { return yylval_token (TOK_GT); }

{BADSTRING1}    { scanner_badstring(yytext); }
{BADSTRING2}    { scanner_badstring(yytext); }
{BADIDENT}      { scanner_badident(yytext); }
.               { scanner_badchar (*yytext); }

%%

RCSC("$Id: scanner.l,v 1.2 2013-10-28 22:54:59-07 - - $")
