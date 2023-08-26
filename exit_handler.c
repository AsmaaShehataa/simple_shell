#include "hsh.h"
#include <ctype.h>
/**
 * b_exit - performs an exit
 * @arr_holder: the passed array holder.
 * @user_input: the passed user_input.
 *
 * Return: integer by exiting (SUCCESS).
 */

int  b_exit(char **arr_holder, char *user_input)
{
	int pos;
	char *tmp;

	if (arr_holder[1] == NULL)
	{
		free(user_input);
		free(arr_holder);
		_exit(prog.status);
	}

	tmp = arr_holder[1];
	for (pos = 0; tmp[pos] != '\0'; pos++)
	{
		if (isdigit(tmp[pos]) == 0)
		{
			fprintf(stderr, "%s: %d: exit: Illegal number: %s\n",
				prog.name, prog.cmd_count, tmp);
			prog.status = 2;
			return (1);
		}
	}
	prog.status = atoi(arr_holder[1]);
	free(user_input);
	free(arr_holder);
	_exit(prog.status);
}
