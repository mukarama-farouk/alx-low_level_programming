#include "main.h"

/**
 * flip_bits - function that returns the number of bits you would
 * need to flip to get from one number to another
 * @n: integer
 * @m: integer
 *
 * Return: flipped numbers
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip =  n ^ m;
	unsigned int i;

	i = 0;

	while (flip != 0)
	{
		i += flip & 1;
		flip >>= 1;
	}
	return (i);
}
