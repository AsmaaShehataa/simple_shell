#include "hsh.h"

/**
 * _getenv - retrieves enviromental variables
 * @var: variable name
 * Return: string
 */
char *_getenv(char *var)
{
	int i;
	char *temp;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(var, environ[i], _strlen(var)))
		{
			temp = _strstr(environ[i], "=");
			temp++;
			return (temp);
		}
	}
	return (NULL);
}
/**
 * _get_alias -retrieve aliases
 * @alias: aliases
 * @var: variable name
 * @idx: index
 * Return: string
 */
int _get_alias(aliases *alias, char *var, int idx)
{
	int i;

	for (i = 0; i < idx; i++)
	{
		if (!_strcmp(var, alias[i].name))
			return (i);
	}
	return (-1);
}
