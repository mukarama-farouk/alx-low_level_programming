#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_strings -  function that prints strings, followed by a new line.
 * @separator:the string to be printed between the strings
 * @n: Number of arguments
 *
 * Return: no return
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ps;
	unsigned int i;
	char *str;

	va_start(ps, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(ps, char*);

		if (str)
			printf("%s", str);
		else
			printf("(nil)");
		if (i < n - 1)
			if (separator)
				printf("%s", separator);
	}
	printf("\n");
	va_end(ps);

}
