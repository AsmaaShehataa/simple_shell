#include "hsh.h"

/**
 * main - the entry point.
 * @argc: the argument counter.
 * @argv: the argument vector.
 * @env: the envirement array.
 *
 * Return: exit_success in case of success, -1 otherwise.
 */

int main(int argc __attribute__((unused)), char *argv[]__attribute__((unused)), char **env __attribute__((unused)))
{
	char *user_input;
	size_t len;
	ssize_t nread;
	char **arr_holder;
	int arr_len;
	
	user_input = NULL;
	len = 0;
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("$ ");
			nread = getline(&user_input, &len, stdin);
			printf("the value of nread is: %lu\n", nread);
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
				if (strcmp(user_input, "exit") == 0)
				{
					free(user_input);
					//kill(child_pid, SIGSENV);
					exit(EXIT_SUCCESS);
				}
			//retriving the array length to allocate suffitiont memory.
				arr_len = arg_arr_lenth(user_input);
				printf("this is from the main() the number of arguments is: %d\n", arr_len);
			//allocate memory to the holder array based on the lenght of the argument array
				arr_holder = malloc(sizeof(char *) * (arr_len));
			//passing the user input as an argument to the arg_process function.
				arr_holder = arg_process(user_input); //pars the arguments
			//pass the returned value as an arg to the execution function.
				printf("befour executing\n");
				exec_command(arr_holder);
                        //execute commands based on the arg_process output.
				printf("after the execution\n");
                        // the freeing is gonna be taken care of from the exec_command(), it's just not being reached yet.
			//free(arr_holder);
			}
		}
	}
	else
	{
		//handel commands from standard input, or scripts.
	}
	exit(EXIT_SUCCESS);
}
