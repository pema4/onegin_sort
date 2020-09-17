#include "gtest/gtest.h"
#include "onegin/utils.h"

TEST(read_file, empty_file) {
    char text[] = "";
    FILE *file = fmemopen(text, sizeof(text), "r");
    char *read_text = read_file(file);
    fclose(file);

    EXPECT_STREQ(text, read_text);
}

TEST(read_file, small_file) {
    char text[] = "abc 123 456";
    FILE *file = fmemopen(text, sizeof(text) - 1, "r");
    char *read_text = read_file(file);
    fclose(file);

    EXPECT_STREQ(text, read_text);
}

TEST(read_file, medium_file) {
    char text[] = "I don't know what to write here.\nLet's improvise.";
    FILE *file = fmemopen(text, sizeof(text), "r");
    char *read_text = read_file(file);
    fclose(file);

    EXPECT_STREQ(text, read_text);
}
