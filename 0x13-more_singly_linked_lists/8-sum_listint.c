#include "lists.h"

/**
 * sum_listint - A function that returns all the sum of thr data(n)
 * of a linked list
 * @head: head of list
 *
 * Return: sum of data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
