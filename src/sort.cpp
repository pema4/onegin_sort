#include "onegin/sort.h"

#include "assert.h"

void bubble_sort(char *arr, size_t N, size_t elem_size, Comparator comp);
void swap(char *a, char *b, size_t size);

void sort(void *arr, size_t N, size_t elem_size, Comparator comp) {
    assert(arr != NULL);
    assert(N > 0);
    assert(elem_size > 0);
    
    bubble_sort((char *)arr, N, elem_size, comp);
}

void bubble_sort(char *arr, size_t N, size_t elem_size, Comparator comp) {
    bool something_changed = false;
    do {
        something_changed = false;
        char *end = arr + (N - 1) * elem_size;
        for (char *curr = arr; curr != end; curr += elem_size) {
            char *next = curr + elem_size;
            if (!comp(curr, next)) {
                swap(curr, next, elem_size);
                something_changed = true;
            }
        }
    } while (something_changed);
}

void swap(char *a, char *b, size_t size) {
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
        if (!comp(curr, curr + elem_size))
            return false;
        curr += elem_size;
    }
    return true;
}
