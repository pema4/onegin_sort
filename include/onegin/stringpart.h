#include "stddef.h"

typedef struct StringPart {
    const char *begin;
    const char *end;
} StringPart;

bool compare_words(const StringPart *first, const StringPart *second);

bool compare_words_reversed(const StringPart *first, const StringPart *second);

bool words_comparator(const void *first, const void *second);

bool words_reversed_comparator(const void *first, const void *second);

size_t split(const char *text, char delim, StringPart **result);
