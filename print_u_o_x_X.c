#include "main.h"

		/******************** U TO PRINT UNSIGNED NUMBER *******************/
/**
 * _print_unsigned - To print unsigned number
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_unsigned(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(datatype, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[x--] = (number % 10) + '0';
		number /= 10;
	}

	x++;

	return (write_unsignd(0, x, buffer, flags, width, precision, size));
}


		/************* O TO PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * _print_octal - to print unsigned octal number
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_octal(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{

	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(datatype, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[x--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & FHASH && init_number != 0)
		buffer[x--] = '0';

	x++;

	return (write_unsignd(0, x, buffer, flags, width, precision, size));
}


			/************** x TO PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * _print_hexadecimal - to print hexadecimal number
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int _print_hexadecimal(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	return (_print_hexa(datatype, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

	/********** X TO PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL *********/
/**
 * print_hexa_upper - to print hexadecimal number in upper
 * @datatype: arguments to list
 * @buffer: array of buffer to print
 * @flags:   flags format specifier
 * @width: Width of format specifier
 * @precision: precision of format specifier
 * @size: Size of format specifier
 * Return: Number of chars to be printed
 */
int print_hexa_upper(va_list datatype, char buffer[],
	int flags, int width, int precision, int size)
{
	return (_print_hexa(datatype, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


			/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * _print_hexa - to prints a hexadecimal number either in lower or upper
 * @datatype: arguments to list
 * @map_to: Array to map value to numbers
 * @buffer: array of buffer to handle inputs
 * @flags:  to calculates active flags
 * @flag_ch: to calculates active flags
 * @width: to get width
 * @precision: to check precision specification
 * @size: to identify size specifier
 * @size: for size specification
 * Return: Number of character to be printed
 */
int _print_hexa(va_list datatype, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	unsigned long int number = va_arg(datatype, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[x--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & FHASH && init_number != 0)
	{
		buffer[x--] = flag_ch;
		buffer[x--] = '0';
	}

	x++;
	return (write_unsignd(0, x, buffer, flags, width, precision, size));
}
