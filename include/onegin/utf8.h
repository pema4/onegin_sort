/**
 * @file utf8.h
 * @brief UTF-8 utilities.
 */

#ifndef UTF8_H
#define UTF8_H

/**
 * @brief Compares two unicode symbols.
 *
 * @param [in] first  Pointer to the first byte of the first symbol.
 * @param [in] second Pointer to the first byte of the second symbol.
 *
 * @return `true` if the first unicode symbol is less than the second.
 */
bool utf8_compare(const char *first, const char *second);

/**
 * @brief Returns if two unicode symbols are equal.
 *
 * @param [in] first  Pointer to the first byte of the first symbol.
 * @param [in] second Pointer to the first byte of the second symbol.
 *
 * @return `true` if the first unicode symbol is equal than the second.
 */
bool utf8_equal(const char *first, const char *second);

/**
 * @brief Returns a pointer to the beginning of current code point
 *
 * Returns NULL if there is no any code_points.
 *
 * @param [in] code_point Pointer to some symbol of the code point.
 *
 * @return Pointer to the first symbol of the next code point or NULL.
 */
const char *utf8_find_next(const char *symbol_byte);

/**
 * @brief Returns a pointer to the first byte after current code point.
 *
 * @param [in] code_point Pointer to the first byte after current code point.
 */
const char *utf8_find_start(const char *symbol_byte);

int utf8_length(const char *symbol);

int utf8_is_letter(const char *symbol);

#endif // UTF8_H
