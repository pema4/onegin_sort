#include "onegin/utf8.h"
#include "assert.h"
#include "ctype.h"
#include "stddef.h"

int utf8_length(const char *symbol) {
    unsigned char first_byte = *symbol;

    // if starts with 0
    if (0x00 == (first_byte >> 7))
        return 1;

    // if starts with 110
    if (0x06 == (first_byte >> 5))
        return 2;

    // if starts with 1110
    if (0x0E == (first_byte >> 4))
        return 3;

    // if starts with 11110
    if (0x1E == (first_byte >> 3))
        return 4;

    return -1;
}

static bool is_continuation(char byte) {
    // continuation byte starts with 10 (in binary)
    return 0x02 == ((unsigned char)byte >> 6);
}

bool utf8_compare(const char *first, const char *second) {
    do {
        if (*first != *second)
            return (unsigned char)*first < (unsigned char)*second;
        ++first;
        ++second;
    } while (is_continuation(*first), is_continuation(*second));

    return false;
}

bool utf8_equal(const char *first, const char *second) {
    do {
        if (*first != *second)
            return false;
        ++first;
        ++second;
    } while (is_continuation(*first), is_continuation(*second));

    return true;
}

int utf8_is_letter(const char *symbol) {
    bool is_ascii_latin = isalpha(*symbol);
    bool is_cyrillic =
        utf8_compare("\u03FF", symbol) && utf8_compare(symbol, "\u0500");
    return is_ascii_latin || is_cyrillic;
}

const char *utf8_find_next(const char *symbol_byte) {
    do {
        ++symbol_byte;
    } while (is_continuation(*symbol_byte));
    return symbol_byte;
}

const char *utf8_find_start(const char *symbol_byte) {
    while (is_continuation(*symbol_byte)) {
        --symbol_byte;
    }
    return symbol_byte;
}
