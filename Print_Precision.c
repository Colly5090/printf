#include "main.h"

/**
 * _get_precision - calculate the precision for printing
 * @format: formatted string in which to print the arguments
 * @x: list of arguments to be printed.
 * @datatype: list name of argument.
 * Return: Precision.
 */

int _get_precision(const char *format, int *x, va_list datatype)
{
	int c = *x + 1;
	int precision = -1;

	if (format[c] != '.')
		return (precision);

	precision = 0;

	for (c += 1; format[c] != '\0'; c++)
	{
		if (is_digit(format[c]))
		{
			precision *= 10;
			precision += format[c] - '0';
		}
		else if (format[c] == '*')
		{
			c++;
			precision = va_arg(datatype, int);
			break;
		}
		else
			break;
	}

	*x = c - 1;

	return (precision);
}

