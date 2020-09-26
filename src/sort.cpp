#include "onegin/sort.h"

#include "assert.h"
#include "stdlib.h"
#include "string.h"

static void quick_sort(char *begin, char *end, size_t elem_size,
                       Comparator comp);
static void swap(char *a, char *b, size_t size);

void sort(void *arr, size_t N, size_t elem_size, Comparator comp) {
    assert(arr != NULL);
    assert(N > 0);
    assert(elem_size > 0);

    quick_sort((char *)arr, (char *)arr + elem_size * (N - 1), elem_size, comp);
}

static void quick_sort(char *first, char *last, size_t elem_size,
                       Comparator comp) {
    // if sorted part consists of one or zero elements, then it is sorted.
    if (first + elem_size > last)
        return;

    char *pivot = (char *)calloc(1, elem_size);
    size_t pivot_offset = ((last - first) / (elem_size) + 1) / 2 * elem_size;
    memcpy(pivot, first + pivot_offset, elem_size);

    char *low = first;
    char *high = last;
    while (true) {
        while (low <= last && comp(low, pivot))
            low += elem_size;

        while (high >= first && comp(pivot, high))
            high -= elem_size;

        if (low > high) {
            free(pivot);
            break;
        }

        swap(low, high, elem_size);
        low += elem_size;
        high -= elem_size;
    }

    quick_sort(first, high, elem_size, comp);
    quick_sort(low, last, elem_size, comp);
}

static void swap(char *a, char *b, size_t size) {
    char *end_a = a + size;
    while (a != end_a) {
        char temp = *a;
        *a++ = *b;
        *b++ = temp;
    }
}

bool is_sorted(void *arr, size_t N, size_t elem_size, Comparator comp) {
    assert(arr != NULL);
    assert(N > 0);
    assert(elem_size > 0);

    char *curr = (char *)arr;
    char *end = curr + (N - 1) * elem_size;
    while (curr != end) {
        if (comp(curr + elem_size, curr))
            return false;
        curr += elem_size;
    }
    return true;
}
