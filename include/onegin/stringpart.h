/**
 * @file stringpart.h
 * @brief The StringPart struct and helper functions for it.
 */

#ifndef STRINGPART_H
#define STRINGPART_H

#include "stddef.h"

/**
 * @brief Represents some part of other string.
 */
typedef struct StringPart {
    /**
     * @brief Pointer to the first symbol of some part of text.
     */
    const char *begin;

    /**
     * @brief Pointer to the first symbol after the end of some part of text.
     */
    const char *end;
} StringPart;

/**
 * @brief Compares two parts by their letters (in alphabetical order)
 *
 * Punctuation, numbers and other symbols are ignored and not used in
 * comparison.
 *
 * @param [in] first  First ::StringPart to be compared.
 * @param [in] second Second ::StringPart to be compared.
 *
 * @return `true` if first part should be placed before second in alphabetical
 * order.
 */
bool compare_letters(const StringPart *first, const StringPart *second);

/**
 * @brief Compares two parts by their letters, starting from the end of both
 * parts (in alphabetical order)
 *
 * Punctuation, numbers and other symbols are ignored and not used in
 * comparison.
 *
 * @param [in] first  First ::StringPart to be compared.
 * @param [in] second Second ::StringPart to be compared.
 *
 * @return `true` if first part should be placed before second in alphabetical
 * order.
 */
bool compare_letters_reversed(const StringPart *first,
                              const StringPart *second);

/**
 * @brief ::compare_letters wrapper compatible with ::Comparator type.
 *
 * @sa ::compare_letters
 *
 * @param [in] first  First ::StringPart to be compared.
 * @param [in] second Second ::StringPart to be compared.
 *
 * @return `true` if first part should be placed before second in alphabetical
 * order.
 */
bool letters_comparator(const void *first, const void *second);

/**
 * @brief ::compare_letters_reversed wrapper compatible with ::Comparator type.
 *
 * @sa ::compare_letters
 *
 * @param [in] first  First ::StringPart to be compared.
 * @param [in] second Second ::StringPart to be compared.
 *
 * @return `true` if the first part is less than the second.
 */
bool letters_reversed_comparator(const void *first, const void *second);

/**
 * @brief Splits text into parts, delimited by `delim`, ignoring empty parts.
 *
 * @param [in] text    Text to be split.
 * @param [in] delim   Delimiter that is used.
 * @param [out] result ::StringPart array to store result in.
 */
size_t split(const char *text, char delim, StringPart **result);

#endif // STRINGPART
