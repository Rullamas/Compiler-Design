//Nico Williams and Brandon Rullamas
//nijowill and brullama
//Assignment 4 - Symbols and Type Checking

#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.h"
#include "stringset.h"
#include "lyutils.h"
#include "symtable.h"

SymbolTable* strSym = new SymbolTable(NULL);

astree* new_astree (int symbol, int filenr, int linenr,
                    int offset, const char* lexinfo) {
   astree* tree = new astree();
   tree->symbol = symbol;
   tree->filenr = filenr;
   tree->linenr = linenr;
   tree->offset = offset;
   tree->lexinfo = intern_stringset (lexinfo);
   DEBUGF ('f', "astree %p->{%d:%d.%d: %s: \"%s\"}\n",
           tree, tree->filenr, tree->linenr, tree->offset,
           get_yytname (tree->symbol), tree->lexinfo->c_str());
   return tree;
}

astree* adopt1 (astree* root, astree* child) {
   root->children.push_back (child);
   DEBUGF ('a', "%p (%s) adopting %p (%s)\n",
           root, root->lexinfo->c_str(),
           child, child->lexinfo->c_str());
   return root;
}

astree* adopt2 (astree* root, astree* left, astree* right) {
   adopt1 (root, left);
   adopt1 (root, right);
   return root;
}

astree* adopt1sym (astree* root, astree* child, int symbol) {
   root = adopt1 (root, child);
   root->symbol = symbol;
   return root;
}


static void dump_node (FILE* outfile, astree* node) {
   fprintf (outfile, "%3ld  %ld.%03ld  %-3d  %-15s (%s)  ",
            node->filenr, node->linenr, node->offset, node->symbol,
            get_yytname (node->symbol), node->lexinfo->c_str()); 
   bool need_space = false;
   for (size_t child = 0; child < node->children.size();
        ++child) {
      if (need_space) fprintf (outfile, " ");
      need_space = true;
      fprintf (outfile, "%p", node->children.at(child));
   }
}

static void dump_astree_rec (FILE* outfile, astree* root,
                             int depth) {
   if (root == NULL) return;
   dump_node (outfile, root);
   fprintf (outfile, "\n");
   for (size_t child = 0; child < root->children.size();
        ++child) {
      dump_astree_rec (outfile, root->children[child],
                       depth + 1);
   }
}

static void dump_astree_rec2 (FILE* outfile, astree* root, int depth) {
   if (root == NULL) return;
   int i = 0;
      while (i < depth){
         fprintf(outfile, "   ");
         i++;
      }
      fprintf(outfile, "%s", get_yytname(root->symbol));
      if(strcmp(root->lexinfo->c_str(), "") != 0)
         fprintf(outfile, " (%s)", root->lexinfo->c_str());
      fprintf(outfile, "\n");
   for (size_t child = 0; child < root->children.size(); ++child){
      dump_astree_rec2 (outfile, root->children[child], depth +1);
   }
}

void dump_astree (FILE* outfile, astree* root) {
   dump_astree_rec (outfile, root, 0);
   fflush (NULL);
}

void dump_astree2(FILE* outfile, astree* root) {
   dump_astree_rec2 (outfile, root, 0);
   fflush (NULL);
}



