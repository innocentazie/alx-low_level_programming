#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: pointer to a pointer to the head of the list
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *temp, *current_node;

	if (head != NULL && *head != NULL)
	{
		current_node = *head;
		while (current_node != NULL)
		{
			temp = current_node;
			current_node = current_node->next;
			free(temp);
		}
		*head = NULL;
	}
}

