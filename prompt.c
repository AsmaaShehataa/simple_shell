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
	char *user_input;
	size_t len;
	ssize_t nread;
	char **arr_holder;
	int arr_len;
	int exit_status;
	
	user_input = NULL;
	len = 0;
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("$ ");
			nread = getline(&user_input, &len, stdin);
			if (nread == -1)
			{
				if (feof(stdin)) //checking for end of file it's equivalent to : Ctr-D
				{
					free(user_input);
					exit(EXIT_SUCCESS);//the user wants this
				}
				perror("Error: ");
				free(user_input);
			}
			//fix the user input by removing the '\n' terminated character.
			user_input[nread - 1] = '\0';
			//check for exit in here.
			
			if (nread > 1)
			{
				//retriving the array length to allocate suffitiont memory.
				arr_len = arg_arr_lenth(user_input);
				//allocate memory to the holder array based on the lenght of the argument array
				arr_holder = malloc(sizeof(char *) * (arr_len));
				//passing the user input as an argument to the arg_process function.
				arr_holder = arg_process(user_input); //pars the arguments
				//pass the returned value as an arg to the execution function.
				if (strcmp(user_input, "env") == 0)
				{
					print_env(env);
				}
				else if (strcmp(user_input, "exit") == 0)
				{
					exit_status = __exit(user_input);
					if (exit_status == 0)
					{
						free(arr_holder);
						exit(EXIT_SUCCESS);
					}
				}
				else
				{
					printf("Befoure the executions\n"); // debug message starts
					exec_command(arr_holder, env);
					printf("After the execution\n"); //debug message ends.
				}
				// the freeing is gonna be taken care of from the exec_command(), it's just not being reached yet.
			}
		}
	}
	else
	{
		//handel commands from standard input, or scripts.
	}
	exit(EXIT_SUCCESS);
}
