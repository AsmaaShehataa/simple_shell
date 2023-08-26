#include "hsh.h"
/**
 * modify_buffer - this modifies the buffer to the newelly
 * assigned executable.
 * @command: this is the executable pased to it.
 *
 * Return: the folder the command was found in, or null if it wasn't
 * found in any path folder..
 */

char *modify_buffer(char *command)
{
	char path_str[1024];
	char **buffer;
	int counter, len, buf_len;
	char *tmp;

	counter = 0;
	tmp = path_value("PATH");
	if (tmp == NULL)
		return (NULL);
	strcpy(path_str, tmp);
	buffer = arg_process(path_str, ":");

	len = strlen(command);
	while (buffer[counter])
	{
		buf_len = strlen(buffer[counter]);
		tmp = malloc(sizeof(char) * (buf_len + len + 2));
		strcpy(tmp, buffer[counter]);
		strcat(tmp, "/");
		strcat(tmp, command);
		if (check_command(tmp) == 0)
		{
			free(buffer);
			return (tmp);
		}
		free(tmp);
		counter++;
	}
	free(buffer);
	return (NULL);
}

/**
 * check_command - this check the command availability.
 * @command: this is the executable passed by the caller fucntion.
 *
 * Return: it returns the path if the executable is found, or NULL
 * if the executable is not found in any path.
 */
int check_command(char *command)
{
	struct stat status;

	return (stat(command, &status));
}
