#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: first string
 * @s2: Second String
 * Return: Concatenated string
 *
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int i, k, j, limit;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;
	p = malloc(sizeof(char) * (i + j + 1));
	if (p == NULL)
	{
		free(p);
		return (NULL);
	}
	for (k = 0; k < i; k++)
		p[k] = s1[k];
	limit = j;

	for (j = 0; j <= limit; k++, j++)
		p[k] = s2[j];
	return (p);

}
