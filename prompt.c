#include "hsh.h"

/**
 * main - the entry point.
 * @argc: the argument counter.
 * @argv: the argument vector.
 * @env: the envirement array.
 *
 * Return: exit_success in case of success, -1 otherwise.
 */

int main(int argc __attribute__ ((unused)),
		char **argv)
{
	char *user_input;
	size_t len;
	ssize_t nread;

	user_input = NULL;
	len = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		nread = getline(&user_input, &len, stdin);
		if (nread < 1)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		user_input[nread - 1] = '\0';
		prompt_holder(user_input, argv[0]);
	}
}