void scan(astree* root, SymbolTable* sym){
   if(root == NULL) return;
   for(size_t child = 0; child < root->children.size(); ++child){
      const char* CurSym = get_yytname(root->children[child]->symbol);
      if(strcmp(CurSym, "vardecl") != 0 && strcmp(CurSym, "block") != 0 && strcmp(CurSym, "function") != 0 && strcmp(CurSym, "struct_") != 0)
         scan(root->children[child], sym);
      else if(strcmp(CurSym, "vardecl") == 0){                         
         if(root->children[child]->children[0]->children.size() < 2){
            sym->addSymbol(root->children[child]->children[1]->lexinfo->c_str(), root->children[child]->children[0]->children[0]->children[0]->lexinfo->c_str(), root->children[child]->children[1]->filenr, root->children[child]->children[1]->linenr, root->children[child]->children[1]->offset); 
            }else{
            string type = root->children[child]->children[0]->children[0]->children[0]->lexinfo->c_str();
            type = type + "[]";
            sym->addSymbol(root->children[child]->children[1]->lexinfo->c_str(), type, root->children[child]->children[1]->filenr, root->children[child]->children[1]->linenr, root->children[child]->children[1]->offset);
         }
      }else if (strcmp(CurSym, "struct_") == 0){
         string tabs;
         SymbolTable* CurTabs;
         for(size_t childOther = 0; childOther < root->children[child]->children.size(); ++childOther){
            string CurChild = get_yytname(root->children[child]->children[childOther]->symbol);
            if(CurChild == "TOK_IDENT"){
               tabs = root->children[child]->children[childOther]->lexinfo->c_str();
               strSym->addStruct(tabs);
               CurTabs = strSym->lookup2(tabs);
            }
         }
         for(size_t childOther = 0; childOther < root->children[child]->children.size(); ++childOther){
            string CurChild = get_yytname(root->children[child]->children[childOther]->symbol);
            if(CurChild == "decl"){
               CurTabs->addSymbol(  root->children[child]->children[childOther]->children[1]->lexinfo->c_str(), root->children[child]->children[childOther]->children[0]->children[0]->children[0]->lexinfo->c_str(), root->children[child]->children[childOther]->children[1]->filenr, root->children[child]->children[childOther]->children[1]->linenr, root->children[child]->children[childOther]->children[1]->offset);
            }
         }

      }else if(strcmp(CurSym, "block") == 0){       
         scan(root->children[child], root->children[child]->blockpt = sym->enterBlock()); 
      }else if(strcmp(CurSym, "function") == 0){       
         char ident[50];
         char decl[100];
         int blocknum;
         int numdecl = 0;
         int funfilenr = 0;
         int funlinenr = 0;
         int funoffset = 0;
         for(size_t childOther = 0; childOther < root->children[child]->children.size(); ++childOther){ 
            const char* CurSymIn = get_yytname(root->children[child]->children[childOther]->symbol);
            if(strcmp(CurSymIn, "TOK_IDENT") == 0){ 
               funfilenr = root->children[child]->children[childOther]->filenr;
               funlinenr = root->children[child]->children[childOther]->linenr;
               funoffset = root->children[child]->children[childOther]->offset;
               strcpy(ident, root->children[child]->children[childOther]->lexinfo->c_str());
            }
            if(strcmp(CurSymIn, "type") == 0){ 
               if(root->children[child]->children[childOther]->children.size() == 2){
               strcpy(decl, root->children[child]->children[childOther]->children[0]->children[0]->lexinfo->c_str());
               strcat(decl, "[]");
               strcat(decl, "(");
               }else{
               strcpy(decl, root->children[child]->children[childOther]->children[0]->children[0]->lexinfo->c_str());
               strcat(decl, "(");
               }
            }
            if(strcmp(CurSymIn, "block") == 0)
               blocknum = childOther;
         }
         for(size_t childOther = 0; childOther < root->children[child]->children.size(); ++childOther){            
            if(strcmp(get_yytname(root->children[child]->children[childOther]->symbol), "decl") == 0){
               if(numdecl != 0)
                  strcat(decl, ",");
               if(root->children[child]->children[childOther]->children[0]->children.size() == 2){
                  strcat(decl,root->children[child]->children[childOther]->children[0]->children[0]->children[0]->lexinfo->c_str());
                  strcat(decl,"[]");
               }else{
               strcat(decl,root->children[child]->children[childOther]->children[0]->children[0]->children[0]->lexinfo->c_str());
               }
               ++numdecl;
            }
         }
         strcat(decl, ")");
         SymbolTable* FunSym = sym->enterFunction(ident, decl, funfilenr, funlinenr, funoffset);
         for(size_t childOther = 0; childOther < root->children[child]->children.size(); ++childOther){
            if(strcmp(get_yytname(root->children[child]->children[childOther]->symbol), "decl") == 0){
               if(root->children[child]->children[childOther]->children[0]->children.size() == 2){
                  string types = root->children[child]->children[childOther]->children[0]->children[0]->children[0]->lexinfo->c_str();
                  types = types + "[]";
                  FunSym->addSymbol(root->children[child]->children[childOther]->children[1]->lexinfo->c_str(), types, root->children[child]->children[childOther]->children[1]->filenr, root->children[child]->children[childOther]->children[1]->linenr,root->children[child]->children[childOther]->children[1]->offset);
                }
               else{
               FunSym->addSymbol(root->children[child]->children[childOther]->children[1]->lexinfo->c_str(), root->children[child]->children[childOther]->children[0]->children[0]->children[0]->lexinfo->c_str(), root->children[child]->children[childOther]->children[1]->filenr, root->children[child]->children[childOther]->children[1]->linenr, root->children[child]->children[childOther]->children[1]->offset);
               }
            }
         }
         scan(root->children[child]->children[blocknum], root->children[child]->children[blocknum]->blockpt = FunSym);
    }
   }

}

