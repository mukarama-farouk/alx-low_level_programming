#include <stdio.h>

/**
 * bf_main - function before main
 * Return: no return
 */
void __attribute__ ((constructor)) bf_main()
{
	printf("You're beat! and yet, you must allow");
	printf(",\nI bore my house upon my back!\n");
}
