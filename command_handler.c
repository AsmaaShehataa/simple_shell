#include "hsh.h"

/**
 * exec_command - executes a given command
 * @arg_array: the arg array.
 * @av: the passed argv value.
 *
 * Return: nothing, only executs.
 */
void exec_command(char **arg_array, char *av)
{
	pid_t child_pid;
	int wait_status;

	child_pid = fork();
	if (child_pid < 0)
		perror("Error");
	else if (child_pid == 0)
	{
		prog.status = 0;
		execve(arg_array[0], arg_array, environ);
		perror(av);
		exit(0);
	}
	else
	{
		wait(&wait_status);
		if (WIFEXITED(wait_status) != 0)
			prog.status = WEXITSTATUS(wait_status);
	}
}
