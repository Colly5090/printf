# Custom printf Function Creation

In C standard library,printf is a function used for formatted output.Hence,this README will provide an overview of creating your own custom 'printf' function in C that can handle printing various types of data. The goal is to implement a simplified version of the standard C 'printf' function, which can handle different format specifiers to print different data types.


## Table of Contents
1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
3. [Handling Format Specifiers](#handling-format-specifiers)
4. [Data Types](#data-types)
5. [Special Characters](#special-characters)
6. [Memory Management](#memory-management)
7. [Error Handling](#error-handling)
8. [Conclusion](#conclusion)

## Introduction
The standard printf function is used to print formatted text to the standard output. It accepts a format string containing format specifiers for various data types and prints the corresponding values.Creating your own printf function can be challenging, fun and requires understanding of data manipulations, string formatting and variadic functions in C.

## Getting Started
1. Include the necessary libraries:
 
- #include <stdio.h>
- #include <stdarg.h>
- #include <stdlib.h>
- #include <string.h>

2. Prototype of the printf:
  
-  void my_printf(const char *format, ...);

3. Function definition and declarations:

void my_printf(const char *format, ...) 
{
	va_list args;
	va_start(args, format); /* Process format specifiers and print the corresponding data. */
	va_copy(va_list dest, va_list src); /* required where necessary */ 
       
	va_end(args);
	return (0); /* Return nothing */
}

## Handling Format Specifiers
Our custom 'printf' function will support the following format specifiers:

- `%c`: Print a single character.
- `%s`: Print a string (a null-terminated character array).
- `%d` or `%i`: Print a signed integer.
- `%u`: Print an unsigned integer.
- `%f`: Print a floating-point number.
- `%%`: Print a literal percent symbol.

## Data Types
The va_arg will be use to extract variable arguments based on the format specifier encountered. For instance %s will be used to extract a string.
It will be used to also extract integers, strings, floats etc based on their format specifiers.:

- void *str_arg = va_arg(args, void *);

## Special Characters
Special sequences and characters will be handled in the format string as follows:

- `\\` - for escaping backslash itself as  literal backslash
- ` \"` - for escaping and printing double quote
- ` \n` - for escaping and printing a newline character
- ` \t` - for escasping and printing a tab
- ` \'` - for printing a single quote

## Memory Management
Since the printf function supports a string,we will need to ensure proper memory management to avoid memory leaks. You may use malloc to allocate memory for strings and free to release the memory once it's no longer needed.

## Error Handling
Consider handling error cases, such as NULL string arguments, memory allocation failures, or unrecognized format specifiers. Proper error handling can make your printf function more robust and user-friendly.

## Conclusion
Creating your own printf function is a challenging task that requires careful handling of format specifiers, various data types, special characters, memory management, and error cases. This guide provides a basic outline to get you started, but remember that a complete and production-ready implementation may require additional complexity and consideration for edge cases.

Happy coding and have fun building your custom printf function 😊😊😁😁😌😌!!!
