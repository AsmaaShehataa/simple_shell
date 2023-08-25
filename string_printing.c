#include "hsh.h"

/**
 * print_string - prints the sting;
 * @string: the supplied string.
 *
 * Return : nothing, only printing the given string.
 */

void print_string(char *string)
{
	int counter;
	char ch;

	counter = 0;
	while (string[counter])
	{
		ch = string[counter];
		write(1, &ch, 1);
		counter++;
	}
	write(1, "\n", 1);
}
