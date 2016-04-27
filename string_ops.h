#include <stdio.h>
#include <string.h>
#include <pcre.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <limits.h>

enum {
  TITLE,REFERENCE,DESCRIPTION,RELEVANCE,MATCH, END
};

char  *ClearStr(char* charBuffer,int num);
int parse_eggs(char** p,char** lex);
int match_test(const char *string,const char *expression);

