#include <stdio.h>

/**
 * main - prints the alphabet in lowercase, and then in uppercase,
 * followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	int lt;

	for (lt = 'a'; lt <= 'z'; lt++)
		putchar(lt);
	for (lt = 'A'; lt <= 'Z'; lt++)
		putchar(lt);
	putchar('\n');
	return (0);

