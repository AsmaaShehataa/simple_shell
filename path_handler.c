#include "hsh.h"
/**
 * modify_buffer - this modifies the buffer to the newelly
 * assigned executable.
 * @executable_holder: this is the executable pased to it.
 * @env: this is the env passed by main.
 *
 * Return: the newelly modified buffer.
 */

char **modify_buffer(char *executable_holder, char **env)
{
	char **buffer;
	const char *path_str;
	int counter;
	char *tmp;

	counter = 0;
	path_str = "PATH";
	buffer = get_path_arr(path_str, env);

	while (buffer[counter])
	{
		tmp = malloc(sizeof(char) * (strlen(executable_holder) + 2));
		if (!tmp)
		{
			fprintf(stderr, "error allocating memory");
			exit(-1);
		}
		snprintf(tmp, (strlen(buffer[counter]) + strlen(executable_holder) + 2),
			 "%s/%s", buffer[counter], executable_holder);
		free(buffer[counter]);
		buffer[counter] = tmp;
		counter++;
	}
	counter = 0;

	return (buffer);
}
/**
 * check_command - this check the command availability.
 * @executable_holder: this is the executable passed by the caller fucntion.
 * @env: this is the env passed by the main function.
 *
 * Return: it returns the path if the executable is found, or NULL
 * if the executable is not found in any path.
 */

char *check_command(char *executable_holder, char **env)
{
	char **new_buffer;
	char *found_path;
	struct stat status;
	int counter;

	new_buffer = modify_buffer(executable_holder, env);
	found_path = NULL;
	counter = 0;
	while (new_buffer[counter])
	{
		if (stat(new_buffer[counter], &status) == 0)
		{
			if (!found_path)
			{
				found_path = new_buffer[counter];
			}
			else
			{
				free(new_buffer[counter]);
			}
		}
		else
		{
			free(new_buffer[counter]);
		}
		counter++;
	}
	free(new_buffer);
	if (found_path)
	{
		return (found_path);
	}
	else
	{
		return (NULL);
	}
}
