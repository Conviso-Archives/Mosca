/*
Simple example code analysis with deterministic finite automaton
based at https://www.securecoding.cert.org/confluence/display/seccode/FIO42-C.+Close+files+when+they+are+no+longer+needed

author: Cooler_
contact: acosta[at]conviso[dot]com
DATE: 14/12/2014
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OPEN,CLOSE,COUNTER,END
};


char *ReadLines(char * NameFile);
int parse_ion(char** p, char** lex);

int main() 
{
	char *p = ReadLines("/home/user/test.php"); //evidente que o analisador funciona com código em linguagem C, Perl, PHP...  em Common lisp não, pois sintaxe é bem diferente.
	char *last = p;
 	int test=0,result=0,line_number=1;

	puts(p);

	while(!result )
		switch (parse_ion(&p, &last)) 
		{
	        	case OPEN:  //detectou função OPEN
		    	test=1;	
		    	printf("OPEN function at line %d\n",line_number); 
	            	break;
	 
		        case CLOSE:  // detectou função close
		        test-=1;
	     	        printf("CLOSE function at line %d\n",line_number);
	   	        break;
	
	        	case COUNTER: // conta as linhas
		    	line_number++;
	            	break;
	
	        	case END: // final nullbyte \0
		    	result=1;	
	            	break;
	        }

	puts("\n===================\n");
	if(test)
		puts("Have BAD practice here\n");
	else
		puts("Ok here");

    return 0;
}


char *ReadLines(char * NameFile)
{
	FILE * arq=NULL;

	arq = fopen(NameFile, "rx");

	if( arq == NULL )
	{
		puts("error at fopen()");
		exit(1);
	}

	char *lineBuffer=calloc(1,1); 
	char line[2048];

	while( fgets(line,sizeof line,arq) )  
	{
		lineBuffer=realloc(lineBuffer,strlen(lineBuffer)+strlen(line));
		strncat(lineBuffer,line,2047);
	}

 
	if( fclose(arq) == EOF )
	{
		puts("error at fclose()");
		exit(1);
	}

	arq=NULL;

	lineBuffer[strlen(lineBuffer)-1]='\0';


	char *tmp=lineBuffer;

	if(lineBuffer != NULL)
		free(lineBuffer);

	return tmp;
}


int parse_ion(char** p, char** lex)
{
    char* marker;

    for (;;) 
    {
	*lex = *p;
    
	{
		char yych;

		yych = (char)**p;
		switch (yych) {
		case 0x00:	goto yy8;     // goto é extremamente rápido, muito utilizado em otimização no contexto desempenho
		case '\n':	goto yy6;
		case '*':
		case '.':
		case '>':	goto yy2;
		case 'c':	goto yy5;
		case 'o':	goto yy4;
		default:	goto yy10;
		}
yy2:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case '*':
		case '.':
		case '>':	goto yy26;
		case 'c':	goto yy25;
		case 'o':	goto yy28;
		default:	goto yy3;
		}
yy3:
		{ continue; }
yy4:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'p':	goto yy19;
		default:	goto yy3;
		}
yy5:
		yych = (char)*(marker = ++*p);
		switch (yych) {
		case 'l':	goto yy11;
		default:	goto yy3;
		}
yy6:
		++*p;
		{ return COUNTER; }
yy8:
		++*p;
		{ return END; }
yy10:
		yych = (char)*++*p;
		goto yy3;
yy11:
		yych = (char)*++*p;
		switch (yych) {
		case 'o':	goto yy13;
		default:	goto yy12;
		}
yy12:
		*p = marker;
		goto yy3;
yy13:
		yych = (char)*++*p;
		switch (yych) {
		case 's':	goto yy14;
		default:	goto yy12;
		}
yy14:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy15;
		default:	goto yy12;
		}
yy15:
		yych = (char)*++*p;
		switch (yych) {
		case ' ':
		case '(':
		case '|':	goto yy16;
		default:	goto yy12;
		}
yy16:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy18;
		default:	goto yy16;
		}
yy18:
		{ return CLOSE; }
yy19:
		yych = (char)*++*p;
		switch (yych) {
		case 'e':	goto yy20;
		default:	goto yy12;
		}
yy20:
		yych = (char)*++*p;
		switch (yych) {
		case 'n':	goto yy21;
		default:	goto yy12;
		}
yy21:
		yych = (char)*++*p;
		switch (yych) {
		case ' ':
		case '(':
		case '|':	goto yy22;
		default:	goto yy12;
		}
yy22:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '\n':	goto yy24;
		default:	goto yy22;
		}
yy24:
		{ return OPEN; }
yy25:
		yych = (char)*++*p;
		switch (yych) {
		case 'l':	goto yy11;
		default:	goto yy12;
		}
yy26:
		++*p;
		yych = (char)**p;
		switch (yych) {
		case '*':
		case '.':
		case '>':	goto yy26;
		case 'c':	goto yy25;
		case 'o':	goto yy28;
		default:	goto yy12;
		}
yy28:
		++*p;
		switch ((yych = (char)**p)) {
		case 'p':	goto yy19;
		default:	goto yy12;
		}
	}

    }
}
