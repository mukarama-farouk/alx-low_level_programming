#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: hash table that has to be added/updated
 * @key: key
 * @value: value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	hash_node_t *new_hashNode = NULL;
	hash_node_t *ptr = NULL;

	if (ht == NULL || key == NULL || (*key) == '\0' || value == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	ptr = ht->array[index];

	while (ptr && strcmp(ptr->key, key) != 0)
		ptr = ptr->next;

	if (ptr != NULL)
	{
		free(ptr->value);
		ptr->value = strdup(value);
		return (1);
	}

	new_hashNode = malloc(sizeof(*new_hashNode));
	if (new_hashNode == NULL)
		return (0);

	new_hashNode->key = strdup(key);
	new_hashNode->value = strdup(value);

	new_hashNode->next = ht->array[index];
	ht->array[index] = new_hashNode;

	return (1);
}
