#include <stdio.h>

/**
 * main - prints all possible different combinations of two digits
 * Return: ALways 0 (Success)
 */
int main(void)
{
	int s, o;

	for (s = 48; s <= 56; s++)
	{
		for (o = 49; o <= 57; o++)
		{
			if (o > s)
			{
				putchar(s);
				putchar(o);
				if (s != 56 || o != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
