#include "hsh.h"

/**
 * cmd_selector - checks for builin functions
 * @cmd: command name
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @idx: index
 * @split: split line
 * @line: line
 *
 * Return: success
 */
int cmd_selector(const char *cmd, char **args,
		char *name, aliases *alias, int *idx, char **split, char *line)
{
	cmd_executer executers[] = {
		{"exit", exit_function},
		{"cd", switch_dir},
		{"setenv", export},
		{"unsetenv", unset},
		{"env", env_handler},
		{"alias", _alias_handeler},
		{NULL, NULL}
	};
	int j = 0;

	while (executers[j].exec_func != NULL && _strcmp(cmd, executers[j].cmd) != 0)
		j++;
	if (executers[j].exec_func != NULL)
		return (executers[j].exec_func(args_count(args), args,
					name, alias, idx, split, line));
	return (-1);
}

/**
 * args_count - counts number of args
 * @args: arguments
 * Return: argc
 */
int args_count(char **args)
{
	if (args == NULL || *args == NULL)
	{
		return (0);
	}
	return (1 + args_count(args + 1));
}
