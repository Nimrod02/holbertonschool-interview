#include "sort.h"

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	int max = array[0];

	for (size_t i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (size_t lsd = 1; max / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort_LSD - count sort with LSD
 * @array: array to sort
 * @size: size of the array
 * @lsd: least significant digit
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count[10] = {0};
	int *output = malloc(sizeof(int) * size);

	if (!output)
		return;

	for (size_t i = 0; i < size; i++)
		count[(array[i] / lsd) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / lsd) % 10] - 1] = array[i];
		count[(array[i] / lsd) % 10]--;
	}

	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
