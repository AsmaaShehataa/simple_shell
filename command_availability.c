#include "hsh.h"

/**
 * c_availability - checks for the availability of the command
 * @command: the given command.
 *
 * Return: 0 if the the command is found, -1 if the it does not exist.
 */
int c_availability(char *command)
{
	struct stat status;

	if (stat(command, &status) == 0)
	{
		return (0);
	}
	else
	{
		return (-1);
	}
}
