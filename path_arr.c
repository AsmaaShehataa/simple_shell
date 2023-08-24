#include "hsh.h"

/**
 * path_value - thsi produces the correct path value from the env.
 * @name: the variable path name.
 *
 * Return: the line value where the variable found
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
