#include "hsh.h"

/**
 * check_alias - checks for aliases
 * @arr: arguments
 * @alias: alias array
 * @idx: integer
 * Return: none
 */
void check_alias(char ***arr, aliases *alias, int idx)
{
	int i, n;

	for (i = 0; (*arr)[i]; i++)
	{
		n = _get_alias(alias, (*arr)[i], idx);
		if (n != -1)
		{
			(*arr)[i] = NULL;
			(*arr)[i] = malloc(_strlen(alias[n].value) + 1);
			_strcpy((*arr)[i], alias[n].value);
		}
	}
}
/**
 * and_handling - handles &&
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 *
 * Return: integer
 */
int and_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "&\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free_buffer(arr);
			_free_buffer(line_split);
			return (error_handeling(name, NULL, NULL, 7));
		}
		_free_buffer(arr);
	}
	for (i = 0; line_split[i]; i++)
	{
		break_condition = 0;
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name, alias, idx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = 1 - _fork_process(name, arr);
		else if (argc > 0)
			break_condition = 1 - selector;
		if (break_condition)
		{
			_free_buffer(arr);
			break;
		}
		_free_buffer(arr);
	}
	_free_buffer(line_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}
/**
 * or_handling - handles ||
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 *
 * Return: integer
 */
int or_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int break_condition, argc, selector, i = 0;

	line_split = _strtok(line, "|\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free_buffer(arr);
			_free_buffer(line_split);
			return (error_handeling(name, NULL, NULL, 8));
		}
		_free_buffer(arr);
	}
	i = 0;
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (_strcmp(arr[0], "alias"))
			check_alias(&arr, alias, *idx);
		break_condition = 0;
		argc = args_count(arr);
		selector = cmd_selector(arr[0], arr, name, alias, idx, line_split, line);
		if (argc > 0 && selector < 0)
			break_condition = _fork_process(name, arr);
		else if (argc > 0)
			break_condition = selector;
		if (break_condition)
		{
			_free_buffer(arr);
			break;
		}
		_free_buffer(arr);
	}
	_free_buffer(line_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}
/**
 * semi_column_handling - handles ;
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int semi_column_handling(char *line, char *name, aliases *alias, int *idx)
{
	char **arr, **line_split;
	int argc, i = 0, frk = 0;

	line_split = _strtok(line, ";\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (args_count(arr) == 0)
		{
			_free_buffer(arr);
			_free_buffer(line_split);
			return (error_handeling(name, NULL, NULL, 9));
		}
		_free_buffer(arr);
	}
	_free_buffer(line_split);
	line_split = _strtok(line, "@;\n");
	for (i = 0; line_split[i]; i++)
	{
		arr = _strtok(line_split[i], " \t");
		if (_strstr(line, "alias"))
			check_alias(&arr, alias, *idx);
		argc = args_count(arr);
		if (argc > 0 && cmd_selector(arr[0], arr,
					name, alias, idx, line_split, line) < 0)
			_fork_process(name, arr);
		else if (!_strstr(line, "@") && argc == 0)
		{
			_free_buffer(line_split);
			_free_buffer(arr);
			return (error_handeling(name, NULL, NULL, 9));
		}
		_free_buffer(arr);
	}
	_free_buffer(line_split);
	return (frk ? EXIT_FAILURE : 0);
}
/**
 * split_line - reads command line (input)
 * @line: input command line
 * @name: file name
 * @alias: alias array
 * @idx: integer
 * Return: integer
 */
int split_line(char *line, char *name, aliases *alias, int *idx)
{
	size_t old_len;
	size_t new_len;

	while (*line == ' ' || *line == '\t')
	{
		rm(&line);
	}
	old_len = _strlen(line);
	if (old_len == 1)
		return (0);
	substring_tok(line, "&&", "&");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		substring_tok(line, "&&", "&");
		if (_strlen(line) < new_len)
			return (error_handeling(name, NULL, NULL, 7));
		return (and_handling(line, name, alias, idx));
	}
	substring_tok(line, "||", "|");
	new_len = _strlen(line);
	if (new_len < old_len)
	{
		substring_tok(line, "||", "|");
		if (_strlen(line) < new_len)
			return (error_handeling(name, NULL, NULL, 8));
		return (or_handling(line, name, alias, idx));
	}
	if (_strstr(line, ";;"))
		return (error_handeling(name, NULL, NULL, 9));
	substring_tok(line, "\n", "@");
	return (semi_column_handling(line, name, alias, idx));
}
