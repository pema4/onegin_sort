/**
 * @file utils.h
 * @brief Various utilities function to solve Onegin problem.
 */

#include "stdio.h"

extern const int INITIAL_BUFFER_SIZE;

/**
 * @brief Returns file content, terminated by `'\0'`.
 *
 * @param [in,out] input File to be read.
 */
char *read_file(FILE *input);
