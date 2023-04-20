#include "3-calc.h"
#include <stdlib.h>

/**
 * op_add - adds two integers
 * @a: input - integer 1
 * @b: input- integer 2
 *
 * Return:  sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}


/**
 * op_sub - subtracts two integers
 * @a: input - integer 1
 * @b: input- integer 2
 *
 * Return:  subtraction of a and b
 */
int op_sub(int a, int b)
{
        return (a - b);
}

/**
 * op_mul - multiplys two integers
 * @a: input - integer 1
 * @b: input- integer 2
 *
 * Return:  multiplication of a and b
 */
int op_mul(int a, int b)
{
        return (a * b);
}

/**
 * op_div - Divides two integers
 * @a: input - integer 1
 * @b: input- integer 2
 *
 * Return:  division of a and b
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

        return (a / b);
}

/**
 * op_mod - Modules two integers
 * @a: input - integer 1
 * @b: input- integer 2
 *
 * Return:  modulus of a and b
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
