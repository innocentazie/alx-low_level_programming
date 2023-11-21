#include "lists.h"

/**
 * listint_len - counts the number of elements in a linked list.
 * @h: head of the list.
 *
 * Return: number of nodes.
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes_count = 0;

	while (h != NULL)
	{
		h = h->next;
		nodes_count++;
	}

	return (nodes_count);
}

