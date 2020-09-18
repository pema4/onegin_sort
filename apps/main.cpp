#include "onegin/sort.h"
#include "onegin/stringpart.h"
#include "onegin/utils.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char **argv) {
    char *input = read_file(stdin);
    StringPart *parts = NULL;
    int parts_number = split(input, '\n', &parts);

    puts("Without sort:");
    for (int i = 0; i < parts_number; ++i) {
        printf("%d: ", i);
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1, stdout);
    }

    sort(parts, parts_number, sizeof(*parts), words_comparator);
    puts("Normal sort:");
    for (int i = 0; i < parts_number; ++i) {
        printf("%d: ", i);
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1, stdout);
    }

    sort(parts, parts_number, sizeof(*parts), words_reversed_comparator);
    puts("Reversed sort:");
    for (int i = 0; i < parts_number; ++i) {
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1, stdout);
    }

    free(parts);
    free(input);
    return 0;
}
