#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list.
 * @head: pointer to the head of the list.
 * @n: element to add.
 *
 * Return: address of the new element or NULL if it fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
        listint_t *new_node = malloc(sizeof(listint_t));

        if (new_node == NULL && head == NULL)
                return (NULL);

        new_node->n = n;
        new_node->next = *head;
        *head = new_node;

        return (*head);
}
