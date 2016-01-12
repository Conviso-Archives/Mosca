#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>
#include <errno.h>
#include "mem_ops.h"

// colors macros 
#define RED "\033[22;31m"
#define YELLOW "\033[01;33m"
#define CYAN "\033[22;36m"
#define GREEN "\033[22;32m"
#define LAST "\033[0m"


char log_file[256];
char *ReadLines(char * NameFile);
char *Search_for(char * NameFile,char *regex);
void fly_to_analyse(char *path, char *config);
void mosca_start (const char * dir_name, char * extension, char * config);


