#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *strtok(char *token, const char *delim)
{
	char *token = NULL;
	char **returned_token;
	char *delim = " ";
	ssize_t nred;
	int i; 

	nred = strtok(token, delim);
	i = 0;
	while (token != NULL)
	{
		returned_token[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	returned_token[i] = token;
	return (returned_token);
}

