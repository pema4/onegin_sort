/**
 * @file utils.h
 * @brief Various utilities function to solve Onegin problem.
 */

#include "stdio.h"

#ifdef NDEBUG
const int INITIAL_BUFFER_SIZE = 16;
#else
const int INITIAL_BUFFER_SIZE = 1;
#endif

/**
 * @brief Returns file content, terminated by `'\0'`.
 *
 * @param [in,out] input File to be read.
 */
char *read_file(FILE *input);
