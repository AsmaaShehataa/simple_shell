#include "hsh.h"

/**
 * print_env - printf the envirement in the screen.
 * @env: the environment variable.
 * @user_input: the given operand.
 *
 * Return: nothing.
 */

int print_env(char **arr_handler)
{
	int counter;

	if (arr_handler[1] != NULL)
		return (0);
	counter = 0;
	while (environ[counter] != NULL)
	{
		print_string(environ[counter]);
		counter++;
	}
	return (1);
}
