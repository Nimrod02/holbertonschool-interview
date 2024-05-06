#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start',
 *             assuming the heaps rooted at its children are valid
 * @array: Array to sort
 * @start: Index of the root of the heap
 * @end: Index of the last element in the heap
 * @size: Size of the array
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while ((2 * root) + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			int temp = array[root];

			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
