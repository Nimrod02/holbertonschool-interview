#include "sort.h"

/**
 * heapify - Heapifies a subtree
 * @arr: Array to be sorted
 * @size: Size of the array
 * @i: Index of the root of the subtree
 *
 * Return: void
*/
void heapify(int arr[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;
    if (left < size && arr[left] > arr[largest])
	largest = left;
    if (right < size && arr[right] > arr[largest])
	largest = right;
    if (largest != i)
    {
	temp = arr[i];
	arr[i] = arr[largest];
	arr[largest] = temp;
	heapify(arr, size, largest);
    }
}

/**
 * headSort - Sorts an array using heap sort algorithm
 * @arr: Array to be sorted
 * @size: Size of the array
 *
 * Return: void
*/
void heapSort(int arr[], int size)
{
	int i, temp;
    for (i = size / 2 - 1; i >= 0; i--)
	heapify(arr, size, i);
    for (i = size - 1; i > 0; i--)
    {
	temp = arr[0];
	arr[0] = arr[i];
	arr[i] = temp;
	heapify(arr, i, 0);
    }
}
