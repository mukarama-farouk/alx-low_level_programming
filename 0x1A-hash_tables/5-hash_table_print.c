#include "hash_tables.h"
/**
 * hash_table_print - Prints a hash table
 * @ht: hash table
 *
 * Return: Nothing
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *ptr;
	char *seperator;

	if (ht == NULL)
		return;

	printf("{");
	seperator = "";

	for (i = 0; i < ht->size; i++)
	{
		ptr = ht->array[i];
		while (ptr)
		{
			printf("%s'%s': '%s'", seperator, ptr->key, ptr->value);
			seperator = ", ";
			ptr = ptr->next;
		}
	}
	printf("}\n");
}
