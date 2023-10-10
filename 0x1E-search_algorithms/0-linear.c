#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers using
 * the linear search algorithm
 *
 * @array: pointer to first element
 * @size: Number of elements
 * @value: value to search for
 *
 * Return: -1 or 1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%u] = [%d]\n", i, array[i]);

		if (array[i] == value)
			return (i);
	}
	return (-1);

}
