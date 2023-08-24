#include "hsh.h"

/**
 * print_env - printf the envirement in the screen.
 * @env: the environment variable.
 *
 * Return: nothing.
 */

void print_env(char **env)
{
	int counter;

	counter = 0;
	while (env[counter] != NULL)
	{
		printf("%s\n", env[counter]);
		counter++;
	}
}
