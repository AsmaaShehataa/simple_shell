#include "hsh.h"

/**
 * check_slash - check the user input for '/'
 * @user_input: the user input.
 *
 * Return: 0 if there is a slash, -1 otherwise.
 */

int check_slash(char *user_input)
{
	int counter;

	counter = 0;
	while (user_input[counter])
	{
		if (user_input[counter] == '/')
			return (0);
		counter++;
	}
	return (-1);
}
