#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - A printf function
 * @format: a pointer to input arguments
 * Return: printed character
 */

int _printf(const char *format, ...)
{
	int x, print = 0, print_char = 0;
	int flag, width, precision, size, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list datatype;


	if (format == NULL)
		return (-1);

	va_start(datatype, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_ind++] = format[x];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			print_char++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flag = _get_flags(format, &x);
			width = _get_width(format, &x, datatype);
			precision = _get_precision(format, &x, datatype);
			size = _get_size(format, &x);
			++x;
			print = handle_print(format, &x, datatype, buffer,
				flag, width, precision, size);
			if (print == -1)
				return (-1);
			print_char += print;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(datatype);
	return (print_char);
}

/**
 * print_buffer - function to print buffer
 * @buffer: an array of buffer to print
 * @buff_ind: pointer to the index on buffer
 * Return: nothing
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
