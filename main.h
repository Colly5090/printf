#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

int _printf(const char *format, ...);

/**
 * struct format - Struct op
 * @fmt: format.
 * @fun: the function associated.
 */
struct format
{
	char fmt;
	int (*fun)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format fmt_t - Struct op
 * @fmt: format.
 * @fm_t: function associated.
 */
typedef struct format fmt_t;

int handle_print(const char *fmt, int *x,
		va_list datatype, char buffer[], int flags, int width, int precision, int size);

#define FMINUS 1
#define FPLUS 2
#define FZERO 4
#define FHASH 8
#define FSPACE 16 /*flags*/

#define SLONG 2
#define SSHORT 1 /*sizes*/



/* Functions that prints characters and strings */

int print_char(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int _print_string(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int _print_percent(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);


/* Functions that prints numbers */

int _print_int(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int _print_unsigned(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int _print_octal(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int _print_hexadecimal(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int _print_binary(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);
int _print_hexa(va_list datatype, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

int _print_non_printable(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);


/* Function that prints memory address */
int _print_pointer(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);

/* Function that prints special characters */
int _print_special(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions that handle other specifiers */
int _get_flags(const char *format, int *x);
int _get_width(const char *format, int *x, va_list datatype);
int _get_precision(const char *format, int *x, va_list datatype);
int _get_size(const char *format, int *x);

/*Function that print string in reverse */
int _print_reverse(va_list datatype, char buffer[],
	int flags, int width, int precision, int size);

/*Function that print a string in rot 13*/
int _print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handlewrite_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int writePointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsignd(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);


int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);


#endif
