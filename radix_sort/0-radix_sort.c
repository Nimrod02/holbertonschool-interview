#include "sort.h"


/**
 * radix_sort - sorts an array of integers using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int i, j, k, m = 0, exp = 1;
	int *tmp = NULL;
	int max = 0;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);

	if (!tmp)
		return (0);

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
		max = array[i];
	}

	while (max / exp > 0)
	{
		int bucket[10] = {0};

		for (i = 0; i < (int)size; i++)
			bucket[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];

		for (i = size - 1; i >= 0; i--)
			tmp[--bucket[(array[i] / exp) % 10]] = array[i];

		for (i = 0; i < (int)size; i++)
			array[i] = tmp[i];

		exp *= 10;

		print_array(array, size);
	}

	free(tmp);
}
