#include "main.h"

/**
 * _memcpy - A function that copies memory area.
 * @dest: Pointer pointing to
 * @src: Memory area
 * @n: integar
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}
