#include <stdio.h>
#include <stdlib.h>

extern char ** environ ;
#define ISSTRING(x) (memcmp(*env, x, strlen(x)) == 0)
int main(int argc, char *argv[])
{
	int i=0;
	char **env = environ;
	char request_uri[LINE_MAX] = {0};
	
	for(i=0; i<argc; i++)
	{
		printf("arg%d:%s\n", i, argv[i]);
	}
	
	while(*env)
	{
		if(memcmp(*env, "HTTP-REFERER", 12 )== 0)
		{
			//printf("%s\n", *env);
		}
		else if(memcmp(*env, "PATH-INFO", 9 )== 0)
		{
			//printf("%s\n", *env);
		}
		else if(memcmp(*env, "SCRIPT_NAME", strlen("SCRIPT_NAME")) == 0)
		{
			//printf("%s\n", *env);
		}
		else if(ISSTRING("REQUEST_URI"))
		{
			char *end = strstr(*env, "\n");
			memcpy(request_uri, *env, end-*env);
			//printf("%s\n", *env);
		}
		else if(ISSTRING("QUERY_STRING"))
		{
			//printf("%s\n", *env);
		}
		else if(ISSTRING("SCRIPT_FILENAME"))
		{
			//printf("%s\n", *env);
		}

		env++;
	}

	
	return 0;
}
