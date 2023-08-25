#include "hsh.h"

/**
 * check_validation - checks if a command is valid
 * @comm: command
 * @name: name
 * @arr: arr
 * Return: string
 */
char *check_validation(char *comm, char *name, char **arr)
{
	int i;
	struct stat buf;
	char *path, **path_arr = NULL, *env;

	env = _getenv("PATH");
	if (!env)
	{
		if (!access(comm, X_OK) && stat(comm, &buf) == 0)
			return (comm);
		return (NULL);
	}
	else if (*env == '\0')
	{
		error_handeling(name, arr, NULL, 1);
		exit(EXIT_FAILURE);
	}
	else
		path_arr = _strtok(env, ":");
	for (i = 0; path_arr[i]; i++)
	{
		if (!_strstr(comm, "/"))
		{
			path = malloc(_strlen(path_arr[i]) + _strlen(comm) + 3);
			_strcpy(path, path_arr[i]);
			_strcat(path, "/");
			_strcat(path, comm);
		}
		else
			path = malloc(_strlen(comm) + 2), _strcpy(path, comm);
		if (!access(path, X_OK) && stat(path, &buf) == 0)
		{
			_free_buffer(path_arr);
			return (path);
		}
		free(path);
	}
	_free_buffer(path_arr);
	return (NULL);
}
