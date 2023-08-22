#include "hsh.h"

/**
 * main - the entry point.
 * @argc: the argument counter.
 * @argv: the argument vector.
 * @env: the envirement array.
 *
 * Return: exit_success in case of success, -1 otherwise.
 */

int main(int argc __attribute__((unused)), char *argv[]__attribute__((unused)), char **env)
{
	char *user_input, **arr_holder, *executable_holder, *c_command_holder;
	size_t len;
	ssize_t nread;
	int arr_len, exit_status, env_status, slash_status, command_status, command_availability;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("$ ");
			user_input = NULL;
			len = 0;
			nread = getline(&user_input, &len, stdin);
			if (nread < 1) //this in here checks if there are errors from the getline() 
			{
				if (feof(stdin)) //checking for end of file it's equivalent to : Ctr-D
				{
					free(user_input);
					exit(EXIT_SUCCESS);//the user wants this
				}
				//free(user_input); //removing this because it procduces double free erros.
			}
			user_input[nread - 1] = '\0';
			// -> create a linked list, stored in an output of a funciotn struct *node head;
			env_status = print_env(env, user_input);
			exit_status = __exit(user_input);
			if (exit_status == 0)
				exit(EXIT_SUCCESS);			
			if ((nread != 1) && (env_status == -1)) // parse the arguments and execute the command is env_status == -1
			{
				//arr_len = arg_arr_lenth(user_input); //we don't need this any more
				arr_holder = arg_process(user_input);
				executable_holder = strdup(arr_holder[0]);//there is memory in here.
				slash_status = check_slash(executable_holder); //this function does not free aything.
				
				if (slash_status == -1) //one place to free in case of a non slash command that does exist
				{
					printf("this command has no slashes, so we are processing it\n");
					c_command_holder = check_command(executable_holder, env);
					if (c_command_holder != NULL)
					{
						command_status = 0;
					}
					else if (c_command_holder == NULL)
					{
						command_status = -1;
					}
					if (command_status == -1)
					{
						printf("main(): the command is not found on any directory\n");
						free(c_command_holder);
						free(executable_holder);
						free(arr_holder);
						free(user_input);
						
					}
					else if (command_status == 0)
					{
						printf("main(): the command is found in here: %s, we are processing it\n", c_command_holder);
						arr_holder[0] = strdup(c_command_holder);
						free(c_command_holder);
						free(executable_holder);
						//executing in here, no issues
						exec_command(arr_holder, env, user_input, slash_status);
					}
				}
				else if (slash_status == 0) //handle the forking issue in here.
				{
					//i think adding a function to check the command in here.
					command_availability = c_availability(arr_holder[0]); //nothing is fread in here
					free(executable_holder);
					printf("main(): there is a slash in the command, so it's a path, then we are executing it direcrelly.\n");
					//executing in here.
					if (command_availability == 0)
					{
						exec_command(arr_holder, env, user_input, slash_status);
					}
					else if (command_availability == -1)
					{
						printf("main(): the command is not found\n");
						free(user_input); //this is freed here because the exec_command is not called
						free(arr_holder); //the same message above.
					}
				}
			}
			else
				free(user_input);
		} //end of while loop.
	}
	else
	{
		//handel commands from standard input, or scripts.
	}
	exit(EXIT_SUCCESS);
}
