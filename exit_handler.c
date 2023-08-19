#include "hsh.h"
/**
 * __exit - performs an exit
 * @user_input: the user input from prompt.c main function
 *
 * Return: it return 0, indicating the memory is freed and the shell 
 * process is killed
 */

int  __exit(char *user_input)
{
	if (strcmp(user_input, "exit") == 0)
	{
		free(user_input);
		return (0);
	}
	else
	{
		return (-1);
	}
}
