#include "main.h"

/**
 * handle_print - to print the type of argument input
 * @fmt: pointer to the argument to print
 * @datatype: arguments to be printed.
 * @ind: the ind
 * @buffer: array of buffer to print
 * @flags: check for active flags
 * @width: to get width.
 * @precision: for precision specification
 * @size: for size specifier
 * Return: an int value
 */
int handle_print(const char *fmt, int *ind, va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	int x, len = 0, chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', _print_string}, {'%', _print_percent},
		{'i', _print_int}, {'d', _print_int}, {'b', _print_binary},
		{'u', _print_unsigned}, {'o', _print_octal}, {'x', _print_hexadecimal},
		{'X', print_hexa_upper}, {'p', _print_pointer}, {'S', _print_non_printable},
		{'r', _print_reverse}, {'R', _print_rot13string}, {'\0', NULL}
	};
	for (x = 0; fmt_types[x].fmt != '\0'; x++)
		if (fmt[*ind] == fmt_types[x].fmt)
			return (fmt_types[x].fun(datatype, buffer, flags, width, precision, size));

	if (fmt_types[x].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &fmt[*ind], 1);
		return (len);
	}
	return (chars);
}
