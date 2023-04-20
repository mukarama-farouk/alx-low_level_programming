#include "function_pointers.h"
#include "3-calc.h"
#include <stdlib.h>
#include <string.h>

/**
 * get_op_func -  A function that gets an operator function
 *
 * @s: Operator passed as argument to program
 *
 * Return: Result of operation
 */

int (*get_op_func(char *s))(int, int)
{
<<<<<<< HEAD
op_t ops[] = {
{"+", op_add},
{"-", op_sub},
{"*", op_mul},
{"/", op_div},
{"%", op_mod},
{NULL, NULL}
};
int i = 0;
while (i < 5)
{
	if (s && s[0] == ops[i].op[0] && !s[1])
		return (ops[i].f);
	i++;
}
return (NULL);
}
=======
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 5)
	{
		if (strcmp(s, ops[i].op) == 0)
			return (ops[i].f);
		i++;
	}
>>>>>>> bcdcec293c031a2123c4de0e4dcdea803e477774

	return (0);
}
