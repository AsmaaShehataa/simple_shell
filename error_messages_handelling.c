#include "hsh.h"

/**
 * error_handeling_2 - prints error msgs to stderr (part 2)
 * @args: args
 * @path: path
 * @n: error index
 *
 * Return: nothing.
 */
void error_handeling_2(char **args, char *path, int n)
{
	char semi = ';';

	if (n == 5)
		print_string(2, "usage: unsetenv VARIABLE VALUE");
	else if (n == 6)
	{
		print_string(2, "environment variable ");
		print_string(2, args[1]);
		print_string(2, " not found");
	}
	else if (n == 7)
		print_string(2, "Syntax error: \"&\" unexpected");
	else if (n == 8)
		print_string(2, "Syntax error: \"|\" unexpected");
	else if (n == 9)
	{
		print_string(2, "OBSyntax error: \"");
		write(STDERR_FILENO, &semi, 1);
		write(STDERR_FILENO, &semi, 1);
		print_string(2, "\" unexpected");
	}
	else if (n == 10)
	{
		print_string(2, "alias: ");
		print_string(2, path);
		print_string(2, " not found");
	}
}

/**
 * error_handeling - prints error msgs to stderr (part 1)
 * @name: name
 * @args: args
 * @path: path
 * @n: error index
 *
 * Return: the value
 */
int error_handeling(char *name, char **args, char *path, int n)
{
	static unsigned int i;

	if (!n)
	{
		i++;
		return (0);
	}
	if (n == 11)
	{
		print_string(2, name);
		print_string(2, ": 0: Can't open ");
		print_string(2, args[1]);
		write(STDERR_FILENO, "\n", 1);
		return (EXIT_FAILURE);
	}
	print_string(2, name);
	print_string(2, ": ");
	to_string(2, i);
	print_string(2, ": ");
	if (n == 1)
	{
		print_string(2, args[0]);
		print_string(2, ": not found");
	}
	else if (n == 2)
	{
		print_string(2, "exit: Illegal number: ");
		print_string(2, args[1]);
	}
	else if (n == 3)
	{
		print_string(2, "cd: can't cd to ");
		print_string(2, path);
	}
	else if (n == 4)
		print_string(2, "usage: setenv VARIABLE VALUE");
	else
		error_handeling_2(args, path, n);
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}
