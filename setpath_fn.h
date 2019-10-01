#include "setpath_defs.h"

char in_path[200];
char out_path[200];
char infilename[10];
char outfilename[11];

FILE* infile;
FILE* outfile;



void setpath()
{
#ifdef _WIN32  //Windows
       char in_path[]="C:\\temp\\coursein\\p1-in.txt";
       char out_path[]="C:\\temp\\courseout\\p1-out.txt";

#else //Linux
	     strcat(out_path, "/fileio/courseout/p1-out.txt");

             const char *homedir;
             homedir = getenv("HOME");
             if (homedir!= NULL){
                    homedir = getpwuid(getuid())->pw_dir;
	     }

             strcpy(in_path,homedir);
             strcat(in_path,"/temp/coursein/p1-in.txt");	

#endif
}
// Now you can use the names, infile and outfile in your fopen, input and output statements.

