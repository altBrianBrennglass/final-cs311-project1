
// In Linux The following block of 6 lines of code must be at the top of your file, 
// after your regular #includes, such as stdio.h.
#ifndef _WIN32
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdlib.h>//Why wasn't this included!!!
#include <stdio.h>
#endif

#ifndef FILE
	#include <string.h>
#endif


