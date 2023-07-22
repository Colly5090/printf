#ifndef main_h
#define main_h
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


#define BUFF_SIZE 1024

/* Functions to print characters and strings */

int _print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/* Functions that prints numbers */

int _print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int _print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);














#endif
