#include "hsh.h"
/**
 * __exit - performs an exit
 * @user_input: the user input from prompt.c main function
 *
 * Return: it return 0, indicating the memory is freed and the shell
 * process is killed
 */

int  b_exit(char **arr_holder, char *user_input)
{
	free(user_input);
	free(arr_holder);
	exit(EXIT_SUCCESS);
}
