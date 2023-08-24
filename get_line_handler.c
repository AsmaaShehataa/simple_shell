#include "hsh.h"

/**
* tokenize - tokenizes a string of limited length based on given delimiter
* @lineptr: string to be tokenized
* @dlimtr: delimietr to tokenize the string
* Return: pointer to tokens
**/
char **tokenize(char *lineptr, char dlimtr)
{
	int i, j, indx, tmpLen;
	char *tmp, *line, **tokens;

	/* it can be null if only new line was entered */
	if (*lineptr == '\0')
		return (NULL);

	/* limit the size of input to be processed */
	tokens = _malloc(sizeof(char *) * BUFRSIZE);
	if (tokens == NULL)
		return (NULL);
/* discard the begining spaces if any */
	lineptr = linep_withoutspaces(lineptr);
/* set tmp to first non space char */
	tmp = lineptr;
	i = 0;
	indx = 0;
	while (*lineptr && indx < BUFRSIZE)
	{
		/* discard any empty spaces inbetween or in the end */
		if (*lineptr == dlimtr && *(lineptr + 1) != ' ')
		{
			line = _malloc(sizeof(char) * i + 1);
			if (line == NULL)
				return (NULL);
			for (j = 0; j < i; j++, tmp++)
				line[j] = *tmp;
			line[j] = '\0';
			tokens[indx++] = line;
			/* set temp to begining of new line */
			tmp = lineptr + 1;
			i = 0;
		}
		if (*lineptr != ' ')
			i++; 
		lineptr++;
	}
	/* could not find the delimiter */
	if (indx == 0)
	{
		tokens[indx] = tmp;
		return (tokens);
	}
	/* theres more to be read, discard it and return null */
	if (*lineptr != '\0')
	{
		_puts("Killed\n");
		return (NULL);
	}
	/* check last empty spaces */
	for (tmpLen = _strlen(tmp) - 1; tmpLen >= 0; tmpLen--)
	{
		if (tmp[tmpLen] != ' ')
			break;
		tmp[tmpLen] = '\0';
	}
	if (*tmp != '\0')
	{
		tokens[indx++] = tmp;
		tokens[indx] = NULL;
	}
	else
		tokens[indx] = NULL;
	return (tokens);
}

/**
* _getline - reads user input and stores in memory
* @lineptr: pointer to input
* @fd: file descriptor for where to read from
* Return: number of chars read or -1
**/
ssize_t _getline(char **lineptr, int fd)
{
 	/* default line length */
	static int bufsz = BUFRSIZE;
	int readCount, charsRead;

	*lineptr = _malloc(sizeof(char) * bufsz);
	if (*lineptr == NULL)
		return (-1);
	charsRead = 0;
	while ((readCount = read(fd, *lineptr + charsRead, bufsz)) > 0)
	{
		if (readCount == -1)
			return (-1);
		/* exit when find a new line */
		if (*(*lineptr + readCount + charsRead - 1) == '\n')
		{
			/* make new line char, null */
			*(*lineptr + readCount + charsRead - 1) = '\0';
			charsRead += readCount;
			return (charsRead);
		}
                /* else needs more memory */
		*lineptr = _realloc(*lineptr, bufsz, 2 * bufsz);
		if (*lineptr == NULL)
			return (-1);
		bufsz *= 2;
		/* increment the pointer to what is already read */
		charsRead += readCount;
	}
	return (readCount);
}