string checker(astree* root, SymbolTable* table){
   if(root == NULL) return NULL;
   string names = get_yytname(root->symbol);

   if(names == "TOK_INT" || names == "TOK_INTCON") return "int";
   if(names == "TOK_CHAR" || names == "TOK_CHARCON") return "char";
   if(names == "TOK_STRING" || names == "TOK_STRINGCON") return "string";
   if(names == "TOK_BOOL" || names == "TOK_TRUE" || names == "TOK_FALSE") return "bool";
   if(names == "TOK_NULL") return "null";

   if(names == "TOK_IDENT") return table->lookup(root->lexinfo->c_str());
   if(names == "constant") return checker(root->children[0], table);
   if(names == "type"){
      if(root->children.size() == 2){
         string type = checker(root->children[0],table);
         type = type + "[]";
         return type;
      }
    return checker(root->children[0], table);
   }
   if(names == "basetype"){
      string offSpr = get_yytname(root->children[0]->symbol);
      string ident = root->children[0]->lexinfo->c_str();
      if(offSpr == "TOK_IDENT"){
         if (strSym->lookup2(ident) != NULL) return ident;
      }
      return checker(root->children[0], table);

   }
   if(names == "variable") {
      if(root->children.size() == 1) return checker(root->children[0], table);
      if(root->children.size() == 2){
         string offSpr2 = get_yytname(root->children[1]->symbol);
         SymbolTable* curnt;
         if(offSpr2 == "TOK_IDENT"){
            string offSpr = checker(root->children[0],table);
            string ident = root->children[1]->lexinfo->c_str();
            if(strSym->lookup2(offSpr) != NULL){
               curnt = strSym->lookup2(offSpr);
               if (curnt == NULL){ 
                  errprintf("Not a variable of this struct!\n");
                  return "";
               }
               return curnt->lookup(ident);
            }
         }else{
            if(checker(root->children[1],table) == "int" && checker(root->children[0],table) == "string") return "char"; 
            if(checker(root->children[1],table) == "int" && checker(root->children[0],table) == "int[]") return "int";
            if(checker(root->children[1],table) == "int" && checker(root->children[0],table) == "bool[]") return "bool";
            if(checker(root->children[1],table) == "int" && checker(root->children[0],table) == "char[]") return "char";
            if(checker(root->children[1],table) == "int" && checker(root->children[0],table) == "struct[]") return "struct";
            if(checker(root->children[1],table) == "int" && checker(root->children[0],table) == "string[]") return "string";
         }
      }

   }

   if(names == "call"){
      string funcoper = "(";
      string funcname;
      string funcops;
      size_t check = -1;
      int begin;
      int comcounter = 0;
      int firstparen;
      for(size_t child = 0; child < root->children.size(); ++child){
         string currchild = get_yytname(root->children[child]->symbol);
         if(currchild != "TOK_IDENT"){
            if (comcounter != 0) funcoper = funcoper + ",";
            string currop = checker(root->children[child], table);
            funcoper = funcoper + currop;
            comcounter++;
         }
         if(currchild == "TOK_IDENT") funcname = root->children[child]->lexinfo->c_str();
      }
      funcoper = funcoper + ")";
      funcops = table->lookup(funcname);
      begin = funcops.length() - funcoper.length();
      if(funcops.find(funcoper) == check)
         errprintf("Incorrect arguments passed to function!\n");
      firstparen = funcops.find_first_of('(', 0);
      return funcops.substr(0,firstparen);
   }


   if(names == "vardecl"){
      string c0 = checker(root->children[0],table);
      string c1 = checker(root->children[2],table);
      if(c0 != c1) errprintf("Declaring incorrect type!\n");
      return "";
   }
   if(names == "program"){
      for(size_t child = 0; child < root->children.size(); ++ child){
         checker(root->children[child], table);
      }
   }
   if(names == "while_" || names == "if_"){
      if(checker(root->children[0],table) != "bool") errprintf("Expression does not return a bool!\n");
      checker(root->children[1], table);
      if(root->children[2] != NULL) checker(root->children[2], table);
      return "";
   }
   if(names == "function"){
      SymbolTable* currblock;
      astree* blockroot;
      string funcreturn;
      for(size_t child = 0; child < root->children.size(); ++child){
         string currchild = get_yytname(root->children[child]->symbol);
         if(currchild == "type"){
            funcreturn = checker(root->children[child], table);
         }
         if(currchild == "block"){
            currblock = root->children[child]->blockpt;
            blockroot = root->children[child];
         }
      }
      if(!searcher(blockroot, funcreturn, currblock)) errprintf("Incorrect return type!\n");
   }
   if(names == "block"){
      SymbolTable* currtable = root->blockpt;
      for(size_t child = 0; child < root->children.size(); ++child){
         checker(root->children[child], currtable);
      }
   }
   if(names == "allocator_"){
      if(root->children.size() < 3) return checker(root->children[1],table);
      else{
         string bracket = get_yytname(root->children[3]->symbol);
         string result = checker(root->children[1],table);
         if(bracket == "'['"){
            if(checker(root->children[2],table) == "int"){
               result = result + "[]";
               return result;
            }else errprintf("Need int in brackets!\n");
         }else return result;
      }
   }
   if(names == "binop"){
      string offSpr2 = get_yytname(root->children[1]->symbol);
      if(offSpr2 == "'+'" || offSpr2 == "'-'" || offSpr2 == "'*'" || offSpr2 == "'/'" || offSpr2 == "'%'"){
         if(checker(root->children[0],table) == "int" && checker(root->children[0], table) == checker(root->children[2],table))
            return "int";
         else errprintf("One or more inputs is not of type int\n");
      }
      if(offSpr2 == "TOK_LT" || offSpr2 == "TOK_LE" || offSpr2 == "TOK_GT" || offSpr2 == "TOK_GE"){
         string c0 = checker(root->children[0], table);
         string c1 = checker(root->children[2], table);
         if((c0 == "int" || c0 == "char" || c0 == "bool") && c0 == c1 )
            return "bool";
         else
            errprintf("Comparison of different or incorrect types!\n");
      }
      if(offSpr2 == "TOK_NE" || offSpr2 == "TOK_EQ"){
         string c0 = checker(root->children[0], table);
         string c1 = checker(root->children[2], table);
         if(c0 == c1 || (c0 != "bool" && c0 != "int" && c0 != "char" && c1 == "null"))
            return "bool";
         else
            errprintf("Comparison of different types!\n");
      }
      if(offSpr2 == "'='"){
         string c0 = checker(root->children[0], table);
         string c1 = checker(root->children[2], table);
         if(c0 == c1 || (c0 != "bool" && c0 != "int" && c0 != "char" && c1 == "null"))
            return c0;
         else
            errprintf("Trying to set variable to different type!\n");
      }
   }

   if(names == "unop"){
      string offSpr = get_yytname(root->children[0]->symbol);
      if(offSpr == "TOK_POS" || offSpr == "TOK_NEG"){
         if(checker(root->children[0]->children[0], table) == "int") return "int";
         else errprintf("Tried adding sign to non-int type!\n");
      }
      if(offSpr == "'!'"){
         if(checker(root->children[0]->children[0], table) == "bool") return "bool";
         else errprintf("Tried negating a non-bool!\n");
      }
      if(offSpr == "TOK_ORD"){
         if(checker(root->children[0]->children[0], table) == "char") return "int";
         else errprintf("Tried using ord on non-char type!\n");
      }
      if(offSpr == "TOK_CHR"){
         if(checker(root->children[0]->children[0], table) == "int") return "char";
         else errprintf("Tried using chr on non-int type!\n");
      }
   }
   return ""; 

}

