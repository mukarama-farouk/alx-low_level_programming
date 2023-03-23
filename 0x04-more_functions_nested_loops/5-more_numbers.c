#include "main.h"

/**
 * more_numbers - prints 10 times the numbers, from 0 to 14,
 * followed by a new line
 *
 * Return: 0
 */
void more_numbers(void)
{
	int m, j;

	for (m = 1; m <= 10; m++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j >= 10)
				_putchar('1');
			_putchar(j % 10 + '0');

		}
		 _putchar('\n');
	}

}
