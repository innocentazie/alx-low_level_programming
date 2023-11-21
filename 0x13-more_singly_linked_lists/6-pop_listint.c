#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to a pointer to the head of the list
 *
 * Return: data of the head node that was deleted
 */
int pop_listint(listint_t **head)
{
	int head_data;
	listint_t *temp, *next_node;

	if (*head == NULL)
		return (0);

	temp = *head;
	head_data = temp->n;
	next_node = temp->next;

	free(temp);

	*head = next_node;

	return (head_data);
}

