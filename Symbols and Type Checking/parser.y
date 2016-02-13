%{
// Dummy parser for scanner project.

#include "lyutils.h"
#include "astree.h"
#include "assert.h"

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_INITDECL
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD
%token TOK_ORD TOK_CHR TOK_ROOT

%token vardecl type basetype constant program decl struct_ function block while_ return_ call unop binop allocator_ variable if_ else_

%right TOK_IF TOK_ELSE
%right '='
%left TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left '+' '-'
%left '*' '/' '%'
%right TOK_POS TOK_NEG '!' TOK_ORD TOK_CHR
%left '[' '.' 
%nonassoc TOK_NEW

%start program1

%%

program1 : stmtseq              { $$ = $$ = $1; }
         ;

stmtseq : stmtseq structdef    { $$ = adopt1($1,$2); }
        | stmtseq function1    { $$ = adopt1($1,$2); }
        | stmtseq statement    { $$ = adopt1($1,$2); }
        |                      { $$ = new_parseroot(); }
        ;

structdef : TOK_STRUCT TOK_IDENT '{' declgroup '}'    { $$ = adopt1($4, $2); }
          ;

declgroup : declgroup decl1 ';'     { $$ = adopt1($1,$2); }
          |                         { $$ = new_astree(struct_,0,0,0,""); } 
          ;

decl1     : type1 TOK_IDENT     { $$ = adopt2(new_astree(decl,0,0,0,""), $1, $2); }
          ;

type1   : basetype1 TOK_ARRAY    { $$ = adopt2(new_astree(type,0,0,0,""), $1, $2); }
        | basetype1              { $$ = adopt1(new_astree(type,0,0,0,""), $1); }
        ;

basetype1 : TOK_VOID             { $$ = adopt1(new_astree(basetype,0,0,0,""), $1); }
          | TOK_BOOL             { $$ = adopt1(new_astree(basetype,0,0,0,""), $1); }
          | TOK_CHAR             { $$ = adopt1(new_astree(basetype,0,0,0,""), $1); }
          | TOK_INT              { $$ = adopt1(new_astree(basetype,0,0,0,""), $1); }
          | TOK_STRING           { $$ = adopt1(new_astree(basetype,0,0,0,""), $1); }
          | TOK_IDENT            { $$ = adopt1(new_astree(basetype,0,0,0,""), $1); }
          ;

function1 : type1 TOK_IDENT '(' comdecl ')' block1        { $$ = adopt1(adopt2($4, $1, $2),$6); }
          | type1 TOK_IDENT '(' ')' block1                { $$ = adopt1(adopt2(new_astree(function,0,0,0,""), $1, $2),$5); }
          ;

comdecl  :  comdecl ',' decl1                       { $$ = adopt1($1, $3); } 
         |  decl1                                   { $$ = adopt1(new_astree(function,0,0,0,""), $1); }
         ;

block1    : '{' blockstmt '}'    {$$ = $2; }
          | ';'                  {$$ = new_astree(block,0,0,0,""); }
          ;

blockstmt : blockstmt statement {$$ = adopt1($1,$2); }
          |                     {$$ = new_astree(block,0,0,0,""); }
          ;

statement : block1               {$$ = $1; }
          | vardecl1             {$$ = $1; }
          | while1               {$$ = $1; }
          | ifelse               {$$ = $1; }
          | return1              {$$ = $1; }
          | expr ';'             {$$ = $1; }
          ;

vardecl1 : type1 TOK_IDENT '=' expr ';'  { $$ = adopt1(adopt2(new_astree(vardecl,0,0,0,""), $1, $2), $4); }
         ;


while1    : TOK_WHILE '(' expr ')' statement { $$ = adopt2(new_astree(while_,0,0,0,""), $3, $5); }
          ;

ifelse    : TOK_IF '(' expr ')' statement %prec TOK_IF            { $$ = adopt2(new_astree(if_,0,0,0,""), $3, $5); }
          | TOK_IF '(' expr ')' statement TOK_ELSE statement      { $$ = adopt1(adopt2(new_astree(if_,0,0,0,""), $3, $5), $7); }  
          ;

return1    : TOK_RETURN expr ';' { $$ = adopt1(new_astree(return_,0,0,0,""), $2); }
           | TOK_RETURN ';'      { $$ = new_astree(return_,0,0,0,""); }
           ;

expr      : unop1               {$$ = $1; }
          | binop1              {$$ = $1; }
          | '(' expr ')'        {$$ = $2; }
          | allocator1          {$$ = $1; }
          | call1               {$$ = $1; }
          | variable1           {$$ = $1; }
          | constant1           {$$ = $1; }
          ;

unop1     : '+' expr %prec TOK_POS      { $$ = adopt1(new_astree(unop,0,0,0,""),adopt1sym($1,$2,TOK_POS)); }
          | '-' expr %prec TOK_NEG      { $$ = adopt1(new_astree(unop,0,0,0,""),adopt1sym($1,$2,TOK_NEG)); }
          | '!' expr %prec '!'          { $$ = adopt1(new_astree(unop,0,0,0,""),adopt1sym($1,$2,'!')); }
          | TOK_ORD expr %prec TOK_ORD  { $$ = adopt1(new_astree(unop,0,0,0,""),adopt1sym($1,$2,TOK_ORD)); }
          | TOK_CHR expr %prec TOK_CHR  { $$ = adopt1(new_astree(unop,0,0,0,""),adopt1sym($1,$2,TOK_CHR)); }
          ;




binop1    : expr '=' expr      { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr TOK_EQ expr   { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr TOK_NE expr   { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr TOK_LE expr   { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr TOK_LT expr   { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr TOK_GT expr   { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr TOK_GE expr   { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr '+' expr      { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr '-' expr      { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr '*' expr      { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr '/' expr      { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          | expr '%' expr      { $$ = adopt1(adopt2(new_astree(binop,0,0,0,""), $1, $2), $3); }
          ;

allocator1 : TOK_NEW basetype1 '(' expr ')'   { $$ = adopt2(adopt2(new_astree(allocator_,0,0,0,""),$1,$2),$4,$3); }
           | TOK_NEW basetype1 '(' ')'        { $$ = adopt2(new_astree(allocator_,0,0,0,""),$1,$2); }
           | TOK_NEW basetype1 '[' expr ']'   { $$ = adopt2(adopt2(new_astree(allocator_,0,0,0,""),$1,$2),$4,$3); }
           ;

call1     : TOK_IDENT '(' comexpr ')'         { $$ = adopt1($3, $1); }
          | TOK_IDENT '(' ')'                 { $$ = adopt1(new_astree(call,0,0,0,""), $1); }
          ;

comexpr   : comexpr ',' expr        { $$ = adopt1($1,$3); }
          | expr                    { $$ = adopt1(new_astree(call,0,0,0,""),$1); }
          ;

variable1 : expr '[' expr ']'       { $$ = adopt2(new_astree(variable,0,0,0,""), $1, $3); }
          | expr '.' TOK_IDENT      { $$ = adopt2(new_astree(variable,0,0,0,""), $1, $3); }
          | TOK_IDENT               { $$ = adopt1(new_astree(variable,0,0,0,""), $1); } 
          ;

constant1  : TOK_INTCON      { $$ = adopt1(new_astree(constant,0,0,0,""), $1); }
           | TOK_CHARCON     { $$ = adopt1(new_astree(constant,0,0,0,""), $1); }
           | TOK_STRINGCON   { $$ = adopt1(new_astree(constant,0,0,0,""), $1); }
           | TOK_FALSE       { $$ = adopt1(new_astree(constant,0,0,0,""), $1); }
           | TOK_TRUE        { $$ = adopt1(new_astree(constant,0,0,0,""), $1); }
           | TOK_NULL        { $$ = adopt1(new_astree(constant,0,0,0,""), $1); }
           ;




%%

const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}

