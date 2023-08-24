#include "hsh.h"

/**
 * exec_command - executes a given command
 * @arg_array: the arg array.
 * @env: the env.
 * @user_input: the user input.
 * @slash_status: the status of exeisting slashes.
 *
 * Return: nothing, only executs.
 */
void exec_command(char **arg_array, char **env __attribute__((unused)),
		  char *user_input, int slash_status)
{
	pid_t parent_pid __attribute__ ((unused));
	pid_t child_pid;
	int wait_status;
	int exec_status;

	parent_pid = getpid();
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("Error");
		free(arg_array);
		exit(-1);
	}
	else if ((child_pid) == 0)
	{
		exec_status = execve(arg_array[0], arg_array, environ);
		if (exec_status < 0)
		{
			perror("Error");
			free(arg_array);
			exit(-1);
		}
	}
	else
	{
		wait(&wait_status);
	}
	if (slash_status == -1)
		free(arg_array[0]);
	free(arg_array);
	free(user_input);
}
