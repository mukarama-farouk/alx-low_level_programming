#include <stdio.h>

/**
 * main - prints the alphabet in lowercase,
 * followed by a new line, except q and e
 * Return: Aways 0 (Sucess)
 */
int main(void)
{
	char lt = 'a';

	while (lt <= 'z')
	{
		if (lt != 'e' && lt != 'q')
		{
			putchar(lt);
		}
		lt++;
	}
	putchar('\n');
	return (0);
}

