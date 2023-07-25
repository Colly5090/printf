#include "main.h"

/**
 * is_printable - checks if a character is printable
 * @c: Character to be evaluated
 * Return: 1 success or 0 failed
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - copy hexadecimal in ascii code to buffer
 * @buffer: Array of characters.
 * @x: Index at which to start to copy.
 * @ascii_code: ASSCI CODE.
 * Return: 3 success
 */
int append_hexa_code(char ascii_code, char buffer[], int x)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = map_to[ascii_code / 16];
	buffer[x] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - check if a character is a digit
 * @c: Character to be evalated
 * Return: 1 for digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - number to cast the specified size
 * @num: Number to be casted
 * @size: indicates number of the type to be casted
 * Return: value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == SLONG)
		return (num);
	else if (size == SSHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts number to specified size
 * @num: a number to be casted
 * @size: indicates number the type to be casted
 * Return: value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == SLONG)
		return (num);
	else if (size == SSHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
