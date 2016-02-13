//Nico Williams and Brandon Rullamas
//nijowill and brullama
//Assignment 4 - Symbols and Type Checking

#include "auxlib.h"
#include "symtable.h"

#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

enum { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
       ATTR_string, ATTR_struct, ATTR_array, ATTR_function,
       ATTR_variable, ATTR_field, ATTR_typeid, ATTR_param,
       ATTR_lval, ATTR_const, ATTR_vreg, ATTR_vaddr,
       ATTR_bitset_size,
};
using attr_bitset = bitset<ATTR_bitset_size>;

struct symbol;
using symbol_table = unordered_map<string*,symbol*>;
using symbol_entry = symbol_table::value_type;

struct symbol {
   attr_bitset attributes;
   symbol_table* fields;
   size_t filenr, linenr, offset;
   size_t blocknr;
   vector<symbol*>* parameters;
};

SymbolTable::SymbolTable(SymbolTable* parent) {
	this->parent = parent;
	this->number = SymbolTable::N++;
}

SymbolTable* SymbolTable::enterBlock() {
	SymbolTable* child = new SymbolTable(this);
	char buffer[10];
	sprintf(&buffer[0], "%d", child->number);
	this->subscopes[buffer] = child;
	return child;
}

SymbolTable* SymbolTable::enterFunction(string name, string signature,int filenr, int linenr, int offset) {
    this->addSymbol(name, signature,filenr,linenr,offset);
    SymbolTable* child = new SymbolTable(this);
    this->subscopes[name] = child;
    return child;
}

void SymbolTable::addSymbol(string name, string type, int filenr,int linenr, int offset) {
    this->mapping[name] = type;
    this->mapfile[name] = filenr;
    this->mapline[name] = linenr;
    this->mapoffset[name] = offset;
}

void SymbolTable::addStruct(string name){
   this->structs[name] = new SymbolTable(NULL);
}


void SymbolTable::dump(FILE* symfile, int depth) {
    std::map<string,string>::iterator it;
    for (it = this->mapping.begin(); it != this->mapping.end(); ++it) {
        const char* name = it->first.c_str();
        const char* type = it->second.c_str();
        fprintf(symfile, "%*s%s (%d, %d, %d){%d} %s\n", 3*depth, "", name, this->mapfile[name]-3, this->mapline[name], this->mapoffset[name], this->number, type);
        
        if (this->subscopes.count(name) > 0) {
            this->subscopes[name]->dump(symfile, depth + 1);
        }
    }
    std::map<string,SymbolTable*>::iterator i;
    for (i = this->subscopes.begin(); i != this->subscopes.end(); ++i) {
        if (this->mapping.count(i->first) < 1) {
            i->second->dump(symfile, depth + 1);
        }
    }
}

string SymbolTable::lookup(string name) {
    if (this->mapping.count(name) > 0) {
        return this->mapping[name];
    }
    if (this->parent != NULL) {
        return this->parent->lookup(name);
    } else {
        errprintf("Unknown identifier: %s\n", name.c_str());
        return "";
    }
}

SymbolTable* SymbolTable::lookup2(string name){
   if (this->structs.count(name) > 0){
      return this->structs[name];
   }
   if (this->parent != NULL){
      return this->parent->lookup2(name);
   }else{
    errprintf("Unknown struct\n");
    return NULL;
   }
}

string SymbolTable::parentFunction(SymbolTable* innerScope) {
    std::map<string,SymbolTable*>::iterator it;
    for (it = this->subscopes.begin(); it != this->subscopes.end(); ++it) {
        if (it->second == innerScope && this->mapping.count(it->first) > 0) {
            return this->mapping[it->first];
        }
    }
    if (this->parent != NULL) {
        return this->parent->parentFunction(this);
    }
    errprintf("Could not find surrounding function\n");
    return "";
}


int SymbolTable::N(0);

vector<string> SymbolTable::parseSignature(string sig) {
    vector<string> results;
    size_t left = sig.find_first_of('(');
    if (left == string::npos) {
        errprintf("%s is not a function\n", sig.c_str());
        return results;
    }
    results.push_back(sig.substr(0, left));
    for (size_t i = left + 1; i < sig.length()-1; i = sig.find_first_of(",)", i) + 1) {
        results.push_back(sig.substr(i, sig.find_first_of(",)", i) - i));
    }
    return results;
}