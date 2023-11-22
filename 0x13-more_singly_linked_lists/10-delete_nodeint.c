#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at a specified
 * index in a linked list.
 * @head: pointer to the head of the list.
 * @index: index of the node to be deleted.
 *
 * Return: 1 if deletion succeeded and -1 if it failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *prev_node;
	listint_t *next_node;

	prev_node = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && prev_node != NULL; i++)
		{
			prev_node = prev_node->next;
		}
	}

	if (prev_node == NULL || (prev_node->next == NULL && index != 0))
	{
		return (-1);
	}

	next_node = prev_node->next;

	if (index != 0)
	{
		prev_node->next = next_node->next;
		free(next_node);
	}
	else
	{
		free(prev_node);
		*head = next_node;
	}

	return (1);
}

