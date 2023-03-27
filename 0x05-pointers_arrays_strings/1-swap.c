#include "main.h"

/**
 * swap_int - a function that swaps the values of two integers.
 * @a: First integar
 * @b: seconf integar
 * Return: 0
 */
void swap_int(int *a, int *b)
{
	int swmp = *a;
	*a = *b;
	*b = swmp;
}
