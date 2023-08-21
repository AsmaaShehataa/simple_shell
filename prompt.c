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
	int arr_len, exit_status, env_status, slash_status, command_status;

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
				arr_len = arg_arr_lenth(user_input);
				arr_holder = arg_process(user_input);
				//defining the exec holder.
				executable_holder = strdup(arr_holder[0]);//there is memory in here.
				slash_status = check_slash(executable_holder); //this function does not free aything, there is a memory leak introduced here.
				
				if (slash_status == -1)
				{
					printf("this command has no slashes, so we are processing it\n");
					//go through the command preocessing function, this will result in a modified arr_holder[0].
					//then this will generate a path with the executable file.
					//we are gonna pass the excutable to the check
					c_command_holder = check_command(executable_holder, env); //this gonna return the command or NULL, we still have to free it.
					if (c_command_holder != NULL)
					{
						command_status = 0;
					}
					else if (c_command_holder == NULL)
					{
						command_status = -1;
					}
					//folow from here. (keeptrack of c_command_holder and executable_holer)
					if (command_status == -1) //this means the command doesn't exist.
					{
						printf("main(): the command is not found on any directory\n");
						//exit the loop and ptint the message.
						free(c_command_holder);
						
					}
					//here we need to update the arr_holder[0] to the path of the executable. 
					else if (command_status == 0)
					{
						printf("main(): the command is found in here: %s, we are processing it\n", c_command_holder);
						arr_holder[0] = strdup(c_command_holder);
						free(c_command_holder);
						exec_command(arr_holder, env, user_input); //executing
						//check the path folder, and return the folder where we found the exc, we gonna merge it wth the exectable, after that
						// update the arr_holder[0] to the new merge return.
						//free(c_command_holder);
					}
					free(executable_holder); //last free in here.
				}
				// this line will have the linked list
				// -> function that cehcks the arr_holder[0] against the linked list nodes [these are folders cause of PATH] 'ls'
				// -> this function will return 0 if it wasn't found,or the directory the binary was found in stat(name-bin, stat) /bin 
				// -> fucntion which handles the retreived output from the function above, and produces the correct path: /bin/ls,
				// -> the last function will pass it's result to arr_holder[0]. -> this is gomma be passed normally to exec_command().
				else if (slash_status == 0)
				{
					free(executable_holder);//1
					printf("main(): there is a slash in the command, so it's a path, then we are executing it direcrelly.\n");
					exec_command(arr_holder, env, user_input); //arr_holder[0] must be acomplete path /bin/ls
				}
			}
			else
				free(user_input); //free the memory when the env_status is 0
		} //end of while loop.
	}
	else
	{
		//handel commands from standard input, or scripts.
	}
	exit(EXIT_SUCCESS);
}
