#include "onegin/utils.h"
#include "stdlib.h"

char *read_file(FILE *input) {
    size_t buffer_length = INITIAL_BUFFER_SIZE;
    char *buffer = (char *)calloc(buffer_length, 1);
    size_t file_length = 0;

    while (true) {
        file_length += fread(
            buffer + file_length, // where to store a new portion of the file.
            1,
            buffer_length - file_length, // we can read only this much
            input);

        // if buffer is not fully filled, then we read whole file.
        if (file_length < buffer_length)
            break;

        // otherwise reallocate and read again
        buffer_length *= 2;
        buffer = (char *)realloc(buffer, buffer_length);
    }

    // add terminating null if there isn't any
    if (buffer[file_length - 1] == '\0') {
        buffer = (char *)realloc(buffer, file_length);
    } else {
        buffer = (char *)realloc(buffer, file_length + 1);
        buffer[file_length] = '\0';
    }

    return buffer;
}
