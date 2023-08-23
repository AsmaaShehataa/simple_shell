#include "hsh.h"
/**
 * arg_process - process the user input.
 * @user_input: the string inputed from the user.
 *
 * Return: array of arguments.
 */

char **arg_process(char *user_input)
{
	char **arg_array;
	char *token;
	char *delim;
	char *string_holder;
	int counter;
	int i;

	delim = " ";
	string_holder = strdup(user_input);
	token = strtok(string_holder, delim);
	counter = 0;
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	arg_array = malloc(sizeof(char *) * (counter + 1));
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
/**
 * arg_arr_lenth - return the lenth of the argument array.
 * @user_input: the input given by the user.
 *
 * Return: the length of the array.
 */

int arg_arr_lenth(char *user_input)
{
	int counter;
	char *token;
	char *delim;
	char *str_holder;

	delim = " ";
	counter = 0;
	str_holder = strdup(user_input);
	token = strtok(str_holder, delim);
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	free(str_holder);
	counter = counter + 1;
	return (counter);
}
