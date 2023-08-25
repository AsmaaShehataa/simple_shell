#include "hsh.h"

/**
 * _calloc_buffer - allocates memory for an array, using malloc.
 * @nmemb: number of members
 * @size: size
 *
 * Return: pointer or NULLs
 */
void *_calloc_buffer(unsigned int nmemb, unsigned int size)
{
	char *p;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(size * nmemb);
	if (p == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size * nmemb)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
/**
 * _free_buffer - frees arrays of strings
 * @arr: arr
 *
 * Return: nothing.
 */

void _free_buffer(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
