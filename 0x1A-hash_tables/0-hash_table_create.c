#include "hash_tables.h"

/**
 * hash_table_create - A function that creates a hash table
 * @size: size of the array
 *
 * Return: A pointer to the newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *new_table;
	hash_table_t **array;
	unsigned long int i;

	new_table = malloc(sizeof(hash_table_t));

	if (new_table == NULL)
		return (NULL);

	array = malloc(sizeof(hash_table_t *) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = NULL;

	new_table->array = array;
	new_table->size = size;

	return (new_table);
}
