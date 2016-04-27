#include "file_ops.h"
#include "mem_ops.h"
#include "string_ops.h"
#include <alloca.h>
#define MAX_file_len 50000

//read lines of file
char *ReadLines(char * NameFile)
{
	FILE * fh;
	static char buffer[MAX_file_len];

	memset(buffer,0,MAX_file_len-1);

	fh = fopen(NameFile, "rb");

	if( fh == NULL )
	{

		DEBUG("error in to open() file");
		perror("Error ");
		exit(-1); 	 
		
	}

	if(fseek(fh, 0L, SEEK_END)==0)
	{
    		long s = ftell(fh);
    		rewind(fh);

    		if ( buffer != NULL && s < MAX_file_len )
    		{
      			if(!fread(buffer, s, 1, fh))
				DEBUG("error \n");
    		}
	}

 
	if( fclose(fh) == EOF )
	{
		DEBUG("Error in close() file %s",NameFile);
		exit(1);
	}

	fh=NULL;

	char *tmp=buffer;
	
	return tmp;
}




// search matchs in file
char *Search_for(char * NameFile,char *regex)
{
        long int count=0;
	int match=0;
	char *lineBuffer=xcalloc(1,1);
	char tmpline[2128];

	FILE * arq;

	arq = fopen(NameFile, "r");
// todo think implement fcntl() ,toctou mitigation...
	if( arq == NULL )
	{
		DEBUG("error in to open() file"); 	 
		exit(1);
	}

	char line[2127];

	while( fgets(line,sizeof line,arq) )  
	{
		match=match_test(line,regex);

		if(match)
		{
			lineBuffer=xrealloc(lineBuffer,strlen(lineBuffer)+2256);
			snprintf(tmpline,2127," Line: %ld -  %s\n",count,line);
			strncat(lineBuffer,tmpline,2255);
		}
		
		count++;
	}

 
	if( fclose(arq) == EOF )
	{
		DEBUG("Error in close() file %s",NameFile);
		exit(1);
	}

	arq=NULL;

	return lineBuffer;
}


void fly_to_analyse(char *path, char *config)
{
	char *p=ReadLines(config);
	char *last=p;
	char title[128],description[512],reference[512],match[1024],relevance[512];	
	int result=0,sz=0;

	
	while(!result && strlen(last)>16)
	{
		switch (parse_eggs(&p, &last)) 
		{
			case TITLE:
					sz = p - last;
					memset(title,0,127);
					snprintf(title,127,"%.*s", sz, last);
					strcpy(title,ClearStr(title,10));
				break;

			case DESCRIPTION:
				
 					sz = p - last;
					memset(description,0,511);
					snprintf(description,511,"%.*s", sz, last);
					strcpy(description,ClearStr(description,16));
				break;

			case REFERENCE:

					sz = p - last - 1;
					memset(reference,0,511);
					snprintf(reference,511,"%.*s", sz, last);
					strcpy(reference,ClearStr(reference,14));
				break;


			case RELEVANCE:

					sz = p - last;
					memset(relevance,0,511);
					snprintf(relevance,511,"%.*s", sz, last);
					strcpy(relevance,ClearStr(relevance,14));
				break;

			case MATCH:
					sz = p - last;
					memset(match,0,1023);
					snprintf(match,1023,"%.*s", sz, last);
					strcpy(match,ClearStr(match,10));


					char *result2=Search_for(path,match);

// TODO* need validate before print out
					if(result2!=NULL)
					if(strlen(result2)>8)
					{
						fprintf(stdout,"\n-------------------\n %sTitle:%s  %s  \n %sDescription:%s %s \n %sRelevance:%s %s \n %sReference:%s %s \n %sMatch:%s %s  \n%s%s%s\n",YELLOW,LAST,title,YELLOW,LAST,description,YELLOW,LAST,relevance,YELLOW,LAST,reference,YELLOW,LAST,match,CYAN,result2,LAST);

						if(log_file != NULL)
						{
							FILE *arq;
 
							arq=fopen(log_file,"a"); 

							if ( arq == NULL ) 
							{
								DEBUG("error in XML file %s",log_file); 
								perror("Error ");
								exit(-1);
							}

							fprintf(arq,"<report_mosca>\n <Path>%s</Path>\n <Module>%s</Module>\n <Title>%s</Title>\n <Description>%s</Description>\n <Level>%s</Level>\n <Reference>%s</Reference>\n <Match>%s</Match>\n <Result>%s</Result>\n</report_mosca>\n\n",path,config,title,description,relevance,reference,match,result2); 

							if( fclose(arq) == EOF )
							{
								DEBUG("error in Write() file %s",log_file);
								perror("Error ");
								exit(-1);
							}
							arq=NULL;
		 
						}
					}
					xfree((void **)&result2);
				break;


			case END:
				result=1;	
				break;
    		}
	
	
	}
	
	if(strlen(last)>16)
		xfree((void **)&last);
}



void mosca_start (const char * dir_name, char * extension, char * config)
{
	DIR * d;
	char tmp_path[512];	

 	d = opendir (dir_name);

	if ( d == NULL) 
	{
//		closedir(d);
		DEBUG ("Cannot open directory '%s': %s\n", dir_name, strerror (errno));
 		exit (EXIT_FAILURE);
	}

	while (1) 
	{
		struct dirent * entry;
 		const char * d_name;

		entry = readdir (d);

		if (! entry) 
		{
			break;
		}

		d_name = entry->d_name;

// TODO* i need improve that extension check
		if(strcmp(d_name,".") && strcmp(d_name,"..") && match_test(d_name,extension))
		{
			snprintf(tmp_path,511,"%s/%s",dir_name,d_name);
			printf("\n=====================================\n%s Path:%s %s \n %sUse Module:%s %s\n",YELLOW,LAST,tmp_path,YELLOW,LAST,config);
			fly_to_analyse(tmp_path, config);
			memset(tmp_path,0,511);
		}


	        if (entry->d_type & DT_DIR) 
		{

            
	            if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0) 
		    {
	  		int path_length;
			char path[1024];
 
			path_length = snprintf (path, 1023, "%s/%s", dir_name, d_name);


     	                if (path_length >= 1023) 
			{
               		     DEBUG("Path length has got too long.\n");
               		     exit(0);
               		}

                	mosca_start (path,extension,config);
	         }
	}
    }

    if(closedir(d)) 
    {
        DEBUG("Could not close '%s': %s\n", dir_name, strerror (errno));
        exit(0);
    }
}
