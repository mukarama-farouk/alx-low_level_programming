#include "main.h"

/**
 * _strncat - a function that concatenates two strings.
 * @src: Pointer string
 * @dest: pointer string
 * @n: Integar
 *
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}

	int i = 0;
	while (*src && i < n)
	{
		*ptr = *src;
		ptr++;
		src++;
		i++;
	}
	*ptr = '\0';
	return (dest);

}
