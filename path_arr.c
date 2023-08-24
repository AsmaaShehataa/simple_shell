#include "hsh.h"

/**
 * get_path - function that retreive all the paths environs
 *
 * Return: Path environment
 */

char **get_path_arr(char **env)
{
	char **path_arr; 
	char *path_line;
	char *token;
	char *path_value_holder;
	int i = 0;
	char delim = ':';
	const char *path_var;
	size_t path_size;

	path_var = "PATH";
	path_size = strlen(path_var);

	while (env[i]) 
	{
		if (strncmp(env[i], path_var, path_size) == 0)
		{
			path_line = strdup(env[i]);

			printf("%s\n", path_line);
		
		}
		i++;
	}
	path_value_holder = malloc(strlen(path_line + 1));
	path_value_holder = strcpy(path_value_holder, path_line);


	

	
	int j;
	int counter = 0;
	while (path_value_holder[j])
	{
		if (path_value_holder[j] == delim)
			counter++;	
		j++;
		//token = strtok(NULL, delim);
	}
	
	
	path_arr = malloc(sizeof(char *) * counter + 1);

	int k = 0; 

	
	token = strtok(path_value_holder, ":");

	while (token != NULL)
	{

		path_arr[k] = strdup(token);
		token = strtok(NULL, ":");
		k++;
	}

	path_arr[k] = NULL;
	free(path_line);
	free(path_value_holder);
	return (path_arr);
}


