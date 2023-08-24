#include "hsh.h"

/**
 * prompt_holder - this fucntion will execute the passed
 * parameter by the prompt.c (containing main())
 * Description: this analogy was introduced only to reduce
 * the number of lines inside a function.
 * @user_input: the user input.
 * @env: the enrirenment passed by main
 * @nread: the number of chars readen by the user.
 *
 * Return: nothing only execution of the code
 */

void prompt_holder(char *user_input, char **env, int nread)
{
	char **arr_holder, *executable_holder;
	int exit_status, env_status, slash_status;

	env_status = print_env(env, user_input);
	exit_status = __exit(user_input);
	if (exit_status == 0)
	{
		exit(EXIT_SUCCESS);
	}
	if ((nread != 1) && (env_status == -1))
	{
		
		arr_holder = arg_process(user_input);
		executable_holder = strdup(arr_holder[0]);
		slash_status = check_slash(executable_holder);
		slash_status_holder(slash_status, arr_holder,
		executable_holder, env, user_input);
	}
	else
	{
		free(user_input);
	}
}


void slash_status_holder(int slash_status, char **arr_holder,
			 char *executable_holder, char **env __attribute__((unused)),
			 char *user_input)
{
	char *command_holder __attribute__ ((unused)), *c_command_holder;
	int command_status, command_availability;

	if (slash_status == -1)
	{
		c_command_holder = check_command(executable_holder, environ);
		if (c_command_holder != NULL)
			command_status = 0;
		else if (c_command_holder == NULL)
			command_status = -1;
		if (command_status == -1)
		{
			perror("Error");
			free(c_command_holder);
			free(executable_holder);
			free(arr_holder);
			free(user_input);
		} else if (command_status == 0)
		{
			arr_holder[0] = strdup(c_command_holder);
			free(c_command_holder);
			free(executable_holder);
			exec_command(arr_holder, environ, user_input, slash_status);
		}
	} else if (slash_status == 0)
	{
		command_availability = c_availability(arr_holder[0]);
		free(executable_holder);
		if (command_availability == 0)
			exec_command(arr_holder, environ, user_input, slash_status);
		else if (command_availability == -1)
		{
			perror("Error");
			free(user_input);
			free(arr_holder);
		}
	}
}
