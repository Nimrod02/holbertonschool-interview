#include "sort.h"

/**
 * radix_sort - sorts an array following the Radix sort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
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
	int *output;
	size_t i;
	int j;

	output = malloc(sizeof(int) * size);

	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / lsd) % 10]++;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / lsd) % 10] - 1] = array[j];
		count[(array[j] / lsd) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
