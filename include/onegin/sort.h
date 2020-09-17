/**
 * @file sort.h
 * @brief Algorithms for sorting.
 */

#include "stddef.h"

/**
 * @brief Comparator type to be used.
 * 
 * Comparator types
 */ 
typedef bool Comparator(const void *a, const void *b);

void sort(void *arr, size_t N, size_t elem_size, Comparator comp);

bool is_sorted(void *arr, size_t N, size_t elem_size, Comparator comp);
