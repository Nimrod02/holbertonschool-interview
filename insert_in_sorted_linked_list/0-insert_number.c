#include "lists.h"


/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *newnode;
    listint_t *newnode2;

    newnode = *head;
    newnode2 = *head;

    newnode = malloc(sizeof(listint_t));
    if (newnode == NULL)
		return (NULL);

    newnode->n = number;

    if (*head == NULL)
    {
        *head = newnode;
        return (newnode);
    }

    if (newnode2->n > number)
    {
        *head = newnode;
        newnode->next = newnode2;
        return (newnode);
    }

    while (newnode2->next->n < number)
    {
        newnode2 = newnode2->next;

        if (newnode2->next == NULL)
        {
        newnode2->next = newnode;
        newnode->next = NULL;
        return (newnode);
        }
    }
    newnode->next = newnode2->next;
    newnode2->next = newnode;
    return (newnode);
}
