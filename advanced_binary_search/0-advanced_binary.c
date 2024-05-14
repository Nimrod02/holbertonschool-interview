#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: pointer to the first element of the array to print
 * @left: left index of the array
 * @right: right index of the array
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t index;

	printf("Searching in array: ");
	for (index = left; index <= right; index++)
	{
		if (index > left)
			printf(", ");
		printf("%d", array[index]);
		}
		printf("\n");
}

/**
 * recursive_binary_search - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @left: left index of the array
 * @right: right index of the array
 * @value: value to search for
 *
 * Return: index where value is located or -1
 */
int recursive_binary_search(int *array, size_t left, size_t right, int value)
{
	if (left > right)
	{
		return (-1);
	}

	print_array(array, left, right);

	size_t mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		return (mid);
		}
	else if (array[mid] > value)
	{
		return (recursive_binary_search(array, left, mid - 1, value));
	}
	else
	{
		return (recursive_binary_search(array, mid + 1, right, value));
	}
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: index where value is located or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_binary_search(array, 0, size - 1, value));
}
