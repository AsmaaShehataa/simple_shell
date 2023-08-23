#include "hsh.h"

/**
 * main - the entry point.
 * @argc: the argument counter.
 * @argv: the argument vector.
 * @env: the envirement array.
 *
 * Return: exit_success in case of success, -1 otherwise.
 */

int main(int argc __attribute__((unused)), char *argv[]__attribute__((unused))
	 , char **env)
{
	char *user_input, sign, sp;
	size_t len;
	ssize_t nread;

	sp = ' ';
	sign = '$';
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(1, &sign, 1);
			write(1, &sp, 1);
			user_input = NULL;
			len = 0;
			nread = getline(&user_input, &len, stdin);
			if (nread < 1)
			{
				if (feof(stdin))
				{
					free(user_input);
					exit(EXIT_SUCCESS);
				}
			}
			user_input[nread - 1] = '\0';
			prompt_holder(user_input, env, nread);
		}
	}
	else
	{
	}
	exit(EXIT_SUCCESS);
}
