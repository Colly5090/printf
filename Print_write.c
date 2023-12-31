#include "main.h"

     /***************** WRITE HANDLE *************************/
/**
 * handlewrite_char - to prints a string
 * @c: to check character types.
 * @buffer: array of buffer to handle print
 * @flags:  to check for active flags.
 * @width: to get width.
 * @precision: to handle precision specifier
 * @size: to handle size specifier
 * Return: characters printed
 */

int handlewrite_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FZERO)
		padd = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = padd;

		if (flags & FMINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

	/***************TO WRITE NUMBER *************************/
/**
 * write_number- to prints a string
 * @is_negative: to check character types
 * @ind: character type
 * @buffer: array of buffer to handle print
 * @flags:  to check for active flags.
 * @width: get width.
 * @precision: to handle precision specifier
 * @size: to handle size specifier
 * Return: characters printed
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int l = BUFF_SIZE - ind - 1;
	char padd = ' ', ch = 0;

	UNUSED(size);

	if ((flags & FZERO) && !(flags & FMINUS))
		padd = '0';
	if (is_negative)
		ch = '-';
	else if (flags & FPLUS)
		ch = '+';
	else if (flags & FSPACE)
		ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				l, padd, ch));
}

/**
 * write_num - To write a number on a bufffer
 * @ind: Index at which the number starts
 * @buffer: array of buffer to handle print
 * @flags:  to check for active flags.
 * @width: width
 * @prec: to handle precision specifier
 * @length: to handle length of a number
 * @padd: Padding a character
 * @extra_c: Extra character
 * Return: characters printed
 */
int write_num(int ind, char buffer[],
		int flags, int width, int prec,
		int length, char padd, char extra_c)
{
	int x, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (x = 1; x < width - length + 1; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & FMINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & FMINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], x - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FMINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], x - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsignd- to prints an unsigned number
 * @is_negative: to check character types is negative
 * @ind: index at which at which a buffer starts
 * @buffer: array of buffer to handle print
 * @flags:  to check for active flags.
 * @width: get width.
 * @precision: to handle precision specifier
 * @size: to handle size specifier
 * Return: size specifier
 */
int write_unsignd(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, x = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);  /* no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & FZERO) && !(flags & FMINUS))
		padd = '0';

	if (width > length)
	{
		for (x = 0; x < width - length; x++)
			buffer[x] = padd;

		buffer[x] = '\0';

		if (flags & FMINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], x));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * writePointer - Write a memory address
 * @buffer: an arrays of Character
 * @ind: index at which at which a buffer starts
 * @length: Length of the number
 * @width: for the width specifier
 * @flags: to check for active flags.
 * @padd: Character represents the padding
 * @extra_c: Character represents extra char
 * @padd_start: Index at which padding should start
 * Return:  characters printed
 */
int writePointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start)
{
	int x;

	if (width > length)
	{
		for (x = 3; x < width - length + 3; x++)
			buffer[x] = padd;
		buffer[x] = '\0';
		if (flags & FMINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & FMINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & FMINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], x - padd_start) +
					write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
