/**
 * @file sort.h
 * @brief Algorithms for sorting.
 */

#include "stddef.h"

/**
 * @brief Comparator type to be used with sort.
 *
 * @param [in] a The first argument.
 * @param [in] b The second argument.
 *
 * @return `true` if `a < b` else `false`.
 */
typedef bool Comparator(const void *a, const void *b);

/**
 * @brief Sorts the array.
 *
 * @param [in,out] arr   Array to be sorted. Must not be NULL.
 * @param [in] N         Size of the array.
 * @param [in] elem_size Size of one array element. Must be positive.
 * @param [in] comp      Comparator to be used.
 */
void sort(void *arr, size_t N, size_t elem_size, Comparator comp);

/**
 * @brief Returns if array is in ascending order or not.
 *
 * @param [in] arr       Array to be checked. Must not be NULL.
 * @param [in] N         Size of the array.
 * @param [in] elem_size Size of one array element. Must be positive.
 * @param [in] comp      Comparator to be used.
 */
bool is_sorted(void *arr, size_t N, size_t elem_size, Comparator comp);
