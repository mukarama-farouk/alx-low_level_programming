#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat -  function that concatenates two strings.
 * @s1: string 1
 * @s2: string 2
 * @n: Number of byte
 * Return: pointer to the allocated memory.
 * If the function fails, it should return NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *con;
	unsigned int j, k, l, i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (j = 0; s1[j] != '\0'; j++)
		;
	for (k = 0; s2[k] != '\0'; k++)
		;

	if (n > k)
		n = k;
	l = j + n;

	con = malloc(l + 1);
	if (con == NULL)
		return (NULL);
	for (i = 0; i < l; i++)
		if (i < j)
			con[i] = s1[i];
		else
			con[i] = s2[i - j];
	con[i] = '\0';
	return (con);
}
