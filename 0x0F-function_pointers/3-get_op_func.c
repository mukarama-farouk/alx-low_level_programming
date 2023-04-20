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

while (ops[i].op != NULL && *(ops[i].op) != *s)

	i++;

return (ops[i].f);
}
