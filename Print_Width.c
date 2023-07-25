#include "main.h"

/**
 * _get_width - checks width for printing
 * @format: arguments formatted before printing
 * @x: arguments to be printed.
 * @datatype: list of arguments.
 * Return: width
 */
int _get_width(const char *format, int *x, va_list datatype)
{
	int curr;
	int width = 0;

	for (curr = *x + 1; format[curr] != '\0'; curr++)
	{
		if (is_digit(format[curr]))
		{
			width *= 10;
			width += format[curr] - '0';
		}
		else if (format[curr] == '*')
		{
			curr++;
			width = va_arg(datatype, int);
			break;
		}
		else
			break;
	}

	*x = curr - 1;

	return (width);
}

