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
	char *holder;

	holder = strdup(user_input);
	counter = 0;
	while (holder[counter])
	{
		if (holder[counter] == '/')
		{
			free(holder);
			return (0);
		}
		counter++;
	}
	free(holder);
	return (-1);
}
