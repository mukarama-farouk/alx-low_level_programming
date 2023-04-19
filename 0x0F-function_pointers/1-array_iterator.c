#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - function that executes a function given as
 * parameter on each element of an array
 * @array: input
 * @size: size of array
 * @action: function pointer
 *
 * Return: no return
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int a;

	if (array == NULL || action == NULL)
		return;
	for (a = 0; a < size; a++)
		action(array[a]);

}
