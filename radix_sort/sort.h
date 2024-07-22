#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void radix_sort(int *array, size_t size);
void count_sort_LSD(int *array, size_t size, size_t lsd);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
