#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to be deleted
 *
 * Return: Void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *ptr1;
	hash_node_t *ptr2;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		ptr1 = ht->array[i];
		while ((ptr2 = ptr1) != NULL)
		{
			ptr1 = ptr1->next;
			free(ptr2->key);
			free(ptr2->value);
			free(ptr2);
		}
	}
	free(ht->array);
	free(ht);
}
