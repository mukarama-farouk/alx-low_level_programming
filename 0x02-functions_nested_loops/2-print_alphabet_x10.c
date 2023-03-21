#include "main.h"
/**
 * main - _prints 10 times the alphabet, in lowercase
 *
 * Return: Always 0 (Success)
 */
void print_alphabet_x10(void)
{
	char lt;
	int i;

	i = 0;

	while (i < 10)
	{
		lt = 'a';
		while (lt <= 'z')
		{
			_putchar(lt);
			lt++;
		}
		_putchar('\n');
		i++;
	}
}
