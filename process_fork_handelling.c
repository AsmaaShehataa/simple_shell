#include "hsh.h"

/**
 * _fork_process - forks process
 * @name: command name
 * @arr: arguments
 * Return: success
 */
int _fork_process(char *name, char **arr)
{
	pid_t pid;
	int status, success = 1;
	char *path = NULL;

	path = check_validation(arr[0], name, arr);
	if (path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			success = exec_cmd(arr, name, path);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
		free(path);
	}
	else
	{
		error_handeling(name, arr, NULL, 1);
		success = 0;
	}
	return (success);
}
