#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in a sorted array of integers
 * using jump search algorithm
 * @array: pointer to the first element
 * @size: Number of elements in the array
 * @value: Target element
 *
 * Return: first index where value is located or -1
 */
int jump_search(int *array, size_t size, int value)
{
	int i;
	int left = 0;
	int jump = (int)sqrt(size);
	int right = jump;

	if (array == NULL)
		return (-1);

	while (right < (int)size && array[right] < value)
	{
		left = right;
		right += jump;
	}
	for (i = left; i < (int)size && i <= right; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
    		if (array[i] == value)
        		return (i);
	}
	return (-1);
}
