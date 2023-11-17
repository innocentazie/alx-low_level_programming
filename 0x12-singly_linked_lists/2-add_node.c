#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: pointer to the pointer of the linked list's head.
 * @str: string to store in the list.
 *
 * Return: address of the new head of the list, NULL on failure.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	size_t str_len = 0;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);

	while (str[str_len])
		str_len++;

	new_node->len = str_len;
	new_node->next = *head;
	*head = new_node;

	return (*head);
}

