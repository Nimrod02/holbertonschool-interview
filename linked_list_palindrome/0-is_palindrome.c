#include "lists.h"

/**
 * reverse - reverses a linked list
 * @head: pointer to head of list
 * Return: pointer to head of reversed list
 */
listint_t *reverse(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return (prev);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *second_half, *prev_slow = *head;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if (fast != NULL)
        slow = slow->next;

    second_half = slow;
    prev_slow->next = NULL;
    second_half = reverse(second_half);

    while (*head != NULL && second_half != NULL)
    {
        if ((*head)->n == second_half->n)
        {
            *head = (*head)->next;
            second_half = second_half->next;
        }
        else
            return (0);
    }

    if (*head == NULL && second_half == NULL)
        return (1);

    return (0);
}
