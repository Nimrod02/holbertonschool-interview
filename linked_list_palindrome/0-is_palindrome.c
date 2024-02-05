#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
    listint_t *current;
    int index, jndex, len = 0;
    int *arr;

    if (*head == NULL)
        return (1);

    current = *head;
    while (current != NULL)
    {
        current = current->next;
        len++;
    }

    arr = malloc(len * sizeof(int));
    if (arr == NULL)
        return (0);

    current = *head;
    for (index = 0; current != NULL; index++)
    {
        arr[index] = current->n;
        current = current->next;
    }

    for (index = 0, jndex = len - 1; index < len / 2; index++, jndex--)
    {
        if (arr[index] != arr[jndex])
        {
            free(arr);
            return (0);
        }
    }

    free(arr);
    return (1);
}
