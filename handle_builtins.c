#include "hsh.h"

int check_builtin(char **arr_holder, char *user_input)
{
	if (strcmp(arr_holder[0], "exit") == 0)
		b_exit(arr_holder, user_input);
	else if (strcmp(arr_holder[0], "env") == 0)
		return (print_env(arr_holder));
	return (0);
}
