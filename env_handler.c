#include "hsh.h"

/**
 * print_env - printf the envirement in the screen.
 * @env: the environment variable.
 * @user_input: the given operand.
 *
 * Return: nothing.
 */

int print_env(char **env __attribute__((unused)), char *user_input)
{
	int counter;
	extern char **environ;
	counter = 0;
	if (strcmp(user_input, "env") == 0)
	{
		while (environ[counter] != NULL)
		{
			print_string(environ[counter]);
			counter++;
		}
		return (0);
	}
	else
	{
		return (-1);
	}
}
