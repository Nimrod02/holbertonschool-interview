#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	skiplist_t *prev = NULL;

	if (!list)
	return (NULL);

	while (current)
	{
	prev = current;
	if (current->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		current->express->index, current->express->n);
		if (current->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
			current->index, current->express->index);
		break;
		}
	current = current->express;
	}
	else
	{
		while (current->next)
		current = current->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, current->index);
	break;
	}
	}

	while (prev && prev->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
		return (prev);
		prev = prev->next;
		}
		return (NULL);
}
