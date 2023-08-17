#include "hsh.h"
/**
 * arg_process - process the user input.
 * @user_input: the string inputed from the user.
 *
 * Return : array of arguments.
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
	//this first while will calculate the length of the array.
	token = strtok(string_holder, delim);
	counter = 0;
	while (token)
	{
		counter++;
		token = strtok(NULL, delim);
	}
	free(string_holder);
	free(token);
	//allocate memory in here
	printf("this is from the arg_process(), the counter is: %d\n", counter); //print the number of arguments
	arg_array = malloc(sizeof(char *) * (counter + 1));
	//we are allocation the elements to the array
	i = 0;
	string_holder = strdup(user_input);
	//string_holder = strdup(user_input);
	token = strtok(user_input, delim);
	while (token)
	{
		arg_array[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	free(token);
	//while the NULL element to the end of the array.
	arg_array[i] = NULL;
	//free the string holder memory in here
	free(string_holder);
	//befour the returning and for testing only. -> this returns a complete and correct array of arguments.
	//returning the resulted array.
	return (arg_array); //make sure to free the memory we used for this array.
}

/**
 * arg_arr_lenth - return the lenth of the argument array.
 * @user_input.
 *
 * Return the length of the array.
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
	free(token);
	free(str_holder);
	counter = counter + 1;
	return (counter);
}
