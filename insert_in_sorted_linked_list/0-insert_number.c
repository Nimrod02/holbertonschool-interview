#include "lists.h"


/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    // Case 1: Insert at the beginning or if the list is empty
    if (*head == NULL || (*head)->n >= number)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        // Case 2: Traverse the list to find the insertion point
        listint_t *current = *head;
        while (current->next != NULL && current->next->n < number)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    return (new_node);
}
