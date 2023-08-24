#include "hsh.h"

char **deepDupe(char **args)
{
	char **stor;
	int i, j, total;

	for (i = 0, total = 0; args[i] != NULL; i++)
	{
		j = _strlen(args[i]);
		total += j;
	}

	stor = _malloc(total * i);
	if (stor == NULL)
		return (NULL);

	for (i = 0; args[i] != NULL; i++)
	{
		j = _strlen(args[i]);
		stor[i] = _strcpy(args[i], j);
	}

	return (stor);
}
