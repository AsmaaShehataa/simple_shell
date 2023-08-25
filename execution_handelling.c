#include "hsh.h"

/**
 * exec_cmd - executes commands
 * @arr: argument array
 * @name: name
 * @path: path
 *
 * Return: success
 */
int exec_cmd(char **arr, char *name, char *path)
{
	int i = 0, success = 1;
	char *env;

	(void) name;
	if (arr)
	{
		i = echo_handeler(arr);
		if (i == 0 && arr[1] && arr[1][0] == '$')
		{
			env = _getenv(arr[1] + 1);
			if (env)
			{
				arr[1] = malloc(sizeof(env));
				_strcpy(arr[1], env);
			}
			else
			{
				write(STDOUT_FILENO, "\n", 1);
				return (1);
			}
		}
		if (i == 0)
		{
			if (execve(path, arr, environ) == -1)
				success = 0;
		}
		_free_buffer(arr);
	}
	return (success);
}
