#include "hsh.h"

/**
 * echo_handeler - handles echo $$ and $? argument to echo
 * @args: arguments
 *
 * Return: success
 */
int echo_handeler(char **args)
{
	int status;

	if (!_strcmp(args[0], "echo") && args[1])
	{
		if (!_strcmp(args[1], "$$"))
		{
			to_string(1, getpid());
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
		else if (!_strcmp(args[1], "$?"))
		{
			waitpid(getpid() - 1, &status, 0);
			to_string(1, WEXITSTATUS(status));
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
	}
	return (0);
}
