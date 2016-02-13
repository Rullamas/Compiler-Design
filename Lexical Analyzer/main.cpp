//Nico Williams and Brandon Rullamas
//nijowill and brullama
//Assignment 3 - LALR(1) Parser using bison

#include <fstream>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <string>
using namespace std;

#include "stringset.h"
#include "auxlib.h"
#include "lyutils.h"


extern FILE *yyin;
extern int yy_flex_debug
const string CPP = "/usr/bin/cpp";
const size_t LINESIZE = 1024;
int exit_status = 0;

//remove the .oc file extention
std::string remove_extension(const std::string& filename) {
    size_t lastdot = filename.find_last_of(".");
    if (lastdot == std::string::npos) return filename;
    return filename.substr(0, lastdot); 
}

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
   size_t len = strlen (string);
   if (len == 0) return;
   char* nlpos = string + len - 1;
   if (*nlpos == delim) *nlpos = '\0';
}

// Run cpp against the lines of the file.
void cpplines (FILE* pipe, char* filename) {
   int linenr = 1;
   char inputname[LINESIZE];
   strcpy (inputname, filename);
   for (;;) {
      char buffer[LINESIZE];
      char* fgets_rc = fgets (buffer, LINESIZE, pipe);
      if (fgets_rc == NULL) break;
      chomp (buffer, '\n');
      int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                              &linenr, filename);
      if (sscanf_rc == 2) {
         continue;
      }
      char* savepos = NULL;
      char* bufptr = buffer;
      for (int tokenct = 1;; ++tokenct) {
         char* token = strtok_r (bufptr, " \t\n", &savepos);
         bufptr = NULL;
         if (token == NULL) break;
         intern_stringset(token);
      }
      ++linenr;
   }
}

int main (int argc, char** argv) {

    int opts;
	int Dopts = 0;
	int Dargs = 0;
    yy_flex_debug = 0;
/*Get options. code based off
gnu.org/software/libc/manual/html_node/Example-of-Getopt.html#Example-of-Getopt
*/
//  printf("test1\n");
  
    while((opts = getopt(argc, argv, "ly::@::D"))!=-1){
 //   printf("test2\n");
      switch(opts){
    
        case 'l':
          yy_flex_debug = 1;
          //printf("case -L\n");
          break;
        
        case 'y':
          //yydebug = 1;
 //         printf("case -Y\n");
          break;
        
        case '@':
          if (optarg == NULL){
            fprintf(stderr, "Please use an appropiate debug flag, such as DEBUGF or DEBUGSTMT.\n");
            fprintf(stderr, "Option: [-ly] [-@flag...] [-D string]\n");
            exit_status = 1;
            exit(exit_status);
          }
          //printf(optarg);
          //printf("\n");
          set_debugflags(optarg);
          //printf("case -@\n");
          break;
        
        case 'D':
        //Pass this option and its argument to cpp. 
        //This is mostly useful as-D__OCLIB_OH__ to suppress inclusion of the code from oclib.oh
        //when testing a program
          //printf("case -D\n");
		  Dopts = 1;
		  Dargs = optind - 1;
          break;
      
        default:
          fprintf(stderr, "Option: [-ly] [-@flag...] [-D string]\n");
          exit_status = 1;
          exit(exit_status);        
      }
    }
    if (optind>=argc){
        fprintf(stderr, "Missing expected argument after the Options\n");
        exit_status=1;
        exit(exit_status);
    }

    string yyin_tmp;
    string base;
    string asg1;
    string asg2;
    FILE * strFile;
    FILE * tokFile;
    set_execname (argv[0]);
    
   for (int argi = optind; argi < argc; ++argi) {
      char* filename = argv[argi]; 
      base = remove_extension(filename); 
      asg1 = base+".str";
      asg2 = base+".tok";
      strFile = fopen(asg1.c_str(), "w");
      tokFile = fopen(asg2.c_str(), "w");
      
	  string command;
	  if (Dopts) {
		command = CPP + " " + argv[Dargs] + " " + filename;
	  } else {
		command = CPP + " " + filename;
	  }  
//      printf ("command=\"%s\"\n", command.c_str());
      yyin = popen (command.c_str(), "r");
      if (pipe == NULL) {
        syserrprintf (command.c_str());
      }else{
        for(;;){
          int token = yylex();
          if (token == YYEOF){
            return;
          } 
        }
        pclose(tokFile);
      }
        

      //cpplines (pipe, filename);
      int pclose_rc = pclose (yyin);
      eprint_status (command.c_str(), pclose_rc);
      }
   } 
   dump_stringset(strFile);
   pclose(strFile);
   return get_exitstatus();
}