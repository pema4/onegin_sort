#include "onegin/sort.h"
#include "onegin/stringpart.h"
#include "onegin/utils.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"

int main() {
    char *input = read_file(stdin);
    StringPart *parts = NULL;
    int parts_number = split(input, '\n', &parts);

    puts("Without sort:");
    for (int i = 0; i < parts_number; ++i) {
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1, stdout);
    }

    sort(parts, parts_number, sizeof(*parts), letters_comparator);
    puts("Normal sort:");
    for (int i = 0; i < parts_number; ++i) {
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1, stdout);
    }
    assert(is_sorted(parts, parts_number, sizeof(*parts), letters_comparator));

    sort(parts, parts_number, sizeof(*parts), letters_reversed_comparator);
    puts("Reversed sort:");
    for (int i = 0; i < parts_number; ++i) {
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1, stdout);
    }
    assert(is_sorted(parts, parts_number, sizeof(*parts), letters_reversed_comparator));

    free(parts);
    free(input);
    return 0;
}
