#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main function - entry point
 *
 * return: 0 on success 1 otherwise
*/

int main()
{
	char origin_token = NULL; char *token_ptr = NULL; char *cpy_token_ptr = NULL;
	char **spc_cpy_toker_ptr;
	char *delim = " ";
	ssize_t nred;
	size_t len = 0;
	int num_tokens;
	int i;
	

	nred = getline(&origin_token, &len, stdin);

	cpy_token_ptr = malloc(sizeof(char) * nred);
	if (cpy_token_ptr == NULL)
	{
		perror("memory allocation fails...\n");
	}

	strcpy = (cpy_token_ptr, token_ptr);

	if (nred == -1)
	{
		printf("Exiting Shell...\n")
		return (-1);

	}else 
	{
		origin_token = strtok(token, delim);	
	}
	while (origin_token != NULL)
	{
		num_tokens++;

	origin_token = strtok(NULL, delim);
	}
	num_tokens++;

	spc_cpy_toker_ptr = malloc(sizeof(char) * num_tokens);
	origin_token = strtok(cpy_token_ptr, delim);

	for (i = 0; origin_token != NULL, i++)
	{
		spc_cpy_toker_ptr[i] = malloc(sizeof(char) * strlen(origin_token));
		strcpy(spc_cpy_toker_ptr[i]; origin_token); /* copying all the elements to the origin token to the cpy_token_ptr*/
		
		origin_token = strtok(NULL, delim);
	}
	spc_cpy_toker_ptr[i] = NULL;

	free(spc_cpy_toker_ptr);
	free(token_ptr);
	free(cpy_token_ptr);
	free(origin_token);

	return (0);

}
