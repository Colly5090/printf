#include "main.h"

		/****************P TO PRINT POINTER ******************/
/**
 * _print_pointer - to print variable pointing to
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_pointer(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_x = 0, padd = ' ';
	int indus = BUFF_SIZE - 2, l = 2, padd_start = 1;
	unsigned long num_add;
	char mapto[] = "0123456789abcdef";
	void *add = va_arg(datatype, void *);

	UNUSED(width);
	UNUSED(size);

	if (add == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_add = (unsigned long)add;

	while (num_add > 0)
	{
		buffer[indus--] = mapto[num_add % 16];
		num_add /= 16;
		l++;
	}

	if ((flags & FZERO) && !(flags & FMINUS))
		padd = '0';
	if (flags & FPLUS)
		extra_x = '+', l++;
	else if (flags & FSPACE)
		extra_x = ' ', l++;

	indus++;

	return (writePointer(buffer, indus, l,
		width, flags, padd, extra_x, padd_start));
}


		/****************** PRINT NON-PRINTABLE ********************/
/**
 * _print_non_printable - print non-hexa decimal values in ascii code
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_non_printable(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = 0, set = 0;
	char *ptr = va_arg(datatype, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		return (write(1, "(null)", 6));

	while (ptr[x] != '\0')
	{
		if (is_printable(ptr[x]))
			buffer[x + set] = ptr[x];
		else
			set += append_hexa_code(ptr[x], buffer, x + set);

		x++;
	}

	buffer[x + set] = '\0';

	return (write(1, buffer, x + set));
}

		/************** PRINT REVERSE **********************/
/**
 * _print_reverse - to print strings in reverse
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_reverse(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	char *ptr;
	int y, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	ptr = va_arg(datatype, char *);

	if (ptr == NULL)
	{
		UNUSED(precision);

		ptr = ")Null(";
	}
	for (y = 0; ptr[y]; y++)
		;

	for (y -= 1; y >= 0; y--)
	{
		char z = ptr[y];

		write(1, &z, 1);
		count++;
	}
	return (count);
}


		/**************** PRINT A STRING IN ROT13 ******************/
/**
 * _print_rot13string - to print strings in ROT13
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_rot13string(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *ptr;
	unsigned int x, y;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	ptr = va_arg(datatype, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (ptr == NULL)
		ptr = "(AHYY)";
	for (x = 0; ptr[x]; x++)
	{
		for (y = 0; in[y]; y++)
		{
			if (in[y] == ptr[x])
			{
				a = out[y];
				write(1, &a, 1);
				count++;
				break;
			}
		}
		if (!in[y])
		{
			a = ptr[x];
			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
