#include "onegin/stringpart.h"
#include "ctype.h"
#include "stdlib.h"

bool compare_letters(const StringPart *first, const StringPart *second) {
    const char *first_curr = first->begin;
    const char *second_curr = second->begin;

    while (true) {
        while (first_curr < first->end && !isalpha(*first_curr))
            ++first_curr;

        while (second_curr < second->end && !isalpha(*second_curr))
            ++second_curr;

        if (first_curr >= first->end)
            return second_curr < second->end;

        if (*first_curr != *second_curr)
            return *first_curr < *second_curr;

        ++first_curr;
        ++second_curr;
    }

    return false;
}

bool compare_letters_reversed(const StringPart *first, const StringPart *second) {
    const char *first_curr = first->end - 1;
    const char *second_curr = second->end - 1;

    while (true) {
        while (first_curr >= first->begin && !isalpha(*first_curr))
            --first_curr;

        while (second_curr >= second->begin && !isalpha(*second_curr))
            --second_curr;

        if (first_curr < first->begin)
            return second_curr >= second->begin;

        if (*first_curr != *second_curr)
            return *first_curr < *second_curr;

        --first_curr;
        --second_curr;
    }

    return false;

    return false;
}

bool letters_comparator(const void *first, const void *second) {
    return compare_letters((const StringPart *)first, (const StringPart *)second);
}

bool letters_reversed_comparator(const void *first, const void *second) {
    return compare_letters_reversed((const StringPart *)first,
                                  (const StringPart *)second);
}

size_t split(const char *text, char delim, StringPart **result) {
    const char *part_begin = text;
    size_t result_index = 0;
    size_t result_length = 1;
    *result = (StringPart *)calloc(result_length, sizeof(StringPart));

    char curr_char = 0;
    while ((curr_char = *text) != '\0') {
        if (curr_char == delim) {
            if (part_begin != text) {
                (*result)[result_index] = {.begin = part_begin, .end = text};
                ++result_index;
                if (result_index == result_length) {
                    result_length *= 2;
                    *result = (StringPart *)realloc(
                        *result, result_length * sizeof(StringPart));
                }
            }
            part_begin = text + 1;
        }
        ++text;
    }

    *result = (StringPart *)realloc(*result, result_index * sizeof(StringPart));
    return result_index;
}
