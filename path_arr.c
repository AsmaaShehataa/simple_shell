#include "hsh.h"

/**
 * get_path_arr - produces an array of folders from the path.
 * @path_str: the path str.
 * @env: the envirement passed by the the caller function.
 *
 * Return: this returns an array of strings, (folders from the path value).
 */
/*char **get_path_arr(const char *path_str, char **env)
{
	char *token;
	char **path_arr;
	char *path_value_str, *path_value_holder;
	int els_num, value_int;
	const char *two_pt_delim;

	els_num = 0;
	two_pt_delim = ":";
//	path_value_str = path_value(path_str, env);
	path_value_holder = strdup(path_value_str);
	token = strtok(path_value_str, two_pt_delim);
	while (token)
	{
		token = strtok(NULL, two_pt_delim);
		els_num++;
	}
	path_arr = malloc(sizeof(char *) * (els_num + 1));
	if (path_arr == NULL)
	{
		perror("Error while allocating memory.");
		free(path_value_str);
		free(path_value_holder);
		exit(EXIT_FAILURE);
	}
	value_int = 0;
	token = strtok(path_value_holder, two_pt_delim);
	while (token)
	{
		path_arr[value_int] = strdup(token);
		token = strtok(NULL, two_pt_delim);
		value_int++;
	}
	path_arr[value_int] = NULL;
	free(path_value_str);
	free(path_value_holder);
	return (path_arr);
}*/

/**
 * path_value - thsi produces the correct path value from the env.
 * @path_str: the pathstring == "PATH"
 * @env: a global variable passed by the calling function.
 *
 * Return: this will be an array of chars (string), containing
 * the value of path in env.
 */
char *path_value(char *name)
{
	size_t path_size;
	int counter;

	counter = 0;
	path_size = strlen(name);
	while (environ[counter])
	{
		if (strncmp(environ[counter], name, path_size) == 0)
			return (environ[counter] + path_size + 1);
		counter++;
	}
	return (NULL);
}
