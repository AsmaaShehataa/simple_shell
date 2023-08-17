#include "hsh.h"

void exec_command(char **arg_array)
{
	extern char **environ;
	pid_t parent_pid;
	pid_t child_pid;
	int env_counter;
	int status;

	//calling the parent id in here (befour executing any command)
	//parent_pid = getppid();
	if (strcmp(arg_array[0], "env") == 0)
	{
		env_counter = 0;
		while (environ[env_counter])
		{
			printf("%s\n", environ[env_counter]);
			env_counter++;
		}
	}
	// herestarts the process creation
	child_pid = fork(); //remember the fork return two values when success, 0 and the pid value (unsigned int).
	/*if ((strcmp(arg_array[0], "env") != 0) && (execve(arg_array[0], arg_array, environ) == -1))
	{
		fprintf(stderr, "Error while ecxecuting the command");
		free(arg_array);
		exit(-1);
	}
	*/
	printf("the child process id is: %u\n", child_pid);
	if (child_pid == -1) //in case of any arrors creating the child.
	{
		fprintf(stderr, "Error while retreiving the child pid");
		free(arg_array);
		exit(-1);
	}
	else if (child_pid == 0)
	{
		//this means that the child process is created and return 0 (indicating success)
		if ((strcmp(arg_array[0], "env") != 0) && (execve(arg_array[0], arg_array, environ) == -1))
		{
			fprintf(stderr, "Erroor while executing the command");
			free(arg_array);
			exit(-1); // thsi is important in case of an error to free the sub process.
		}
		
	}
	else
	{
		//this means that the child is created and return pid value.
		// execute the wait function.
		wait(&status);
	}
	//this is not reached (that's why), and still we dont need to free it in prompt.c
	free(arg_array);
	// int his file we ignored the use of wait and process handler for now.
}
