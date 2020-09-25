/**
 * @file utf8.h
 * @brief UTF-8 utilities.
 */

#ifndef UTF8_H
#define UTF8_H

/**
 * @brief Compares two UTF-8 symbols.
 *
 * @param [in] first  Pointer to the first byte of the first symbol.
 * @param [in] second Pointer to the first byte of the second symbol.
 *
 * @return `true` if the first UTF-8 symbol is less than the second.
 */
bool utf8_compare(const char *first, const char *second);

/**
 * @brief Returns if two UTF-8 symbols are equal.
 *
 * @param [in] first  Pointer to the first byte of the first symbol.
 * @param [in] second Pointer to the first byte of the second symbol.
 *
 * @return `true` if the first UTF-8 symbol is equal to the second.
 */
bool utf8_equal(const char *first, const char *second);

/**
 * @brief Returns a pointer to the firts bytebeginning of current code point
 *
 * Returns NULL if there is no any code_points.
 *
 * @param [in] code_point Pointer to some byte of the UTF-8 symbol.
 *
 * @return Pointer to the first byte of the next UTF-8 symbol or NULL.
 */
const char *utf8_find_next(const char *symbol_byte);

/**
 * @brief Returns a pointer to the first byte after current UTF-8 symbol.
 *
 * @param [in] code_point Pointer to some byte of the UTF-8 symbol.
 *
 * @return Pointer to the first byte after current UTF-8 symbol.
 */
const char *utf8_find_start(const char *symbol_byte);

/**
 * @brief Returns how many bytes takes UTF-8 symbol.
 *
 * @param [in] symbol Pointer to the first byte.
 *
 * @return Length of the symbol (in bytes).
 */
int utf8_length(const char *symbol);

/**
 * @brief Checks if UTF-8 symbol is latin|cyrillic letter.
 *
 * @param [in] symbol Pointer to the first byte of the UTF-8 symbol.
 *
 * @return `true` if the symbol is latin or cyrillic letter.
 */
int utf8_is_letter(const char *symbol);

#endif // UTF8_H
