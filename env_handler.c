#include "hsh.h"

/**
 * print_env - printf the envirement in the screen.
 * @env: the environment variable.
 * @user_input: the given operand.
 *
 * Return: nothing.
 */

int print_env(char **env, char *user_input)
{
	int counter;

	counter = 0;
	if (strcmp(user_input, "env") == 0)
	{
		while (env[counter] != NULL)
		{
			print_string(env[counter]);
			counter++;
		}
		return (0);
	}
	else
	{
		return (-1);
	}
}
