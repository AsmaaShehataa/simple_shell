#include "hsh.h"
/**
 * check_builtin - checks for the "exit", "env" builtin commands
 * @arr_holder: the passed array.
 * @user_input: the passed user_input string
 *
 * Return: (0) in case of "env", call b_exit() in case of "exit".
 */
int check_builtin(char **arr_holder, char *user_input)
{
	if (strcmp(arr_holder[0], "exit") == 0)
	{
		b_exit(arr_holder, user_input);
		return (1);
	}
	else if (strcmp(arr_holder[0], "env") == 0)
		return (print_env(arr_holder));
	return (0);
}
