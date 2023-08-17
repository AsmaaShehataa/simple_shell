#include "hsh.h"

void exec_command(char **arg_array, char **env)
{
	pid_t parent_pid;
	pid_t child_pid;
	int wait_status; //renaming to wait_status.
	int exec_status;

	parent_pid = getpid();
	child_pid = fork(); //remember the fork return two values when success, 0 and the pid value (unsigned int).
	printf("the child process id is: %u\n", child_pid);
	if (child_pid < 0) //in case of any arrors creating the child.
	{
		fprintf(stderr, "Error while retreiving the child pid");
		free(arg_array);
		exit(-1);
	}
	else if ((child_pid) == 0) // the fork return 0 to the child
	{
		exec_status = execve(arg_array[0], arg_array, env);
		//this means that the child process is created and return 0 (indicating success)
		if (exec_status < 0)
		{
			perror("Error");
			free(arg_array);
			exit(-1);
		}
	}
	else //the fork() returns the process id to the parent (we can use this to wait for the child to exit)
	{
		//this means that the child is created and return pid value.
		// execute the wait command from the parent
		wait(&wait_status);
	}
	//this is not reached (that's why), and still we dont need to free it in prompt.c
	free(arg_array);
	// int his file we ignored the use of wait and process handler for now.
}
