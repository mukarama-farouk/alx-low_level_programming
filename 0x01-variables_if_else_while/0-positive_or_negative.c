#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * Main - This program will assign a random number.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	else if (n == 0)
	{
		printf("%d is zer\n", n);

	}
	else
	{
		printf("%d is negative\n", n);

	}
	return (0);
}