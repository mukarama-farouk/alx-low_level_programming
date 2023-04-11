#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates array of chars
 * @size: Size of int
 * @c: Pointer
 * Return: Pointer of an array of chars
 */
char *create_array(unsigned int size, char c)
{
	char *ca;
	unsigned int i;

	if (size == 0)
		return (NULL);
	ca = malloc(sizeof(c) * size);
	if (ca == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ca[i] = c;
	return (ca);
}
