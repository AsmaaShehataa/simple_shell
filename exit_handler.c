#include "hsh.h"
/**
 * b_exit - performs an exit
 * @arr_holder: the passed array holder.
 * @user_input: the passed user_input.
 *
 * Return: integer by exiting (SUCCESS).
 */

int  b_exit(char **arr_holder, char *user_input)
{
	int code;

	if (arr_holder[1] == NULL)
	{
		free(user_input);
		free(arr_holder);
		_exit(0);
	}
	else
	{
		code = atoi(arr_holder[1]);
		free(user_input);
		free(arr_holder);
		if (code > 0)
			_exit(code);
		else
			_exit(0);
	}
}
