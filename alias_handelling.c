#include "hsh.h"

/**
 * _alias - takes care of aliases
 * @argc: arguments count (number)
 * @args: arguments array (vector)
 * @name: the program name
 * @alias: the alias struct, contains names and values
 * @idx: the number of aliases
 * @split: split line
 * @line: the line
 *
 * Return: success
 */

int _alias_handeler(int argc, char **args, char *name,
		aliases *alias, int *idx, char **split, char *line)
{
	int i, j;
	char **al;

	(void) split;
	(void) name;
	(void) line;
	if (argc == 1)
	{
		for (i = 0; *idx && i < *idx; i++)
		{
			print_string(1, alias[i].name), print_string(1, "='");
			print_string(1, alias[i].value), print_string(1, "'\n");
		}
	}
	for (i = 1; i < argc; i++)
	{
		al = _strtok(args[i], "'="), j = _get_alias(alias, al[0], *idx);
		if (!_strstr(args[i], "="))
		{
			if (j != -1)
			{
				print_string(1, alias[j].name), print_string(1, "='");
				print_string(1, alias[j].value), print_string(1, "'\n");
			} else
				error_handeling(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			alias[j].value = malloc(_strlen(al[1]) + 1 + _strlen("''"));
			_strcpy(alias[j].value, al[1]);
		}
		else
		{
			alias[*idx].name = malloc(_strlen(al[0]) + 1);
			alias[*idx].value = malloc(_strlen(al[1]) + 1 + _strlen("''"));
			_strcpy(alias[*idx].name, al[0]);
			_strcpy(alias[*idx].value, al[1]), (*idx)++;
		}
	}
	return (1);
}
