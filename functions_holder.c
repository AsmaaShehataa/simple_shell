#include "hsh.h"

/**
 * prompt_holder - this fucntion will execute the passed
 * parameter by the prompt.c (containing main())
 * Description: this analogy was introduced only to reduce
 * the number of lines inside a function.
 * @user_input: the passed user_input
 * @av: the name of the executable used by the user to run the shell.
 *
 * Return: nothing only execution of the code
 */

void prompt_holder(char *user_input, char *av)
{
	char **arr_holder;
	int command_status, slash_status, builtin_status;

	arr_holder = arg_process(user_input, " \t");
	if (arr_holder == NULL)
		return;
	if (arr_holder[0] == NULL)
	{
		free(arr_holder);
		return;
	}

	builtin_status = check_builtin(arr_holder, user_input);
	if (builtin_status == 1)
	{
		free(arr_holder);
		return;
	}

	command_status = check_command(arr_holder[0]);
	slash_status = check_slash(arr_holder[0]);
	if (slash_status == 0 || command_status == 0)
		exec_command(arr_holder, av);
	else
	{
		arr_holder[0] = modify_buffer(arr_holder[0]);
		if (arr_holder[0] == NULL)
		{
			write(1, av, strlen(av));
			print_string(": No such file or directory");
		}
		else
		{
			exec_command(arr_holder, av);
			free(arr_holder[0]);
		}
	}
	free(arr_holder);
}
