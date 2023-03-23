#include "main.h"

/**
 * print_numbers - Prints the number from 0-9
 *
 * Return: 0
 */
void print_numbers(void)
{
	char b;

	for (b = '0'; b <= '9'; b++)
	{
		_putchar(b);
	}
	_putchar('\n');

}
