#include "hsh.h"
/**
 * arg_process - process the user input.
 * @user_input: the string inputed from the user.
 *
 * Return: array of arguments.
 */

char **arg_process(char *user_input, char *delim)
{
	char **arg_array;
	char *token;
	char *string_holder;
	int counter;
	int i;

	string_holder = strdup(user_input);
	token = strtok(string_holder, delim);
	counter = 0;
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	arg_array = malloc(sizeof(char *) * (counter + 1));
	if (arg_array == NULL)
		return (NULL);

	i = 0;
	token = strtok(user_input, delim);
	while (token)
	{
		arg_array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	arg_array[i] = NULL;
	free(string_holder);
	return (arg_array);
}
