#include "main.h"

/************************* C TO PRINT CHAR *************************/

/**
 * print_char - Prints a character using c specifier
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags: flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: chars to be printed
 */
int print_char(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(datatype, int);

	return (handlewrite_char(c, buffer, flags, width, precision, size));
}


/************************* S TO PRINT A STRING *************************/

/**
 * _print_string - Prints a string using s specifier
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:  flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_string(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	int total = 0, x;
	char *ptr = va_arg(datatype, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (ptr == NULL)
	{
		ptr = "(null)";
		if (precision >= 6)
			ptr = "      ";
	}

	while (ptr[total] != '\0')
		total++;

	if (precision >= 0 && precision < total)
		total = precision;

	if (width > total)
	{
		if (flags & FMINUS)
		{
			write(1, &ptr[0], total);
			for (x = width - total; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - total; x > 0; x--)
				write(1, " ", 1);
			write(1, &ptr[0], total);
			return (width);
		}
	}

	return (write(1, ptr, total));
}

/************************* % TO PRINT PERCENT SIGN *************************/

/**
 * _print_percent - Prints a percent sign
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_percent(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(datatype);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/************************* D or I TO PRINT INT *************************/

/**
 * _print_int - Print integer
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_int(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(datatype, long int);
	unsigned long int number;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)n;

	if (n < 0)
	{
		number = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (number > 0)
	{
		buffer[x--] = (number % 10) + '0';
		number /= 10;
	}

	x++;

	return (write_number(is_neg, x, buffer, flags, width, precision, size));
}

/************************* B TO PRINT BINARY *************************/

/**
 * _print_int - Print integer
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_binary(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int y, i, x, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	y = va_arg(datatype, unsigned int);
	i = 2147483648; /* (2 ^ 31) */
	a[0] = y / i;
	for (x = 1; x < 32; x++)
	{
		i /= 2;
		a[x] = (y / i) % 2;
	}
	for (x = 0, sum = 0, count = 0; x < 32; x++)
	{
		sum += a[x];
		if (sum || x == 31)
		{
			char z = '0' + a[x];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
