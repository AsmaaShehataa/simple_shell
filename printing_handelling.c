#include "hsh.h"

/**
 * to_string - cast an integer to decimal
 * @n: input number
 * @i: integer
 * Return: string length
 */
int to_string(int i, unsigned int n)
{
	char digit;

	if (n >= 10)
		return (to_string(i, n / 10) + to_string(i, n % 10));
	digit = '0' + n;
	if (i == 1)
		return (write(STDOUT_FILENO, &digit, 1));
	return (write(STDERR_FILENO, &digit, 1));
}
/**
 * print_string - check code
 * @str: string
 * @i: integer
 * Return: string length
 */
int print_string(int i, char *str)
{
	if (i == 1)
		return (write(STDOUT_FILENO, str, _strlen(str)));
	return (write(STDERR_FILENO, str, _strlen(str)));
}
