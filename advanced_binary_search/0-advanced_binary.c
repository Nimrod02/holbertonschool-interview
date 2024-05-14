#include "search_algos.h"

void print_array(int *array, size_t left, size_t right) {
    printf("Searching in array: ");
    for (size_t i = left; i <= right; i++) {
        if (i > left) {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

int recursive_binary_search(int *array, size_t left, size_t right, int value) {
    if (left > right) {
        return -1;
    }

    print_array(array, left, right);

    size_t mid = left + (right - left) / 2;

    if (array[mid] == value) {
        return mid;
    } else if (array[mid] > value) {
        return recursive_binary_search(array, left, mid - 1, value);
    } else {
        return recursive_binary_search(array, mid + 1, right, value);
    }
}

int advanced_binary(int *array, size_t size, int value) {
    if (array == NULL || size == 0) {
        return -1;
    }

    return recursive_binary_search(array, 0, size - 1, value);
}
