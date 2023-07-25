#include "main.h"

/**
 * _get_size - calculates the size to cast the argument
 * @format: formatted string in which to print the arguments
 * @x: list of arguments to be printed.
 * Return: size.
 */

int _get_size(const char *format, int *x)
{
	int y = *x + 1;
	int size = 0;

	if (format[y] == 'l')
	{
		size = SLONG;
	}
	else if (format[y] == 'h')
	{
		size = SSHORT;
	}

	if (size == 0)
	{
		*x = y - 1;
	}
	else
	{
		*x = y;
	}

	return (size);
}

