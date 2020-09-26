#include "assert.h"
#include "onegin/sort.h"
#include "onegin/stringpart.h"
#include "onegin/utils.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int help() {
    puts("Usage: main [NORMAL_OUT] [SORTED_OUT] [REVERSED_SORTED_OUT]");
    return 0;
}

int unknown_command() {
    puts("Unknown command! Use \"-h\" or \"--help\" to view help");
    return -1;
}

int do_sort(FILE *in, FILE *normal_out, FILE *sorted_out,
            FILE *reversed_sorted_out) {
    char *text = read_file(in);
    StringPart *parts = NULL;
    int parts_number = split(text, '\n', &parts);

    for (int i = 0; i < parts_number; ++i)
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1,
               normal_out);

    sort(parts, parts_number, sizeof(*parts), letters_comparator);
    for (int i = 0; i < parts_number; ++i)
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1,
               sorted_out);
    assert(is_sorted(parts, parts_number, sizeof(*parts), letters_comparator));

    sort(parts, parts_number, sizeof(*parts), letters_reversed_comparator);
    for (int i = 0; i < parts_number; ++i)
        fwrite(parts[i].begin, 1, parts[i].end - parts[i].begin + 1,
               reversed_sorted_out);
    assert(is_sorted(parts, parts_number, sizeof(*parts),
                     letters_reversed_comparator));

    free(parts);
    return 0;
}

int main(int argc, char **argv) {
    switch (argc) {
    case 4: {
        FILE *normal_out = fopen(argv[1], "w"),
             *sorted_out = fopen(argv[2], "w"),
             *reversed_sorted_out = fopen(argv[3], "w");
        if (!normal_out || !sorted_out || !reversed_sorted_out)
            return -1;
        int result =
            do_sort(stdin, normal_out, sorted_out, reversed_sorted_out);
        fclose(normal_out);
        fclose(sorted_out);
        fclose(reversed_sorted_out);
        return result;
    }
    case 1:
        return help();
    case 2:
        if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))
            return help();
    default:
        return unknown_command();
    }
}
