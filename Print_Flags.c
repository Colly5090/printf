#include "main.h"

/**
 * _get_flags - to calculates active flags
 * @format: formatted string in which to print the arguments
 * @x: parameter.
 * Return: flags
 */

int _get_flags(const char *format, int *x)
{
	int i, y;
	int flags = 0;
	const char FLAGS_C[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_A[] = {FMINUS, FPLUS, FZERO, FHASH, FSPACE, 0};

	for (y = *x + 1; format[y] != '\0'; y++)
	{
		for (i = 0; FLAGS_C[i] != '\0'; i++)
			if (format[y] == FLAGS_C[i])
			{
				flags |= FLAGS_A[i];
				break;
			}

		if (FLAGS_C[i] == 0)
			break;
	}

	*x = y - 1;

	return (flags);
}

