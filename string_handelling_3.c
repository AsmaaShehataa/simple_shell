#include "hsh.h"

/**
 * exists_within - checks whether character is within delim
 * @c: character
 * @s: delim
 * Return: boolean
 */
int exists_within(char c, char *s)
{
	if (*s == '\0')
		return (c == *s);
	return (c == *s ? 1 : exists_within(c, s + 1));
}

/**
 * _strtok - string tokenizer
 * @s: string
 * @delim: string
 * Return: tokens set
 */
char **_strtok(char *s, char *delim)
{
	char **tokens;
	size_t j = 0, i, len = _strlen(s) + 1;
	int found = 1, k = 0;

	tokens = (char **)_calloc_buffer(len * sizeof(char *), sizeof(char));
	*tokens = (char *)_calloc_buffer(len, sizeof(char));
	if (!*tokens)
		free(tokens);
	for (i = 0; s[i]; i++)
	{
		if (exists_within(s[i], delim))
		{
			if (!found)
			{
				tokens[k++][j] = '\0';
				tokens[k] = (char *)_calloc_buffer(len, sizeof(char));
				if (!tokens[k])
					_free_buffer(tokens);
			}
			found = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = s[i];
			found = 0;
		}
	}
	if (found)
	{
		free(tokens[k]);
		tokens[k] = NULL;
	}
	else
		tokens[k][j] = '\0';
	return (tokens);
}

/**
 * substring_tok - replaces substring
 * @str: input string
 * @old_substr: old substring
 * @new_substr: input substring
 * Return: command decomposition
 */
void substring_tok(char *str, char *old_substr, char *new_substr)
{
	char *ptr = NULL;
	size_t old_len = _strlen(old_substr);
	size_t new_len = _strlen(new_substr);
	size_t k = new_len, l = old_len;

	ptr = _strstr(str, old_substr);
	if (!ptr)
		return;
	do {
		ptr[k++] = ptr[l++];
	} while (ptr[l]);
	ptr[k] = '\0';
	_memcpy(ptr, new_substr, new_len);
	substring_tok(ptr + new_len, old_substr, new_substr);
}

/**
 * _atoi - convert a string to an integer
 *@s: string
 * Return: integer
 */

int _atoi(char *s)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		n *= 10;
		n += (s[i] - '0');
		i++;
	}
	return (n);
}
