#include "hsh.h"

int c_availability(char *command)
{
	struct stat status;

	if (stat(command, &status) == 0)
	{
		return (0); // this means the command is found.
	}
	else
	{
		return (-1); // the command is not found.
	}
}