bool searcher(astree* root, string type, SymbolTable* table){
   if(root == NULL) return true;
   SymbolTable* currtab = table;
   for(size_t child = 0; child < root->children.size(); ++child){
      string currsym = get_yytname(root->children[child]->symbol);
      if(currsym == "return_"){
         if(root->children[child]->children.size() != 0 && type == "void") return false;
         if(root->children[child]->children.size() == 1){
            string roottype = checker(root->children[child]->children[0], table);
            if(roottype != type) return false; 
         }
      }
      if(currsym == "block"){
         currtab = root->children[child]->blockpt;
      }
      if(!searcher(root->children[child], type, currtab)) return false;
   }
   return true;
}

void yyprint (FILE* outfile, unsigned short toknum,
              astree* yyvaluep) {
   if (is_defined_token (toknum)) {
      dump_node (outfile, yyvaluep);
   }else {
      fprintf (outfile, "%s(%d)\n",
               get_yytname (toknum), toknum);
   }
   fflush (NULL);
}


void free_ast (astree* root) {
   while (not root->children.empty()) {
      astree* child = root->children.back();
      root->children.pop_back();
      free_ast (child);
   }
   DEBUGF ('f', "free [%p]-> %d:%d.%d: %s: \"%s\")\n",
           root, root->filenr, root->linenr, root->offset,
           get_yytname (root->symbol), root->lexinfo->c_str());
   delete root;
}

void free_ast2 (astree* tree1, astree* tree2) {
   free_ast (tree1);
   free_ast (tree2);
}
