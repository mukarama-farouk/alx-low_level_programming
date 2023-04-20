#include "3-calc.h"

/**
 * get_op_func - Selects the right function to perform
 * @s: operator passed
 *
 * Return: Pointer to the function that corresponds to the
 * operator
 */
int (*get_op_func(char *s))(int, int)
{
op_t ops[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL}
};
int i;
while (i < 6)
{
	if (s[0] == ops->op[i])
		break;
	i++;
}
return (ops[i / 2].f);
}

