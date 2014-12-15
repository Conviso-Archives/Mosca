#include "string_ops.h"
#include "mem_ops.h"

#define array_elements(array) (sizeof(array) / sizeof *(array))


void Dead_Space(char *str) 
{
	char *p1 = str, *p2 = str;

	while((*p1++ = *p2++))
	{
		while(*p2 == '\r' || *p2 == '\t' || *p2 == '	')
			++p2;
	}

}


char  *ClearStr(char* charBuffer,int num) 
{
	char *tmp=(charBuffer + num);
	tmp[strlen(tmp)-2]='\0';
	return tmp;
}

// DFA to parse egg module
int parse_eggs(char** p, char** lex)
{
    char* marker=NULL;

    for (;;) 
    {
      *lex = *p;
	{
		char yych;
		unsigned int yyaccept = 0;

		yych = (char)**p;
		switch (yych) {
		case 0x00:	goto yy4;
		case ':':	goto yy2;
		default:	goto yy6;
		}
yy2:
		yyaccept = 0;
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case ':':	goto yy7;
		default:	goto yy3;
		}
yy3:
		{ continue; }
yy4:
		++*p;
		{ return END; }
yy6:
		yych = (char)*++*p;
		goto yy3;
yy7:
		yych = (char)*++*p;
		switch (yych) {
		case 'D':
		case 'd':	goto yy10;
		case 'M':
		case 'm':	goto yy12;
		case 'R':
		case 'r':	goto yy11;
		case 'T':
		case 't':	goto yy9;
		default:	goto yy8;
		}
yy8:
		*p = marker;
		switch (yyaccept) {
		case 0: 	goto yy3;
		case 1: 	goto yy24;
		case 2: 	goto yy58;
		}
yy9:
		yych = (char)*++*p;
		switch (yych) {
		case 'I':
		case 'i':	goto yy77;
		default:	goto yy8;
		}
yy10:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy60;
		default:	goto yy8;
		}
yy11:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy26;
		default:	goto yy8;
		}
yy12:
		yych = (char)*++*p;
		switch (yych) {
		case 'A':
		case 'a':	goto yy13;
		default:	goto yy8;
		}
yy13:
		yych = (char)*++*p;
		switch (yych) {
		case 'T':
		case 't':	goto yy14;
		default:	goto yy8;
		}
yy14:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':
		case 'c':	goto yy15;
		default:	goto yy8;
		}
yy15:
		yych = (char)*++*p;
		switch (yych) {
		case 'H':
		case 'h':	goto yy16;
		default:	goto yy8;
		}
yy16:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy17;
		default:	goto yy8;
		}
yy17:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy18;
		default:	goto yy8;
		}
yy18:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy19;
		default:	goto yy8;
		}
yy19:
		yych = (char)*++*p;
		switch (yych) {
		case ')':
		case ':':
		case '>':	goto yy8;
		default:	goto yy20;
		}
yy20:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case ' ':	goto yy22;
		case ')':
		case ':':	goto yy25;
		case '>':	goto yy8;
		default:	goto yy20;
		}
yy22:
		yyaccept = 1;
		marker = ++*p;
		yych = (char)**p;
		switch (yych) {
		case ' ':	goto yy22;
		case ')':
		case ':':	goto yy25;
		case '>':	goto yy24;
		default:	goto yy20;
		}
yy24:
		{ return MATCH; }
yy25:
		yych = (char)*++*p;
		goto yy24;
yy26:
		yych = (char)*++*p;
		switch (yych) {
		case 'F':
		case 'f':	goto yy28;
		case 'L':
		case 'l':	goto yy27;
		default:	goto yy8;
		}
yy27:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy45;
		default:	goto yy8;
		}
yy28:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy29;
		default:	goto yy8;
		}
yy29:
		yych = (char)*++*p;
		switch (yych) {
		case 'R':
		case 'r':	goto yy30;
		default:	goto yy8;
		}
yy30:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy31;
		default:	goto yy8;
		}
yy31:
		yych = (char)*++*p;
		switch (yych) {
		case 'N':
		case 'n':	goto yy32;
		default:	goto yy8;
		}
yy32:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':
		case 'c':	goto yy33;
		default:	goto yy8;
		}
yy33:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy34;
		default:	goto yy8;
		}
yy34:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy35;
		default:	goto yy8;
		}
yy35:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy36;
		default:	goto yy8;
		}
yy36:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy37;
		default:	goto yy8;
		}
yy37:
		yych = (char)*++*p;
		switch (yych) {
		case ')':	goto yy8;
		default:	goto yy39;
		}
yy38:
		++*p;
		yych = (char)**p;
yy39:
		switch (yych) {
		case ')':	goto yy40;
		case '>':	goto yy8;
		default:	goto yy38;
		}
yy40:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case ')':	goto yy40;
		case ':':	goto yy42;
		default:	goto yy8;
		}
yy42:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy43;
		default:	goto yy8;
		}
yy43:
		++*p;
		{ return REFERENCE; }
yy45:
		yych = (char)*++*p;
		switch (yych) {
		case 'V':
		case 'v':	goto yy46;
		default:	goto yy8;
		}
