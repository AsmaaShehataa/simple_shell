#include "hsh.h"

/**
 * exit_function - function to exit
 * @n: arguments count
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 *
 * Return: success
 */
int exit_function(int n, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i = 0;

	(void) alias;
	(void) idx;
	while (n > 1 && args[1][i])
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			error_handeling(name, args, NULL, 2);
			return (0);
		}
		i++;
	}
	if (n > 1)
	{
		i = _atoi(args[1]);
	}
	_free_buffer(split);
	free(line);
	_free_buffer(args);
	exit(i);
	return (1);
}
/**
 * change_dir - handles cd
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int switch_dir(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	char *path, *temp;

	(void) alias;
	(void) idx;
	(void) line;
	(void) split;
	path = argc == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (chdir(path) < 0)
	{
		error_handeling(name, args, path, 3);
		return (0);
	}
	temp = _getenv("PWD");
	_strcpy(temp, path);
	if (argc == 1)
	{
		print_string(1, path);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
/**
 * export - handles setenv
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int export(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i = 0;
	char *temp = NULL;

	(void) alias;
	(void) idx;
	(void) split;
	(void) line;
	if (argc != 3)
	{
		error_handeling(name, args, NULL, 4);
		return (0);
	}
	else
	{
		temp = _getenv(args[1]);
		if (temp)
			_strcpy(temp, args[2]);
		else
		{
			while (environ[i])
				i++;
			environ[i] = _calloc_buffer(_strlen(args[1]) + _strlen(args[2]) + 3, 1);
			_strcat(environ[i], args[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], args[2]);
			environ[++i] = NULL;
		}
		return (1);
	}
}
/**
 * unset - handles unsetenv
 * @argc: arguments count
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int unset(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i;

	(void) alias;
	(void) idx;
	(void) split;
	(void) line;
	if (argc != 2)
	{
		error_handeling(name, args, NULL, 5);
		return (0);
	}
	else if (_getenv(args[1]) == NULL)
	{
		error_handeling(name, args, NULL, 6);
		return (0);
	}
	else
	{
		for (i = 0; environ[i]; i++)
		{
			if (_strncmp(environ[i], args[1], _strlen(args[1])) == 0)
			{
				free(environ[i]);
				break;
			}
		}
		return (1);
	}
}
/**
 * env_handler - handles and prints env
 * @argc: argc
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 * Return: success
 */
int env_handler(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i;

	(void) argc;
	(void) args;
	(void) name;
	(void) split;
	(void) alias;
	(void) idx;
	(void) line;
	for (i = 0; environ[i]; i++)
	{
		print_string(1, environ[i]);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
