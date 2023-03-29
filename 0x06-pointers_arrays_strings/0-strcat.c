#include "main.h"

/**
 * _strcat - a function that concatenates two strings.
 * @dest: pointer string
 * @src: pointer string
 * Return: Pointer to the resulting string
 *
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);

}
