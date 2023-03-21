#include "main.h"

/**
 * main - prints the alphabets in lowercase
 *
 * Return : Always 0 (Success)
 */
void print_alphabet(void)
{
	char lt;

	for (lt = 'a'; lt <= 'z'; lt++)
		_putchar(lt);
	_putchar('\n');
}
