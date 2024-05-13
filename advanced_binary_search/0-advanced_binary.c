#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid;
	int *new_array;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");

	if (size == 1 && *array != value)
		return (-1);

	mid = size % 2 == 0 ? size / 2 : (size / 2) + 1;

	if (array[mid - 1] == value)
	{
		if (array[mid - 2] < value)
			return (mid - 1);
	}

	if (array[mid - 1] < value)
	{
		new_array = array + mid;
		if (size % 2 != 0)
			mid--;
	}
	else
		new_array = array;

	return (advanced_binary(new_array, mid, value));
}
