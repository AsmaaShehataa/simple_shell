#include "hsh.h"

int check_slash(char *user_input) //arr_holder[0]
{
	int counter;
	char *holder;

	holder = strdup(user_input);
	counter = 0;
	while (holder[counter])
	{
		if (holder[counter] == '/')
		{
			free(holder); // free the holder then return.
			return (0);
		}
		counter++;
	}
	free(holder);
	return (-1);
}
