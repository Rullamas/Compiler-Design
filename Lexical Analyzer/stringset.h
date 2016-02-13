//Nico Williams and Brandon Rullamas
//nijowill and brullama
//Assignment 3 - LALR(1) Parser using bison

#ifndef __STRINGSET__
#define __STRINGSET__

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include "lyutils.h"

using namespace std;


const std::string* intern_stringset (const char*);

void dump_stringset (FILE*);

#endif