yy46:
		yych = (char)*++*p;
		switch (yych) {
		case 'A':
		case 'a':	goto yy47;
		default:	goto yy8;
		}
yy47:
		yych = (char)*++*p;
		switch (yych) {
		case 'N':
		case 'n':	goto yy48;
		default:	goto yy8;
		}
yy48:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':
		case 'c':	goto yy49;
		default:	goto yy8;
		}
yy49:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy50;
		default:	goto yy8;
		}
yy50:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy51;
		default:	goto yy8;
		}
yy51:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy52;
		default:	goto yy8;
		}
yy52:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy53;
		default:	goto yy8;
		}
yy53:
		yych = (char)*++*p;
		switch (yych) {
		case ')':
		case ':':
		case '>':	goto yy8;
		default:	goto yy54;
		}
yy54:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case ' ':	goto yy56;
		case ')':
		case ':':	goto yy59;
		case '>':	goto yy8;
		default:	goto yy54;
		}
yy56:
		yyaccept = 2;
		marker = ++*p;
		yych = (char)**p;
		switch (yych) {
		case ' ':	goto yy56;
		case ')':
		case ':':	goto yy59;
		case '>':	goto yy58;
		default:	goto yy54;
		}
yy58:
		{ return RELEVANCE; }
yy59:
		yych = (char)*++*p;
		goto yy58;
yy60:
		yych = (char)*++*p;
		switch (yych) {
		case 'S':
		case 's':	goto yy61;
		default:	goto yy8;
		}
yy61:
		yych = (char)*++*p;
		switch (yych) {
		case 'C':
		case 'c':	goto yy62;
		default:	goto yy8;
		}
yy62:
		yych = (char)*++*p;
		switch (yych) {
		case 'R':
		case 'r':	goto yy63;
		default:	goto yy8;
		}
yy63:
		yych = (char)*++*p;
		switch (yych) {
		case 'I':
		case 'i':	goto yy64;
		default:	goto yy8;
		}
yy64:
		yych = (char)*++*p;
		switch (yych) {
		case 'P':
		case 'p':	goto yy65;
		default:	goto yy8;
		}
yy65:
		yych = (char)*++*p;
		switch (yych) {
		case 'T':
		case 't':	goto yy66;
		default:	goto yy8;
		}
yy66:
		yych = (char)*++*p;
		switch (yych) {
		case 'I':
		case 'i':	goto yy67;
		default:	goto yy8;
		}
yy67:
		yych = (char)*++*p;
		switch (yych) {
		case 'O':
		case 'o':	goto yy68;
		default:	goto yy8;
		}
yy68:
		yych = (char)*++*p;
		switch (yych) {
		case 'N':
		case 'n':	goto yy69;
		default:	goto yy8;
		}
yy69:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy70;
		default:	goto yy8;
		}
yy70:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy71;
		default:	goto yy8;
		}
yy71:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy72;
		default:	goto yy8;
		}
yy72:
		yych = (char)*++*p;
		switch (yych) {
		case ')':
		case ':':	goto yy8;
		default:	goto yy74;
		}
yy73:
		++*p;
		yych = (char)**p;
yy74:
		switch (yych) {
		case ')':
		case ':':	goto yy75;
		case '>':	goto yy8;
		default:	goto yy73;
		}
yy75:
		++*p;
		{ return DESCRIPTION; }
yy77:
		yych = (char)*++*p;
		switch (yych) {
		case 'T':
		case 't':	goto yy78;
		default:	goto yy8;
		}
yy78:
		yych = (char)*++*p;
		switch (yych) {
		case 'L':
		case 'l':	goto yy79;
		default:	goto yy8;
		}
yy79:
		yych = (char)*++*p;
		switch (yych) {
		case 'E':
		case 'e':	goto yy80;
		default:	goto yy8;
		}
yy80:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy81;
		default:	goto yy8;
		}
yy81:
		yych = (char)*++*p;
		switch (yych) {
		case ':':	goto yy82;
		default:	goto yy8;
		}
yy82:
		yych = (char)*++*p;
		switch (yych) {
		case '(':	goto yy83;
		default:	goto yy8;
		}
yy83:
		yych = (char)*++*p;
		switch (yych) {
		case ')':
		case ':':	goto yy8;
		default:	goto yy85;
		}
yy84:
		++*p;
		yych = (char)**p;
yy85:
		switch (yych) {
		case ')':
		case ':':	goto yy86;
		case '>':	goto yy8;
		default:	goto yy84;
		}
yy86:
		++*p;
		{ return TITLE; }
	}

    }
}


int match_test(const char *string,const char *expression)
{
	const char *err;
	int errofs=0,offset=0;
	int ovector[100];

	pcre *re = pcre_compile(expression, 0, &err, &errofs, NULL);

	if (re == NULL) 
	{
		DEBUG(" regex compilation failed : %s\n",expression);
		exit(0);
	}
	const int rc = pcre_exec(re, NULL, string, strlen(string), offset, 0, ovector, array_elements(ovector));
	pcre_free(re);

	return rc > 0;

}
